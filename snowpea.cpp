#include "snowpea.h"

SnowPea::SnowPea()
{
    atk = 25;
    hp = 300;
    time = atk_speed(1.4);
    setMovie(":/images/SnowPea.gif");
    name = "SnowPea";
}

void SnowPea::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (hp <= 0)
        delete this;
    else if (++counter >= time)
    {
        counter = 0;
        if (!collidingItems().isEmpty())
        {
            Pea *pea = new Pea(atk, true);
            pea->setX(x() + 32);
            pea->setY(y());
            scene()->addItem(pea);
            return;
        }
    }
}

bool SnowPea::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    return other->type() == Zombie::Type && qFuzzyCompare(other->y(), y());
}
