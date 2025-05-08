#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    //随机化
    qsrand(uint(QTime(0,0,0).secsTo(QTime::currentTime())));
    file = new File;
    maxScore = file->getMaxScore();
    score = 0;
    sound = new QSound(":/audio/Kitanai_Sekai.wav");
    sound->setLoops(QSound::Infinite);
    sound->play();
    //以上会使音乐顺序播放
    timer = new QTimer;
    scene = new QGraphicsScene(this);
    scene->setSceneRect(150, 0, 900, 600);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);

    Shop *shop = new Shop;
    shop->setPos(520, 45);
    scene->addItem(shop);

    Shovel *shovel = new Shovel;
    shovel->setPos(830, 40);
    scene->addItem(shovel);

    scorecard = new ScoreCard(QString::number(score, 10));
    scorecard->setPos(200, 60);
    scene->addItem(scorecard);
    MaxScoreCard *maxscore = new MaxScoreCard(QString::number(maxScore, 10));
    maxscore->setPos(200, 20);
    scene->addItem(maxscore);

    Button *button = new Button(sound, timer);
    button->setPos(970, 20);
    scene->addItem(button);
    Exit *button1 = new Exit(sound, timer, &maxScore, &score);
    button1->setPos(970, 60);
    scene->addItem(button1);

    Map *map = new Map;
    map->setPos(618, 326);
    scene->addItem(map);

    for (int i = 0; i < 5; ++i)
    {
        Mower *mower = new Mower;
        mower->setPos(MOWER_X, MAP_Y + CELL_HIGHT * i);
        scene->addItem(mower);
    }
    view = new QGraphicsView(scene, this);
    view->resize(902, 602);
    view->setRenderHint(QPainter::Antialiasing); //反走样
    view->setBackgroundBrush(QPixmap(":/images/Background.jpg"));
    view->setCacheMode(QGraphicsView::CacheBackground);
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    connect(timer, &QTimer::timeout, scene, &QGraphicsScene::advance);
    connect(timer, &QTimer::timeout, this, &MainWindow::addZombie);
    connect(timer, &QTimer::timeout, this, &MainWindow::checkLose);
    connect(timer, &QTimer::timeout, this, &MainWindow::checkWin);
    timer->start(33);
    view->show();
}

MainWindow::~MainWindow()
{
    delete sound;
    delete timer;
    delete scene;
    delete view;
    delete scorecard;
    delete file;
}

void MainWindow::addZombie()
{
    static int maxtime = ZOMBIE_APPEAR_SPEED;
    static int time = maxtime / 2;
    static int counter = 0;
    if (++counter >= time)
    {
        counter = 0;
        //基于一定范围的随机时间算法
        time = qrand() % (2 * maxtime / 3) + maxtime / 3;
        //按照不同比例产生僵尸
        int type = qrand() % 150;
        int i = qrand() % 5;
        Zombie *zombie;
        if (type < 40)
        {
            zombie = new BasicZombie;
            score += 15;
            scorecard->addScore(15);
        }
        else if (type < 70)
        {
            zombie = new ConeZombie;
            score += 20;
            scorecard->addScore(20);
        }
        else if (type < 90)
        {
            score += 20;
            zombie = new BucketZombie;
            scorecard->addScore(20);
        }
        else if (type < 110)
        {
            score += 20;
            zombie = new ScreenZombie;
            scorecard->addScore(20);
        }
        else if (type < 120)
        {
            score += 30;
            zombie = new FootballZombie;
            scorecard->addScore(30);
        }
        else if (type < 140)
        {
            score += 25;
            zombie = new NewspaperZombie;
            scorecard->addScore(25);
        }
        if(type >= 0 && type < 140)
        {   //有1/15的概率不产生僵尸
            zombie->setPos(1028, MAP_Y + CELL_HIGHT * i);
            scene->addItem(zombie);
        }
    }
}

//检查是否失败
void MainWindow::checkLose()
{
    static int time = 1 * 1000 / 33;
    static int counter = 0;
    if (++counter >= time)
    {
        counter = 0;
        const QList<QGraphicsItem *> items = scene->items();
        foreach (QGraphicsItem *item, items)
            if (item->type() == Zombie::Type && item->x() < 200)
            {
                scene->addPixmap(QPixmap(":/images/ZombiesWon.png"))->setPos(336, 92);
                scene->advance();
                timer->stop();
                file->writeScore(score);
                return;
            }
    }
}

//检查是否成功
void MainWindow::checkWin()
{
    if (score >= 999){
        scene->addPixmap(QPixmap(":/images/WeWin.png"))->setPos(255, 140);
        scene->advance();
        timer->stop();
        file->writeScore(score);
        return;
    }
}
