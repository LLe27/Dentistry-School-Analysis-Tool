#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

<<<<<<< HEAD
namespace Ui
{
    class MainWindow;
=======
namespace Ui {
class MainWindow;
>>>>>>> Demo1
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

<<<<<<< HEAD
    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();

    private:
        Ui::MainWindow *ui;
=======
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
>>>>>>> Demo1
};

#endif // MAINWINDOW_H
