/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_as;
    QAction *actionPreferences;
    QAction *actionView;
    QAction *actionContents;
    QAction *actionIndex;
    QAction *actionReport_BUg;
    QAction *actionReport_Bug;
    QWidget *centralWidget;
    QTreeWidget *treeWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QDateEdit *dateEdit;
    QSpacerItem *horizontalSpacer;
    QDateEdit *dateEdit_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnDates;
    QSpacerItem *horizontalSpacer_2;
    QLabel *lblDateRange;
    QLabel *label;
    QLabel *label_2;
    QPushButton *bntDisplayBar;
    QPushButton *bntDisplayPie;
    QPushButton *bntDisplayScatter;
    QLabel *label_3;
    QPushButton *bntDisplayLine;
    QLineEdit *minText_1;
    QLineEdit *minText_2;
    QLineEdit *maxText_1;
    QLineEdit *maxText_2;
    QLabel *labelHyp_1;
    QLabel *labelHyp_2;
    QLabel *lblMin_1;
    QLabel *lblMin_2;
    QLabel *lblMax_1;
    QLabel *lblMax_2;
    QMenuBar *menuBar;
    QMenu *menuFIle;
    QMenu *menuOptions;
    QMenu *menuWindow;
    QMenu *menuTools;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QLatin1String("\n"
"QComboBox {\n"
"    border: 1px solid gray;\n"
"    border-radius: 3px;\n"
"    padding: 1px 18px 1px 3px;\n"
"   \n"
"}\n"
"\n"
"QComboBox:editable {\n"
"    background: white;\n"
"}\n"
"\n"
"QComboBox:!editable, QComboBox::drop-down:editable {\n"
"     background: white\n"
"}\n"
"\n"
"/* QComboBox gets the \"on\" state when the popup is open */\n"
"QComboBox:!editable:on, QComboBox::drop-down:editable:on {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #D3D3D3, stop: 0.4 #D8D8D8,\n"
"                                stop: 0.5 #DDDDDD, stop: 1.0 #E1E1E1);\n"
"}\n"
"\n"
"QComboBox:on { /* shift the text when the popup opens */\n"
"    padding-top: 3px;\n"
"    padding-left: 4px;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 15px;\n"
"\n"
"    border-left-width: 1px;\n"
"    border-left-color: darkgray;\n"
"    border-left-style: solid; /* just a single line */\n"
""
                        "    border-top-right-radius: 3px; /* same radius as the QComboBox */\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/myFiles/down-arrow-circle-hi.png);\n"
"}\n"
"\n"
"QComboBox::down-arrow:on { /* shift the arrow when popup is open */\n"
"    top: 1px;\n"
"    left: 1px;\n"
"}"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName(QStringLiteral("actionSave_as"));
        actionPreferences = new QAction(MainWindow);
        actionPreferences->setObjectName(QStringLiteral("actionPreferences"));
        actionView = new QAction(MainWindow);
        actionView->setObjectName(QStringLiteral("actionView"));
        actionContents = new QAction(MainWindow);
        actionContents->setObjectName(QStringLiteral("actionContents"));
        actionIndex = new QAction(MainWindow);
        actionIndex->setObjectName(QStringLiteral("actionIndex"));
        actionReport_BUg = new QAction(MainWindow);
        actionReport_BUg->setObjectName(QStringLiteral("actionReport_BUg"));
        actionReport_Bug = new QAction(MainWindow);
        actionReport_Bug->setObjectName(QStringLiteral("actionReport_Bug"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        treeWidget = new QTreeWidget(centralWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setGeometry(QRect(420, 10, 330, 531));
        treeWidget->setStyleSheet(QLatin1String("QTreeView {\n"
"    show-decoration-selected: 2;\n"
"}\n"
"\n"
"QTreeView::item {\n"
"     border: 1px solid #d9d9d9;\n"
"    border-top-color: transparent;\n"
"    border-bottom-color: transparent;\n"
"}\n"
"\n"
"QTreeView::item:hover {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #e7effd, stop: 1 #cbdaf1);\n"
"    border: 1px solid #bfcde4;\n"
"}\n"
"\n"
"QTreeView::item:selected {\n"
"    border: 1px solid #567dbc;\n"
"}\n"
"\n"
"QTreeView::item:selected:active{\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #6ea1f1, stop: 1 #567dbc);\n"
"}\n"
"\n"
"QTreeView::item:selected:!active {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #6b9be8, stop: 1 #577fbf);\n"
"}\n"
"\n"
"/*\n"
"QTreeView::branch:has-children:!has-siblings:closed,\n"
"QTreeView::branch:closed:has-children:has-siblings {\n"
"        border-image: none;\n"
"    image: url(:/myFiles/black-plus-sign.png);\n"
"}\n"
"\n"
"QTreeView::branch:open:has-children:!has-siblings,"
                        "\n"
"QTreeView::branch:open:has-children:has-siblings  {\n"
"        border-image: none;\n"
"        image: url(:/myFiles/minus_sign_u2212_icon_256x256.png);\n"
"}\n"
"*/"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 30, 256, 103));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        dateEdit = new QDateEdit(layoutWidget);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));

        horizontalLayout->addWidget(dateEdit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        dateEdit_2 = new QDateEdit(layoutWidget);
        dateEdit_2->setObjectName(QStringLiteral("dateEdit_2"));

        horizontalLayout->addWidget(dateEdit_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        btnDates = new QPushButton(layoutWidget);
        btnDates->setObjectName(QStringLiteral("btnDates"));
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        btnDates->setFont(font);

        horizontalLayout_2->addWidget(btnDates);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        lblDateRange = new QLabel(layoutWidget);
        lblDateRange->setObjectName(QStringLiteral("lblDateRange"));

        horizontalLayout_2->addWidget(lblDateRange);


        verticalLayout->addLayout(horizontalLayout_2);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(11, 11, 32, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(145, 11, 32, 16));
        bntDisplayBar = new QPushButton(centralWidget);
        bntDisplayBar->setObjectName(QStringLiteral("bntDisplayBar"));
        bntDisplayBar->setGeometry(QRect(30, 210, 141, 141));
        QFont font1;
        font1.setFamily(QStringLiteral("Terminal"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setWeight(50);
        bntDisplayBar->setFont(font1);
        bntDisplayBar->setStyleSheet(QStringLiteral("border-image: url(:/images/BarIcon.png);"));
        bntDisplayPie = new QPushButton(centralWidget);
        bntDisplayPie->setObjectName(QStringLiteral("bntDisplayPie"));
        bntDisplayPie->setGeometry(QRect(210, 230, 141, 111));
        bntDisplayPie->setStyleSheet(QStringLiteral("border-image: url(:/images/PieIcon.png);"));
        bntDisplayScatter = new QPushButton(centralWidget);
        bntDisplayScatter->setObjectName(QStringLiteral("bntDisplayScatter"));
        bntDisplayScatter->setGeometry(QRect(40, 370, 121, 121));
        bntDisplayScatter->setStyleSheet(QStringLiteral("border-image: url(:/images/ScatterIcon.png);"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 140, 211, 61));
        label_3->setStyleSheet(QStringLiteral("font: 87 22pt \"Segoe UI Black\";"));
        bntDisplayLine = new QPushButton(centralWidget);
        bntDisplayLine->setObjectName(QStringLiteral("bntDisplayLine"));
        bntDisplayLine->setGeometry(QRect(210, 370, 151, 121));
        bntDisplayLine->setStyleSheet(QStringLiteral("border-image: url(:/images/LineIcon2.png);"));
        minText_1 = new QLineEdit(centralWidget);
        minText_1->setObjectName(QStringLiteral("minText_1"));
        minText_1->setEnabled(true);
        minText_1->setGeometry(QRect(280, 50, 41, 20));
        minText_2 = new QLineEdit(centralWidget);
        minText_2->setObjectName(QStringLiteral("minText_2"));
        minText_2->setEnabled(true);
        minText_2->setGeometry(QRect(280, 100, 41, 20));
        maxText_1 = new QLineEdit(centralWidget);
        maxText_1->setObjectName(QStringLiteral("maxText_1"));
        maxText_1->setEnabled(true);
        maxText_1->setGeometry(QRect(350, 50, 41, 20));
        maxText_2 = new QLineEdit(centralWidget);
        maxText_2->setObjectName(QStringLiteral("maxText_2"));
        maxText_2->setEnabled(true);
        maxText_2->setGeometry(QRect(350, 100, 41, 20));
        labelHyp_1 = new QLabel(centralWidget);
        labelHyp_1->setObjectName(QStringLiteral("labelHyp_1"));
        labelHyp_1->setEnabled(true);
        labelHyp_1->setGeometry(QRect(320, 50, 30, 15));
        QFont font2;
        font2.setPointSize(23);
        labelHyp_1->setFont(font2);
        labelHyp_1->setAlignment(Qt::AlignCenter);
        labelHyp_2 = new QLabel(centralWidget);
        labelHyp_2->setObjectName(QStringLiteral("labelHyp_2"));
        labelHyp_2->setEnabled(true);
        labelHyp_2->setGeometry(QRect(320, 100, 30, 15));
        labelHyp_2->setFont(font2);
        labelHyp_2->setAlignment(Qt::AlignCenter);
        lblMin_1 = new QLabel(centralWidget);
        lblMin_1->setObjectName(QStringLiteral("lblMin_1"));
        lblMin_1->setEnabled(true);
        lblMin_1->setGeometry(QRect(280, 30, 47, 13));
        lblMin_2 = new QLabel(centralWidget);
        lblMin_2->setObjectName(QStringLiteral("lblMin_2"));
        lblMin_2->setEnabled(true);
        lblMin_2->setGeometry(QRect(280, 80, 47, 13));
        lblMax_1 = new QLabel(centralWidget);
        lblMax_1->setObjectName(QStringLiteral("lblMax_1"));
        lblMax_1->setEnabled(true);
        lblMax_1->setGeometry(QRect(350, 30, 47, 13));
        lblMax_2 = new QLabel(centralWidget);
        lblMax_2->setObjectName(QStringLiteral("lblMax_2"));
        lblMax_2->setEnabled(true);
        lblMax_2->setGeometry(QRect(350, 80, 47, 13));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 21));
        menuFIle = new QMenu(menuBar);
        menuFIle->setObjectName(QStringLiteral("menuFIle"));
        menuOptions = new QMenu(menuBar);
        menuOptions->setObjectName(QStringLiteral("menuOptions"));
        menuWindow = new QMenu(menuBar);
        menuWindow->setObjectName(QStringLiteral("menuWindow"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFIle->menuAction());
        menuBar->addAction(menuOptions->menuAction());
        menuBar->addAction(menuWindow->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFIle->addAction(actionOpen);
        menuFIle->addAction(actionSave);
        menuFIle->addAction(actionSave_as);
        menuOptions->addAction(actionPreferences);
        menuWindow->addAction(actionView);
        menuHelp->addSeparator();
        menuHelp->addAction(actionContents);
        menuHelp->addAction(actionIndex);
        menuHelp->addSeparator();
        menuHelp->addAction(actionReport_Bug);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0));
        actionSave_as->setText(QApplication::translate("MainWindow", "Save as...", 0));
        actionPreferences->setText(QApplication::translate("MainWindow", "Preferences", 0));
        actionView->setText(QApplication::translate("MainWindow", "View", 0));
        actionContents->setText(QApplication::translate("MainWindow", "Contents", 0));
        actionIndex->setText(QApplication::translate("MainWindow", "Index", 0));
        actionReport_BUg->setText(QApplication::translate("MainWindow", "Report BUg", 0));
        actionReport_Bug->setText(QApplication::translate("MainWindow", "Report Bug", 0));
        btnDates->setText(QApplication::translate("MainWindow", "Enter Dates", 0));
        lblDateRange->setText(QString());
        label->setText(QApplication::translate("MainWindow", "Date 1", 0));
        label_2->setText(QApplication::translate("MainWindow", "Date 2", 0));
#ifndef QT_NO_STATUSTIP
        bntDisplayBar->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        bntDisplayBar->setText(QString());
        bntDisplayPie->setText(QString());
        bntDisplayScatter->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "Display Graph", 0));
        bntDisplayLine->setText(QString());
        labelHyp_1->setText(QApplication::translate("MainWindow", "-", 0));
        labelHyp_2->setText(QApplication::translate("MainWindow", "-", 0));
        lblMin_1->setText(QApplication::translate("MainWindow", "Min", 0));
        lblMin_2->setText(QApplication::translate("MainWindow", "Min", 0));
        lblMax_1->setText(QApplication::translate("MainWindow", "Max", 0));
        lblMax_2->setText(QApplication::translate("MainWindow", "Max", 0));
        menuFIle->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuOptions->setTitle(QApplication::translate("MainWindow", "Options", 0));
        menuWindow->setTitle(QApplication::translate("MainWindow", "Window", 0));
        menuTools->setTitle(QApplication::translate("MainWindow", "Tools", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
