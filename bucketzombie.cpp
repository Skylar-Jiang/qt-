#include "bucketzombie.h"

BucketZombie::BucketZombie()
{
    hp = 1000;
    atk = attack(100);
    speed = sped(4.7);
    allHp = hp;
    name = "BucketZombie";
    setMovie(":/images/BucketZombieWalk.gif");
}

void BucketZombie::advance(int phase)
{
    if (!phase)
        return;
    update(); //更新窗口
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
            setMovie(":/images/BucketZombieAttack.gif");
        }
        return;
    }
    if (state)
    {
        state = ZOM_MOVE;
        setMovie(":/images/BucketZombieWalk.gif");
    }
    setX(x() - speed);
}
