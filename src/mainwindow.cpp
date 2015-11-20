//Necessaru Includes
#include "mainwindow.h"
#include "../lib/nightcharts/nightcharts.h"
#include "../lib/nightcharts/nightchartswidget.h"

QDate Startdate;
QDate Enddate;

PublicationProcessing* p;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    ui->

    string filename = on_actionOpen_triggered().toStdString();


    //process data by constructing PublicationProcessing

    p = new PublicationProcessing(filename);


    /*
    //Initialize First set combo boxes
    initDate_Month(ui->comboBox);
    initDate_Years(ui->comboBox_2);

    //Initialize Second set combo boxes
    initDate_Month(ui->comboBox_3);
    initDate_Years(ui->comboBox_4);

    //Resize them to appropriate size

    ui->comboBox->resize(69,22);
    ui->comboBox_2->resize(69,22);
    ui->comboBox_3->resize(69,22);
    ui->comboBox_4->resize(69,22);
    */
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




    //Making abunch of filler items for the tree to test functions




//    //Testing Function
//    QTreeWidgetItem *treeBranch2 = new QTreeWidgetItem(ui->treeWidget);
//    addTreeRoot(treeBranch2,"Yo","Works");
//    QTreeWidgetItem *CurrentParent;
//    CurrentParent = treeBranch2;

//    //WOW SUPER EASY
//    for(int i = 0; i < 10;i++){
//        if(i%2){
//            QTreeWidgetItem *treeTest = new QTreeWidgetItem(CurrentParent);
//            treeTest->setText(0,"Parent");
//            treeTest->setText(1,"Yeah");
//            CurrentParent = treeTest;
//        }
//        else{
//            QTreeWidgetItem *treeTest = new QTreeWidgetItem(CurrentParent);
//            treeTest->setText(0,"Child");
//            treeTest->setText(1,"Nah");
//        }

//    }

    ui->treeWidget->sortByColumn(0,Qt::AscendingOrder);
    ui->treeWidget->setSortingEnabled(true);

    on_btnDates_clicked();



}
//Deletes UI after program stops
MainWindow::~MainWindow()
{
    delete ui;
}

/*
void MainWindow::initDate_Month(QComboBox *months){
    months->addItem("Jan");
    months->addItem("Feb");
    months->addItem("Mar");
    months->addItem("Apr");
    months->addItem("May");
    months->addItem("June");
    months->addItem("July");
    months->addItem("Sept");
    months->addItem("Oct");
    months->addItem("Nov");
    months->addItem("Dec");

}

void MainWindow::initDate_Years(QComboBox *months){

    for(int i = 0; i < 116; i++){
        int year = 2015;
        year -= i;

        months->addItem(QString::number(year));

    }

}
*/


//Add root tot the tree
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

QString MainWindow::on_actionOpen_triggered()
{
    //Returns file name of sleected file in QFileDialog
    QString filename= QFileDialog::getOpenFileName(this, tr("Open File"),"C://","CSV File (*.csv);;All files (*.*)");
    ui->lblDateRange->setText(filename);

    return filename;

    //Pass filename to open file function
}

void MainWindow::on_bntDisplayGraph_clicked()
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
    vector<string> types = p->getListOfTypes();
    vector<int> indDate = p->getIndicesDate(dayStart,monthStart,yearStart,dayEnd,monthEnd,yearEnd);
    for (int i=0; i<types.size(); i++) {
        numItems << p->getIndicesType(types.at(i),indDate).size();
    }

    makeGraph(numItems, title, types);
    //w.show();

}

void MainWindow::on_bntDisplayPie_clicked()
{

    //QString title = "My Sample Pie";

    QVector<QString> labels;
    labels.append("Apple");
    labels.append("Donut");
    labels.append("Cherry");


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
    vector<string> types = p->getListOfTypes();
    vector<int> indDate = p->getIndicesDate(dayStart,monthStart,yearStart,dayEnd,monthEnd,yearEnd);
    for (int i=0; i<types.size(); i++) {
        numItems << p->getIndicesType(types.at(i),indDate).size();
    }
    QVector<double> data;
    data.append(1);
    data.append(2);
    data.append(3);
/*
     data.append(1);
    data.append(2);
    data.append(3);
    data.append(1);
    data.append(2);
    data.append(3);
    data.append(1);
    data.append(2);
    data.append(3);
    data.append(1);
    data.append(2);
    data.append(3);
*/
    makePie(data, title, labels);

}


void MainWindow::on_bntDisplayScatter_clicked()
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

    QVector<double> xData;
    QVector<double> yData;
    QString title = QString("%1-%2-%3 to %4-%5-%6").arg(dayStart).arg(monthStart).arg(yearStart).arg(dayEnd).arg(monthEnd).arg(yearEnd);

    //return as vector all of the possible types.
    vector<string> types = p->getListOfTypes();
    vector<int> indDate = p->getIndicesDate(dayStart,monthStart,yearStart,dayEnd,monthEnd,yearEnd);


    double yearTotal = 0;
    for (int i = yearStart; i < yearEnd; i++)
    {
        // Get all Indeces for the current year
        vector<int> indDate = p->getIndicesDate(1,1,yearStart,31,12,yearStart);
        xData << i;
        for (int j = 0; j < types.size(); j++) {
            yearTotal += p->getIndicesType(types.at(j),indDate).size();
        }
        yData << yearTotal;

    }
    xData.push_back(3.4);
    xData.push_back(15.6);
    xData.push_back(7.5);
    xData.push_back(14);
    xData.push_back(15.8);
    xData.push_back(12);

    yData.push_back(10.7);
    yData.push_back(2.1);
    yData.push_back(6.3);
    yData.push_back(19.2);
    yData.push_back(18.8);
    yData.push_back(14.7);

    makeScatter(xData, yData, title);
}

QStringList MainWindow::on_btnDates_clicked()
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
    ui->treeWidget->clear();
    processDates();
    return ColumnNames;

}


void MainWindow::makePie(QVector<double> pieData, QString title, QVector<QString> pieLabels ) {

    // Compute minimum & maximum height to show all labels
    int height=30*pieLabels.size();
    if (height < 320) height = 320;
    else if (height > 800) height = 800;

    // Create window
    QWidget * window = new QWidget();
    window->resize(520, height);
    window->show();
    window->setWindowTitle("Pie Chart");  // Set the title of the window
    window->setAttribute( Qt::WA_DeleteOnClose );  // Delete the window when closed

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


void MainWindow::makeGraph(QVector<double> yAxisData, QString title, vector<string> barLabels ) {
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
    /*
    customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    customPlot->legend->setBrush(QColor(255, 255, 255, 200));
    QPen legendPen;
    legendPen.setColor(QColor(130, 130, 130, 200));
    customPlot->legend->setBorderPen(legendPen);
    QFont legendFont = QFont("sanserif", 30);
    customPlot->legend->setFont(legendFont);
    customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
*/

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

    //find maximum x and y values.
    int xMax = 0;
    for(int xDataIndex=0; xDataIndex < xData.size(); xDataIndex++)
        if(xData.at(xDataIndex) > xMax)
            xMax = xData.at(xDataIndex);

    int yMax = 0;
    for(int yDataIndex=0; yDataIndex < yData.size(); yDataIndex++)
        if(yData.at(yDataIndex) > yMax)
            yMax = yData.at(yDataIndex);

    // pass the data points to the scatter plot
    customPlot->graph()->setData(xData, yData);

    //set the x axis to be larger than the maximum x value
    customPlot->xAxis->setRange(0, xMax + 2);
    //set the y axis to be larger than the maximum y value
    customPlot->yAxis->setRange(0, yMax + 2);
    //draw scatter plot
    customPlot->replot();

}


void MainWindow::processDates(){


        vector<string> types = p->getListOfTypes();
        string statuses[] = {"Published","Accepted / In Press","Submitted","Other"};
        vector<int> indStatus, indStatusType, indStatusTypeMember;
        vector<string> members = p->getListOfMemberNames();
        //get the subset of indices where the paper was published during the specified date range.
        vector<int> indDate = p->getIndicesDate(Startdate.day(),Startdate.month(),Startdate.year(),Enddate.day(),Enddate.month(),Enddate.year());
        vector<int> indOther = indDate;
        int count;

        QTreeWidgetItem *treeRoot = new QTreeWidgetItem(ui->treeWidget);
        addTreeRoot(treeRoot,"Publications", QString::number(indDate.size()));

        for (string status : statuses) {

            if (status == "Other") indStatus = indOther;
            //get the subset of indices where the paper is of the status specified and is in the date range specified.
            else indStatus = p->getIndicesStatus(status,indDate);
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
                    indStatusType = p->getIndicesType(type,indStatus);
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
