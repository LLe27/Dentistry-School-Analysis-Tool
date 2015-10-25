#include "mainwindow.h"
#include "../lib/qcustomplot.h"

#include <QFont>

void makeGraph(MainWindow &w, QVector<double> yAxisData, QString title ) {
    QCustomPlot *customPlot = w.findChild<QCustomPlot*>("myChart");

    QCPBars *myBars = new QCPBars(customPlot->xAxis, customPlot->yAxis);
    customPlot->addPlottable(myBars);
    //    myBars->setName("this is the name");

    QVector<double> xAxisPositions;
    QVector<QString> xAxisLabels;

    xAxisPositions
            << 1
            << 2
            << 3
            << 4
            << 5
            << 6
            << 7
            << 8
            << 9
            << 10
            << 11
            << 12
            << 13
            << 14
            << 15
            << 16
            << 17
            << 18
            << 19
            << 20
            << 21;

    xAxisLabels
            << "Book Chapters"
            << "Books"
            << "Books Edited"
            << "Case Reports"
            << "Clinical Care\nGuidelines"
            << "Commentaries"
            << "Conference\nProceedings"
            << "Editorials"
            << "Invited Articles"
            << "Journal Article"
            << "Letters to Editor"
            << "Magazine Entries"
            << "Manuals"
            << "Monographs"
            << "Multimedia"
            << "Newsletter Articles"
            << "Newspaper Articles"
            << "Published Abstract"
            << "Supervised Student Publications"
            << "Websites/Videos"
            << "Working Papers";

    customPlot->xAxis->setAutoTicks(false);
    customPlot->xAxis->setAutoTickLabels(false);
    customPlot->xAxis->setTickVector(xAxisPositions);
    customPlot->xAxis->setTickVectorLabels(xAxisLabels);
    customPlot->xAxis->setTickLabelRotation(60);
    customPlot->xAxis->setSubTickCount(0);
    customPlot->xAxis->setTickLength(0, 4);
    customPlot->xAxis->grid()->setVisible(true);
    customPlot->xAxis->setRange(0, 22);  // Set min and max tick value (one beyond either end)

    customPlot->yAxis->setRange(0, 12.1);
    customPlot->yAxis->setPadding(5);
    customPlot->yAxis->setLabel("number of articles");
    customPlot->yAxis->grid()->setSubGridVisible(true);

    QPen gridPen;
    gridPen.setStyle(Qt::SolidLine);
    gridPen.setColor(QColor(0, 0, 0, 25));
    customPlot->yAxis->grid()->setPen(gridPen);
    gridPen.setStyle(Qt::DotLine);
    customPlot->yAxis->grid()->setSubGridPen(gridPen);


    customPlot->legend->setVisible(false);
    /*
    customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    customPlot->legend->setBrush(QColor(255, 255, 255, 200));
    QPen legendPen;
    legendPen.setColor(QColor(130, 130, 130, 200));
    customPlot->legend->setBorderPen(legendPen);
    QFont legendFont = QFont("sanserif", 30);
    customPlot->legend->setFont(legendFont);
    customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
*/

    customPlot->yAxis->setPadding(25); // Add space to the left of the Y axis title
    customPlot->yAxis2->setPadding(25); // Add space to the left of the Y axis title

    // Set the title
    customPlot->plotLayout()->insertRow(0); // inserts an empty row above the default axis rect
    customPlot->plotLayout()->addElement(0, 0, new QCPPlotTitle(customPlot, title));

    myBars->setData(xAxisPositions, yAxisData);

    customPlot->yAxis->rescale();
    customPlot->replot();

}
