/*
 * Child to CSVProcessing. Contains query methods for publications.
 *
 * Author(s): Kevin Stubbs
 */
#include "PublicationProcessing.h"
#include "parsetestFTN.h"
#include "../mainwindow.h"
#include "../lib/qcustomplot.h"

using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Constructor(s)
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

PublicationProcessing::PublicationProcessing(vector<vector<string>> data) : CSVProcessing(data) {
    //note that data, memberNames, and memberNamesIndices are assigned in the super-constructor

    //populate list of types and its indices
    populateTypes();

    //merge redundent types
    //we may or may not want to run this as it will merge:
    //FOR BETTER: "* Journal Article, Meta-Analysis, Review" into "Journal Article"
    //FOR WORSE?: "Books Edited" into "Books"
    mergeSimilarTypes();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Public Functions
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

vector<string> PublicationProcessing::getListOfTypes() {
    return types;
}

vector<int> PublicationProcessing::getIndicesStatus(string status) {
    return getIndicesStatus(status,allInd);
}

vector<int> PublicationProcessing::getIndicesStatus(string status, vector<int> indToConsider) {
    return getIndicesIntersect( getColumnMatch(COLUMN_STATUS,status) , indToConsider );
}

vector<int> PublicationProcessing::getIndicesType(string type) {
    return getIndicesType(type,allInd);
}

//uses stored type indices
vector<int> PublicationProcessing::getIndicesType(string type, vector<int> indToConsider) {
    //get type ind or return empty vector
    int indType = -1;
    for (int i=0; i<types.size(); i++) {
        if (types.at(i)==type) {
            indType = i;
            break;
        }
    }
    if (indType==-1) return {};

    //retrurn intersect between known type indicies and indToConsider
    return getIndicesIntersect( typesIndices.at(indType) , indToConsider );
}


void PublicationProcessing::makeGraph(MainWindow &w, QVector<double> yAxisData, QString title ) {
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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Private Functions
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PublicationProcessing::populateTypes() {
    pair<vector<string>,vector<vector<int>>> uniqueType = getUniqueInColumn(COLUMN_TYPE);
    types = uniqueType.first;
    typesIndices = uniqueType.second;
}

void PublicationProcessing::mergeSimilarTypes() {
    //Note: all types are unique so either t1 is found in t2 or the opposite, but not both

    /*
     * Find pairs for which t1 contains t2
     */
    string t1,t2;
    vector<int> pairs[2];
    for (int i=0; i<types.size(); i++) {
        //get type
        t1 = types.at(i);
        //type must have length
        if (t1.length()<=0) continue;
        //consider lower case
        transform(t1.begin(),t1.end(),t1.begin(),::tolower);

        for (int j=0; j<types.size(); j++) {
            //don't compare to self
            if (i==j) continue;
            //get type
            t2 = types.at(j);
            //type must have length
            if (t2.length()<=0) continue;
            //consider lower case
            transform(t2.begin(),t2.end(),t2.begin(),::tolower);

            //find type2 in type1
            if (t1.find(t2) != string::npos) {
                //MATCH FOUND
                pairs[0].push_back(i);
                pairs[1].push_back(j);
            }
        }
    }

    /*
     * Do merging of types indices
     */
    vector<int> toRemove;
    int indSource, indTarget;
    for (int i=0; i<pairs[0].size(); i++) {
        //keep whichever name is more common
        if (typesIndices.at(pairs[0].at(i)).size() > typesIndices.at(pairs[1].at(i)).size()) {
            indSource = pairs[1].at(i);
            indTarget = pairs[0].at(i);
        }
        else {
            indSource = pairs[0].at(i);
            indTarget = pairs[1].at(i);
        }

        //append source
        for (int j=0; j<typesIndices.at(indSource).size(); j++) {
            typesIndices.at(indTarget).push_back( typesIndices.at(indSource).at(j) );
        }

        //merge names (may want to comment out this step?)
        types.at(indTarget) += " & " + types.at(indSource);

        //mark source for delete
        toRemove.push_back(indSource);
    }

    /*
     * Delete source types
     */
    //first, sort
    sort(toRemove.begin(),toRemove.end());
    //second, remove (highest index to lowest index)
    for (int i=toRemove.size()-1; i>=0; i--) {
        typesIndices.erase(typesIndices.begin()+toRemove.at(i));
        types.erase(types.begin()+toRemove.at(i));
    }
}
