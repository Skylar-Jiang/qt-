#include "mainwindow.h"
#include <startwindow.h>
#include <QApplication>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    startwindow start;
    start.setFixedSize(900,600);
    start.setWindowTitle("植物大战僵尸");
    start.setWindowIcon(QIcon(":/images/myappico.ico"));

    w.setFixedSize(900, 600);
    w.setWindowTitle("植物大战僵尸");
    w.setWindowIcon(QIcon(":/images/myappico.ico"));

    QObject::connect(&start, &startwindow::startGame, [&]() {
            start.hide();
            w.show();
            w.timerStart();
        });

    start.show();
    return a.exec();
}
