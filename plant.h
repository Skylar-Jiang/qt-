#ifndef PLANT_H
#define PLANT_H

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPainter>
#include <QMovie>
#include <QString>
#include <QDebug>
#include "basic.h"


class Plant : public QGraphicsItem
{
public:
    int hp;
    int state;
    QString name;
    enum { Type = UserType + 1};
    Plant();
    ~Plant() override;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    int type() const override;
    void setMovie(QString path);
    void getDamage(int atk);
    void setPumpKin(int state);
protected:
    QMovie *movie;
    QMovie *pump;
    int pumpHp;
    bool havePump;
    int pumpState;
    int atk;
    int counter;
    int time;
};

#endif // PLANT_H
