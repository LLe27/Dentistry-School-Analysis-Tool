#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //Gets the dates and puts them into strings following the format below
    QDate date1 = (ui->dateEdit->date());
    QDate date2 = (ui->dateEdit_2->date());
    QString dateString1 = date1.toString("yyyy-MM-dd");
    QString dateString2 = date2.toString("yyyy-MM-dd");
    ui->label->setText(dateString1 + " " + dateString2);
}
