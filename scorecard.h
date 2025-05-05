#ifndef SCORECARD_H
#define SCORECARD_H

#include <QTimer>
#include <QSound>
#include <QString>
#include "interface.h"

class ScoreCard : public Interface
{
public:
    ScoreCard(QString s);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void addScore(int s);
private:
    QString score;
};

class MaxScoreCard : public Interface
{
public:
    MaxScoreCard(QString s);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
private:
    QString score;
};

#endif // SCORECARD_H