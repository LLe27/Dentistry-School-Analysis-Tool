#include "mainwindow.h"
#include <unistd.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPixmap pixmap(":/myFiles/BarIcon.png");

    QSplashScreen splash(pixmap);
    splash.show();
    a.processEvents();
    MainWindow w;
    w.show();
    splash.finish(&w);


    return a.exec();
}
