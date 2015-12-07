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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSaveDashboard;
    QAction *actionPreferences;
    QAction *actionContents;
    QAction *actionIndex;
    QAction *actionReport_BUg;
    QAction *actionReport_Bug;
    QAction *actionSave_Bar_Graph;
    QAction *actionSave_Pie_Chart;
    QAction *actionSave_Line_Graph;
    QAction *actionSave_Scatter_Plot;
    QAction *actionDashboard;
    QWidget *centralWidget;
    QTreeWidget *treeWidget;
    QPushButton *bntDisplayPie;
    QPushButton *bntDisplayBar;
    QPushButton *bntDisplayLine;
    QPushButton *bntDisplayScatter;
    QLabel *label_3;
    QDateEdit *dateEdit;
    QDateEdit *dateEdit_2;
    QPushButton *btnDates;
    QLabel *lblMax_1;
    QLabel *lblMax_2;
    QLabel *lblMin_1;
    QLabel *lblMin_2;
    QLabel *labelHyp_1;
    QLabel *labelHyp_2;
    QLineEdit *maxText_1;
    QLineEdit *maxText_2;
    QLineEdit *minText_1;
    QLineEdit *minText_2;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *pushButton;
    QComboBox *comboBox;
    QLabel *label_8;
    QLabel *label_7;
    QLabel *label;
    QPushButton *btnCollapse;
    QPushButton *btnExpand;
    QMenuBar *menuBar;
    QMenu *menuFIle;
    QMenu *menuSave_Graph;
    QMenu *menuOptions;
    QMenu *menuWindow;
    QMenu *menuView;
    QMenu *menuTools;
    QMenu *menuHelp;
    QStatusBar *statusBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(850, 720);
        MainWindow->setStyleSheet(QLatin1String("QLabel{\n"
"color: white;\n"
"}"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSaveDashboard = new QAction(MainWindow);
        actionSaveDashboard->setObjectName(QStringLiteral("actionSaveDashboard"));
        actionPreferences = new QAction(MainWindow);
        actionPreferences->setObjectName(QStringLiteral("actionPreferences"));
        actionContents = new QAction(MainWindow);
        actionContents->setObjectName(QStringLiteral("actionContents"));
        actionIndex = new QAction(MainWindow);
        actionIndex->setObjectName(QStringLiteral("actionIndex"));
        actionReport_BUg = new QAction(MainWindow);
        actionReport_BUg->setObjectName(QStringLiteral("actionReport_BUg"));
        actionReport_Bug = new QAction(MainWindow);
        actionReport_Bug->setObjectName(QStringLiteral("actionReport_Bug"));
        actionSave_Bar_Graph = new QAction(MainWindow);
        actionSave_Bar_Graph->setObjectName(QStringLiteral("actionSave_Bar_Graph"));
        actionSave_Pie_Chart = new QAction(MainWindow);
        actionSave_Pie_Chart->setObjectName(QStringLiteral("actionSave_Pie_Chart"));
        actionSave_Line_Graph = new QAction(MainWindow);
        actionSave_Line_Graph->setObjectName(QStringLiteral("actionSave_Line_Graph"));
        actionSave_Scatter_Plot = new QAction(MainWindow);
        actionSave_Scatter_Plot->setObjectName(QStringLiteral("actionSave_Scatter_Plot"));
        actionDashboard = new QAction(MainWindow);
        actionDashboard->setObjectName(QStringLiteral("actionDashboard"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        treeWidget = new QTreeWidget(centralWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        __qtreewidgetitem->setTextAlignment(0, Qt::AlignLeading|Qt::AlignVCenter);
        treeWidget->setHeaderItem(__qtreewidgetitem);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem1->setTextAlignment(0, Qt::AlignTrailing|Qt::AlignVCenter);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setGeometry(QRect(430, 20, 331, 401));
        QFont font;
        font.setFamily(QStringLiteral("Verdana"));
        font.setBold(false);
        font.setWeight(50);
        treeWidget->setFont(font);
        treeWidget->setStyleSheet(QLatin1String("QTreeView{\n"
"        background-color:rgb(191, 85, 236);\n"
"        color:rgb(255, 255, 255);\n"
"        border: none;\n"
"}\n"
"\n"
"QHeaderView::section{\n"
"        background-color:rgb(191, 85, 236);\n"
"        color: white;\n"
"        border-top: none;\n"
"        border-left: none;\n"
"        border-right:none;\n"
"}"));
        treeWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        bntDisplayPie = new QPushButton(centralWidget);
        bntDisplayPie->setObjectName(QStringLiteral("bntDisplayPie"));
        bntDisplayPie->setGeometry(QRect(210, 70, 165, 221));
        bntDisplayPie->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image: url(:/images/PieGraph_Button.png);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"border-image: url(:/images/PieGraph_Button_Hover.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/images/PieGraph_Button_Clicked.png);\n"
"}"));
        bntDisplayBar = new QPushButton(centralWidget);
        bntDisplayBar->setObjectName(QStringLiteral("bntDisplayBar"));
        bntDisplayBar->setGeometry(QRect(30, 70, 165, 221));
        bntDisplayBar->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image: url(:/images/BarGraph_Button.png);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"border-image: url(:/images/BarGraph_Button_Hover.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/images/BarGraph_Button_Clicked.png);\n"
"}"));
        bntDisplayLine = new QPushButton(centralWidget);
        bntDisplayLine->setObjectName(QStringLiteral("bntDisplayLine"));
        bntDisplayLine->setGeometry(QRect(210, 290, 165, 221));
        bntDisplayLine->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image: url(:/images/LineGraph_Button.png);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"border-image: url(:/images/LineGraph_Button_Hover.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/images/LineGraph_Button_Clicked.png);\n"
"}\n"
""));
        bntDisplayScatter = new QPushButton(centralWidget);
        bntDisplayScatter->setObjectName(QStringLiteral("bntDisplayScatter"));
        bntDisplayScatter->setGeometry(QRect(30, 290, 165, 221));
        bntDisplayScatter->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image: url(:/images/ScatterPlot_Button.png);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"border-image: url(:/images/ScatterPlot_Button_Hover.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/images/ScatterPlot_Button_Clicked.png);\n"
"}"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 12, 341, 41));
        QFont font1;
        font1.setFamily(QStringLiteral("NEOTERIC"));
        font1.setPointSize(25);
        font1.setBold(true);
        font1.setWeight(75);
        label_3->setFont(font1);
        label_3->setStyleSheet(QStringLiteral("color: white;"));
        label_3->setAlignment(Qt::AlignCenter);
        dateEdit = new QDateEdit(centralWidget);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(425, 456, 121, 25));
        dateEdit->setStyleSheet(QLatin1String("QDateEdit{\n"
"        background-color:rgb(191, 85, 236);\n"
"        color:rgb(255, 255, 255);\n"
"        border:none;\n"
"}"));
        dateEdit->setDateTime(QDateTime(QDate(1900, 1, 1), QTime(0, 0, 0)));
        dateEdit_2 = new QDateEdit(centralWidget);
        dateEdit_2->setObjectName(QStringLiteral("dateEdit_2"));
        dateEdit_2->setGeometry(QRect(645, 456, 121, 25));
        dateEdit_2->setStyleSheet(QLatin1String("QDateEdit{\n"
"        background-color:rgb(191, 85, 236);\n"
"        color:rgb(255, 255, 255);\n"
"        border:none;\n"
"}"));
        btnDates = new QPushButton(centralWidget);
        btnDates->setObjectName(QStringLiteral("btnDates"));
        btnDates->setGeometry(QRect(420, 600, 366, 61));
        btnDates->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image: url(:/images/Enter_Button.png);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"border-image: url(:/images/Enter_Button_Hover.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/images/Enter_Button_Clicked.png);\n"
"}"));
        lblMax_1 = new QLabel(centralWidget);
        lblMax_1->setObjectName(QStringLiteral("lblMax_1"));
        lblMax_1->setGeometry(QRect(700, 513, 47, 13));
        QFont font2;
        font2.setFamily(QStringLiteral("NEOTERIC"));
        font2.setBold(true);
        font2.setWeight(75);
        lblMax_1->setFont(font2);
        lblMax_2 = new QLabel(centralWidget);
        lblMax_2->setObjectName(QStringLiteral("lblMax_2"));
        lblMax_2->setGeometry(QRect(700, 553, 47, 13));
        lblMax_2->setFont(font2);
        lblMin_1 = new QLabel(centralWidget);
        lblMin_1->setObjectName(QStringLiteral("lblMin_1"));
        lblMin_1->setGeometry(QRect(424, 513, 47, 13));
        lblMin_1->setFont(font2);
        lblMin_1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lblMin_2 = new QLabel(centralWidget);
        lblMin_2->setObjectName(QStringLiteral("lblMin_2"));
        lblMin_2->setGeometry(QRect(424, 553, 47, 13));
        lblMin_2->setFont(font2);
        lblMin_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        labelHyp_1 = new QLabel(centralWidget);
        labelHyp_1->setObjectName(QStringLiteral("labelHyp_1"));
        labelHyp_1->setGeometry(QRect(536, 510, 101, 20));
        labelHyp_1->setFont(font2);
        labelHyp_1->setAlignment(Qt::AlignCenter);
        labelHyp_2 = new QLabel(centralWidget);
        labelHyp_2->setObjectName(QStringLiteral("labelHyp_2"));
        labelHyp_2->setGeometry(QRect(536, 550, 101, 20));
        labelHyp_2->setFont(font2);
        labelHyp_2->setAlignment(Qt::AlignCenter);
        maxText_1 = new QLineEdit(centralWidget);
        maxText_1->setObjectName(QStringLiteral("maxText_1"));
        maxText_1->setGeometry(QRect(640, 510, 51, 20));
        maxText_2 = new QLineEdit(centralWidget);
        maxText_2->setObjectName(QStringLiteral("maxText_2"));
        maxText_2->setGeometry(QRect(640, 550, 51, 20));
        minText_1 = new QLineEdit(centralWidget);
        minText_1->setObjectName(QStringLiteral("minText_1"));
        minText_1->setGeometry(QRect(480, 510, 51, 20));
        minText_2 = new QLineEdit(centralWidget);
        minText_2->setObjectName(QStringLiteral("minText_2"));
        minText_2->setGeometry(QRect(480, 550, 51, 20));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(420, 10, 381, 451));
        label_4->setStyleSheet(QLatin1String("QLabel{\n"
"border-image: url(:/images/TreeWidget_Background.png);\n"
"}"));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(30, 10, 345, 61));
        label_5->setStyleSheet(QLatin1String("QLabel{\n"
"border-image: url(:/images/DisplayGraph.png);\n"
"}"));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(420, 451, 141, 42));
        label_6->setStyleSheet(QLatin1String("QLabel{\n"
"border-image: url(:/images/Label.png);\n"
"}"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(30, 510, 341, 61));
        pushButton->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image: url(:/images/Change_Button.png);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"border-image: url(:/images/Change_Button_Hover.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/images/Change_Button_Clicked.png);\n"
"}\n"
""));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(40, 610, 311, 22));
        comboBox->setStyleSheet(QLatin1String("QComboBox {\n"
"    border: none;\n"
"\n"
"    padding: 1px 18px 1px 3px;\n"
"   background:rgb(191, 85, 236);\n"
"\n"
"}\n"
"\n"
"QComboBox:editable {\n"
"    background: rgb(191, 85, 236);\n"
"}\n"
"\n"
"/* QComboBox gets the \"on\" state when the popup is open */\n"
"QComboBox:!editable:on, QComboBox::drop-down:editable:on {\n"
"    background: white;\n"
"}\n"
"\n"
"\n"
"QComboBox:on { /* shift the text when the popup opens */\n"
"    padding-top: 3px;\n"
"    padding-left: 4px;\n"
"}"));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(640, 451, 141, 42));
        label_8->setStyleSheet(QLatin1String("QLabel{\n"
"border-image: url(:/images/Label.png);\n"
"}"));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(30, 600, 345, 61));
        label_7->setStyleSheet(QLatin1String("QLabel{\n"
"border-image: url(:/images/DisplayGraph.png);\n"
"}"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(420, 500, 381, 111));
        label->setStyleSheet(QLatin1String("QLabel{\n"
"border-image: url(:/images/Label_Group.png);\n"
"}"));
        btnCollapse = new QPushButton(centralWidget);
        btnCollapse->setObjectName(QStringLiteral("btnCollapse"));
        btnCollapse->setGeometry(QRect(390, 50, 21, 21));
        btnCollapse->setStyleSheet(QStringLiteral("border-image: url(:/images/red_minus_sign.png);"));
        btnExpand = new QPushButton(centralWidget);
        btnExpand->setObjectName(QStringLiteral("btnExpand"));
        btnExpand->setGeometry(QRect(390, 20, 21, 21));
        btnExpand->setStyleSheet(QStringLiteral("border-image: url(:/images/green_plus_sign.png);"));
        MainWindow->setCentralWidget(centralWidget);
        label->raise();
        label_7->raise();
        label_8->raise();
        label_6->raise();
        label_5->raise();
        label_4->raise();
        treeWidget->raise();
        bntDisplayPie->raise();
        bntDisplayBar->raise();
        bntDisplayLine->raise();
        bntDisplayScatter->raise();
        label_3->raise();
        dateEdit->raise();
        dateEdit_2->raise();
        btnDates->raise();
        lblMax_1->raise();
        lblMax_2->raise();
        lblMin_1->raise();
        lblMin_2->raise();
        labelHyp_1->raise();
        labelHyp_2->raise();
        maxText_1->raise();
        maxText_2->raise();
        minText_1->raise();
        minText_2->raise();
        pushButton->raise();
        comboBox->raise();
        btnCollapse->raise();
        btnExpand->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 850, 21));
        menuFIle = new QMenu(menuBar);
        menuFIle->setObjectName(QStringLiteral("menuFIle"));
        menuSave_Graph = new QMenu(menuFIle);
        menuSave_Graph->setObjectName(QStringLiteral("menuSave_Graph"));
        menuOptions = new QMenu(menuBar);
        menuOptions->setObjectName(QStringLiteral("menuOptions"));
        menuWindow = new QMenu(menuBar);
        menuWindow->setObjectName(QStringLiteral("menuWindow"));
        menuView = new QMenu(menuWindow);
        menuView->setObjectName(QStringLiteral("menuView"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menuFIle->menuAction());
        menuBar->addAction(menuOptions->menuAction());
        menuBar->addAction(menuWindow->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFIle->addAction(actionOpen);
        menuFIle->addAction(actionSaveDashboard);
        menuFIle->addAction(menuSave_Graph->menuAction());
        menuSave_Graph->addSeparator();
        menuSave_Graph->addAction(actionSave_Bar_Graph);
        menuSave_Graph->addAction(actionSave_Pie_Chart);
        menuSave_Graph->addAction(actionSave_Line_Graph);
        menuSave_Graph->addAction(actionSave_Scatter_Plot);
        menuOptions->addAction(actionPreferences);
        menuWindow->addAction(menuView->menuAction());
        menuView->addAction(actionDashboard);
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
        actionSaveDashboard->setText(QApplication::translate("MainWindow", "Save Dashboard", 0));
        actionPreferences->setText(QApplication::translate("MainWindow", "Preferences", 0));
        actionContents->setText(QApplication::translate("MainWindow", "Contents", 0));
        actionIndex->setText(QApplication::translate("MainWindow", "Index", 0));
        actionReport_BUg->setText(QApplication::translate("MainWindow", "Report BUg", 0));
        actionReport_Bug->setText(QApplication::translate("MainWindow", "Report Bug", 0));
        actionSave_Bar_Graph->setText(QApplication::translate("MainWindow", "Save Bar Graph", 0));
        actionSave_Pie_Chart->setText(QApplication::translate("MainWindow", "Save Pie Chart", 0));
        actionSave_Line_Graph->setText(QApplication::translate("MainWindow", "Save Line Graph", 0));
        actionSave_Scatter_Plot->setText(QApplication::translate("MainWindow", "Save Scatter Plot", 0));
        actionDashboard->setText(QApplication::translate("MainWindow", "Dashboard", 0));

        const bool __sortingEnabled = treeWidget->isSortingEnabled();
        treeWidget->setSortingEnabled(false);
        treeWidget->setSortingEnabled(__sortingEnabled);

        bntDisplayPie->setText(QString());
        bntDisplayBar->setText(QString());
        bntDisplayLine->setText(QString());
        bntDisplayScatter->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "\"Publications.csv\"", 0));
        btnDates->setText(QString());
        lblMax_1->setText(QApplication::translate("MainWindow", "MAX", 0));
        lblMax_2->setText(QApplication::translate("MainWindow", "MAX", 0));
        lblMin_1->setText(QApplication::translate("MainWindow", "MIN", 0));
        lblMin_2->setText(QApplication::translate("MainWindow", "MIN", 0));
        labelHyp_1->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        labelHyp_2->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        label_4->setText(QString());
        label_5->setText(QString());
        label_6->setText(QString());
        pushButton->setText(QString());
        label_8->setText(QString());
        label_7->setText(QString());
        label->setText(QString());
        btnCollapse->setText(QString());
        btnExpand->setText(QString());
        menuFIle->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuSave_Graph->setTitle(QApplication::translate("MainWindow", "Save Graph", 0));
        menuOptions->setTitle(QApplication::translate("MainWindow", "Options", 0));
        menuWindow->setTitle(QApplication::translate("MainWindow", "Window", 0));
        menuView->setTitle(QApplication::translate("MainWindow", "View", 0));
        menuTools->setTitle(QApplication::translate("MainWindow", "Tools", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
