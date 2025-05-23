#include "potatomine.h"

PotatoMine::PotatoMine()
{
    atk = 1800;
    hp = 300;
    time = int(15.0 * 1000 / 33);
    setMovie(":/images/PotatoMine1.gif");
    name = "PotatoMine";
}

QRectF PotatoMine::boundingRect() const
{
    return state == 2 ? QRectF(-75, -75, 150, 150) : Plant::boundingRect();
}

void PotatoMine::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (hp <= 0)
        delete this;
    else if (state == BOMB_PRE && ++counter >= time)
    {
        state = BOMB_REA;
        counter = 0;
        time = int(1.0 * 1000 / 33);
        setMovie(":/images/PotatoMine.gif");
    }
    else if (state == BOMB_REA && ++counter >= time)
    {
        counter = 0;
        QList<QGraphicsItem *> items = collidingItems();
        if (!items.isEmpty())
        {
            state = BOMB_BOMB;
            setMovie(":/images/PotatoMineBomb.gif");
            foreach (QGraphicsItem *item, items)
            {
                Zombie *zombie = qgraphicsitem_cast<Zombie *>(item);
                zombie->hp -= atk;
                if (zombie->hp <= 0)
                    delete zombie;
            }
        }
    }
    else if (state == BOMB_BOMB && movie->currentFrameNumber() == movie->frameCount() - 1)
        delete this;
}

bool PotatoMine::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    return other->type() == Zombie::Type && qFuzzyCompare(other->y(), y()) && qAbs(other->x() - x()) < 50;
}

