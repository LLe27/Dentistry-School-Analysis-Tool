/********************************************************************************
** Form generated from reading UI file 'errorform.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ERRORFORM_H
#define UI_ERRORFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ErrorForm
{
public:
    QTableWidget *tableWidget;
    QPushButton *saveButton;
    QPushButton *openButton;
    QPushButton *checkButton;
    QGroupBox *groupBox;
    QRadioButton *mandButton;
    QRadioButton *radioButton_2;
    QLabel *lbl_FileEdit;
    QLabel *lbl_FileEdit_2;

    void setupUi(QWidget *ErrorForm)
    {
        if (ErrorForm->objectName().isEmpty())
            ErrorForm->setObjectName(QStringLiteral("ErrorForm"));
        ErrorForm->resize(1194, 553);
        tableWidget = new QTableWidget(ErrorForm);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(10, 30, 1010, 430));
        saveButton = new QPushButton(ErrorForm);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setGeometry(QRect(1040, 190, 121, 40));
        openButton = new QPushButton(ErrorForm);
        openButton->setObjectName(QStringLiteral("openButton"));
        openButton->setGeometry(QRect(1040, 250, 121, 40));
        checkButton = new QPushButton(ErrorForm);
        checkButton->setObjectName(QStringLiteral("checkButton"));
        checkButton->setGeometry(QRect(1040, 310, 121, 40));
        groupBox = new QGroupBox(ErrorForm);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(1040, 85, 120, 80));
        mandButton = new QRadioButton(groupBox);
        mandButton->setObjectName(QStringLiteral("mandButton"));
        mandButton->setGeometry(QRect(10, 20, 121, 17));
        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(10, 50, 121, 17));
        lbl_FileEdit = new QLabel(ErrorForm);
        lbl_FileEdit->setObjectName(QStringLiteral("lbl_FileEdit"));
        lbl_FileEdit->setGeometry(QRect(1040, 20, 121, 31));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        lbl_FileEdit->setFont(font);
        lbl_FileEdit->setAlignment(Qt::AlignCenter);
        lbl_FileEdit_2 = new QLabel(ErrorForm);
        lbl_FileEdit_2->setObjectName(QStringLiteral("lbl_FileEdit_2"));
        lbl_FileEdit_2->setGeometry(QRect(1040, 40, 121, 31));
        lbl_FileEdit_2->setAlignment(Qt::AlignCenter);

        retranslateUi(ErrorForm);

        QMetaObject::connectSlotsByName(ErrorForm);
    } // setupUi

    void retranslateUi(QWidget *ErrorForm)
    {
        ErrorForm->setWindowTitle(QApplication::translate("ErrorForm", "Form", 0));
        saveButton->setText(QApplication::translate("ErrorForm", "Save", 0));
        openButton->setText(QApplication::translate("ErrorForm", "Open", 0));
        checkButton->setText(QApplication::translate("ErrorForm", "Check/Update", 0));
        groupBox->setTitle(QApplication::translate("ErrorForm", "Display Options", 0));
        mandButton->setText(QApplication::translate("ErrorForm", "Mandatory Only", 0));
        radioButton_2->setText(QApplication::translate("ErrorForm", "Show All", 0));
        lbl_FileEdit->setText(QApplication::translate("ErrorForm", "File Being Edited:", 0));
        lbl_FileEdit_2->setText(QApplication::translate("ErrorForm", "\"Publications.csv\"", 0));
    } // retranslateUi

};

namespace Ui {
    class ErrorForm: public Ui_ErrorForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ERRORFORM_H
