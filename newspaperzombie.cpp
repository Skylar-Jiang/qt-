#include "newspaperzombie.h"

NewspaperZombie::NewspaperZombie()
{
    hp = 1200;
    atk = attack(100);
    speed = sped(4.5);
    allHp = hp;
    newspaper = 1;
    name = "NewspaperZombie";
    setMovie(":/images/NewsZombieWalk0.gif");
}

void NewspaperZombie::advance(int phase)
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
    if(hp <= int(allHp/2) && newspaper == 1)
    {
        newspaper = 0;
        speed = sped(3.0);
        atk = attack(100);
        if(state == ZOM_ATK)
            setMovie(":/images/NewsZombieAttack1.gif");
        else if(state == ZOM_MOVE)
            setMovie(":/images/NewsZombieWalk1.gif");
        update();
    }
    QList<QGraphicsItem *> items = collidingItems();
    if (!items.isEmpty())
    {
        Plant *plant = qgraphicsitem_cast<Plant *>(items[0]);
        if (state != ZOM_ATK)
        {
            state = ZOM_ATK;
            if(newspaper == 1)
                setMovie(":/images/NewsZombieAttack0.gif");
            else
                setMovie(":/images/NewsZombieAttack1.gif");
        }
        plant->getDamage(atk);
        return;
    }
    if (state)
    {
        state = ZOM_MOVE;
        if(newspaper == 1)
            setMovie(":/images/NewsZombieWalk0.gif");
        else
            setMovie(":/images/NewsZombieWalk1.gif");
        
    }
    setX(x() - speed);
}
