//Necessary Includes
#include <QDate>
#include "mainwindow.h"
#include "../lib/nightcharts/nightcharts.h"
#include "../lib/nightcharts/nightchartswidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    string filename = on_actionOpen_triggered().toStdString();

    this->setWindowTitle("Dashboard");

    //process data by constructing PublicationProcessing

    p = new PublicationProcessing(filename);

    //Setup TreeList, set it to have two columns
    ui->treeWidget->setColumnCount(2);


    //Read in list of Column Names to set the column Names
    QStringList ColumnNames;
    ColumnNames << " " << "Total";
    ui->treeWidget->setHeaderLabels(ColumnNames);
    ui->treeWidget->setColumnWidth(0,170);

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
        
    double yearTotal = 0;
    for (int i = yearStart; i < yearEnd; i++)
    {
        // Get all Indeces for the current year
//        vector<int> indDate = p->getIndicesDate(1,1,yearStart,31,12,yearStart);
        xData.push_back(i);
        yearTotal = 0;
        for (int j = 0; j < types.size(); j++) {
            yearTotal += ((PublicationProcessing *)p)->getIndicesType(types.at(j),indDate).size();
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
    QString title = QString("%1-%2-%3 to %4-%5-%6").arg(dayStart).arg(monthStart).arg(yearStart).arg(dayEnd).arg(monthEnd).arg(yearEnd);

    //return as vector all of the possible types.
    vector<string> types = ((PublicationProcessing *)p)->getListOfTypes();

    double yearTotal = 0;
    for (int i = yearStart; i < yearEnd; i++)
    {
        // Get all Indeces for the current year
//        vector<int> indDate = p->getIndicesDate(1,1,yearStart,31,12,yearStart);
        xData.push_back(i);
        yearTotal = 0;
        for (int j = 0; j < types.size(); j++) {
            yearTotal += ((PublicationProcessing *)p)->getIndicesType(types.at(j),indDate).size();
        }
        yData.push_back(yearTotal);

    }

    makeLine(xData, yData, title);
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
    layout->addWidget(btnPrintPie);

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

    //set the x axis label
    customPlot->xAxis->setLabel("Years");

    //set the x axis range
    customPlot->xAxis->setRange(xRangeMinimum, xRangeMaximum);

    //set the y axis to be larger than the maximum y value
    if(yMin < 2) yRangeMinimum = 0;
    else yRangeMinimum = yMin - 2;

    yRangeMaximum = yMax + 2;

    //set the y axis label
    customPlot->yAxis->setLabel("number of papers");

    //set the y axis range
    customPlot->yAxis->setRange(yRangeMinimum, yRangeMaximum);

    //draw scatter plot
    customPlot->replot();
}

// Create the line graph
void MainWindow::makeLine(QVector<double> xData, QVector<double> yData, QString title ) {

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
    customPlot->graph(0)->setLineStyle(QCPGraph::lsLine);
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

    //set the x axis label
    customPlot->xAxis->setLabel("Years");

    //set the x axis range
    customPlot->xAxis->setRange(xRangeMinimum, xRangeMaximum);

    //set the y axis to be larger than the maximum y value
    if(yMin < 2) yRangeMinimum = 0;
    else yRangeMinimum = yMin - 2;

    yRangeMaximum = yMax + 2;

    //set the y axis label
    customPlot->yAxis->setLabel("number of papers");

    //set the y axis range
    customPlot->yAxis->setRange(yRangeMinimum, yRangeMaximum);

    //draw scatter plot
    customPlot->replot();

}


void MainWindow::drawDashboard(){
        vector<string> types = ((PublicationProcessing *)p)->getListOfTypes();
        string statuses[] = {"Published","Accepted / In Press","Submitted","Other"};
        vector<int> indStatus, indStatusType, indStatusTypeMember;
        vector<string> members = p->getListOfMemberNames();
        //get the subset of indices where the paper was published during the specified date range.
        vector<int> indOther = indDate;
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


}
