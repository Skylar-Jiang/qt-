#ifndef MOWER_H
#define MOWER_H

#include "interface.h"
#include "zombie.h"
//割草机
class Mower : public Interface
{
public:
    Mower();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    void advance(int phase) override;
private:
    bool flag;
    qreal speed;
};

#endif
