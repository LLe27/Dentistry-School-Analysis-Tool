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

    /*
     * At present,
     * 1. csv is loaded into a vector of string vectors "data" by parsetestFTN (a temporary function)
     * 2. "data" is processed during the creation of PublicationProcessing Object
     * 3. queries to the data may be made for all, published, submitted, and accepted entries
     * 4. a specific type (e.g., Journal Article) may be queried by including the type's index in the string
     *    vector returned by PublicationProcessing.getTypes()
     *
     * NOTE:
     * -At present, only authors and counts may be queried
     * -My intention is for other processing Objects (e.g., PresentationsProcessing) to also extend the CSVProcessing Object
     * -CSVProcessing contains helper functions which should make further functions much easier to implement
     * -Function descriptions are included in headers
     * -Variables in PublicationProcessingfor which there is a getter are populated once (not per call)
     *
     */

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
