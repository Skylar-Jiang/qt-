#include "basiczombie.h"

BasicZombie::BasicZombie()
{
    hp = 300;
    atk = attack(100);
    speed = sped(4.7);
    allHp = hp;
    name = "BasicZombie";
    if (qrand() % 2)
        setMovie(":/images/ZombieWalk1.gif");
    else
        setMovie(":/images/ZombieWalk2.gif");
}

void BasicZombie::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (hp <= 0)
    {   //死亡
        if (state == ZOM_MOVE || state == ZOM_ATK)
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
            setMovie(":/images/ZombieAttack.gif");
        }
        return;
    }
    if (state)
    {
        state = ZOM_MOVE;
        if (qrand() % 2)
            setMovie(":/images/ZombieWalk1.gif");
        else
            setMovie(":/images/ZombieWalk2.gif");
    }
    setX(x() - speed);
}
