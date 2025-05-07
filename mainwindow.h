#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QDebug>
#include "basic.h"
#include "shop.h"
#include "card.h"
#include "shovel.h"
#include "button.h"
#include "map.h"
#include "mower.h"
#include "basiczombie.h"
#include "conezombie.h"
#include "bucketzombie.h"
#include "screenzombie.h"
#include "footballzombie.h"
#include "newspaperzombie.h"
#include "file.h"
#include "scorecard.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow() override;
    void addZombie();
    void checkLose();
    void checkWin();
private:
    File *file;
    int maxScore;
    int score;
    QTimer *timer;
    QGraphicsScene *scene;
    QGraphicsView *view;
    ScoreCard *scorecard;
};

#endif // MAINWINDOW_H
