#include "mainwindow.h"
#include <unistd.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowIcon(QIcon(":images/shulichlogo.png"));
    w.show();
    return a.exec();
}
