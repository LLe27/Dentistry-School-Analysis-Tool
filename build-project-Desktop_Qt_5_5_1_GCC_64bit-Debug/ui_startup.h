/********************************************************************************
** Form generated from reading UI file 'startup.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTUP_H
#define UI_STARTUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_StartUp
{
public:
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QLabel *label;

    void setupUi(QDialog *StartUp)
    {
        if (StartUp->objectName().isEmpty())
            StartUp->setObjectName(QStringLiteral("StartUp"));
        StartUp->resize(400, 300);
        buttonBox = new QDialogButtonBox(StartUp);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        groupBox = new QGroupBox(StartUp);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(30, 30, 331, 181));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(20, 40, 82, 17));
        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(20, 115, 82, 17));
        radioButton_3 = new QRadioButton(groupBox);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setGeometry(QRect(20, 65, 82, 17));
        radioButton_4 = new QRadioButton(groupBox);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));
        radioButton_4->setGeometry(QRect(20, 90, 91, 17));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 40, 161, 91));
        QFont font;
        font.setPointSize(40);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(StartUp);
        QObject::connect(buttonBox, SIGNAL(accepted()), StartUp, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), StartUp, SLOT(reject()));

        QMetaObject::connectSlotsByName(StartUp);
    } // setupUi

    void retranslateUi(QDialog *StartUp)
    {
        StartUp->setWindowTitle(QApplication::translate("StartUp", "Dialog", 0));
        groupBox->setTitle(QApplication::translate("StartUp", "GroupBox", 0));
        radioButton->setText(QApplication::translate("StartUp", "Publications", 0));
        radioButton_2->setText(QApplication::translate("StartUp", "Grants", 0));
        radioButton_3->setText(QApplication::translate("StartUp", "Teaching", 0));
        radioButton_4->setText(QApplication::translate("StartUp", "Presentations", 0));
        label->setText(QApplication::translate("StartUp", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class StartUp: public Ui_StartUp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTUP_H
