#include "cherrybomb.h"

CherryBomb::CherryBomb()
{
    atk = 1800;
    hp = 300;
    setMovie(":/images/CherryBomb.gif");
    name = "CherryBomb";
}

QRectF CherryBomb::boundingRect() const
{
    return state ? QRectF(-150, -150, 300, 300) : Plant::boundingRect();
}

void CherryBomb::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (hp <= 0)
        delete this;
    else if (state == BOMB_PRE && movie->currentFrameNumber() == movie->frameCount() - 1)
    {
        QList<QGraphicsItem *> items = collidingItems();
        if (!items.isEmpty())
        {
            foreach (QGraphicsItem *item, items)
            {
                Zombie *zombie = qgraphicsitem_cast<Zombie *>(item);
                zombie->hp -= atk;
                if (zombie->hp <= 0)
                {
                    zombie->state = 3;
                    zombie->setMovie(":/images/Burn.gif");
                }
            }
            state = BOMB_BOMB;
            setMovie(":/images/Boom.gif");
        }     
    }
    else if (state == BOMB_BOMB && movie->currentFrameNumber() == movie->frameCount() - 1)
        delete this;
}


bool CherryBomb::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    return other->type() == Zombie::Type && QLineF(pos(), other->pos()).length() < 150;
}
