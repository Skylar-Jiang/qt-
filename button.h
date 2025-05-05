#ifndef BUTTON_H
#define BUTTON_H

#include <QTimer>
#include "interface.h"
#include "file.h"

class Button : public Interface
{
public:
    Button(QTimer *t);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
private:
    QTimer *timer;
};

#endif // BUTTON_H

class Exit :public Interface
{
public:
    Exit(QTimer *t, int *m, int *sc);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
private:
    QTimer *timer;
    int *maxscore;
    int *score;

};
