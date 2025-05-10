#ifndef STARTWIDGET_H
#define STARTWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QPixmap>
#include <QMouseEvent>
#include <QTimer>  // 引入 QTimer 用于闪烁效果

class startwindow : public QWidget
{
    Q_OBJECT
    QWidget *widget;
    QPixmap backgroundImage; // 用于存储背景图片
    QTimer *flashTimer;      // 闪烁定时器
    bool isTextVisible;      // 标记文字是否可见

public:
    explicit startwindow(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *event) override; // 重写鼠标点击事件

signals:
    void startGame(); // 声明开始游戏的信号

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // STARTWIDGET_H
