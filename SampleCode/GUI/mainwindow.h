#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QTreeWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    void initDate_Month(QComboBox *months);
    void initDate_Years(QComboBox *months);
    void addTreeRoot(QTreeWidgetItem *treeBranch,QString name, QString description);
    void addTreeChild(QTreeWidgetItem *parent, QString name, QString description);
};

#endif // MAINWINDOW_H
