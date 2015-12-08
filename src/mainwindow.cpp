//Necessary Includes
#include <QDate>
#include "mainwindow.h"
#include "../lib/nightcharts/nightcharts.h"
#include "../lib/nightcharts/nightchartswidget.h"
#include <iostream>
#include <math.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initialize();

    this->setWindowTitle("Dashboard");

    ui->treeWidget->sortByColumn(0,Qt::AscendingOrder);
    ui->treeWidget->setSortingEnabled(true);

    createHelpMenu();
    createActions();
    addComboBoxItems();

}

//Deletes UI after program stops
MainWindow::~MainWindow()
{
    delete ui;
}

//Add root to the tree (2 Columns)
void MainWindow::addTreeRoot(QTreeWidgetItem *treeBranch, QString name, QString description){
    treeBranch ->setText(0, name);
    treeBranch ->setText(1, description);
}

//Add root to the tree (3 Columns)
void MainWindow::addTreeRoot(QTreeWidgetItem *treeBranch, QString name, QString description, QString count){
treeBranch ->setText(0, name);
treeBranch ->setText(1, description);
treeBranch ->setText(2,count);
}


//Add leaf to tree
void MainWindow::addTreeChild(QTreeWidgetItem *parent,QString name,QString description){
    QTreeWidgetItem *treeItem = new QTreeWidgetItem();
    treeItem->setText(0,name);
    treeItem -> setText(1,description);
    parent ->addChild(treeItem);
}

void MainWindow::addComboBoxItems()
{
    vector<string> members;
    switch(csvtype)
    {
        case 1:
        {
            members = ((PublicationProcessing*)p)->getListOfMemberNames();
            break;
        }
        case 2:
        {
            members = ((TeachingProcessing*)p)->getListOfMemberNames();
            break;
        }
        case 3:
        {
            members = ((PresentationProcessing*)p)->getListOfMemberNames();
            break;
        }
        case 4:
        {
            members = ((GrantProcessing*)p)->getListOfMemberNames();
            break;
        }

    }
    ui->comboBox->addItem(QString::fromStdString("Total"));
    int i = 0;
    for(string member: members)
    {
        // Add member names to combobox
        ui->comboBox->addItem(QString::fromStdString(member));
        i++;
    }
    ui->comboBox->setCurrentText("Total");
}

void MainWindow::createActions()
{

    ui->bntDisplayBar->setStatusTip(tr("Bar Graph"));
    ui->bntDisplayScatter->setStatusTip(tr("Scatter Plot"));
    ui->bntDisplayPie->setStatusTip(tr("Pie Chart"));
    ui->bntDisplayLine->setStatusTip(tr("Line Graph"));

    ui->actionContents->setStatusTip(tr("Display help menu contents"));
    connect(ui->actionContents, SIGNAL(triggered()), this, SLOT(helpContents()));
    connect(ui->actionSaveDashboard, SIGNAL(triggered()), this, SLOT(saveDashboard()));
    connect(ui->actionDashboard, SIGNAL(triggered()), this, SLOT(viewDashboard()));
    connect(ui->actionSave_Bar_Graph, SIGNAL(triggered()), this, SLOT(saveBarGraph()));
    connect(ui->actionSave_Line_Graph, SIGNAL(triggered()), this, SLOT(saveLineGraph()));
    connect(ui->actionSave_Pie_Chart, SIGNAL(triggered()), this, SLOT(savePieChart()));
    connect(ui->actionSave_Scatter_Plot, SIGNAL(triggered()), this, SLOT(saveScatterPlot()));
    ui->menuHelp->addAction(ui->actionContents);
}

void MainWindow::createHelpMenu()
{
    tree = new QTreeWidget();
    tree->setWindowTitle("Help Menu");
    tree->setColumnCount(1);

    QStringList headers;
    headers << " ";
    tree->setHeaderLabels(headers);
    tree->clear();

    QTreeWidgetItem* item = new QTreeWidgetItem(tree);
    QTreeWidgetItem* item2 = new QTreeWidgetItem(tree);
    QTreeWidgetItem* item3 = new QTreeWidgetItem(tree);
    QTreeWidgetItem* item4 = new QTreeWidgetItem(tree);

    item->setText(0, (QString)"Opening a CSV file");
    item2->setText(0, (QString)"Navigating the Dashboard");
    item3->setText(0, (QString)"Choosing a Graph");
    item4->setText(0, (QString)"Printing");

    QTreeWidgetItem* item5 = new QTreeWidgetItem(item);
    item5->setText(0, (QString)"Choosing a File");
    QTreeWidgetItem* item6 = new QTreeWidgetItem(item);
    item6->setText(0, (QString)"Fixing Errors");

    QTreeWidgetItem* item7 = new QTreeWidgetItem(item5);
    item7->setText(0, (QString)"First choose the type of CSV file you would like to\n"
                               "open (Teachings, Publications, Grants, or Presentations).\n"
                               "To open a CSV file, click on file->open\n"
                               "from the menubar at the top of the window.");

    QTreeWidgetItem* item8 = new QTreeWidgetItem(item6);
    item8->setText(0, (QString)"If there are more than 10 errors in the CSV file, a separate\n"
                               "window will pop up prompting you to fix those errors. After Fixing\n"
                               "the appropriate errors, choose the display options and then you may\n"
                               "save the changes and/or open it up in the dashboard.");

    item5 = new QTreeWidgetItem(item2);
    item5->setText(0, (QString)"To navigate through the dashboard, first "
                               "select the date range for the records you\n"
                               "would like to view and then click 'Enter Dates'.\n"
                               "Click on the +/- buttons to expand and collapse categories.\n"
                               "Click on a column to order the data according to that column.");

    item6 = new QTreeWidgetItem(item3);
    item6->setText(0, (QString)"To choose a graph, first click on the 'graph configuration'\n"
                               "button to choose your graph settings. Then click on the icon\n"
                               "for the graph you would like to view.");

    item7 = new QTreeWidgetItem(item4);
    item7->setText(0, (QString)"To print a graph simply click on the 'print graph' button \n"
                               "in the bottom right corner of the graph window.");


    tree->resize(600, 300);
}

void MainWindow::helpContents()
{
    tree->show();
}

QString MainWindow::on_actionOpen_triggered()
{
    //Returns file name of selected file in QFileDialog
    QString filename= QFileDialog::getOpenFileName(this, tr("Open File"),"C://","CSV File (*.csv);;All files (*.*)");

    return filename;
}



/*
 * on_bntDisplayBar_clicked()
 *
 * Description: This function runs when the bar graph button in the GUI is clicked. The first thing this
 * function does is collect relevant data from instance variables (start date, end date, csvtype, etc).
 * Then, this data is used to derive the proper parameters for the function
 * makeBarGraph(QVector<double> yAxisData, QString title, vector<string> barLabels). Lastly, our function
 * calls makeBarGraph with the proper data.
 *
 * Parameters:
 * none
 *
 * Output:
 * none
 */
void MainWindow::on_bntDisplayBar_clicked()
{
    int dayStart, monthStart, yearStart, dayEnd, monthEnd, yearEnd;
    dayStart = Startdate.day();
    monthStart = Startdate.month();
    yearStart = Startdate.year();
    dayEnd = Enddate.day();
    monthEnd = Enddate.month();
    yearEnd = Enddate.year();

    QVector<double> numItems;
    QString title = QString("%1-%2-%3 to %4-%5-%6").arg(dayStart).arg(monthStart).arg(yearStart).arg(dayEnd).arg(monthEnd).arg(yearEnd);

    //return as vector all of the possible types.
    vector<string> types;
    vector<int> indOther, indStatus, indMember;

    // Get Faculty Member
    const QString mem = ui->comboBox->currentText();
    string member  = mem.toStdString();

    // Narrow down the indeces to just show those of the member
    if(member == "Total")
    {
        // Get all the members
        indMember = indDate;
    }
    else  {
        indMember = p->getIndicesMemberName(member, indDate);
    }

    switch(csvtype)
    {
        case 1:
        {
        types = ((PublicationProcessing* )p)->getListOfTypes();
        for (string type: types) {
            numItems << ((PublicationProcessing *)p)->getIndicesType(type,indMember).size();
        }break;}

        case 2:
        {
        types = {"Postgraduate Medical Education","Continuing Medical Education", "Undergraduate Medical Education", "Other" };
        indOther = indMember;
        for (string type: types) {
            if(type != "Other")
                indStatus = ((TeachingProcessing*)p)->getIndicesProgram(type, indMember);

            // Remove indices from other that are assigned to one of the other categories
            indOther = remove_from_other(indOther, indStatus);
            if(type == "Other") numItems << indOther.size();
            else numItems << ((TeachingProcessing *)p)->getIndicesProgram(type, indMember).size();
        }break;}

        case 3:
        {
        types = ((PresentationProcessing*)p)->getListOfTypes();
        for (string type: types) {
            numItems << ((PresentationProcessing *)p)->getIndicesType(type,indMember).size();
        }break;}

        case 4:
        {
        types = ((GrantProcessing*)p)->getListOfTypes();
        for (string type: types) {
            numItems << ((GrantProcessing *)p)->getIndicesType(type,indMember).size();
        }break;}
     }

    makeBarGraph(numItems, title, types);

}




/*
 * on_bntDisplayPie_clicked()
 *
 * Description: This function runs when the pie graph button in the GUI is clicked. The first thing this
 * function does is collect relevant data from an instance variable (csvtype). Then, this data is used
 * to derive the proper parameters for the function
 * makePie(QVector<double> pieData, QString title, vector<string> Labels ). Lastly, our function
 * calls makePie with the proper data.
 *
 * Parameters:
 * none
 *
 * Output:
 * none
 */
void MainWindow::on_bntDisplayPie_clicked()
{

    int dayStart, monthStart, yearStart, dayEnd, monthEnd, yearEnd;
    dayStart = Startdate.day();
    monthStart = Startdate.month();
    yearStart = Startdate.year();
    dayEnd = Enddate.day();
    monthEnd = Enddate.month();
    yearEnd = Enddate.year();

    QVector<double> numItems;
    vector<string> types;
    vector<int> indStatus, indOther, indMember;

    // Get Faculty Member
    const QString mem = ui->comboBox->currentText();
    string member  = mem.toStdString();

    // Narrow down the indeces to just show those of the member
    if(member == "Total")
    {
        // Get all the members
        indMember = indDate;
    }
    else  {
        indMember = p->getIndicesMemberName(member, indDate);
    }


    QString title = QString("%1-%2-%3 to %4-%5-%6").arg(dayStart).arg(monthStart).arg(yearStart).arg(dayEnd).arg(monthEnd).arg(yearEnd);

    switch(csvtype)
    {
        case 1:
        {
        types = ((PublicationProcessing* )p)->getListOfTypes();
        for (string type: types) {
            numItems << ((PublicationProcessing *)p)->getIndicesType(type,indMember).size();
        }break;}

        case 2:
        {
        types = {"Postgraduate Medical Education","Continuing Medical Education", "Undergraduate Medical Education", "Other" };
        indOther = indMember;
        for (string type: types) {
            if(type != "Other")
                indStatus = ((TeachingProcessing*)p)->getIndicesProgram(type, indMember);

            // Remove indices from other that are assigned to one of the other categories
            indOther = remove_from_other(indOther, indStatus);
            if(type == "Other") numItems << indOther.size();
            else numItems << ((TeachingProcessing *)p)->getIndicesProgram(type,indMember).size();
        }break;}

        case 3:
        {
        types = ((PresentationProcessing*)p)->getListOfTypes();
        for (string type: types) {
            numItems << ((PresentationProcessing *)p)->getIndicesType(type,indMember).size();
        }break;}

        case 4:
        {
        types = ((GrantProcessing*)p)->getListOfTypes();
        for (string type: types) {
            numItems << ((GrantProcessing *)p)->getIndicesType(type,indMember).size();
        }break;}
     }


    makePie(numItems, title, types);
}






/*
 * on_bntDisplayScatter_clicked()
 *
 * Description: This function runs when the scatter plot button in the GUI is clicked. The first thing this
 * function does is collect relevant data from instance variables (start date, end date, csvtype, etc).
 * Then, this data is used to derive the proper parameters for the function
 * makeScatter(QVector<double> xData, QVector<double> yData, QString title). Lastly, our function
 * calls makeScatter with the proper data.
 *
 * Parameters:
 * none
 *
 * Output:
 * none
 */
void MainWindow::on_bntDisplayScatter_clicked()
{

    // Make the graph
    int dayStart, monthStart, yearStart, dayEnd, monthEnd, yearEnd;
    dayStart = Startdate.day();
    monthStart = Startdate.month();
    yearStart = Startdate.year();
    dayEnd = Enddate.day();
    monthEnd = Enddate.month();
    yearEnd = Enddate.year();

    QVector<double> xData;
    QVector<double> yData;
    QString title = QString("%1-%2-%3 to %4-%5-%6").arg(dayStart).arg(monthStart).arg(yearStart).arg(dayEnd).arg(monthEnd).arg(yearEnd);

    //return as vector all of the possible types.
    vector<string> types;
    vector<int> indDate2;
    vector<int> indStatus, indOther, indMember;

    // Get Faculty Member
    const QString mem = ui->comboBox->currentText();
    string member  = mem.toStdString();




    double yearTotal = 0;
    for (int i = yearStart; i <= yearEnd; i++)
    {
        // Get all Indeces for the current year
        indDate2 = p->getIndicesDate(1,1,i,31,12,i);
        // Narrow down the indeces to just show those of the member
        if(member == "Total")
        {
            // Get all the members
            indMember = indDate2;
        }
        else  {
            indMember = p->getIndicesMemberName(member, indDate2);
        }

        switch(csvtype)
        {
            // Publications
            case 1:
            {

                types = ((PublicationProcessing *)p)->getListOfTypes();
                xData.push_back(i);
                yearTotal = 0;
                for (unsigned int j = 0; j < types.size(); j++) {
                    yearTotal += ((PublicationProcessing *)p)->getIndicesType(types.at(j),indMember).size();
                }
                yData.push_back(yearTotal);
                break;
            }

            // Teaching
            case 2:
            {

                xData.push_back(i);
                yearTotal = 0;
                types = {"Postgraduate Medical Education","Continuing Medical Education", "Undergraduate Medical Education", "Other" };
                for (string type: types) {
                    if (type != "Other") {
                        indStatus = ((TeachingProcessing*)p)->getIndicesProgram(type, indMember);
                    }

                    indOther = remove_from_other(indOther, indStatus);
                    if(type == "Other") yearTotal += indOther.size();
                    else yearTotal += ((TeachingProcessing *)p)->getIndicesProgram(type,indMember).size();
                }
                yData.push_back(yearTotal);
                break;

            }

            // Presentations
            case 3:
            {

                types = ((PresentationProcessing *)p)->getListOfTypes();
                xData.push_back(i);
                yearTotal = 0;
                for (unsigned int j = 0; j < types.size(); j++) {
                    yearTotal += ((PresentationProcessing *)p)->getIndicesType(types.at(j), indMember).size();
                }
                yData.push_back(yearTotal);
                break;

            }

            // Grants
            case 4:
            {


                types = ((GrantProcessing *)p)->getListOfTypes();
                xData.push_back(i);
                yearTotal = 0;
                for (unsigned int j = 0; j < types.size(); j++) {
                    yearTotal += ((GrantProcessing *)p)->getIndicesType(types.at(j),indMember).size();
                }
                yData.push_back(yearTotal);
                break;

            }


         } // End Switch

    } // End For

    makeScatter(xData, yData, title);
}






/*
 * on_bntDisplayLine_clicked()
 *
 * Description: This function runs when the line graph button in the GUI is clicked. The first thing this
 * function does is collect relevant data from instance variables (start date, end date, csvtype, etc).
 * Then, this data is used to derive the proper parameters for the function
 * makeLine(QVector<double> xData, QVector<double> yDataMax, QVector<QVector<double>> yData,
 * QVector<QString> names, QString title). In order to obtain the yData, an extra step
 * is needed, which does not happen in the other graphs. The Y axis data (Number of Papers) is
 * divided into N categories(N could be 1, 3, or 4. The value of N depends on csvtype). We loop through
 * each Y data point and figure out which category it belongs to, and it is then put into one of N vectors.
 * Later, these will become N separate overlayed graphs on a single plot. Finally, our function can
 * call makeLine with the proper data.
 *
 * Parameters:
 * none
 *
 * Output:
 * none
 */
void MainWindow::on_bntDisplayLine_clicked()
{
    // Make the graph
    int dayStart, monthStart, yearStart, dayEnd, monthEnd, yearEnd;
    dayStart = Startdate.day();
    monthStart = Startdate.month();
    yearStart = Startdate.year();
    dayEnd = Enddate.day();
    monthEnd = Enddate.month();
    yearEnd = Enddate.year();

    QVector<double> xData;
    QVector<double> yDataMax;

    QVector<QVector<double>> yData; // To hold yData for each of the different statuses/programs etc...

    QString title = QString("%1-%2-%3 to %4-%5-%6").arg(dayStart).arg(monthStart).arg(yearStart).arg(dayEnd).arg(monthEnd).arg(yearEnd);


    vector<string> statuses;
    //vector<string> types;
    vector<int> indDate2, indStatus, indOther, indMember;

    // Get Faculty Member
    const QString mem = ui->comboBox->currentText();
    string member  = mem.toStdString();

    // Publications vectors
    QVector<double> yDataA;
    QVector<double> yDataP;
    QVector<double> yDataO;
    QVector<double> yDataS;
    QVector<QString> names;


    for (int i = yearStart; i <= yearEnd; i++)
    {
        xData.push_back(i);

        // Get all Indeces for the current year
        indDate2 = ((PublicationProcessing *)p)->getIndicesDate(1,1,i,31,12,i);

        // Narrow down the indeces to just show those of the member
        if(member == "Total")
        {
            // Get all the members
            indMember = indDate2;
        }
        else  {
            indMember = p->getIndicesMemberName(member, indDate2);
        }

        indOther = indMember;

        switch(csvtype)
        {
            case 1:
            {
                double maxY = 0;
                double yearTotal = 0;
                statuses = {"Published","Accepted / In Press","Submitted","Other"};

                for(string status: statuses)
                {
                    if(status != "Other") {
                        indStatus = ((PublicationProcessing*)p)->getIndicesStatus(status, indMember);
                    }
                    // Remove from indOther the indeces that belong to a status
                    indOther = remove_from_other(indOther, indStatus);
                    if(status == "Other") yearTotal = indOther.size();
                    else yearTotal = indStatus.size();
                    if (yearTotal > maxY) maxY = yearTotal; // Find maxY value

                    yDataMax.push_back(maxY);

                    // Store the y Data for a particular program for a certain year
                    if (status == "Other") yDataO.push_back(yearTotal);
                    else if (status == "Published") yDataP.push_back(yearTotal);
                    else if(status == "Accepted / In Press") yDataA.push_back(yearTotal);
                    else if (status == "Submitted") yDataS.push_back(yearTotal);

                    if(!names.contains(QString::fromStdString(status)))
                        names.push_back(QString::fromStdString(status));

                }
                break;

            } // end case1

            case 2:
            {
                double maxY = 0;
                double yearTotal = 0;
                statuses = {"Postgraduate Medical Education","Continuing Medical Education", "Undergraduate Medical Education", "Other"};


                for(string status: statuses)
                {
                    if(status != "Other") {
                        indStatus = ((PublicationProcessing*)p)->getIndicesStatus(status, indMember);
                    }
                    // Remove from indOther the indeces that belong to a status
                    indOther = remove_from_other(indOther, indStatus);
                    if(status == "Other") yearTotal = indOther.size();
                    else yearTotal = indStatus.size();
                    if (yearTotal > maxY) maxY = yearTotal; // Find maxY value

                    yDataMax.push_back(maxY);

                    // Store the y Data for a particular program for a certain year
                    if (status == "Other") yDataO.push_back(yearTotal);
                    else if (status == "Postgraduate Medical Education") yDataP.push_back(yearTotal);
                    else if(status == "Continuing Medical Education") yDataA.push_back(yearTotal);
                    else if (status == "Undergraduate Medical Education") yDataS.push_back(yearTotal);

                    if(!names.contains(QString::fromStdString(status)))
                        names.push_back(QString::fromStdString(status));

                }
                break;

            } // end case2
            case 3:
            {
                double yearTotal = 0;
                string status = "Presentations";
                vector<string> types = ((PresentationProcessing*)p)->getListOfTypes();
                for(string type: types)
                {
                    yearTotal += ((PresentationProcessing*)p)->getIndicesType(type, indMember).size();
                }
                yDataMax.push_back(yearTotal);
                yDataP.push_back(yearTotal);
                if(!names.contains(QString::fromStdString(status)))
                    names.push_back(QString::fromStdString(status));
                break;

            } // end case3

            case 4:
            {
                double maxY = 0;
                (void) maxY;
                double yearTotal = 0;
                string status = "All Grants";
                vector<string> types = ((GrantProcessing*)p)->getListOfTypes();

                for(string type: types)
                {
                    yearTotal += ((GrantProcessing*)p)->getIndicesType(type, indMember).size();
                }
                yDataMax.push_back(yearTotal);
                yDataP.push_back(yearTotal);

                if(!names.contains(QString::fromStdString(status)))
                    names.push_back(QString::fromStdString(status));


                break;

            } // end case4
        } // end switch

    } // End For

    switch(csvtype)
    {
        case 1: case 2: {
            yData.push_back(yDataP);
            yData.push_back(yDataA);
            yData.push_back(yDataS);
            yData.push_back(yDataO);
        }

        case 3: {
            yData.push_back(yDataP);
        }
        case 4: {
            yData.push_back(yDataP);
            yData.push_back(yDataA);
            yData.push_back(yDataO);

        }


    }


    makeLine(xData, yDataMax, yData, names, title);
}
vector<int> MainWindow::remove_from_other(vector<int> indOther, vector<int> indStatus)
{
    //remove from other
    //remove things from indOther so that indOther is the set of papers that are within the date range, but
    //do NOT have the correct status.
    for (int iStat : indStatus) {
        for (int i=indOther.size()-1; i>=0; i--) {
            if (iStat==indOther.at(i)) {
                indOther.erase(indOther.begin()+i);
            }
        }
    }
    return indOther;
}

void MainWindow::on_btnCollapse_clicked() {
    ui->treeWidget->collapseAll();
}

void MainWindow::on_btnExpand_clicked() {
    ui->treeWidget->expandAll();
}

void MainWindow::on_btnDates_clicked()
{
    QDate date1 = (ui->dateEdit->date());
    QDate date2 = (ui->dateEdit_2->date());
    QString dateString1 = date1.toString("yyyy/MM/dd");
    QString dateString2 = date2.toString("yyyy/MM/dd");
    QString dateString3 = date1.toString("MMM/yyyy");
    QString dateString4 = date2.toString("MMM/yyyy");
    QStringList ColumnNames;
    ColumnNames << dateString3 + " " + dateString4;
    ui->treeWidget->setHeaderLabels(ColumnNames);
    Startdate = date1;
    Enddate = date2;
    indDate = p->getIndicesDate(Startdate.day(),Startdate.month(),Startdate.year(),Enddate.day(),Enddate.month(),Enddate.year());

    ui->treeWidget->clear();
    drawDashboard();

}

/*
 * makePie
 *
 * Description: This function makes a pie chart using the data, title, and labels sent in as parameters.
 * This function uses the Night Charts code library to make the pie chart.
 *
 * Parameters:
 * Param 1: pieData: The quantities to be expressed in the pie graph. Note that each double in this QVector
 * must be divided by the sum in order to obtain percentages.
 * Param 2: title: title of the window.
 * Param 3: Labels: The labels associated with each quantity in pieData. These labels are displayed in the
 * legend on the left side of the window.
 *
 * Output:
 * none
 */
void MainWindow::makePie(QVector<double> pieData, QString title, vector<string> Labels ) {


    QVector<QString> pieLabels;

    for (unsigned int i = 0; i < Labels.size(); i++) {
        pieLabels << Labels.at(i).c_str();
    }

    QVBoxLayout* layout = new QVBoxLayout;



    // Compute minimum & maximum height to show all labels
    int height=30*pieLabels.size();
    if (height < 320) height = 320;
    else if (height > 800) height = 800;

    // Create window
    QWidget * window = new QWidget();
    window->resize(520, height);
    window->show();
    window->setWindowTitle(title);  // Set the title of the window
    window->setAttribute( Qt::WA_DeleteOnClose );  // Delete the window when closed
    window->setLayout(layout);


    PieChart = new NightchartsWidget(window);
    PieChart->clear();
    PieChart->setType(Nightcharts::Pie);//{Histogramm,Pie,DPie};
    PieChart->resize(520, height);

    // Compute sum of data - to convert values to %
    double sum=0;
    for (int i=0; i<pieData.size(); i++) sum += pieData.at(i);
    if (sum == 0) sum=1;  // Prevent divide by 0 if pie slice data adds to 0

    // Reset RGB values so cycle through the colors
    int red = 0;
    int green = 0;
    int blue = 0;

    // Add data to pie (as %), and add label to pie, and compute unique color
    for (int i=0; i<pieData.size(); i++) {
        red = (red + 57) % 255;
        green = (green + 97) % 255;
        blue = (blue + 137) % 255;
        PieChart->addItem(QString(pieLabels.at(i)),QColor(red,green,blue),static_cast<float>(pieData.at(i)*100/sum));
    }

    // Show the pie
    PieChart->show();

}







/*
 * makeBarGraph
 *
 * Description: This function displays a bar graph using the parameters sent in.
 *
 * Parameters:
 * Param 1: yAxisData: The height of each bar.
 * Param 2: title: The title of the bar graph.
 * Param 3: barLabels: These labels will go on the x axis, below each bar.
 *
 * Output:
 * none
 */
void MainWindow::makeBarGraph(QVector<double> yAxisData, QString title, vector<string> barLabels ) {
    QRect rec = QApplication::desktop()->screenGeometry();
     int height = rec.height();
     int width = rec.width();

    barcustomPlot = new QCustomPlot();
    barcustomPlot->show();
    barcustomPlot->setGeometry(100, 100, width-200, height-200);

    QCPBars *myBars = new QCPBars(barcustomPlot->xAxis, barcustomPlot->yAxis);
    barcustomPlot->addPlottable(myBars);
        myBars->setName("this is the name");


    QVector<double> xAxisPositions;
    QVector<QString> xAxisLabels;

    for (unsigned int i = 0; i < barLabels.size(); i++) {
        xAxisPositions << i;
        xAxisLabels << barLabels.at(i).c_str();
    }

    barcustomPlot->xAxis->setAutoTicks(false);
    barcustomPlot->xAxis->setAutoTickLabels(false);
    barcustomPlot->xAxis->setTickVector(xAxisPositions);
    barcustomPlot->xAxis->setTickVectorLabels(xAxisLabels);
    barcustomPlot->xAxis->setTickLabelRotation(60);
    barcustomPlot->xAxis->setSubTickCount(0);
    barcustomPlot->xAxis->setTickLength(0, 4);
    barcustomPlot->xAxis->grid()->setVisible(true);
    barcustomPlot->xAxis->setRange(-1, barLabels.size()+1);  // Set min and max tick value (one beyond either end)

    barcustomPlot->yAxis->setRange(0, 12.1);
    barcustomPlot->yAxis->setPadding(5);

    if(csvtype == 1)
        barcustomPlot->yAxis->setLabel("Number of Publications");
    else if(csvtype == 2)
        barcustomPlot->yAxis->setLabel("Number of Teaching items");
    else if(csvtype == 3)
        barcustomPlot->yAxis->setLabel("Number of Presentations");
    else if(csvtype == 4)
        barcustomPlot->yAxis->setLabel("Number of Grants");


    barcustomPlot->yAxis->grid()->setSubGridVisible(true);

    //find the maximum y value.
    int yMax = yAxisData.at(0);
    for(int yDataIndex=0; yDataIndex < yAxisData.size(); yDataIndex++) {
        if (yAxisData.at(yDataIndex) > yMax) yMax = yAxisData.at(yDataIndex);
    }

    createOptimalYAxis(barcustomPlot, yMax);

    QPen gridPen;
    gridPen.setStyle(Qt::SolidLine);
    gridPen.setColor(QColor(0, 0, 0, 25));
    barcustomPlot->yAxis->grid()->setPen(gridPen);
    gridPen.setStyle(Qt::DotLine);
    barcustomPlot->yAxis->grid()->setSubGridPen(gridPen);


    barcustomPlot->legend->setVisible(false);

    barcustomPlot->yAxis->setPadding(25); // Add space to the left of the Y axis title
    barcustomPlot->yAxis2->setPadding(25); // Add space to the left of the Y axis title

    // Set the title
    barcustomPlot->plotLayout()->insertRow(0); // inserts an empty row above the default axis rect

    if(csvtype == 1)
            barcustomPlot->plotLayout()->addElement(0, 0, new QCPPlotTitle(barcustomPlot, "Number of Publications From " + title));
    else if(csvtype == 2)
            barcustomPlot->plotLayout()->addElement(0, 0, new QCPPlotTitle(barcustomPlot, "Number of Teaching Items From " + title));
    else if(csvtype == 3)
            barcustomPlot->plotLayout()->addElement(0, 0, new QCPPlotTitle(barcustomPlot, "Number of Presentations From " + title));
    else if(csvtype == 4)
            barcustomPlot->plotLayout()->addElement(0, 0, new QCPPlotTitle(barcustomPlot, "Number of Grants From " + title));

    myBars->setData(xAxisPositions, yAxisData);

    barcustomPlot->yAxis->rescale();
    barcustomPlot->replot();
}






/*
 * makeScatter
 *
 * Description: This function displays the data points that are sent in as parameters.
 *
 * Parameters:
 * Param 1: xData: The x coordinates of all data points
 * Param 2: yData: The y coordinates of all data points
 * Param 3: title: The title of the scatter plot
 *
 * Output:
 * none
 */
void MainWindow::makeScatter(QVector<double> xData, QVector<double> yData, QString title ) {

    QRect rec = QApplication::desktop()->screenGeometry();
     int height = rec.height();
     int width = rec.width();
     double xRangeMinimum, yRangeMinimum, xRangeMaximum, yRangeMaximum;

    scattercustomPlot = new QCustomPlot();
    scattercustomPlot->show();
    //set window size based on screen size
    scattercustomPlot->setGeometry(100, 100, width-200, height-200);
    // Tell QscattercustomPlot to show dots, but not lines
    scattercustomPlot->addGraph();
    scattercustomPlot->graph(0)->setLineStyle(QCPGraph::lsNone);
    scattercustomPlot->graph(0)->setPen(QPen(Qt::blue)); // line color blue for first graph

    // add title
    scattercustomPlot->plotLayout()->insertRow(0);

    if(csvtype == 1)
        scattercustomPlot->plotLayout()->addElement(0, 0, new QCPPlotTitle(scattercustomPlot, "Number of Publications From " + title));
    else if(csvtype == 2)
        scattercustomPlot->plotLayout()->addElement(0, 0, new QCPPlotTitle(scattercustomPlot, "Number of Teaching Items From " + title));
    else if(csvtype == 3)
        scattercustomPlot->plotLayout()->addElement(0, 0, new QCPPlotTitle(scattercustomPlot, "Number of Presentations From " + title));
    else if(csvtype == 4)
        scattercustomPlot->plotLayout()->addElement(0, 0, new QCPPlotTitle(scattercustomPlot, "Number of Grants From " + title));

    //set the graph to a scatter plot
    scattercustomPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4));
    scattercustomPlot->graph(0)->setName(title);

    //find minimum and maximum x values.
    int xMax = xData.at(0);
    int xMin = xData.at(0);
    for(int xDataIndex=0; xDataIndex < xData.size(); xDataIndex++) {
        if (xData.at(xDataIndex) < xMin) xMin = xData.at(xDataIndex);
        if(xData.at(xDataIndex) > xMax)  xMax = xData.at(xDataIndex);
    }

    //find minimum and maximum y values.
    int yMax = yData.at(0);
    int yMin = yData.at(0);
    for(int yDataIndex=0; yDataIndex < yData.size(); yDataIndex++) {
        if (yData.at(yDataIndex) < yMin) yMin = yData.at(yDataIndex);
        if (yData.at(yDataIndex) > yMax) yMax = yData.at(yDataIndex);
    }

    // pass the data points to the scatter plot
    scattercustomPlot->graph()->setData(xData, yData);

    // Add up to 2 years gap to min of X range
    if(xMin < 2) xRangeMinimum = 0;
    else xRangeMinimum = xMin - 2;

    // Add up to 2 years gap to max of X range (up to current year)
    int currentYear = QDate::currentDate().year();
    if(currentYear - xMax < 2)
    {
        if(currentYear - xMax == 1)
            xRangeMaximum = currentYear;
        else if(currentYear - xMax == 0)
            xRangeMaximum = currentYear + 0.5;
    }
    else
        xRangeMaximum = xMax + 2;

    //set the x axis tick labels
    scattercustomPlot->xAxis->setAutoTickStep(false);
    scattercustomPlot->xAxis->setTickStep(2);
    scattercustomPlot->xAxis->setTickLengthIn(5);
    scattercustomPlot->xAxis->setAutoSubTicks(false);
    scattercustomPlot->xAxis->setSubTickCount(1);
    scattercustomPlot->xAxis->setSubTickLengthIn(5);


    //set the x axis label
    scattercustomPlot->xAxis->setLabel("Years");

    //set the x axis range
    scattercustomPlot->xAxis->setRange(xRangeMinimum, xRangeMaximum);

    createOptimalYAxis(scattercustomPlot, yMax-yMin);

    //set the y axis to be larger than the maximum y value
    if(yMin < 2)
    {
        if(yMin == 1)
            yRangeMinimum = 0;
        else if (yMin == 0)
            yRangeMinimum = -0.8;
    }
    else
        yRangeMinimum = yMin - 2;

    yRangeMaximum = yMax + 2;

    //set the y axis label
    if(csvtype == 1)
        scattercustomPlot->yAxis->setLabel("Number of Publications");
    else if(csvtype == 2)
        scattercustomPlot->yAxis->setLabel("Number of Teaching items");
    else if(csvtype == 3)
        scattercustomPlot->yAxis->setLabel("Number of Presentations");
    else if(csvtype == 4)
        scattercustomPlot->yAxis->setLabel("Number of Grants");

    //set the y axis range
    scattercustomPlot->yAxis->setRange(yRangeMinimum, yRangeMaximum);

    //draw scatter plot
    scattercustomPlot->replot();
}







/*
 * makeLine
 *
 * Description: This function creates a line graph. This function creates N overlayed graphs on a single plot, each
 * having it's own colour. A legend is created, to indicate what each colour represents. Note that N could
 * be 1, 3, or 4. The value of N depends on csvtype.
 *
 * Parameters:
 * Param 1: xData: The x coordinates of the data points.
 * Param 2: yDataMax: This vector contains the highest y coordinates for each of the N overlayed graphs.
 * Param 3: yData: This vector contains N vectors, each of which contains the y coordinates for one of the overlayed graphs.
 * Param 4: names: This vector contains N descriptions for what each overlayed graph(and colour) represent.
 * Param 5: title: The title of the plot.
 *
 */
void MainWindow::makeLine(QVector<double> xData, QVector<double> yDataMax,
                          QVector<QVector<double>> yData, QVector<QString> names, QString title ) {

    QRect rec = QApplication::desktop()->screenGeometry();
    int height = rec.height();
    int width = rec.width();
    double xRangeMinimum, yRangeMinimum, xRangeMaximum, yRangeMaximum;
    QPen pen;

    linecustomPlot = new QCustomPlot();

    linecustomPlot->show();
    //set window size based on screen size
    linecustomPlot->setGeometry(100, 100, width-200, height-200);
    // Tell QCustomPlot to show dots, but not lines

    int red = 0;
    int green = 0;
    int blue = 0;

    int i = 0;
    for(QString name: names)
    {
        // Get a random colour
        red = (red + 57) % 255;
        green = (green + 97) % 255;
        blue = (blue + 137) % 255;

        // pass the data points to the scatter plot
        linecustomPlot->addGraph();
        linecustomPlot->graph()->setName(name);
        QColor *color = new QColor(red, green, blue);

        pen.setColor(*color);
        linecustomPlot->graph()->setPen(pen);
        linecustomPlot->graph()->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4));
        linecustomPlot->graph()->setData(xData, yData.at(i));

        i++;
    }

    linecustomPlot->legend->setVisible(true);

    // add title
    linecustomPlot->plotLayout()->insertRow(0);

    if(csvtype == 1)
        linecustomPlot->plotLayout()->addElement(0, 0, new QCPPlotTitle(linecustomPlot, "Number of Publications From " + title));
    else if(csvtype == 2)
        linecustomPlot->plotLayout()->addElement(0, 0, new QCPPlotTitle(linecustomPlot, "Number of Teaching Items From " + title));
    else if(csvtype == 3)
        linecustomPlot->plotLayout()->addElement(0, 0, new QCPPlotTitle(linecustomPlot, "Number of Presentations From " + title));
    else if(csvtype == 4)
        linecustomPlot->plotLayout()->addElement(0, 0, new QCPPlotTitle(linecustomPlot, "Number of Grants From " + title));


    //find minimum and maximum x values.
    int xMax = xData.at(0);
    int xMin = xData.at(0);
    for(int xDataIndex=0; xDataIndex < xData.size(); xDataIndex++) {
        if (xData.at(xDataIndex) < xMin) xMin = xData.at(xDataIndex);
        if (xData.at(xDataIndex) > xMax)  xMax = xData.at(xDataIndex);
    }

    //find minimum and maximum y values.
    int yMax = yDataMax.at(0);
    int yMin = yDataMax.at(0);
    for(int yDataIndex=0; yDataIndex < yDataMax.size(); yDataIndex++) {
        if (yDataMax.at(yDataIndex) < yMin) yMin = yDataMax.at(yDataIndex);
        if (yDataMax.at(yDataIndex) > yMax) yMax = yDataMax.at(yDataIndex);
    }


    // Add up to 2 years gap to min of X range
    if(xMin < 2) xRangeMinimum = 0;
    else xRangeMinimum = xMin - 2;

    // Add up to 2 years gap to max of X range (up to current year)
    int currentYear = QDate::currentDate().year();
    if(currentYear - xMax < 2)
    {
        if(currentYear - xMax == 1)
            xRangeMaximum = currentYear;
        else if(currentYear - xMax == 0)
            xRangeMaximum = currentYear + 0.5;
    }
    else
        xRangeMaximum = xMax + 2;

    //set the x axis tick labels
    linecustomPlot->xAxis->setAutoTickStep(false);
    linecustomPlot->xAxis->setTickStep(2);
    linecustomPlot->xAxis->setTickLengthIn(5);
    linecustomPlot->xAxis->setAutoSubTicks(false);
    linecustomPlot->xAxis->setSubTickCount(1);
    linecustomPlot->xAxis->setSubTickLengthIn(5);


    //set the x axis label
    linecustomPlot->xAxis->setLabel("Years");

    //set the x axis range
    linecustomPlot->xAxis->setRange(xRangeMinimum, xRangeMaximum);

    createOptimalYAxis(linecustomPlot, yMax-yMin);

    //set the y axis to be larger than the maximum y value
    if(yMin < 2)
    {
        if(yMin == 1)
            yRangeMinimum = 0;
        else if (yMin == 0)
            yRangeMinimum = -0.8;
    }
    else
        yRangeMinimum = yMin - 2;

    yRangeMaximum = yMax + 2;

    //set the y axis label
    if(csvtype == 1)
        linecustomPlot->yAxis->setLabel("Number of Publications");
    else if(csvtype == 2)
        linecustomPlot->yAxis->setLabel("Number of Teaching items");
    else if(csvtype == 3)
        linecustomPlot->yAxis->setLabel("Number of Presentations");
    else if(csvtype == 4)
        linecustomPlot->yAxis->setLabel("Number of Grants");

    //set the y axis range
    linecustomPlot->yAxis->setRange(yRangeMinimum, yRangeMaximum);

    //draw scatter plot
    linecustomPlot->replot();

}

void MainWindow::PaletteSwap(QColor color){
        QPalette Pal(palette());
        Pal.setColor(QPalette::Background, color);
        MainWindow::setAutoFillBackground(true);
        MainWindow::setPalette(Pal);
}

void MainWindow::initialize(){
    s = new StartUp(this);
//    s->setStyleSheet("background-color:rgb(68,50,102);");
    QPalette Pal(palette());
    string filename;
    QColor color(195,195,229,255);
    Pal.setColor(QPalette::Background, color);
    QColor wcolor(255, 255, 255,255);
    PaletteSwap(wcolor);
    s->setAutoFillBackground(true);
    s->setPalette(Pal);
    s->show();


    if(s->exec() == QDialog::Accepted) {
        csvtype = s->getCsvType();
        if(csvtype > 0){

        filename = on_actionOpen_triggered().toStdString();





    //These will only be for CSV's that reuire additional input for indicie queries

    //Min text box
    ui->minText_1->setVisible(false);
    ui->minText_2->setVisible(false);

    //Hypens
    ui->labelHyp_1->setVisible(false);
    ui->labelHyp_2->setVisible(false);

    //Max text box
    ui->maxText_1->setVisible(false);
    ui->maxText_2->setVisible(false);

    //Min label
    ui->lblMin_1->setVisible(false);
    ui->lblMin_2->setVisible(false);

    //Max label
    ui->lblMax_1->setVisible(false);
    ui->lblMax_2->setVisible(false);

    QStringList ColumnNames;


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    switch(csvtype){
        //Publications
        case(1):
            p = new PublicationProcessing(filename,csvtype);
            ui->treeWidget->setColumnCount(2);
            ColumnNames << " " << "Total";
            ui->label_2->setText(QString::fromStdString("Publications"));
            break;
        //Teaching
        case(2):
            p = new TeachingProcessing(filename, csvtype);
            ui->treeWidget->setColumnCount(3);
            ColumnNames << " " << "Hours" << "Students";

            //Min text box
            ui->minText_1->setVisible(true);
            ui->minText_2->setVisible(true);

            ui->minText_1->setText(QString::number(0));
            ui->minText_2->setText(QString::number(0));
            ui->label_2->setText(QString::fromStdString("Teaching"));

            //Hypens
            ui->labelHyp_1->setText("------------Hours------------");
            ui->labelHyp_2->setText("------------Students------------");

            ui->labelHyp_1->setVisible(true);
            ui->labelHyp_2->setVisible(true);

            //Max text box
            ui->maxText_1->setVisible(true);
            ui->maxText_2->setVisible(true);

            ui->maxText_1->setText(QString::number(100));
            ui->maxText_2->setText(QString::number(100));

            //Min label
            ui->lblMin_1->setVisible(true);
            ui->lblMin_2->setVisible(true);

            //Max label
            ui->lblMax_1->setVisible(true);
            ui->lblMax_2->setVisible(true);
            break;

        //Presentations
        case(3):
            p = new PresentationProcessing(filename,csvtype);
            ui->treeWidget->setColumnCount(2);
            ColumnNames << " " << "#of \npresentations" ;
            ui->label_2->setText(QString::fromStdString("Presentations"));
            break;

        //Grants
        case(4):
            p = new GrantProcessing(filename, csvtype);
            ui->treeWidget->setColumnCount(3);
            ColumnNames << " " << "Total#" << "Total$" ;

            ui->minText_1->setVisible(true);
            ui->maxText_1->setVisible(true);
            ui->labelHyp_1->setText("------------Amount------------");
            ui->labelHyp_1->setVisible(true);
            ui->lblMin_1->setVisible(true);
            ui->lblMax_1->setVisible(true);

            ui->minText_1->setText(QString::number(0));
            ui->maxText_1->setText(QString::number(10));
            ui->label_2->setText(QString::fromStdString("Grants"));

            break;
        default:
            ui->treeWidget->setColumnCount(3);
            //CSV is not of the four types
        }


    //Read in list of Column Names to set the column Names
    ui->treeWidget->setHeaderLabels(ColumnNames);
    ui->treeWidget->setColumnWidth(0,300);
    ui->treeWidget->setColumnWidth(1,80);
    ui->treeWidget->setColumnWidth(2,300);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    ui->dateEdit->setMaximumDate(QDate::currentDate());
    ui->dateEdit_2->setMaximumDate(QDate::currentDate());

    ui->dateEdit->setDate(p->earliestDate());
    ui->dateEdit_2->setDate(QDate::currentDate());

    on_btnDates_clicked();
        }
    }


    else{
          //None Work.....
          close();
          QApplication::closeAllWindows();
          QApplication::quit();
    }
}


void MainWindow::drawDashboard(){

    switch(csvtype){
        case(1):{
        vector<string> types = ((PublicationProcessing *)p)->getListOfTypes();
        string statuses[] = {"Published","Accepted / In Press","Submitted","Other"};
        vector<int> indStatus, indStatusType, indStatusTypeMember;
        vector<int> indOther = indDate;
        vector<string> members = p->getListOfMemberNames();
        int count;

        QTreeWidgetItem *treeRoot = new QTreeWidgetItem(ui->treeWidget);
        addTreeRoot(treeRoot,"Publications", QString::number(indDate.size()));

        for (string status : statuses) {

            if (status == "Other") indStatus = indOther;
            //get the subset of indices where the paper is of the status specified and is in the date range specified.
            else indStatus = ((PublicationProcessing *)p)->getIndicesStatus(status,indDate);
            count = indStatus.size();

            QTreeWidgetItem *treeBranch = new QTreeWidgetItem();
            treeRoot->addChild(treeBranch);
              addTreeRoot(treeBranch,QString::fromStdString(status),QString::number(count));

              //remove from other
              //remove things from indOther so that indOther is the set of papers that are within the date range, but
              //do NOT have the correct status.
              for (int iStat : indStatus) {
                  for (int i=indOther.size()-1; i>=0; i--) {
                      if (iStat==indOther.at(i)) {
                          indOther.erase(indOther.begin()+i);
                      }
                  }
              }

              if (count) {
                for (string type : types) {
                    indStatusType = ((PublicationProcessing *)p)->getIndicesType(type,indStatus);
                    if (type.length()<1) type = "Unspecified"; // rename the blank type
                    count = indStatusType.size();
                    if (count) {
                        QTreeWidgetItem *treeItem = new QTreeWidgetItem();
                        treeBranch->addChild(treeItem);
                        addTreeRoot(treeItem,QString::fromStdString(type),QString::number(count));

                        for (string member : members) {

                            indStatusTypeMember = p->getIndicesMemberName(member,indStatusType);
                            count = indStatusTypeMember.size();
                            if (count) {
                                if (member.length()<1) member = "Unspecified"; //rename blank member
                               QTreeWidgetItem *treeChild = new QTreeWidgetItem();
                               treeItem->addChild(treeChild);
                               treeChild->setText(0,QString::fromStdString(member));
                               treeChild -> setText(1,QString::number(count));
                            }
                        }
                    }
                }
            }

        }

    }break;

    case(2):{
        vector<string> members = p->getListOfMemberNames();
        vector<int> indProgram,indHours, indStudents, indProgramMember;
        vector<int> indOther = indDate;
        int hoursTotal,hoursProg,hoursMember;
        int students;
        string programs[] = {"Postgraduate Medical Education","Continuing Medical Education", "Undergraduate Medical Education", "Other" };

        indHours = ((TeachingProcessing *)p)->getIndicesHours(ui->minText_1->text().toInt(),ui->maxText_1->text().toInt(),indDate);
        for(unsigned int i =0;i < indHours.size(); i++){
            hoursTotal += ((TeachingProcessing *)p)->getHours(indHours.at(i));
        } // Testing to see if populates
        indStudents = ((TeachingProcessing *)p)->getIndicesStudents(ui->minText_2->text().toInt(),ui->maxText_2->text().toInt(),indDate);
        students = indStudents.size();

        QTreeWidgetItem *treeRoot = new QTreeWidgetItem(ui->treeWidget);
        addTreeRoot(treeRoot,"Teaching",QString::number(hoursTotal), QString::number(students));

        for(string program : programs){
            hoursProg = 0;
            if (program == "Other") indProgram = indOther;
            //get the subset of indices where the paper is of the status specified and is in the date range specified.
            else indProgram = ((TeachingProcessing *)p)->getIndicesProgram(program,indDate);

            indHours = ((TeachingProcessing *)p)->getIndicesHours(ui->minText_1->text().toInt(),ui->maxText_1->text().toInt(),indProgram);
            for(unsigned int i =0;i < indHours.size(); i++){
                hoursProg += ((TeachingProcessing *)p)->getHours(indHours.at(i));
            } // Testing to see if populates
            indStudents = ((TeachingProcessing *)p)->getIndicesStudents(ui->minText_2->text().toInt(),ui->maxText_2->text().toInt(),indProgram);
            students = indStudents.size();

            //remove from other
            //remove things from indOther so that indOther is the set of papers that are within the date range, but
            //do NOT have the correct status.
            for (int iProg : indProgram) {
                for (int i=indOther.size()-1; i>=0; i--) {
                    if (iProg==indOther.at(i)) {
                        indOther.erase(indOther.begin()+i);
                    }
                }
            }

            QTreeWidgetItem *treeProgram = new QTreeWidgetItem();
            addTreeRoot(treeProgram, QString::fromStdString(program), QString::number(hoursProg), QString::number(students));
            treeRoot->addChild(treeProgram);

            for(string member: members){
                hoursMember = 0;
                indProgramMember = p->getIndicesMemberName(member,indProgram);

                indHours = ((TeachingProcessing *)p)->getIndicesHours(ui->minText_1->text().toInt(),ui->maxText_1->text().toInt(),indProgramMember);
                for(unsigned int i =0;i < indHours.size(); i++){
                    hoursMember += ((TeachingProcessing *)p)->getHours(indHours.at(i));
                } // Testing to see if populates
                indStudents = ((TeachingProcessing *)p)->getIndicesStudents(ui->minText_2->text().toInt(),ui->maxText_2->text().toInt(),indProgramMember);
                students = indStudents.size();
                if(hoursMember){
                     if (member.length()<1) member = "Unspecified"; //rename blank member
                     QTreeWidgetItem *treeProgramMember = new QTreeWidgetItem();
                     treeProgramMember->setText(0,QString::fromStdString(member));
                     treeProgramMember->setText(1,QString::number(hoursMember));
                     treeProgramMember->setText(2,QString::number(students));
                     treeProgram->addChild(treeProgramMember);

                }
            }
       }
    }

            break;
    case(3):{
        vector<string> types = ((PresentationProcessing *)p)->getListOfTypes();
        vector<int> indType, indTypeMember;
        vector<string> members = p->getListOfMemberNames();
        vector<int> indOther = indDate;
        int count;

        QTreeWidgetItem *treeRoot = new QTreeWidgetItem(ui->treeWidget);
        addTreeRoot(treeRoot,"Presentations", QString::number(indDate.size()));

        for(string type: types ){
            if (type == "Other"){indType = indOther;}
            else{ indType = ((PresentationProcessing *)p)->getIndicesType(type,indDate);}
            count = indType.size();

            QTreeWidgetItem *treeBranch = new QTreeWidgetItem();
            addTreeRoot(treeBranch,QString::fromStdString(type),QString::number(count));
            treeRoot->addChild(treeBranch); 

            if(count){
                for(string member : members){
                    indTypeMember = p->getIndicesMemberName(member,indType);
                    if(member.length()<1) type = "Unspecified";
                    count = indTypeMember.size();

                    if(count){
                        QTreeWidgetItem *treeItem = new QTreeWidgetItem();
                        treeItem->setText(0,QString::fromStdString(member));
                        treeItem->setText(1,QString::number(count));
                        treeBranch->addChild(treeItem);
                    }
                }
            }

        }}
            break;
    case(4):{
        vector<string> types = ((GrantProcessing *)p)->getListOfTypes();
        vector<int> indType, indAmount, indPeer, indInd, indPMember, indIMember;
        vector<string> members = p->getListOfMemberNames();
        vector<int> indOther = indDate;
        int count;
        double amountType,amountTypePeer,amountTypeInd,amountPeerMember,amountIndMember;

        //Gets the indices of that type and date
        for(string type : types){
            amountType = 0;
            amountTypePeer = 0;
            amountTypeInd = 0;
            amountPeerMember = 0;
            amountIndMember = 0;

            if(type == "Other") indType = indOther;
            else indType = ((GrantProcessing *)p)->getIndicesType(type,indDate);
            count = indType.size();

            //Calculate amount
            indAmount = ((GrantProcessing*) p)->getIndicesAmount(ui->minText_1->text().toInt(),ui->maxText_1->text().toInt(),indType);
            for(unsigned int i = 0; i <  indAmount.size(); i++){
                amountType += ((GrantProcessing*)p)->getAmount((indAmount.at(i)));
            }

            QTreeWidgetItem *treeRoot = new QTreeWidgetItem(ui->treeWidget);
            addTreeRoot(treeRoot,QString::fromStdString(type),QString::number(count),"$" + QString::number(amountType,'f',2));

            //Gets the indicies for all peer review
            indPeer = ((GrantProcessing *)p)->getIndicesPeerReviewed(indType);
            count = indPeer.size();

            indAmount = ((GrantProcessing*) p)->getIndicesAmount(ui->minText_1->text().toInt(),ui->maxText_1->text().toInt(),indPeer);
            for(unsigned int i = 0; i <  indAmount.size(); i++){
                amountTypePeer += ((GrantProcessing*)p)->getAmount(indAmount.at(i));
            }
            QTreeWidgetItem *treePeer =new QTreeWidgetItem();
            addTreeRoot(treePeer,"Peer Reviewed",QString::number(count),"$" + QString::number(amountTypePeer,'f',2));

            treeRoot->addChild(treePeer);

            //Getthe indicies for all Industry
            indInd = ((GrantProcessing *)p)->getIndicesIndustry(indType);
            count = indInd.size();

            indAmount = ((GrantProcessing*) p)->getIndicesAmount(ui->minText_1->text().toInt(),ui->maxText_1->text().toInt(),indInd);
            for(unsigned int i = 0; i <  indAmount.size(); i++){
                amountTypeInd += ((GrantProcessing*)p)->getAmount(indAmount.at(i));
            }
            QTreeWidgetItem *treeInd =new QTreeWidgetItem();
            addTreeRoot(treeInd,"Industry Sponsored",QString::number(count),("$" + QString::number(amountTypeInd,'f',2)));

            treeRoot->addChild(treeInd);

            for(string member: members){
                amountPeerMember = 0;
                amountIndMember = 0;

               indPMember = p->getIndicesMemberName(member,indPeer);
               count = indPMember.size();
               //amount claculation
               indAmount = ((GrantProcessing*) p)->getIndicesAmount(ui->minText_1->text().toInt(),ui->maxText_1->text().toInt(),indPMember);
               for(unsigned int i = 0; i <  indAmount.size(); i++){
                   amountPeerMember += ((GrantProcessing*)p)->getAmount(indAmount.at(i));
               }
             if(count){
                 if (member.length()<1) member = "Unspecified"; //rename blank member
                   QTreeWidgetItem *treePeerMember =new QTreeWidgetItem();
                   treePeerMember->setText(0,QString::fromStdString(member));
                   treePeerMember->setText(1,QString::number(count));
                   treePeerMember->setText(2,"$" + QString::number(amountPeerMember,'f',2));
                   treePeer->addChild(treePeerMember);
            }

                   indIMember = p->getIndicesMemberName(member,indInd);
                   count = indIMember.size();
                   //amount calculation
                   indAmount = ((GrantProcessing*) p)->getIndicesAmount(ui->minText_1->text().toInt(),ui->maxText_1->text().toInt(),indIMember);
                   for(unsigned int i = 0; i <  indAmount.size(); i++){
                       amountIndMember += ((GrantProcessing*)p)->getAmount(indAmount.at(i));
                   }
               if(count){
                   if (member.length()<1) member = "Unspecified"; //rename blank member
                   QTreeWidgetItem *treeIndMember =new QTreeWidgetItem();
                   treeIndMember->setText(0,QString::fromStdString(member));
                   treeIndMember->setText(1,QString::number(count));
                   treeIndMember->setText(2,"$" + QString::number(amountIndMember,'f',2));
                   treeInd->addChild(treeIndMember);
                }
            }



        }



    }
            break;
    default:{}

    }//End Switch

}



/*
 * createOptimalYAxis
 *
 * Description: This function uses the range of Y data to create a Y axis that
 * is asthetically appealing, and easy to read. If the data range is 2000 or less, the
 * numerical distance between ticks is set manually. If the data range exceeds 2000, then
 * it is set automatically using pre built methods in QCustomPlot.
 *
 * Parameters:
 * Param 1: customPlot: This is a QCustomPlot object. A QCustomPlot object represents a
 * graph, and all it's components. The parameter customPlot is the graph that will
 * have its y axis created.
 * Param 2: range: This variable represents the difference between the highest and lowest
 * y coordinates of data points on the graph.
 *
 * Output:
 * none
 */
void MainWindow::createOptimalYAxis(QCustomPlot * customPlot, int range)
{
    if(range <= 10)
    {
        customPlot->yAxis->setAutoTickStep(false);
        customPlot->yAxis->setTickStep(1);
        customPlot->yAxis->setTickLengthIn(5);
        customPlot->yAxis->setAutoSubTicks(false);
        customPlot->yAxis->setSubTickCount(0);
    }
    else if ((range > 10) && (range <= 300))
    {
        customPlot->yAxis->setAutoTickStep(false);
        customPlot->yAxis->setTickStep(5);
        customPlot->yAxis->setTickLengthIn(5);
        customPlot->yAxis->setAutoSubTicks(false);
        customPlot->yAxis->setSubTickCount(4);
        customPlot->yAxis->setSubTickLengthIn(5);
    }
    else if ((range > 300) && (range <= 1000))
    {
        customPlot->yAxis->setAutoTickStep(false);
        customPlot->yAxis->setTickStep(20);
        customPlot->yAxis->setTickLengthIn(5);
        customPlot->yAxis->setAutoSubTicks(false);
        customPlot->yAxis->setSubTickCount(3);
        customPlot->yAxis->setSubTickLengthIn(5);
    }
    else if ((range > 1000) && (range <= 2000))
    {
        customPlot->yAxis->setAutoTickStep(false);
        customPlot->yAxis->setTickStep(50);
        customPlot->yAxis->setTickLengthIn(5);
        customPlot->yAxis->setAutoSubTicks(false);
        customPlot->yAxis->setSubTickCount(4);
        customPlot->yAxis->setSubTickLengthIn(5);
    }
    else
    {
        customPlot->yAxis->setAutoTickStep(true);
        customPlot->yAxis->setTickLengthIn(5);
        customPlot->yAxis->setAutoSubTicks(false);
        customPlot->yAxis->setSubTickCount(0);
    }
}


void MainWindow::on_pushButton_clicked()
{
    initialize();
}
void MainWindow::saveBarGraph()
{
    // Create graph if not created already
    if(barcustomPlot->hasHeightForWidth()) {
           on_bntDisplayBar_clicked();
         barcustomPlot->close();
    }
    barcustomPlot->grab().save(QFileDialog::getSaveFileName(this, tr("Save File"),"C://","PNG File (*.png);;All files (*.*)"));
}
void MainWindow::savePieChart()
{
    if(PieChart->hasHeightForWidth()) {
           on_bntDisplayPie_clicked();
         PieChart->close();
    }
    PieChart->grab().save(QFileDialog::getSaveFileName(this, tr("Save File"),"C://","PNG File (*.png);;All files (*.*)"));
}
void MainWindow::saveScatterPlot()
{
    if(scattercustomPlot->hasHeightForWidth()) {
           on_bntDisplayScatter_clicked();
         scattercustomPlot->close();
    }
    scattercustomPlot->grab().save(QFileDialog::getSaveFileName(this, tr("Save File"),"C://","PNG File (*.png);;All files (*.*)"));
}
void MainWindow::saveLineGraph()
{
    if(linecustomPlot->hasHeightForWidth()) {
           on_bntDisplayLine_clicked();
         linecustomPlot->close();
    }
    linecustomPlot->grab().save(QFileDialog::getSaveFileName(this, tr("Save File"),"C://","PNG File (*.png);;All files (*.*)"));
}

// Duplicates the tree in a new window and saves it
// If save is set
void MainWindow::duplicateDashboard(int save)
{

    // Duplicate Dashboard
    QTreeWidget* tree1 = new QTreeWidget();

    tree1->setColumnCount(ui->treeWidget->columnCount());
    QStringList ColumnNames;
    QString Column;

    for(int i = 0; i < tree1->columnCount(); i++)
    {
        Column = ui->treeWidget->headerItem()->text(i);
        ColumnNames << Column;

    }
    tree1->setHeaderLabels(ColumnNames);

    tree1->sortByColumn(0,Qt::AscendingOrder);
    tree1->setSortingEnabled(true);

    QTreeWidgetItem* item;
    QTreeWidgetItem* item2;
    QTreeWidgetItem* item3;

    int height = 0;

    for(int i = 0; i < ui->treeWidget->topLevelItemCount(); i++)
    {
        height++;
        item = ui->treeWidget->topLevelItem(i);
        QTreeWidgetItem* itemnew = new QTreeWidgetItem(tree1);
        *itemnew = *item;
        if(item->isExpanded())
        {
            itemnew->setExpanded(true);
        }
        if(item->childCount() > 0)
        {
            for(int j = 0; j < item->childCount(); j++)
            {
                item2 = item->child(j);
                QTreeWidgetItem* itemnew2 = new QTreeWidgetItem(itemnew);
                *itemnew2 = *item2;
                if(item->isExpanded())
                {
                    height++;
                }
                if(item2->isExpanded())
                {
                    itemnew2->setExpanded(true);
                }
                if(item2->childCount() > 0)
                {
                    for(int k = 0; k < item2->childCount(); k++)
                    {
                        item3 = item2->child(k);
                        QTreeWidgetItem* itemnew3 = new QTreeWidgetItem(itemnew2);
                        *itemnew3 = *item3;
                        if(item2->isExpanded())
                        {
                            height++;
                        }
                        if(item3->isExpanded())
                        {
                            itemnew3->setExpanded(true);
                        }
                    }
                }
            }
        }
    }

    tree1->setColumnWidth(0, 250);
    tree1->setColumnWidth(1, 250);
    if(height < 10) {
        tree1->resize(700, 500);
    }
    else {
        tree1->resize(700,height*20);
    }

    // Save the Dashboard
    if(save) {
        tree1->grab().save(QFileDialog::getSaveFileName(this, tr("Save File"),"C://","PNG File (*.png);;All files (*.*)"));
    }
    else
        tree1->show();
}
void MainWindow::viewDashboard()
{
    // duplicate the dashboard without saving
    duplicateDashboard(0);
}
void MainWindow::saveDashboard()
{
    // duplicate the dashboard and save it
    duplicateDashboard(1);
}
