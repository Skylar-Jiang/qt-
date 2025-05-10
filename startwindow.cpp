#include "startwindow.h"
#include <QStyleOptionGraphicsItem>
#include <QPainter>
#include <QMouseEvent>
#include <QFont>
#include <QPalette>

startwindow::startwindow(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(900, 600);
    backgroundImage.load(":/images/startbg.jpg");

    // 初始化闪烁定时器
    flashTimer = new QTimer(this);
    isTextVisible = true;

    // 连接定时器的 timeout 信号到槽函数
    connect(flashTimer, &QTimer::timeout, [this]() {
        isTextVisible = !isTextVisible;
        update(); // 触发重绘事件
    });

    // 启动定时器，设置闪烁间隔为 500 毫秒
    flashTimer->start(1000);
}

void startwindow::mousePressEvent(QMouseEvent *event)
{
    emit startGame(); // 发射开始游戏的信号
}

void startwindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    // 绘制背景图片
    if (!backgroundImage.isNull()) {
        painter.drawPixmap(0, 0, width(), height(), backgroundImage);
    }

    // 设置字体和颜色
    QFont font("Calibri", 15, QFont::Bold, true);
    QPalette palette;
    palette.setColor(QPalette::WindowText, QColor(255, 255, 0)); // 黄色文字
    painter.setFont(font);
    painter.setPen(palette.color(QPalette::WindowText));

    // 在屏幕中间绘制提示信息
    if (isTextVisible) {
        QString message = "Click anywhere to start";
        QRect rect = this->rect();
        painter.drawText(rect, Qt::AlignCenter, message);
    }
}
