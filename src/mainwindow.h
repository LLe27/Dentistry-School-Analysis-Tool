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
#include "startup.h"

#include "ui_mainwindow.h"
#include <QFileDialog>
#include "../lib/qcustomplot.h"
#include "../lib/nightcharts/nightcharts.h"
#include "../lib/nightcharts/nightchartswidget.h"

namespace Ui {
class MainWindow;
}

using namespace std;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * Constructor
     *
     * @param parent
     */
    explicit MainWindow(QWidget *parent = 0);

    /**
     * Deconstructor
     */
    ~MainWindow();

    /**
     * Draw bar graph onto windows canvas
     *
     * @param w
     * @param yAxisData
     * @param title
     * @return
     */
    void makeBarGraph(QVector<double> yAxisData, QString title , vector<string> barLabels);

    /**
     * Draw pie graph onto windows canvas
     *
     * @param pieData
     * @param title
     * @param pieLabels
     */
    void makePie(QVector<double> pieData, QString title, vector<string> pieLabels );

    /**
     * Draw scatter graph onto windows canvas
     *
     * @param xData
     * @param yData
     * @param title
     */
    void makeScatter(QVector<double> xData, QVector<double> yData, QString title );

    /**
     * Draw line graph onto windows canvas
     *
     * @param xData
     * @param yData
     * @param title
     */
    void makeLine(QVector<double> xData, QVector<double> yDataMax,
                  QVector<QVector<double>>, QVector<QString> names, QString title );



private slots:
    /**
     * Returns file name of selected file in QFileDialog
     *
     * @return
     */
    QString on_actionOpen_triggered();

    /**
     * Button response function. Calls plot function for current data.
     */
    void on_bntDisplayBar_clicked();

    /**
     * Button response function. Calls plot function for current data.
     */
    void on_bntDisplayPie_clicked();

    /**
     * Button response function. Calls plot function for current data.
     */
    void on_bntDisplayScatter_clicked();

    /**
     * Button response function. Calls plot function for current data.
     */
    void on_bntDisplayLine_clicked();

    /**
     * Button response function. Creates a treeWidget for the Help Menu
     */
    void helpContents();

    /**
     * Button response function. Updates date range and queries data for new range.
     */
    void on_btnDates_clicked();

    /**
     * Button response function. Collapses all nodes in dashboard tree.
     */
    void on_btnCollapse_clicked();

    /**
     * Button response function. Expands all nodes in dashboard tree.
     */

    void on_btnExpand_clicked();

    void on_pushButton_clicked();

    void saveDashboard();
    void viewDashboard();
    void saveBarGraph();
    void saveLineGraph();
    void savePieChart();
    void saveScatterPlot();

private:
    /*
     * Commented out unused functions
     */
//    void initDate_Month(QComboBox *months);
//    void initDate_Years(QComboBox *months);

    /**
     * Initializing Function. Pops up start menu and creates default palletes for GUI
     */
    void initialize();

    /**
     * Swaps the background pallete with the parameter color.
     *
     * @param color
     */
    void PaletteSwap(QColor color);

    void createActions();
    void createMenus();
    void addComboBoxItems();
    vector<int> remove_from_other(vector<int> indOther, vector<int> indStatus);



    void initDate_Month(QComboBox *months);
    void initDate_Years(QComboBox *months);

    /**
     * Adds root with specified name and description to specified branch. (for Dashboard with two columns)
     *
     * @param treeBranch
     * @param name
     * @param description
     */

    void addTreeRoot(QTreeWidgetItem *treeBranch,QString name, QString description);

    /**
     * Adds root with specified name and descirption and count to specified branch. (for Dashboard with three columns)
     *
     * @param treeBranch
     * @param name
     * @param description
     * @param count
     */
    void addTreeRoot(QTreeWidgetItem *treeBranch, QString name, QString description, QString count);


    /**
     * Adds child with specified name and description to specified root.
     *
     * @param parent
     * @param name
     * @param description
     */
    void addTreeChild(QTreeWidgetItem *parent, QString name, QString description);

    void createHelpMenu();


    void createOptimalYAxis(QCustomPlot * customPlot, int range);



    /**
     * Draws dashboard with current date-range data.
     */
    void drawDashboard();

    /**
      * Duplicates dashboard in a new window with the option to save
      *
      * @param save
      */
    void duplicateDashboard(int save);

    /*
     * Private Instance Variables
     */

    QCustomPlot* barcustomPlot;
    QCustomPlot* linecustomPlot;
    QCustomPlot* scattercustomPlot;
    NightchartsWidget* PieChart;


    Ui::MainWindow *ui;
    QMenu *HelpMenu;
    QAction *HelpAction;
    QTreeWidget* tree;
    QDate Startdate;
    QDate Enddate;
    CSVProcessing* p;
    vector<int> indDate;
    int csvtype;
    StartUp *s;
};

#endif // MAINWINDOW_H
