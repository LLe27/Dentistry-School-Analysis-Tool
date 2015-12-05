#include "startup.h"
#include "ui_startup.h"

StartUp::StartUp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartUp)
{
    ui->setupUi(this);
    ui->groupBox->setStyleSheet("border:0;");
    csvtype = -1;
}

StartUp::~StartUp()
{
    delete ui;
}

void StartUp::on_radioButton_toggled(bool checked)
{
    csvtype =1;

}

void StartUp::on_radioButton_3_toggled(bool checked)
{
    csvtype = 2;
}

void StartUp::on_radioButton_4_toggled(bool checked)
{
    csvtype = 3;
}

void StartUp::on_radioButton_2_toggled(bool checked)
{
    csvtype = 4;
}


int StartUp::getCsvType(){
    return csvtype;
}

void StartUp::on_buttonBox_accepted()
{

}
