#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "mainwindow.h"

MainWindow * w;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    w= new MainWindow();
    w->show();

    return a.exec();
}
