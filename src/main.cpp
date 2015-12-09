#include "mainwindow.h"
#include <unistd.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowIcon(QIcon("\003.JPG"));
    w.show();
    return a.exec();
}
