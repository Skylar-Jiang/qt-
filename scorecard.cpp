#include "scorecard.h"

ScoreCard::ScoreCard(QString s)
{
    score = s;
}

QRectF ScoreCard::boundingRect() const
{
    return QRectF(-50, -20, 100, 40);
}

void ScoreCard::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(QRect(-50, -20, 100, 40), QPixmap(":/images/ScoreCard.jpeg"));
    painter->setPen(Qt::green);
    QFont font("Calibri", 15, QFont::Bold, true); //字体设置
    painter->setFont(font);
    QString sc = " .NOW:" + score;
    painter->drawText(boundingRect(), Qt::AlignLeft | Qt::AlignVCenter, sc);
}

void ScoreCard::addScore(int s)
{
    int tmp = score.toInt();
    score = QString::number((tmp + s), 10);
}

MaxScoreCard::MaxScoreCard(QString s)
{
    score = s;
}

QRectF MaxScoreCard::boundingRect() const
{
    return QRectF(-50, -20, 100, 40);
}

void MaxScoreCard::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(QRect(-50, -20, 100, 40), QPixmap(":/images/ScoreCard.jpeg"));
    painter->setPen(Qt::green);
    QFont font("Calibri", 15, QFont::Bold, true); //字体设置
    painter->setFont(font);
    if(score.toInt() > 999)
        score == "999";
    QString sc = " .MAX:" + score;
    painter->drawText(boundingRect(), Qt::AlignLeft | Qt::AlignVCenter, sc);
}
