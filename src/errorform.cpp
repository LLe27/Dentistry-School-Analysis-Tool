#include "errorform.h"
#include "ui_errorform.h"
#include <QFileDialog>
#include <QTextStream>
#include <vector>
#include <string>

using namespace std;

ErrorForm::ErrorForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ErrorForm)
{
    ui->setupUi(this);
}

ErrorForm::~ErrorForm()
{
    delete ui;
}

void ErrorForm::on_saveButton_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this, tr("Save File"),"C://","CSV File (*.csv);;All files (*.*)");
    QFile f(filename);
    if(f.open(QIODevice::WriteOnly|QIODevice::Truncate)){
    //store data in f
        QTextStream output(&f); //stores the data in the out put stream
        for(int i = 0; i <ui->tableWidget->rowCount(); i++){
            for(int j = 0; j < ui->tableWidget->columnCount();j++){
                output << ui->tableWidget->item(i,j)->text() << ",";
            }
            output << "\n";
        }
    }


    f.close();
   }


QString ErrorForm::on_openButton_clicked()
{
     QString filename = QFileDialog::getOpenFileName(this, tr("Open File"),"C://","CSV File (*.csv);;All files (*.*)");
     if(filename != ""){
        ui->lbl_FileEdit_2->setText(filename);
     }
     //Pass to processer
     return filename;
}

void ErrorForm::on_checkButton_clicked()
{
    //Call check error function
    //recheck csv for errors
}

void ErrorForm::popTable(vector<vector<string>> *errors){
    ui->tableWidget->setRowCount(errors->size());
    ui->tableWidget->setColumnCount(errors->at(0).size());

    for(int i = 0; i < errors->size();i++){
        for(int j = 0; j < errors->at(i).size(); j++){
            string input;
            input = errors->at(i).at(j);
            ui->tableWidget->setItem(i,j,new QTableWidgetItem(QString::fromStdString(input)));
        }
    }

}
