#include "shovel.h"

Shovel::Shovel()
{
    //铲子
}

QRectF Shovel::boundingRect() const
{
    return QRectF(-40, -40, 80, 80);
}

void Shovel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(QRect(-40, -40, 80, 80), QPixmap(":/images/ShovelBank.png"));
    painter->drawPixmap(QRect(-35, -35, 70, 70), QPixmap(":/images/Shovel.png"));
}

void Shovel::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    setCursor(Qt::ArrowCursor);
}

void Shovel::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    //和植物的移动类似
    if (QLineF(event->screenPos(), event->buttonDownScreenPos(Qt::LeftButton)).length() < QApplication::startDragDistance())
        return;
    QDrag *drag = new QDrag(event->widget());
    QMimeData *mime = new QMimeData;
    QImage image(":/images/Shovel.png");
    mime->setText("Shovel");
    mime->setImageData(image);
    drag->setMimeData(mime);
    drag->setPixmap(QPixmap::fromImage(image).scaled(70, 70));
    drag->setHotSpot(QPoint(35, 35));
    drag->exec();
    setCursor(Qt::ArrowCursor);
}

void Shovel::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    setCursor(Qt::ArrowCursor);
}

void Shovel::removePlant(QPointF pos)
{
    QList<QGraphicsItem *> items = scene()->items(pos);
    foreach (QGraphicsItem *item, items)
        if (item->type() == Plant::Type)
        {
            delete item;
            return;
        }
}
