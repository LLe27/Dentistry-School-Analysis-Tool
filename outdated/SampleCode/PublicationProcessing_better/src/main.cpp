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
     * Query Test 1: get names of publication types (e.g., Journal Article)
     */
    cout << "QUERY TEST 1" << endl;
    vector<string> types = p->getTypes();

    /*
     * Query Test 2: print number of articles of each type
     */
    cout << "\n\nQUERY TEST 2" << endl;
    for (int i=0; i<types.size(); i++) {
        cout << i << " - " << types.at(i) << " - " << p->getCountAll(i) << endl;
    }

    /*
     * Query Test 3: print number of articles + each author set for published entries of the first type (Journal Articles)
     */
    cout << "\n\nQUERY TEST 3" << endl;
    int typeIndex = 0;
    cout << "Published " << types.at(typeIndex) << " (" << p->getCountPublished(typeIndex) << ")" << endl;
    for (string str : p->getAuthorsPublished(typeIndex)) {
        cout << "+" << str << endl;
    }

    /*
     * Query Test 4: print number of articles + each author set for submitted entries of all types
     *
     * Note: if no type index is given to the getters, all types are returned
     */
    cout << "\n\nQUERY TEST 4" << endl;
    cout << "All Submitted Entries (" << p->getCountSubmitted() << ")" << endl;
    for (string str : p->getAuthorsSubmitted()) {
        cout << "+" << str << endl;
    }

    cout << "SUCCESS!" << endl;
    exit(EXIT_SUCCESS);
}
