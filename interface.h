#ifndef OTHER_H
#define OTHER_H

#include <QGraphicsItem>
#include <QtWidgets>
#include <QPainter>

class Interface : public QGraphicsItem
{
public:
    enum { Type = UserType + 3};
    Interface();
    int type() const override;
};

#endif // OTHER_H
