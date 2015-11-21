#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QTreeWidget>
#include <string>
#include <vector>
#include "csvprocessing/PublicationProcessing.h"
#include "csvprocessing/GrantProcessing.h"
#include "csvprocessing/PresentationProcessing.h"
#include "csvprocessing/TeachingProcessing.h"


#include "ui_mainwindow.h"
#include <QFileDialog>
#include "../lib/qcustomplot.h"

namespace Ui {
class MainWindow;
}

using namespace std;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    /**
     * Draw graph onto windows canvas
     *
     * @param w
     * @param yAxisData
     * @param title
     * @return
     */
    void makeGraph(QVector<double> yAxisData, QString title , vector<string> barLabels);
    void makePie(QVector<double> pieData, QString title, vector<string> pieLabels );
    void makeScatter(QVector<double> xData, QVector<double> yData, QString title );
    void makeLine(QVector<double> xData, QVector<double> yData, QString title );

private slots:
    QString on_actionOpen_triggered();

    void on_bntDisplayGraph_clicked();
    void on_bntDisplayPie_clicked();
    void on_bntDisplayScatter_clicked();
    void on_bntDisplayLine_clicked();

    QStringList on_btnDates_clicked();

private:
    Ui::MainWindow *ui;

    void initDate_Month(QComboBox *months);
    void initDate_Years(QComboBox *months);
    void addTreeRoot(QTreeWidgetItem *treeBranch,QString name, QString description);
    void addTreeChild(QTreeWidgetItem *parent, QString name, QString description);
    void drawDashboard();

    QDate Startdate;
    QDate Enddate;
    CSVProcessing* p;
    vector<int> indDate;
};

#endif // MAINWINDOW_H
