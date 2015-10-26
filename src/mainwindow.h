#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
<<<<<<< HEAD

<<<<<<< HEAD
namespace Ui
{
    class MainWindow;
=======
namespace Ui {
class MainWindow;
>>>>>>> Demo1
}

=======
#include <QComboBox>
#include <QTreeWidget>
#include <string>
#include <vector>
#include "publicationprocessing/PublicationProcessing.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include "../lib/qcustomplot.h"

namespace Ui {
class MainWindow;
}

using namespace std;

>>>>>>> DEMO1_25102015
class MainWindow : public QMainWindow
{
    Q_OBJECT

<<<<<<< HEAD
<<<<<<< HEAD
    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();

    private:
        Ui::MainWindow *ui;
=======
=======
>>>>>>> DEMO1_25102015
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

<<<<<<< HEAD
private:
    Ui::MainWindow *ui;
>>>>>>> Demo1
=======
    /**
     * Draw graph onto windows canvas
     *
     * @param w
     * @param yAxisData
     * @param title
     * @return
     */
    void makeGraph(QVector<double> yAxisData, QString title , vector<string> barLabels);

private slots:
    QString on_actionOpen_triggered();

    void on_bntDisplayGraph_clicked();

    QStringList on_btnDates_clicked();

private:
    Ui::MainWindow *ui;
    //PublicationProcessing p;

    void initDate_Month(QComboBox *months);
    void initDate_Years(QComboBox *months);
    void addTreeRoot(QTreeWidgetItem *treeBranch,QString name, QString description);
    void addTreeChild(QTreeWidgetItem *parent, QString name, QString description);
    void processDates();
>>>>>>> DEMO1_25102015
};

#endif // MAINWINDOW_H
