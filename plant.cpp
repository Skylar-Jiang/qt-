#include "plant.h"
#include "zombie.h"

Plant::Plant()
{
    movie = nullptr;
    atk = counter = state = time = 0;
    pump = nullptr;
    havePump = 0;
    pumpHp = PUMPKIN_HP;
    pumpState = 0;
}

Plant::~Plant()
{
    delete movie;
}

QRectF Plant::boundingRect() const
{   //返回边界矩形
    return QRectF(-35, -35, 70, 70);
}

void Plant::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{   //画植物
    painter->drawImage(boundingRect(), movie->currentImage());
    if(havePump)
        painter->drawImage(QRectF(-35, -10, 70, 50), pump->currentImage());
}

bool Plant::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{   //判断僵尸是否到达植物，qFuzzyCompare用于浮点数比较
    return other->type() == Zombie::Type && qFuzzyCompare(other->y(), y()) && qAbs(other->x() - x()) < 30;
}

int Plant::type() const
{
    return Type;
}

void Plant::setMovie(QString path)
{   //设置动画
    if (movie)
        delete movie;
    movie = new QMovie(path);
    movie->start();
}

void Plant::getDamage(int atk)
{
    if(havePump == 1)
    {
        pumpHp -= atk;
        if(pumpHp <= 0)
        {
            havePump = 0;
            pumpHp = PUMPKIN_HP;
            pumpState = 0;
            delete pump;
            pump = nullptr;
        }
        else if (pumpHp <= int(PUMPKIN_HP/2) && pumpState != 2) //1是满血状态，2是半血状态，0是没有南瓜
        {
            pumpState = 2;
            setPumpKin(pumpState);
        }
    }
    else
    {
        hp -= atk;
    }
    
}

void Plant::setPumpKin(int state)
{
    if (pump)
        delete pump;
    if(state == 0)
    {
        pump = new QMovie(":/images/Pumpkin1.gif");      
        havePump = 1;
        pumpHp = PUMPKIN_HP;
        pumpState = 1;
    }
    else if(state == 1)
        pump = new QMovie(":/images/Pumpkin1.gif");
    else if(state == 2)
        pump = new QMovie(":/images/Pumpkin2.gif");
    pump->start();
}
