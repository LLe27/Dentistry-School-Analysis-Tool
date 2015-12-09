#include "errorform.h"
#include "ui_errorform.h"
#include <QFileDialog>
#include <QTextStream>
#include <vector>
#include <string>
#include <iostream>

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
                //if(i == errorIndicies.at())


                output << ui->tableWidget->item(j,i)->text() << ",";
            }
            output << "\n";
        }
    }


    f.close();
   }

void ErrorForm::setCSVProccessor(CSVProcessing * p){
    ep = p;
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
    //cout <<rowError.size() << endl;
    for(int i = 0; i < rowError.size(); i++){

            //If the text at this error cell has changed
//            cout << "row: " << rowError.at(i) << endl;
//            cout << "col: " << colError.at(i) << endl;

            if(ui->tableWidget->item(rowError.at(i),colError.at(i))->text() != "Unspecified" && ui->tableWidget->item(rowError.at(i),colError.at(i))->text() != ""){

                //Change the value in the data, and update its background
                ep->processingChangeField(rowError.at(i),colError.at(i),(CSVType)csvtype, ui->tableWidget->item(rowError.at(i),colError.at(i))->text().toStdString());
                ui->tableWidget->item(rowError.at(i),colError.at(i))->setBackground(Qt::white);
            }
        }


    rowError.clear();
    colError.clear();


    for(int i = 0; i < errorIndicies.size(); i++){
        for(int j = 0; j < ui->tableWidget->columnCount(); j++){
            if(errorIndicies.at(i).size() > 0)    {
                if(ui->tableWidget->item(i,j)->text() == "Unspecified" || ui->tableWidget->item(i,j)->text() == ""){
                    rowError.push_back(i);
                    colError.push_back(j);
                }
            }
        }


    }

    //

//    cout << "Second: " << errorIndicies.at(1).at(0) <<endl;
}

void ErrorForm:: setErrorIndices(vector<vector<int>> Index){
    errorIndicies = Index;
}

void ErrorForm::setCSVType(int type){
       csvtype = type;
}

void ErrorForm::popTable(vector<vector<string>> *errors){
    ui->tableWidget->setRowCount(errors->at(0).size());
    ui->tableWidget->setColumnCount(errors->size());

    for(int i = 0; i < errors->size();i++){
         //cout <<"Run" <<endl;
        for(int j = 0; j < errors->at(i).size(); j++){
            string input;
            input = errors->at(i).at(j);
            ui->tableWidget->setItem(j,i,new QTableWidgetItem(QString::fromStdString(input)));
            if(input == "Unspecified" || input == ""){
                ui->tableWidget->item(j,i)->setBackground(Qt::red);
            }
            else{
                ui->tableWidget->item(j,i)->setFlags(Qt::ItemIsEditable);
            }
        }
    }

    //cout << errorIndicies.size() << endl;

    for(int i = 0; i < errorIndicies.size(); i++){
        for(int j = 0; j < ui->tableWidget->columnCount(); j++){
            if(errorIndicies.at(i).size() > 0)    {
                if(ui->tableWidget->item(i,j)->text() == "Unspecified" || ui->tableWidget->item(i,j)->text() == ""){
                    rowError.push_back(i);
                    colError.push_back(j);
                }

            }
        }


    }

}
