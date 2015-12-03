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
    QLabel *label_2;
    QLabel *label;

    void setupUi(QDialog *StartUp)
    {
        if (StartUp->objectName().isEmpty())
            StartUp->setObjectName(QStringLiteral("StartUp"));
        StartUp->resize(840, 463);
        StartUp->setStyleSheet(QStringLiteral(""));
        buttonBox = new QDialogButtonBox(StartUp);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(430, 420, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        groupBox = new QGroupBox(StartUp);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 210, 800, 200));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(12, 13, 175, 175));
        radioButton->setStyleSheet(QLatin1String("QRadioButton::indicator{\n"
"        width: 175px;\n"
"        height: 175px;\n"
"}\n"
"\n"
"QRadioButton::indicator::unchecked{\n"
"        image: url(:/images/Publications_Button.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked:hover {\n"
"    image: url(:/images/Publications_Button_Unchecked_Hover.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked:pressed{\n"
"    image: url(:/images/Publications_Button_Unchecked_Clicked.png);\n"
"}\n"
"\n"
"\n"
"QRadioButton::indicator::checked{\n"
"        image: url(:/images/Publications_Button_Checked.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:checked:hover {\n"
"    image: url(:/images/Publications_Button_Checked_Hover.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:checked:pressed{\n"
"    image: url(:/images/Publications_Button_Checked_Clicked.png);\n"
"}"));
        radioButton->setIconSize(QSize(100, 61));
        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(612, 13, 175, 175));
        radioButton_2->setStyleSheet(QLatin1String("QRadioButton::indicator{\n"
"                 width: 175px;\n"
"        height: 175px;\n"
"}\n"
"\n"
"QRadioButton::indicator::unchecked{\n"
"        image: url(:/images/Grants_Button.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked:hover {\n"
"    image: url(:/images/Grants_Button_Unchecked_Hover.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked:pressed{\n"
"    image: url(:/images/Grants_Button_Unchecked_Clicked.png);\n"
"}\n"
"\n"
"\n"
"QRadioButton::indicator::checked{\n"
"        image: url(:/images/Grants_Button_Checked.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:checked:hover {\n"
"    image: url(:/images/Grants_Button_Checked_Hover.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:checked:pressed{\n"
"    image: url(:/images/Grants_Button_Checked_Clicked.png);\n"
"}"));
        radioButton_3 = new QRadioButton(groupBox);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setGeometry(QRect(212, 13, 175, 175));
        radioButton_3->setStyleSheet(QLatin1String("QRadioButton::indicator{\n"
"         width: 175px;\n"
"        height: 175px;\n"
"}\n"
"\n"
"QRadioButton::indicator::unchecked{\n"
"        image: url(:/images/Teachings_Button.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked:hover {\n"
"    image: url(:/images/Teachings_Button_Unchecked_Hover.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked:pressed{\n"
"    image: url(:/images/Teachings_Button_Unchecked_Clicked.png);\n"
"}\n"
"\n"
"\n"
"QRadioButton::indicator::checked{\n"
"        image: url(:/images/Teachings_Button_Checked.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:checked:hover {\n"
"    image: url(:/images/Teachings_Button_Checked_Hover.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:checked:pressed{\n"
"    image: url(:/images/Teachings_Button_Checked_Clicked.png);\n"
"}"));
        radioButton_4 = new QRadioButton(groupBox);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));
        radioButton_4->setGeometry(QRect(412, 13, 175, 175));
        radioButton_4->setStyleSheet(QLatin1String("QRadioButton::indicator{\n"
"                 width: 175px;\n"
"        height: 175px;\n"
"}\n"
"\n"
"QRadioButton::indicator::unchecked{\n"
"        image: url(:/images/Presentation_Button.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked:hover {\n"
"    image: url(:/images/Presentation_Button_Unchecked_Hover.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked:pressed{\n"
"    image: url(:/images/Presentation_Button_Unchecked_Clicked.png);\n"
"}\n"
"\n"
"\n"
"QRadioButton::indicator::checked{\n"
"        image: url(:/images/Presentation_Button_Checked.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:checked:hover {\n"
"    image: url(:/images/Presentation_Button_Checked_Hover.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:checked:pressed{\n"
"    image: url(:/images/Presentation_Button_Checked_Clicked.png);\n"
"}"));
        label_2 = new QLabel(StartUp);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(-30, -10, 271, 211));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/images/schulich-school-of-medicine-dentistry.gif")));
        label = new QLabel(StartUp);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(720, 10, 111, 111));
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/small-5978-9276397.png")));

        retranslateUi(StartUp);
        QObject::connect(buttonBox, SIGNAL(accepted()), StartUp, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), StartUp, SLOT(reject()));

        QMetaObject::connectSlotsByName(StartUp);
    } // setupUi

    void retranslateUi(QDialog *StartUp)
    {
        StartUp->setWindowTitle(QApplication::translate("StartUp", "Welcome", 0));
        groupBox->setTitle(QString());
        radioButton->setText(QString());
        radioButton_2->setText(QString());
        radioButton_3->setText(QString());
        radioButton_4->setText(QString());
        label_2->setText(QString());
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class StartUp: public Ui_StartUp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTUP_H
