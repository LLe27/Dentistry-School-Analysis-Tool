//Necessaru Includes
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


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

    //Setup TreeList, set it to have two columns
    ui->treeWidget->setColumnCount(2);

    //Read in list of Column Names to set the column Names
    QStringList ColumnNames;
    ColumnNames << " " << "Total";
    ui->treeWidget->setHeaderLabels(ColumnNames);
    ui->treeWidget->setColumnWidth(0,170);


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




}
//Deletes UI after program stops
MainWindow::~MainWindow()
{
    delete ui;
}


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

//On button click, do stuff
void MainWindow::on_pushButton_clicked()
{
    ui->lblDateRange->setText(ui->comboBox->currentText() + "-" + ui->comboBox_2->currentText() + " " + ui->comboBox_3->currentText() + "-" + ui->comboBox_4->currentText());
    QStringList ColumnNames;
    ColumnNames << ui->comboBox->currentText() + "-" + ui->comboBox_2->currentText() + "\t" + ui->comboBox_3->currentText() + "-" + ui->comboBox_4->currentText() << "Total";
    ui->treeWidget->setHeaderLabels(ColumnNames);
}

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
