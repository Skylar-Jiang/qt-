#include "footballzombie.h"

FootballZombie::FootballZombie()
{
    hp = 1600;
    atk = attack(100);
    speed = sped(2.5);
    allHp = hp;
    name = "FootballZombie";
    setMovie(":/images/FootballZombieWalk.gif");
}

void FootballZombie::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (hp <= 0)
    {
        if (state < ZOM_DIE)
        {
            state = ZOM_DIE;
            setMovie(":/images/FootballZombieDie.gif");
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
            setMovie(":/images/FootballZombieAttack.gif");
        }
        return;
    }
    if (state)
    {
        state = ZOM_MOVE;
        setMovie(":/images/FootballZombieWalk.gif");
    }
    setX(x() - speed);
}
