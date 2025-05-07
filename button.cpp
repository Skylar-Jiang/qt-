#include "button.h"
#include <QTextStream>

Button::Button( QTimer *t)
{
    timer = t;
}

QRectF Button::boundingRect() const
{
    return QRectF(-80, -20, 160, 40);
}

void Button::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(QRect(-80, -20, 160, 40), QPixmap(":/images/Button.png"));
    painter->setPen(Qt::green);
    QFont font("Calibri", 15, QFont::Bold, true); //字体设置
    painter->setFont(font);
    if (timer->isActive())
        painter->drawText(boundingRect(), Qt::AlignCenter, "PAUSE");
    else
        painter->drawText(boundingRect(), Qt::AlignCenter, "CONTINUE");
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        if (timer->isActive())
        {
            timer->stop();
        }
        else
        {
            timer->start();
        }
    }
    update();
}

Exit::Exit( QTimer *t, int *m, int *sc)
{
    timer = t;
    maxscore = m;
    score = sc;
}

QRectF Exit::boundingRect() const
{
    return QRectF(-80, -20, 160, 40);
}

void Exit::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(QRect(-80, -20, 160, 40), QPixmap(":/images/Button.png"));
    painter->setPen(Qt::green);
    QFont font("Calibri", 15, QFont::Bold, true); //字体设置
    painter->setFont(font);
    painter->drawText(boundingRect(), Qt::AlignCenter, "EXIT");
}

void Exit::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        timer->stop();
        QFile file("/Users/apple/Desktop/plantVSzombie/txt/maxscore.txt");
        if( *maxscore < *score)
        {
            if(file.open(QIODevice::WriteOnly | QIODevice::Text))
            {
                QTextStream txtOutput(&file);
                txtOutput << QString::number(*score, 10);
                file.close();
            }
        }
        exit(-1);
    }
    update();
}
