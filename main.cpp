#include "mainwindow.h"
#include <QApplication>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(900, 600);
    w.setWindowTitle("植物大战僵尸");
    w.setWindowIcon(QIcon(":/images/myappico.ico"));
    w.show();
    return a.exec();
}
