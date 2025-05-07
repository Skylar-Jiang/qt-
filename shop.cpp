#include "shop.h"

Shop::Shop()
{
    sun = 2000;
    counter = 0;
    time = int(7.0 * 1000 / 33);
    Card *card = nullptr;
    for (int i = 0; i < Card::name.size(); ++i)
    {
        //初始化每张卡牌
        card = new Card(Card::name[i]);
        card->setParentItem(this);
        card->setPos(-157 + 65 * i, -2);
    }
}

QRectF Shop::boundingRect() const
{
    return QRectF(-270, -45, 540, 90);
}

void Shop::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(QRect(-270, -45, 540, 90), QPixmap(":/images/Shop.png"));
    QFont font;
    font.setPointSizeF(10);
    painter->setFont(font);
    painter->drawText(QRectF(-255, 18, 65, 22), Qt::AlignCenter, QString::number(sun));
    painter->drawPoint(-220, 0);
}

void Shop::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (++counter >= time)
    {
        counter = 0;
        scene()->addItem(new Sun);
    }
}

void Shop::addPlant(QString s, QPointF pos)
{
    qDebug() << s;
    if(s != "Pumpkin")
    {
        //种植物
        QList<QGraphicsItem *> items = scene()->items(pos);
        foreach (QGraphicsItem *item, items)
            if (item->type() == Plant::Type) //如果已经种过了植物，就不能再种了
                return;
        sun -= Card::cost[Card::map[s]];
        Plant *plant = nullptr;
        switch (Card::map[s])
        {
        case 0:
            plant = new SunFlower; break;
        case 1:
            plant = new SnowPea; break;
        case 2:
            plant = new Repeater; break;
        case 3:
            plant = new WallNut; break;
        case 4:
            plant = new PotatoMine; break;
        case 5:
            plant = new CherryBomb; break;
        case 6:
            plant = new Pumpkin; break;
        }
        plant->setPos(pos);
        scene()->addItem(plant);
        QList<QGraphicsItem *> child = childItems();
        foreach (QGraphicsItem *item, child)
        {
            Card *card = qgraphicsitem_cast<Card *>(item);
            if (card->text == s) //重置冷却时间
                card->counter = 0;
        }
        counter = 0;
    }
    else
    {
        QList<QGraphicsItem *> items = scene()->items(pos);
        Plant *plant = nullptr;
        bool havePlant = 0;
        foreach (QGraphicsItem *item, items)
        {
            if (item->type() == Plant::Type) //如果已经种过了植物，就不能再种了
            {
                plant = qgraphicsitem_cast<Plant *>(item);
                havePlant = 1;
            }
        }
        if(havePlant == 0)
        {
            sun -= Card::cost[Card::map[s]];
            plant = new Pumpkin;
            plant->setPos(pos);
            scene()->addItem(plant);
            QList<QGraphicsItem *> child = childItems();
            foreach (QGraphicsItem *item, child)
            {
                Card *card = qgraphicsitem_cast<Card *>(item);
                if (card->text == s) //重置冷却时间
                    card->counter = 0;
            }
            counter = 0;
        }
        else
        {
            if(plant->name == "Pumpkin" || plant->name == "CherryBomb" || plant->name == "PotatoMine")
                return;
            sun -= Card::cost[Card::map[s]];
            plant->setPumpKin(0);
            QList<QGraphicsItem *> child = childItems();
            foreach (QGraphicsItem *item, child)
            {
                Card *card = qgraphicsitem_cast<Card *>(item);
                if (card->text == s) //重置冷却时间
                    card->counter = 0;
            }
            counter = 0;
        }
        
    }
    
}
