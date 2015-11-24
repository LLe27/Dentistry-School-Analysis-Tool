#include "startup.h"
#include "ui_startup.h"

StartUp::StartUp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartUp)
{
    ui->setupUi(this);
    ui->label->setText("");
}

StartUp::~StartUp()
{
    delete ui;
}

void StartUp::on_radioButton_toggled(bool checked)
{
    csvtype =1;
    ui->label->setText(QString::number(csvtype));
}

void StartUp::on_radioButton_3_toggled(bool checked)
{
    csvtype = 2;
    ui->label->setText(QString::number(csvtype));
}

void StartUp::on_radioButton_4_toggled(bool checked)
{

    csvtype = 3;
    ui->label->setText(QString::number(csvtype));

}

void StartUp::on_radioButton_2_toggled(bool checked)
{
    csvtype = 4;
    ui->label->setText(QString::number(csvtype));
}


int StartUp::getCsvType(){
    return csvtype;
}

void StartUp::on_buttonBox_accepted()
{
    ui->label->setText("Accepted");
}
