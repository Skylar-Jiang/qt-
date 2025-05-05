#include "screenzombie.h"

ScreenZombie::ScreenZombie()
{
    hp = 1200;
    atk = attack(80);
    speed = sped(4.7);
    allHp = hp;
    screen = 1;
    name = "ScreenZombie";
    setMovie(":/images/ScreenZombieWalk.gif");
}

void ScreenZombie::advance(int phase)
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
    if(hp <= int(allHp/2) && screen == 1)
    {
        screen = 0;
        speed = sped(3.5);
        if(state == ZOM_MOVE)
            setMovie(":/images/ZombieWalk1.gif");
        else if(state == ZOM_ATK)
            setMovie(":/images/ZombieAttack.gif");
        update();
    }
    QList<QGraphicsItem *> items = collidingItems();
    if (!items.isEmpty())
    {
        Plant *plant = qgraphicsitem_cast<Plant *>(items[0]);
        if (state != ZOM_ATK)
        {
            state = ZOM_ATK;
            if(screen == 1)
                setMovie(":/images/ScreenZombieAttack.gif");
            else
                setMovie(":/images/ZombieAttack.gif");
        }
        plant->getDamage(atk);
        return;
    }
    if (state)
    {
        state = ZOM_MOVE;
        if(screen == 1)
            setMovie(":/images/ScreenZombieWalk.gif");
        else
            setMovie(":/images/ZombieWalk1.gif");
        
    }
    setX(x() - speed);
}
