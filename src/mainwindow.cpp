<<<<<<< HEAD
#include "mainwindow.h"
#include "ui_mainwindow.h"

<<<<<<< HEAD
=======
#if 0
>>>>>>> Demo1
=======
//Necessaru Includes
#include "mainwindow.h"

QDate Startdate;
QDate Enddate;

PublicationProcessing* p;


>>>>>>> DEMO1_25102015
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
<<<<<<< HEAD
<<<<<<< HEAD
    setGeometry(100, 100, 1000, 400);
=======
>>>>>>> Demo1
}

=======

    string filename = on_actionOpen_triggered().toStdString();
    myData CSVData;

    vector<vector<string>> data = CSVData.parsePublications(filename);

    //process data by constructing PublicationProcessing
    p = new PublicationProcessing(data);






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
>>>>>>> DEMO1_25102015
MainWindow::~MainWindow()
{
    delete ui;
}
<<<<<<< HEAD
<<<<<<< HEAD
=======
#endif
>>>>>>> Demo1
=======

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

    vector<string> types = p->getListOfTypes();
    vector<int> indDate = p->getIndicesDate(dayStart,monthStart,yearStart,dayEnd,monthEnd,yearEnd);
    for (int i=0; i<types.size(); i++) {
        numItems << p->getIndicesType(types.at(i),indDate).size();
    }

    makeGraph(numItems, title, types);
    //w.show();

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

void MainWindow::makeGraph(QVector<double> yAxisData, QString title, vector<string> barLabels ) {
    QCustomPlot *customPlot = new QCustomPlot();//   ui->MainWindow::findChild<QCustomPlot*>("myChart");
    customPlot->show();
    customPlot->setGeometry(100, 100, 1400, 800);

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


void MainWindow::processDates(){
        vector<string> types = p->getListOfTypes();
        string statuses[] = {"Published","Accepted / In Press","Submitted","Other"};
        vector<int> indStatus, indStatusType, indStatusTypeMember;
        vector<string> members = p->getListOfMemberNames();
        vector<int> indDate = p->getIndicesDate(Startdate.day(),Startdate.month(),Startdate.year(),Enddate.day(),Enddate.month(),Enddate.year());
        vector<int> indOther = indDate;
        int count;

        QTreeWidgetItem *treeRoot = new QTreeWidgetItem(ui->treeWidget);
        addTreeRoot(treeRoot,"Publications", QString::number(indDate.size()));

        for (string status : statuses) {

            if (status == "Other") indStatus = indOther;
            else indStatus = p->getIndicesStatus(status,indDate);
            count = indStatus.size();
            //cout << status << "(" << count << ")" << endl;
            QTreeWidgetItem *treeBranch = new QTreeWidgetItem();
            treeRoot->addChild(treeBranch);
              addTreeRoot(treeBranch,QString::fromStdString(status),QString::number(count));

              //remove from other
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
                               treeChild->setText(0,QString::fromStdString(type));
                               treeChild -> setText(1,QString::number(count));

                                //cout << "\t\t" << member << "(" << count << ")" << endl;
                            }
                        }
                    }
                }
            }

        }


}
>>>>>>> DEMO1_25102015
