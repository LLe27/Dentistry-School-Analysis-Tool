//Necessaru Includes
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);





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
    QTreeWidgetItem *treeBranch = new QTreeWidgetItem(ui->treeWidget);

    addTreeRoot(treeBranch, "A", "Root_first");

    //Making abunch of filler items for the tree to test functions
    for(int i =0; i < 10; i++){
    QTreeWidgetItem *treeItem = new QTreeWidgetItem(2);
    QString in = i;

    //Need a check to see if the treeitem has a child or not
    if(i%2 == 0){
        QTreeWidgetItem *treeItem2 = new QTreeWidgetItem(ui->treeWidget,1);
        addTreeRoot(treeItem2,"TREE","BRANCH");
    }
    else{

        addTreeRoot(treeItem,"Test","Testing");
        //Need Parent Widget item to test to see if it is a parent
        treeBranch->addChild(treeItem);
    }

    addTreeChild(treeItem,"Hello",in);

}

    //Testing Function
    QTreeWidgetItem *treeBranch2 = new QTreeWidgetItem(ui->treeWidget);
    addTreeRoot(treeBranch2,"Yo","Works");
    QTreeWidgetItem *CurrentParent;
    CurrentParent = treeBranch2;

    //WOW SUPER EASY
    for(int i = 0; i < 10;i++){
        if(i%2){
            QTreeWidgetItem *treeTest = new QTreeWidgetItem(CurrentParent);
            treeTest->setText(0,"Parent");
            treeTest->setText(1,"Yeah");
            CurrentParent = treeTest;
        }
        else{
            QTreeWidgetItem *treeTest = new QTreeWidgetItem(CurrentParent);
            treeTest->setText(0,"Child");
            treeTest->setText(1,"Nah");
        }

    }

    ui->treeWidget->sortByColumn(0,Qt::AscendingOrder);
    ui->treeWidget->setSortingEnabled(true);



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
addTreeChild(treeBranch, name + "A", "Child_first");
addTreeChild(treeBranch,name + "B", "Child_second");



}

//Add leaf to tree
void MainWindow::addTreeChild(QTreeWidgetItem *parent,QString name,QString description){

    QTreeWidgetItem *treeItem = new QTreeWidgetItem();
    treeItem->setText(0,name);
    treeItem -> setText(1,description);

    parent ->addChild(treeItem);

}

void MainWindow::on_actionOpen_triggered()
{
    //Returns file name of sleected file in QFileDialog
    QString filename= QFileDialog::getOpenFileName(this, tr("Open File"),"C://","CSV File (*.csv);;All files (*.*)");
    ui->lblDateRange->setText(filename);

    //Pass filename to open file function
}

void MainWindow::on_bntDisplayGraph_clicked()
{
    QPixmap pm("FILENAME GOES HERE");
    ui->lblGraph->setPixmap(pm);
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
}
