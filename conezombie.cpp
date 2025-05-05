#include "conezombie.h"

ConeZombie::ConeZombie()
{   //路障僵尸
    hp = 600;
    atk = attack(100);
    speed = sped(4.7);
    allHp = hp;
    setMovie(":/images/ConeZombieWalk.gif");
}

void ConeZombie::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (hp <= 0)
    {
        if (state < ZOM_DIE)
        {
            state = ZOM_DIE;
            setMovie(":/images/ZombieDie.gif");
            setHead(":/images/ZombieHead.gif");
        }
        else if (movie->currentFrameNumber() == movie->frameCount() - 1)
            delete this;
        return;
    }
    QList<QGraphicsItem *> items = collidingItems();
    if (!items.isEmpty())
    {
        Plant *plant = qgraphicsitem_cast<Plant *>(items[0]);
        plant->getDamage(atk);
        if (state != ZOM_ATK)
        {
            state = ZOM_ATK;
            setMovie(":/images/ConeZombieAttack.gif");
        }
        return;
    }
    if (state)
    {
        state = ZOM_MOVE;
        setMovie(":/images/ConeZombieWalk.gif");
    }
    setX(x() - speed);
}
