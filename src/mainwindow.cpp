//Necessary Includes
#include <QDate>
#include "mainwindow.h"
#include "../lib/nightcharts/nightcharts.h"
#include "../lib/nightcharts/nightchartswidget.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initialize();

    string filename = on_actionOpen_triggered().toStdString();

    this->setWindowTitle("Dashboard");

    //Hardcoded value for csv type int, have to finish main window/check csv type


    //List to store the text of the colun headers for the treeWidget
    QStringList ColumnNames;

    switch(csvtype){
        //Publications
        case(1):
            p = new PublicationProcessing(filename,csvtype);
            ui->treeWidget->setColumnCount(2);
            ColumnNames << " " << "Total";
            break;
        //Teaching
        case(2):
            p = new TeachingProcessing(filename, csvtype);
            ui->treeWidget->setColumnCount(3);
            ColumnNames << " " << "Hours" << "Students";

            //Min text box
            ui->minText_1->setVisible(true);
            ui->minText_2->setVisible(true);

            ui->minText_1->setText(QString::number(0));
            ui->minText_2->setText(QString::number(0));

            //Hypens
            ui->labelHyp_1->setVisible(true);
            ui->labelHyp_2->setVisible(true);

            //Max text box
            ui->maxText_1->setVisible(true);
            ui->maxText_2->setVisible(true);

            ui->maxText_1->setText(QString::number(100));
            ui->maxText_2->setText(QString::number(100));

            //Min label
            ui->lblMin_1->setVisible(true);
            ui->lblMin_2->setVisible(true);

            //Max label
            ui->lblMax_1->setVisible(true);
            ui->lblMax_2->setVisible(true);




            break;
        //Presentations
        case(3):
            p = new PresentationProcessing(filename,csvtype);
            ui->treeWidget->setColumnCount(2);
            ColumnNames << " " << "#of \npresentations" ;
            break;
        //Grants
        case(4):
            p = new GrantProcessing(filename, csvtype);
            ui->treeWidget->setColumnCount(3);
            ColumnNames << " " << "Total#" << "Total$" ;

            ui->minText_1->setVisible(true);
            ui->maxText_1->setVisible(true);
            ui->labelHyp_1->setVisible(true);
            ui->lblMin_1->setVisible(true);
            ui->lblMax_1->setVisible(true);

            ui->minText_1->setText(QString::number(0));
            ui->maxText_1->setText(QString::number(10));
            break;
        default:
            ui->treeWidget->setColumnCount(3);
            //CSV is not of the four types
        }


    //Read in list of Column Names to set the column Names
    ui->treeWidget->setHeaderLabels(ColumnNames);
    ui->treeWidget->setColumnWidth(0,150);

    ui->dateEdit->setMaximumDate(QDate::currentDate());
    ui->dateEdit_2->setMaximumDate(QDate::currentDate());

    ui->dateEdit_2->setDate(QDate::currentDate());

    //Create treewidget item asa root
    ui->treeWidget->sortByColumn(0,Qt::AscendingOrder);
    ui->treeWidget->setSortingEnabled(true);

    createHelpMenu();
    createActions();

    on_btnDates_clicked();

}
//Deletes UI after program stops
MainWindow::~MainWindow()
{
    delete ui;
}

//Add root to the tree
void MainWindow::addTreeRoot(QTreeWidgetItem *treeBranch, QString name, QString description){

    treeBranch ->setText(0, name);
    treeBranch ->setText(1, description);
}

void MainWindow::addTreeRoot(QTreeWidgetItem *treeBranch, QString name, QString description, QString count){
treeBranch ->setText(0, name);
treeBranch ->setText(1, description);
treeBranch ->setText(2,count);
}


//Add leaf to tree
void MainWindow::addTreeChild(QTreeWidgetItem *parent,QString name,QString description){
    QTreeWidgetItem *treeItem = new QTreeWidgetItem();
    treeItem->setText(0,name);
    treeItem -> setText(1,description);

    parent ->addChild(treeItem);
}

void MainWindow::createActions()
{

    ui->bntDisplayBar->setStatusTip(tr("Bar Graph"));
    ui->bntDisplayScatter->setStatusTip(tr("Scatter Plot"));
    ui->bntDisplayPie->setStatusTip(tr("Pie Chart"));
    ui->bntDisplayLine->setStatusTip(tr("Line Graph"));

    ui->actionContents->setStatusTip(tr("Display help menu contents"));
    connect(ui->actionContents, SIGNAL(triggered()), this, SLOT(helpContents()));
    ui->menuHelp->addAction(ui->actionContents);
}
void MainWindow::createHelpMenu()
{
    tree = new QTreeWidget();
    tree->setWindowTitle("Help Menu");
    tree->setColumnCount(1);

    QStringList headers;
    headers << " ";
    tree->setHeaderLabels(headers);
    tree->clear();

    QTreeWidgetItem* item = new QTreeWidgetItem(tree);
    QTreeWidgetItem* item2 = new QTreeWidgetItem(tree);
    QTreeWidgetItem* item3 = new QTreeWidgetItem(tree);
    QTreeWidgetItem* item4 = new QTreeWidgetItem(tree);

    item->setText(0, (QString)"Opening a CSV file");
    item2->setText(0, (QString)"Navigating the Dashboard");
    item3->setText(0, (QString)"Choosing a Graph");
    item4->setText(0, (QString)"Printing");

    QTreeWidgetItem* item5 = new QTreeWidgetItem(item);
    item5->setText(0, (QString)"Choosing a File");
    QTreeWidgetItem* item6 = new QTreeWidgetItem(item);
    item6->setText(0, (QString)"Fixing Errors");

    QTreeWidgetItem* item7 = new QTreeWidgetItem(item5);
    item7->setText(0, (QString)"First choose the type of CSV file you would like to\n"
                               "open (Teachings, Publications, Grants, or Presentations).\n"
                               "To open a CSV file, click on file->open\n"
                               "from the menubar at the top of the window.");

    QTreeWidgetItem* item8 = new QTreeWidgetItem(item6);
    item8->setText(0, (QString)"If there are more than 10 errors in the CSV file, a separate\n"
                               "window will pop up prompting you to fix those errors. After Fixing\n"
                               "the appropriate errors, choose the display options and then you may\n"
                               "save the changes and/or open it up in the dashboard.");

    item5 = new QTreeWidgetItem(item2);
    item5->setText(0, (QString)"To navigate through the dashboard, first "
                               "select the date range for the records you\n"
                               "would like to view and then click 'Enter Dates'.\n"
                               "Click on the +/- buttons to expand and collapse categories.\n"
                               "Click on a column to order the data according to that column.");

    item6 = new QTreeWidgetItem(item3);
    item6->setText(0, (QString)"To choose a graph, first click on the 'graph configuration'\n"
                               "button to choose your graph settings. Then click on the icon\n"
                               "for the graph you would like to view.");

    item7 = new QTreeWidgetItem(item4);
    item7->setText(0, (QString)"To print a graph simply click on the 'print graph' button \n"
                               "in the bottom right corner of the graph window.");


    tree->resize(600, 300);
}
void MainWindow::helpContents()
{
    tree->show();
}
QString MainWindow::on_actionOpen_triggered()
{
    //Returns file name of selected file in QFileDialog
    QString filename= QFileDialog::getOpenFileName(this, tr("Open File"),"C://","CSV File (*.csv);;All files (*.*)");
    ui->lblDateRange->setText(filename);
    return filename;

    //Pass filename to open file function
}

void MainWindow::on_bntDisplayBar_clicked()
{
    //update dates
    //on_btnDates_clicked();

    // Make the graph
    int dayStart, monthStart, yearStart, dayEnd, monthEnd, yearEnd;
    dayStart = Startdate.day();
    monthStart = Startdate.month();
    yearStart = Startdate.year();
    dayEnd = Enddate.day();
    monthEnd = Enddate.month();
    yearEnd = Enddate.year();

    QVector<double> numItems;
    QString title = QString("%1-%2-%3 to %4-%5-%6").arg(dayStart).arg(monthStart).arg(yearStart).arg(dayEnd).arg(monthEnd).arg(yearEnd);

    //return as vector all of the possible types.
    vector<string> types = ((PublicationProcessing *)p)->getListOfTypes();
//    vector<int> indDate = p->getIndicesDate(dayStart,monthStart,yearStart,dayEnd,monthEnd,yearEnd);
    for (int i=0; i<types.size(); i++) {
        numItems << ((PublicationProcessing *)p)->getIndicesType(types.at(i),indDate).size();
    }

    makeBarGraph(numItems, title, types);
    //w.show();

}

void MainWindow::on_bntDisplayPie_clicked()
{

    int dayStart, monthStart, yearStart, dayEnd, monthEnd, yearEnd;
    dayStart = Startdate.day();
    monthStart = Startdate.month();
    yearStart = Startdate.year();
    dayEnd = Enddate.day();
    monthEnd = Enddate.month();
    yearEnd = Enddate.year();

    QVector<double> numItems;
    QString title = QString("%1-%2-%3 to %4-%5-%6").arg(dayStart).arg(monthStart).arg(yearStart).arg(dayEnd).arg(monthEnd).arg(yearEnd);

    //return as vector all of the possible types.
    vector<string> types = ((PublicationProcessing *)p)->getListOfTypes();
    //    vector<int> indDate = p->getIndicesDate(dayStart,monthStart,yearStart,dayEnd,monthEnd,yearEnd);
    for (int i=0; i<types.size(); i++) {
        numItems << ((PublicationProcessing *)p)->getIndicesType(types.at(i),indDate).size();
    }

    makePie(numItems, title, types);
}


void MainWindow::on_bntDisplayScatter_clicked()
{

    // Make the graph
    int dayStart, monthStart, yearStart, dayEnd, monthEnd, yearEnd;
    dayStart = Startdate.day();
    monthStart = Startdate.month();
    yearStart = Startdate.year();
    dayEnd = Enddate.day();
    monthEnd = Enddate.month();
    yearEnd = Enddate.year();

    QVector<double> xData;
    QVector<double> yData;
    QString title = QString("%1-%2-%3 to %4-%5-%6").arg(dayStart).arg(monthStart).arg(yearStart).arg(dayEnd).arg(monthEnd).arg(yearEnd);

    //return as vector all of the possible types.
    vector<string> types = ((PublicationProcessing *)p)->getListOfTypes();
     vector<int> indDate2;

    double yearTotal = 0;
    for (int i = yearStart; i < yearEnd; i++)
    {
        // Get all Indeces for the current year
        indDate2 = p->getIndicesDate(1,1,i,31,12,i);
        xData.push_back(i);
        yearTotal = 0;
        for (int j = 0; j < types.size(); j++) {
            yearTotal += ((PublicationProcessing *)p)->getIndicesType(types.at(j),indDate2).size();
        }
        yData.push_back(yearTotal);

    }
    makeScatter(xData, yData, title);
}

void MainWindow::on_bntDisplayLine_clicked()
{

    // Make the graph
    int dayStart, monthStart, yearStart, dayEnd, monthEnd, yearEnd;
    dayStart = Startdate.day();
    monthStart = Startdate.month();
    yearStart = Startdate.year();
    dayEnd = Enddate.day();
    monthEnd = Enddate.month();
    yearEnd = Enddate.year();

    QVector<double> xData;
    QVector<double> yData;
    QVector<double> yDataA;
    QVector<double> yDataO;
    QVector<double> yDataP;
    QVector<double> yDataS;
    QString title = QString("%1-%2-%3 to %4-%5-%6").arg(dayStart).arg(monthStart).arg(yearStart).arg(dayEnd).arg(monthEnd).arg(yearEnd);


    string statuses[] = {"Published","Accepted / In Press","Submitted","Other"};
    vector<string> types = ((PublicationProcessing *)p)->getListOfTypes();
    vector<int> indDate2, indStatus, indStatusType;
    vector<int> indOther;



    double yearTotal = 0;
    double yearTotalA = 0;
    double yearTotalO = 0;
    double yearTotalP = 0;
    double yearTotalS = 0;

    for (int i = yearStart; i <= yearEnd; i++)
    {

        xData.push_back(i);
        // Get all Indeces for the current year

        indDate2 = ((PublicationProcessing *)p)->getIndicesDate(1,1,i,31,12,i);
        indOther = indDate2;

        /*
        // Get all the indices for "Published" status
        indStatus = ((PublicationProcessing *)p)->getIndicesStatus("Published",indDate2);
        for(string type: types)
        {
            // Sum the total number of articles for each type
            yearTotalP += ((PublicationProcessing *)p)->getIndicesType(type, indStatus).size();
        }
        yDataP.push_back(yearTotalP);*/




        // For each year, Get the total number of articles
        // for each year Status and calculate the max

        indStatus = ((PublicationProcessing *)p)->getIndicesStatus("Accepted / In Press",indDate2);
        yearTotalA = indStatus.size();
        indOther = remove_from_other(indOther, indStatus);
        double maxY = yearTotalA;

        indStatus = ((PublicationProcessing *)p)->getIndicesStatus("Submitted",indDate2);
        yearTotalS = indStatus.size();
        indOther = remove_from_other(indOther, indStatus);
        if(yearTotalS > maxY) maxY = yearTotalS;

        indStatus = ((PublicationProcessing *)p)->getIndicesStatus("Published",indDate2);
        yearTotalP = indStatus.size();
        indOther = remove_from_other(indOther, indStatus);
        if(yearTotalP > maxY) maxY = yearTotalP;

        yearTotalO = indOther.size();
        if(yearTotalO > maxY) maxY = yearTotalO;

        yData.push_back(maxY);
        yDataA.push_back(yearTotalA);
        yDataO.push_back(yearTotalO);
        yDataP.push_back(yearTotalP);
        yDataS.push_back(yearTotalS);

    }

    makeLine(xData, yData, yDataA, yDataO, yDataP, yDataS, title);
}
vector<int> MainWindow::remove_from_other(vector<int> indOther, vector<int> indStatus)
{
    //remove from other
    //remove things from indOther so that indOther is the set of papers that are within the date range, but
    //do NOT have the correct status.
    for (int iStat : indStatus) {
        for (int i=indOther.size()-1; i>=0; i--) {
            if (iStat==indOther.at(i)) {
                indOther.erase(indOther.begin()+i);
            }
        }
    }
    return indOther;
}

void MainWindow::on_btnDates_clicked()
{
    QDate date1 = (ui->dateEdit->date());
    QDate date2 = (ui->dateEdit_2->date());
    QString dateString1 = date1.toString("yyyy/MM/dd");
    QString dateString2 = date2.toString("yyyy/MM/dd");
    QString dateString3 = date1.toString("MMM/yyyy");
    QString dateString4 = date2.toString("MMM/yyyy");
    ui->lblDateRange->setText(dateString1 + " - " + dateString2);
    QStringList ColumnNames;
    ColumnNames << dateString3 + " " + dateString4;
    ui->treeWidget->setHeaderLabels(ColumnNames);
    Startdate = date1;
    Enddate = date2;
    indDate = p->getIndicesDate(Startdate.day(),Startdate.month(),Startdate.year(),Enddate.day(),Enddate.month(),Enddate.year());

    ui->treeWidget->clear();
    drawDashboard();

    //return ColumnNames;

}


void MainWindow::makePie(QVector<double> pieData, QString title, vector<string> Labels ) {


    QVector<QString> pieLabels;

    for (int i = 0; i < Labels.size(); i++) {
        pieLabels << Labels.at(i).c_str();
    }

    QVBoxLayout* layout = new QVBoxLayout;



    // Compute minimum & maximum height to show all labels
    int height=30*pieLabels.size();
    if (height < 320) height = 320;
    else if (height > 800) height = 800;

    // Create window
    QWidget * window = new QWidget();
    window->resize(520, height);
    window->show();
    window->setWindowTitle(title);  // Set the title of the window
    window->setAttribute( Qt::WA_DeleteOnClose );  // Delete the window when closed
    window->setLayout(layout);


    NightchartsWidget * PieChart = new NightchartsWidget(window);
    PieChart->clear();
    PieChart->setType(Nightcharts::Pie);//{Histogramm,Pie,DPie};
    PieChart->resize(520, height);

    // Compute sum of data - to convert values to %
    double sum=0;
    for (int i=0; i<pieData.size(); i++) sum += pieData.at(i);
    if (sum == 0) sum=1;  // Prevent divide by 0 if pie slice data adds to 0

    // Reset RGB values so cycle through the colors
    int red = 0;
    int green = 0;
    int blue = 0;

    // Add data to pie (as %), and add label to pie, and compute unique color
    for (int i=0; i<pieData.size(); i++) {
        red = (red + 57) % 255;
        green = (green + 97) % 255;
        blue = (blue + 137) % 255;
        PieChart->addItem(QString(pieLabels.at(i)),QColor(red,green,blue),static_cast<float>(pieData.at(i)*100/sum));
    }

    // Show the pie
    PieChart->show();

}


void MainWindow::makeBarGraph(QVector<double> yAxisData, QString title, vector<string> barLabels ) {
    QRect rec = QApplication::desktop()->screenGeometry();
     int height = rec.height();
     int width = rec.width();

    QCustomPlot *customPlot = new QCustomPlot();
    customPlot->show();
    customPlot->setGeometry(100, 100, width-200, height-200);

    QCPBars *myBars = new QCPBars(customPlot->xAxis, customPlot->yAxis);
    customPlot->addPlottable(myBars);
        myBars->setName("this is the name");


    QVector<double> xAxisPositions;
    QVector<QString> xAxisLabels;

    for (int i = 0; i < barLabels.size(); i++) {
        xAxisPositions << i;
        xAxisLabels << barLabels.at(i).c_str();
    }

    customPlot->xAxis->setAutoTicks(false);
    customPlot->xAxis->setAutoTickLabels(false);
    customPlot->xAxis->setTickVector(xAxisPositions);
    customPlot->xAxis->setTickVectorLabels(xAxisLabels);
    customPlot->xAxis->setTickLabelRotation(60);
    customPlot->xAxis->setSubTickCount(0);
    customPlot->xAxis->setTickLength(0, 4);
    customPlot->xAxis->grid()->setVisible(true);
    customPlot->xAxis->setRange(-1, barLabels.size()+1);  // Set min and max tick value (one beyond either end)

    customPlot->yAxis->setRange(0, 12.1);
    customPlot->yAxis->setPadding(5);
    customPlot->yAxis->setLabel("number of articles");
    customPlot->yAxis->grid()->setSubGridVisible(true);

    QPen gridPen;
    gridPen.setStyle(Qt::SolidLine);
    gridPen.setColor(QColor(0, 0, 0, 25));
    customPlot->yAxis->grid()->setPen(gridPen);
    gridPen.setStyle(Qt::DotLine);
    customPlot->yAxis->grid()->setSubGridPen(gridPen);


    customPlot->legend->setVisible(false);

    customPlot->yAxis->setPadding(25); // Add space to the left of the Y axis title
    customPlot->yAxis2->setPadding(25); // Add space to the left of the Y axis title

    // Set the title
    customPlot->plotLayout()->insertRow(0); // inserts an empty row above the default axis rect
    customPlot->plotLayout()->addElement(0, 0, new QCPPlotTitle(customPlot, title));

    myBars->setData(xAxisPositions, yAxisData);

    customPlot->yAxis->rescale();
    customPlot->replot();

}


// Create the scatter plot
void MainWindow::makeScatter(QVector<double> xData, QVector<double> yData, QString title ) {

    QRect rec = QApplication::desktop()->screenGeometry();
     int height = rec.height();
     int width = rec.width();
     double xRangeMinimum, yRangeMinimum, xRangeMaximum, yRangeMaximum;

    QCustomPlot *customPlot = new QCustomPlot();
    customPlot->show();
    //set window size based on screen size
    customPlot->setGeometry(100, 100, width-200, height-200);
    // Tell QCustomPlot to show dots, but not lines
    customPlot->addGraph();
    customPlot->graph(0)->setLineStyle(QCPGraph::lsNone);
    customPlot->graph(0)->setPen(QPen(Qt::blue)); // line color blue for first graph

    // add title
    customPlot->plotLayout()->insertRow(0);
    customPlot->plotLayout()->addElement(0, 0, new QCPPlotTitle(customPlot, title));

    //set the graph to a scatter plot
    customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4));
    customPlot->graph(0)->setName(title);

    //find minimum and maximum x values.
    int xMax = xData.at(0);
    int xMin = xData.at(0);
    for(int xDataIndex=0; xDataIndex < xData.size(); xDataIndex++) {
        if (xData.at(xDataIndex) < xMin) xMin = xData.at(xDataIndex);
        if(xData.at(xDataIndex) > xMax)  xMax = xData.at(xDataIndex);
    }

    //find minimum and maximum y values.
    int yMax = yData.at(0);
    int yMin = yData.at(0);
    for(int yDataIndex=0; yDataIndex < yData.size(); yDataIndex++) {
        if (yData.at(yDataIndex) < yMin) yMin = yData.at(yDataIndex);
        if (yData.at(yDataIndex) > yMax) yMax = yData.at(yDataIndex);
    }

    // pass the data points to the scatter plot
    customPlot->graph()->setData(xData, yData);

    // Add up to 2 years gap to min of X range
    if(xMin < 2) xRangeMinimum = 0;
    else xRangeMinimum = xMin - 2;

    // Add up to 2 years gap to max of X range (up to current year)
    int currentYear = QDate::currentDate().year();
    if(currentYear - xMax < 2)
    {
        if(currentYear - xMax == 1)
            xRangeMaximum = currentYear;
        else if(currentYear - xMax == 0)
            xRangeMaximum = currentYear + 0.5;
    }
    else
        xRangeMaximum = xMax + 2;

    //set the x axis tick labels
    customPlot->xAxis->setAutoTickStep(false);
    customPlot->xAxis->setTickStep(2);
    customPlot->xAxis->setTickLengthIn(5);
    customPlot->xAxis->setAutoSubTicks(false);
    customPlot->xAxis->setSubTickCount(1);
    customPlot->xAxis->setSubTickLengthIn(5);


    //set the x axis label
    customPlot->xAxis->setLabel("Years");

    //set the x axis range
    customPlot->xAxis->setRange(xRangeMinimum, xRangeMaximum);

    //set the y axis tick labels
    customPlot->yAxis->setAutoTickStep(false);
    customPlot->yAxis->setTickStep(5);
    customPlot->yAxis->setTickLengthIn(5);
    customPlot->yAxis->setAutoSubTicks(false);
    customPlot->yAxis->setSubTickCount(4);
    customPlot->yAxis->setSubTickLengthIn(5);

    //set the y axis to be larger than the maximum y value
    if(yMin < 2)
    {
        if(yMin == 1)
            yRangeMinimum = 0;
        else if (yMin == 0)
            yRangeMinimum = -1;
    }
    else
        yRangeMinimum = yMin - 2;

    yRangeMaximum = yMax + 2;

    //set the y axis label
    customPlot->yAxis->setLabel("number of papers");

    //set the y axis range
    customPlot->yAxis->setRange(yRangeMinimum, yRangeMaximum);

    //draw scatter plot
    customPlot->replot();
}

// Create the line graph
void MainWindow::makeLine(QVector<double> xData, QVector<double> yData,
                          QVector<double> yDataA, QVector<double> yDataO,
                          QVector<double> yDataP, QVector<double> yDataS,
                          QString title ) {

    QRect rec = QApplication::desktop()->screenGeometry();
    int height = rec.height();
    int width = rec.width();
    double xRangeMinimum, yRangeMinimum, xRangeMaximum, yRangeMaximum;
    QPen pen;

    QCustomPlot *customPlot = new QCustomPlot();

    customPlot->show();
    //set window size based on screen size
    customPlot->setGeometry(100, 100, width-200, height-200);
    // Tell QCustomPlot to show dots, but not lines




    // pass the data points to the scatter plot
    customPlot->addGraph();
    customPlot->graph()->setName("Accepted / In Press");
    pen.setColor(QColor(Qt::darkYellow));
    customPlot->graph()->setPen(pen);
    customPlot->graph()->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4));
    customPlot->graph()->setData(xData, yDataA);

    customPlot->addGraph();
    customPlot->graph()->setName("Other");
    pen.setColor(QColor(Qt::magenta));
    customPlot->graph()->setPen(pen);
    customPlot->graph()->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4));
    customPlot->graph()->setData(xData, yDataO);

    customPlot->addGraph();
    customPlot->graph()->setName("Published");
    pen.setColor(QColor(Qt::green));
    customPlot->graph()->setPen(pen);
    customPlot->graph()->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4));
    customPlot->graph()->setData(xData, yDataP);

    customPlot->addGraph();
    customPlot->graph()->setName("Submitted");
    pen.setColor(QColor(Qt::red));
    customPlot->graph()->setPen(pen);
    customPlot->graph()->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4));
    customPlot->graph()->setData(xData, yDataS);

    customPlot->legend->setVisible(true);

    // add title
    customPlot->plotLayout()->insertRow(0);
    customPlot->plotLayout()->addElement(0, 0, new QCPPlotTitle(customPlot, title));

    //find minimum and maximum x values.
    int xMax = xData.at(0);
    int xMin = xData.at(0);
    for(int xDataIndex=0; xDataIndex < xData.size(); xDataIndex++) {
        if (xData.at(xDataIndex) < xMin) xMin = xData.at(xDataIndex);
        if (xData.at(xDataIndex) > xMax)  xMax = xData.at(xDataIndex);
    }

    //find minimum and maximum y values.
    int yMax = yData.at(0);
    int yMin = yData.at(0);
    for(int yDataIndex=0; yDataIndex < yData.size(); yDataIndex++) {
        if (yData.at(yDataIndex) < yMin) yMin = yData.at(yDataIndex);
        if (yData.at(yDataIndex) > yMax) yMax = yData.at(yDataIndex);
    }




    // Add up to 2 years gap to min of X range
    if(xMin < 2) xRangeMinimum = 0;
    else xRangeMinimum = xMin - 2;

    // Add up to 2 years gap to max of X range (up to current year)
    int currentYear = QDate::currentDate().year();
    if(currentYear - xMax < 2)
    {
        if(currentYear - xMax == 1)
            xRangeMaximum = currentYear;
        else if(currentYear - xMax == 0)
            xRangeMaximum = currentYear + 0.5;
    }
    else
        xRangeMaximum = xMax + 2;

    //set the x axis tick labels
    customPlot->xAxis->setAutoTickStep(false);
    customPlot->xAxis->setTickStep(2);
    customPlot->xAxis->setTickLengthIn(5);
    customPlot->xAxis->setAutoSubTicks(false);
    customPlot->xAxis->setSubTickCount(1);
    customPlot->xAxis->setSubTickLengthIn(5);


    //set the x axis label
    customPlot->xAxis->setLabel("Years");

    //set the x axis range
    customPlot->xAxis->setRange(xRangeMinimum, xRangeMaximum);

    //set the y axis tick labels

    customPlot->yAxis->setAutoTickStep(false);
    customPlot->yAxis->setTickStep(5);
    customPlot->yAxis->setTickLengthIn(5);
    customPlot->yAxis->setAutoSubTicks(false);
    customPlot->yAxis->setSubTickCount(4);
    customPlot->yAxis->setSubTickLengthIn(5);

    //set the y axis to be larger than the maximum y value
    if(yMin < 2)
    {
        if(yMin == 1)
            yRangeMinimum = 0;
        else if (yMin == 0)
            yRangeMinimum = -1;
    }
    else
        yRangeMinimum = yMin - 2;

    yRangeMaximum = yMax + 2;

    //set the y axis label
    customPlot->yAxis->setLabel("number of papers");

    //set the y axis range
    customPlot->yAxis->setRange(yRangeMinimum, yRangeMaximum);

    //draw scatter plot
    customPlot->replot();

}

void MainWindow::initialize(){
    s = new StartUp(this);
//    s->setStyleSheet("background-color:rgb(68,50,102);");
    QPalette Pal(palette());
    QColor color(195,195,229,255);
    Pal.setColor(QPalette::Background, color);
    s->setAutoFillBackground(true);
    s->setPalette(Pal);
    s->show();
    if(s->exec() == QDialog::Accepted){
        csvtype = s->getCsvType();
    }
    //These will only be for CSV's that reuire additional input for indicie queries

    //Min text box
    ui->minText_1->setVisible(false);
    ui->minText_2->setVisible(false);

    //Hypens
    ui->labelHyp_1->setVisible(false);
    ui->labelHyp_2->setVisible(false);

    //Max text box
    ui->maxText_1->setVisible(false);
    ui->maxText_2->setVisible(false);

    //Min label
    ui->lblMin_1->setVisible(false);
    ui->lblMin_2->setVisible(false);

    //Max label
    ui->lblMax_1->setVisible(false);
    ui->lblMax_2->setVisible(false);

}


void MainWindow::drawDashboard(){



    switch(csvtype){
        case(1):{
        vector<string> types = ((PublicationProcessing *)p)->getListOfTypes();
        string statuses[] = {"Published","Accepted / In Press","Submitted","Other"};
        vector<int> indStatus, indStatusType, indStatusTypeMember;
        vector<int> indOther = indDate;
        cout << "Date: " << indOther.size() << endl;
        vector<string> members = p->getListOfMemberNames();

        int count;
        QTreeWidgetItem *treeRoot = new QTreeWidgetItem(ui->treeWidget);
        addTreeRoot(treeRoot,"Publications", QString::number(indDate.size()));

        for (string status : statuses) {

            if (status == "Other") indStatus = indOther;
            //get the subset of indices where the paper is of the status specified and is in the date range specified.
            else indStatus = ((PublicationProcessing *)p)->getIndicesStatus(status,indDate);
            count = indStatus.size();
            //cout << status << "(" << count << ")" << endl;
            QTreeWidgetItem *treeBranch = new QTreeWidgetItem();
            treeRoot->addChild(treeBranch);
              addTreeRoot(treeBranch,QString::fromStdString(status),QString::number(count));

              //remove from other
              //remove things from indOther so that indOther is the set of papers that are within the date range, but
              //do NOT have the correct status.
              for (int iStat : indStatus) {
                  for (int i=indOther.size()-1; i>=0; i--) {
                      if (iStat==indOther.at(i)) {
                          indOther.erase(indOther.begin()+i);
                      }
                  }
              }

              if (count) {
                for (string type : types) {
                    indStatusType = ((PublicationProcessing *)p)->getIndicesType(type,indStatus);
                    if (type.length()<1) type = "Unspecified"; // rename the blank type
                    count = indStatusType.size();
                    if (count) {
                        //cout << "\t" << type << "(" << count << ")" << endl;
                        QTreeWidgetItem *treeItem = new QTreeWidgetItem();
                        treeBranch->addChild(treeItem);
                        addTreeRoot(treeItem,QString::fromStdString(type),QString::number(count));

                        for (string member : members) {

                            indStatusTypeMember = p->getIndicesMemberName(member,indStatusType);
                            count = indStatusTypeMember.size();
                            if (count) {
                                if (member.length()<1) member = "Unspecified"; //rename blank member
                               QTreeWidgetItem *treeChild = new QTreeWidgetItem();
                               treeItem->addChild(treeChild);
                               treeChild->setText(0,QString::fromStdString(member));
                               treeChild -> setText(1,QString::number(count));

                                //cout << "\t\t" << member << "(" << count << ")" << endl;
                            }
                        }
                    }
                }
            }

        }

    }break;
    case(2):{
        vector<string> members = p->getListOfMemberNames();
        vector<int> indProgram,indHours, indStudents, indProgramMember;
        vector<int> indOther = indDate;
        int hoursTotal,hoursProg,hoursMember;
        int students;
        string programs[] = {"Postgraduate Medical Education","Continuing Medical Education", "Undergraduate Medical Education", "Other" };



        indHours = ((TeachingProcessing *)p)->getIndicesHours(ui->minText_1->text().toInt(),ui->maxText_1->text().toInt(),indDate);
        for(int i =0;i < indHours.size(); i++){
            hoursTotal += ((TeachingProcessing *)p)->getHours(indHours.at(i));
        } // Testing to see if populates
        indStudents = ((TeachingProcessing *)p)->getIndicesStudents(ui->minText_2->text().toInt(),ui->maxText_2->text().toInt(),indDate);
        students = indStudents.size();

        QTreeWidgetItem *treeRoot = new QTreeWidgetItem(ui->treeWidget);
        addTreeRoot(treeRoot,"Teaching",QString::number(hoursTotal), QString::number(students));

        for(string program : programs){
            hoursProg = 0;
            if (program == "Other") indProgram = indOther;
            //get the subset of indices where the paper is of the status specified and is in the date range specified.
            else indProgram = ((TeachingProcessing *)p)->getIndicesProgram(program,indDate);

            indHours = ((TeachingProcessing *)p)->getIndicesHours(ui->minText_1->text().toInt(),ui->maxText_1->text().toInt(),indProgram);
            for(int i =0;i < indHours.size(); i++){
                hoursProg += ((TeachingProcessing *)p)->getHours(indHours.at(i));
            } // Testing to see if populates
            indStudents = ((TeachingProcessing *)p)->getIndicesStudents(ui->minText_2->text().toInt(),ui->maxText_2->text().toInt(),indProgram);
            students = indStudents.size();

            //remove from other
            //remove things from indOther so that indOther is the set of papers that are within the date range, but
            //do NOT have the correct status.
            for (int iProg : indProgram) {
                for (int i=indOther.size()-1; i>=0; i--) {
                    if (iProg==indOther.at(i)) {
                        indOther.erase(indOther.begin()+i);
                    }
                }
            }

            QTreeWidgetItem *treeProgram = new QTreeWidgetItem();
            addTreeRoot(treeProgram, QString::fromStdString(program), QString::number(hoursProg), QString::number(students));
            treeRoot->addChild(treeProgram);

            for(string member: members){
                hoursMember = 0;
                indProgramMember = p->getIndicesMemberName(member,indProgram);

                indHours = ((TeachingProcessing *)p)->getIndicesHours(ui->minText_1->text().toInt(),ui->maxText_1->text().toInt(),indProgramMember);
                for(int i =0;i < indHours.size(); i++){
                    hoursMember += ((TeachingProcessing *)p)->getHours(indHours.at(i));
                } // Testing to see if populates
                indStudents = ((TeachingProcessing *)p)->getIndicesStudents(ui->minText_2->text().toInt(),ui->maxText_2->text().toInt(),indProgramMember);
                students = indStudents.size();
                if(hoursMember){
                     if (member.length()<1) member = "Unspecified"; //rename blank member
                     QTreeWidgetItem *treeProgramMember = new QTreeWidgetItem();
                     treeProgramMember->setText(0,QString::fromStdString(member));
                     treeProgramMember->setText(1,QString::number(hoursMember));
                     treeProgramMember->setText(2,QString::number(students));
                     treeProgram->addChild(treeProgramMember);

                }

            }



       }
    }

            break;
    case(3):{
        vector<string> types = ((PresentationProcessing *)p)->getListOfTypes();
        vector<int> indType, indTypeMember;
        vector<string> members = p->getListOfMemberNames();
        vector<int> indOther = indDate;
        int count;

        QTreeWidgetItem *treeRoot = new QTreeWidgetItem(ui->treeWidget);
        addTreeRoot(treeRoot,"Presentations", QString::number(indDate.size()));

        for(string type: types ){
            if (type == "Other"){indType = indOther;}
            else{ indType = ((PresentationProcessing *)p)->getIndicesType(type,indDate);}
            count = indType.size();
            cout << "Count: " << count <<endl;

            QTreeWidgetItem *treeBranch = new QTreeWidgetItem();
            addTreeRoot(treeBranch,QString::fromStdString(type),QString::number(count));
            treeRoot->addChild(treeBranch);

//            for(int i: indRole){
//                for(int i =indOther.size()-1; i>=0;i--){
//                    if(iRole==indOther.at(i)){
//                        indOther.erase(indOther.begin()+i);
//                    }
//                }
//            }

            if(count){
                for(string member : members){
                    indTypeMember = p->getIndicesMemberName(member,indType);
                    if(member.length()<1) type = "Unspecified";
                    count = indTypeMember.size();

                    if(count){
                        QTreeWidgetItem *treeItem = new QTreeWidgetItem();
                        treeItem->setText(0,QString::fromStdString(member));
                        treeItem->setText(1,QString::number(count));
                        treeBranch->addChild(treeItem);
                    }
                }
            }

        }}
            break;
    case(4):{
        vector<string> types = ((GrantProcessing *)p)->getListOfTypes();
        vector<int> indType, indAmount, indPeer, indInd, indPMember, indIMember;
        vector<string> members = p->getListOfMemberNames();
        vector<int> indOther = indDate;
        int count;
        double amountType,amountTypePeer,amountTypeInd,amountPeerMember,amountIndMember;

        //Gets the indices of that type and date
        for(string type : types){
            amountType = 0;
            amountTypePeer = 0;
            amountTypeInd = 0;
            amountPeerMember = 0;
            amountIndMember = 0;

            if(type == "Other") indType = indOther;
            else indType = ((GrantProcessing *)p)->getIndicesType(type,indDate);
            count = indType.size();

            //Calculate amount
            indAmount = ((GrantProcessing*) p)->getIndicesAmount(ui->minText_1->text().toInt(),ui->maxText_1->text().toInt(),indType);
            for(int i = 0; i <  indAmount.size(); i++){
                amountType += ((GrantProcessing*)p)->getAmount((indAmount.at(i)));
            }

            QTreeWidgetItem *treeRoot = new QTreeWidgetItem(ui->treeWidget);
            addTreeRoot(treeRoot,QString::fromStdString(type),QString::number(count),"$" + QString::number(amountType));

            //Gets the indicies for all peer review
            indPeer = ((GrantProcessing *)p)->getIndicesPeerReviewed(indType);
            count = indPeer.size();
            //cout << "Peer Review Count: " << count <<endl;
            indAmount = ((GrantProcessing*) p)->getIndicesAmount(ui->minText_1->text().toInt(),ui->maxText_1->text().toInt(),indPeer);
            for(int i = 0; i <  indAmount.size(); i++){
                amountTypePeer += ((GrantProcessing*)p)->getAmount(indAmount.at(i));
            }
            QTreeWidgetItem *treePeer =new QTreeWidgetItem();
            addTreeRoot(treePeer,"Peer Reviewed",QString::number(count),"$" + QString::number(amountTypePeer));

            treeRoot->addChild(treePeer);

            //Getthe indicies for all Industry
            indInd = ((GrantProcessing *)p)->getIndicesIndustry(indType);
            count = indInd.size();
            //cout << "Industry Sponsor Count: " << count <<endl;
            indAmount = ((GrantProcessing*) p)->getIndicesAmount(ui->minText_1->text().toInt(),ui->maxText_1->text().toInt(),indInd);
            for(int i = 0; i <  indAmount.size(); i++){
                amountTypeInd += ((GrantProcessing*)p)->getAmount(indAmount.at(i));
            }
            QTreeWidgetItem *treeInd =new QTreeWidgetItem();
            addTreeRoot(treeInd,"Industry Sponsored",QString::number(count),("$" + QString::number(amountTypeInd)));

            treeRoot->addChild(treeInd);

            for(string member: members){
                amountPeerMember = 0;
                amountIndMember = 0;

               indPMember = p->getIndicesMemberName(member,indPeer);
               count = indPMember.size();
               //amount claculation
               indAmount = ((GrantProcessing*) p)->getIndicesAmount(ui->minText_1->text().toInt(),ui->maxText_1->text().toInt(),indPMember);
               for(int i = 0; i <  indAmount.size(); i++){
                   amountPeerMember += ((GrantProcessing*)p)->getAmount(indAmount.at(i));
               }
             if(count){
                   QTreeWidgetItem *treePeerMember =new QTreeWidgetItem();
                   treePeerMember->setText(0,QString::fromStdString(member));
                   treePeerMember->setText(1,QString::number(count));
                   treePeerMember->setText(2,"$" + QString::number(amountPeerMember));
                   treePeer->addChild(treePeerMember);
            }

                   indIMember = p->getIndicesMemberName(member,indInd);
                   count = indIMember.size();
                   //amount calculation
                   indAmount = ((GrantProcessing*) p)->getIndicesAmount(ui->minText_1->text().toInt(),ui->maxText_1->text().toInt(),indIMember);
                   for(int i = 0; i <  indAmount.size(); i++){
                       amountIndMember += ((GrantProcessing*)p)->getAmount(indAmount.at(i));
                   }
               if(count){
                   QTreeWidgetItem *treeIndMember =new QTreeWidgetItem();
                   treeIndMember->setText(0,QString::fromStdString(member));
                   treeIndMember->setText(1,QString::number(count));
                   treeIndMember->setText(2,"$" + QString::number(amountIndMember));
                   treeInd->addChild(treeIndMember);
                }
            }



        }



    }
            break;
    default:{}

    }//End Switch



}
