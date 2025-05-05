#ifndef CARD_H
#define CARD_H

#include "interface.h"

class Card : public Interface
{
public:
    int counter;
    QString text;
    Card(QString s);
    const static QMap<QString, int> map; //可以直接通过名字锁定其他变量
    const static QVector<QString> name;
    const static QVector<int> cost;
    const static QVector<int> cool;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void advance(int phase) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
private:
};

#endif // CARD_H
