#include "mainwindow.h"
#include <QApplication>
#include <QString>
#include <string>
#include "publicationprocessing/parsetestFTN.h"
#include "publicationprocessing/PublicationProcessing.h"

//#include "marcgraph.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //load data (parsetestFTN is just a temp function I threw together from parsetest)
    string filename = "../Publications_sample.csv";
    vector<vector<string>> data = parsetestFTN::loadData(filename);

    //process data by constructing PublicationProcessing
    PublicationProcessing* p = new PublicationProcessing(data);

    /*
     * Print dashboard (verbose)
     */
    cout << "\n\n\nSTART OF TEST 1\n\n\n" << endl;
    vector<string> types = p->getListOfTypes();
    string statuses[] = {"Published", "Accepted / In Press", "Submitted"};
    vector<int> indStatus, indStatusType;
    int count;
    for (string status : statuses) {
        indStatus = p->getIndicesStatus(status);
        count = indStatus.size();
        cout << status << "(" << count << ")" << endl;
        if (count) {
            for (string type : types) {
                indStatusType = p->getIndicesType(type,indStatus);
                if (type.length()<1) type = "Unspecified"; // rename the blank type
                count = indStatusType.size();
                if (count) {
                    cout << "\t" << type << "(" << count << ")" << endl;
                    for (string str : p->toStringTest(indStatusType)) cout << "\t\t" << str << endl;
                }
            }
        }
    }

    /*
     * Print dashboard
     */
    cout << "\n\n\nSTART OF TEST 2\n\n\n" << endl;
    vector<int> indStatusTypeMember;
    vector<string> members = p->getListOfMemberNames();
    for (string status : statuses) {
        indStatus = p->getIndicesStatus(status);
        count = indStatus.size();
        cout << status << "(" << count << ")" << endl;
        if (count) {
            for (string type : types) {
                indStatusType = p->getIndicesType(type,indStatus);
                if (type.length()<1) type = "Unspecified"; // rename the blank type
                count = indStatusType.size();
                if (count) {
                    cout << "\t" << type << "(" << count << ")" << endl;
                    for (string member : members) {
                        indStatusTypeMember = p->getIndicesMemberName(member,indStatusType);
                        count = indStatusTypeMember.size();
                        if (count) {
                            if (member.length()<1) member = "Unspecified"; //rename blank member
                            cout << "\t\t" << member << "(" << count << ")" << endl;
                        }
                    }
                }
            }
        }
    }

    /*
     * Print dashboard from Jan 27 2005 to May 14 2010
     */
    cout << "\n\n\nSTART OF TEST 3\n\n\n" << endl;
    vector<int> indDate = p->getIndicesDate(27,1,2005,14,5,2010);
    for (string status : statuses) {
        indStatus = p->getIndicesStatus(status,indDate);
        count = indStatus.size();
        cout << status << "(" << count << ")" << endl;
        if (count) {
            for (string type : types) {
                indStatusType = p->getIndicesType(type,indStatus);
                if (type.length()<1) type = "Unspecified"; // rename the blank type
                count = indStatusType.size();
                if (count) {
                    cout << "\t" << type << "(" << count << ")" << endl;
                    for (string member : members) {
                        indStatusTypeMember = p->getIndicesMemberName(member,indStatusType);
                        count = indStatusTypeMember.size();
                        if (count) {
                            if (member.length()<1) member = "Unspecified"; //rename blank member
                            cout << "\t\t" << member << "(" << count << ")" << endl;
                        }
                    }
                }
            }
        }
    }

    cout << "SUCCESS!" << endl;

    // Make the graph
    MainWindow w;
    w.show();
    QVector<double> numItems;
    QString title = "my title";

    numItems
            << 35
            << 40
            << 23
            << 63
            << 51
            << 47
            << 60
            << 23
            << 25
            << 71
            << 59
            << 11
            << 35
            << 33
            << 32
            << 61
            << 28
            << 14
            << 27
            << 57
            << 12;

    p->makeGraph(w, numItems, title);

    return a.exec();
//    exit(EXIT_SUCCESS);

}
