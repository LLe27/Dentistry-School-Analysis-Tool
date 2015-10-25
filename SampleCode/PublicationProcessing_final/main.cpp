/*
 * Test method for PublicationProcessing.COLUMN_AUTHORS
 *
 * Author(s): Kevin Stubbs
 */
#include <iostream>
#include "PublicationProcessing.h"
#include "parsetestFTN.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    //load data (parsetestFTN is just a temp function I threw together from parsetest)
    string filename = "Publications_sample.csv";
    vector<vector<string>> data = parsetestFTN::loadData(filename);

    //process data by constructing PublicationProcessing
    PublicationProcessing* p = new PublicationProcessing(data);

    /*
     * Print dashboard (verbose)
     */
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





    cout << "SUCCESS!" << endl;
    exit(EXIT_SUCCESS);
}
