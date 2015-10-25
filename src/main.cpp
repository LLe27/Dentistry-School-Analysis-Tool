#include "mainwindow.h"
#include <QApplication>
#include <QString>
#include "marcgraph.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QVector<double> numItems;
    QString title = "my title";

    numItems
            << 35
            << 40
            << 23
            << 63
            << 51
            << 47
            << 60
            << 23
            << 25
            << 71
            << 59
            << 11
            << 35
            << 33
            << 32
            << 61
            << 28
            << 14
            << 27
            << 57
            << 12;

    makeGraph(w, numItems, title);

    return a.exec();
}
