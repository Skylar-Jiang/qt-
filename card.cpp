#include "card.h"
#include "shop.h"

const QMap<QString, int> Card::map = {{"SunFlower", 0}, {"SnowPea", 1}, {"Repeater", 2}, {"WallNut", 3},
                                      {"PotatoMine", 4}, {"CherryBomb", 5}, {"Pumpkin", 6}};
const QVector<QString> Card::name = {"SunFlower", "SnowPea", "Repeater", "WallNut",
                                     "PotatoMine", "CherryBomb", "Pumpkin"};
const QVector<int> Card::cost = {50, 100, 150, 50, 50, 150, 50};
//const QVector<int> Card::cool = {227, 227, 227, 606, 606, 1437, 227};
const QVector<int> Card::cool = {227, 227, 227, 606, 606, 227, 227};
Card::Card(QString s)
{
    text = s;
    counter = 0;
}

QRectF Card::boundingRect() const
{
    return QRectF(-50, -30, 100, 60);
}

void Card::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->scale(0.6, 0.58);
    painter->drawPixmap(QRect(-50, -70, 100, 140), QPixmap(":/images/Card.png"));
    painter->drawPixmap(QRect(-35, -42, 70, 70), QPixmap(":/images/" + text + ".png"));
    QFont font;
    font.setPointSizeF(15);
    painter->setFont(font);
    painter->drawText(-30, 60, QString().sprintf("%3d", cost[map[text]]));
    if (counter < cool[map[text]])
    {   //绘制阴影，透明度为200
        QBrush brush(QColor(0, 0, 0, 200), Qt::Dense1Pattern);
        painter->setBrush(brush);
        painter->drawRect(QRectF(-48, -68, 96, 138 * (1 - qreal(counter) / cool[map[text]]))); //画阴影
    }
}

void Card::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (counter < cool[map[text]])
        counter++;
}

void Card::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (counter < cool[map[text]])
        event->setAccepted(false);
    Shop *shop = qgraphicsitem_cast<Shop *>(parentItem()); //强制类型转换，先转换为Interface，再转换为Shop
    if (cost[map[text]] > shop->sun)
        event->setAccepted(false);
    setCursor(Qt::ArrowCursor);
}

void Card::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    //处理点击后只拖动一小段距离没有离开card的情况
    if (QLineF(event->screenPos(), event->buttonDownScreenPos(Qt::LeftButton)).length() < QApplication::startDragDistance())
        return;
    QDrag *drag = new QDrag(event->widget());
    QMimeData *mime = new QMimeData; //中间存储容器
    QImage image(":/images/" + text + ".png");
    mime->setText(text);
    mime->setImageData(image);
    drag->setMimeData(mime);
    drag->setPixmap(QPixmap::fromImage(image));
    drag->setHotSpot(QPoint(35, 35));
    drag->exec();
    setCursor(Qt::ArrowCursor);
}

void Card::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    setCursor(Qt::ArrowCursor);
}
