#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPainter>
#include <QMovie>
#include "basic.h"

class Zombie : public QGraphicsItem
{
public:
    int hp;
    int allHp;
    int atk;
    int state;
    qreal speed;
    QString name;
    enum { Type = UserType + 2};
    Zombie();
    ~Zombie() override;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    int type() const override;
    void setMovie(QString path);
    void setHead(QString path);
    void beSnow();
protected:
    QMovie *movie;
    QMovie *head; //死亡僵尸头部GIF
};

#endif // ZOOMBIE_H
