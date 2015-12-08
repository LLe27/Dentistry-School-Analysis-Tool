#include <vector>
#include <string>
#include <cctype>

using namespace std;

/* System Defines */
enum publicationField {vm_name, vp_domain, vp_status, vp_type, vs_date, vrole, vauthor, vjn_pi_bt, vtitle};
enum CSVType {pubType, presType, teachType, fundType};

/* MyData CSV2Vector Class */
class myData {
private:
	vector<vector<string>> *publications, *teaching, *funding, *presentations;

public:

    /* Default Constructor */
    myData();
    /* Static Teaching Headers Used to Identify Each Column*/
    vector<string> TeachingHeader = {"Member Name","Primary Domain","Start Date","End Date","Program",\
                                     "Type of Course / Activity","Geographical Scope","Course / Activity",\
                                     "Hours per Teaching Session or Week","Number of Teaching Sessions or Weeks",\
                                     "Total Hours"};
    vector<string> FundingHeader = {"Member Name","Primary Domain","Start Date","End Date","Funding Type","Status",\
                                    "Peer Reviewed?","Industry Grant?","Role","Title""Principal Investigator",\
                                    "Co-Investigators","Total Amount"};
    vector<string> PresHeader = {"Member Name","Primary Domain","Date","Type","Role","Title"};
    vector<string> PubHeader = {"Member Name","Primary Domain","Publication Status","Type","Status Date *",\
                                "Role *","Journal Name | Published In | Book Title | etc.""Author(s)",\
                                "Title"};

    /* Returns a vector of vectors of each column and row of the CSV
     * filePath: The Path of the File to be parsed 
     */
    vector<vector<string >> parseTeaching(string filePath);
    vector<vector<string >> parseFunding(string filePath);
    vector<vector<string >> parsePresentations(string filePath);
    vector<vector<string >> parsePublications(string filePath);
	
    /* Error subsets */
    vector<vector<int>> getErrors(CSVType type);
    void changeField(int myField, int userNumber, CSVType type, string newMsg);
    vector<vector<string>> getDatabaseCopy(CSVType type);

    /* An Enhanced Way of Parsing A given CSV. The CSV will be stored as a database 
     * filePath: The Path of the File to be parsed. 
     */
    bool createParsePublications(string filePath);
    bool createParseTeaching(string filePath);
    bool createParseFunding(string filePath);
    bool createParsePresentations(string filePath);

    /* Check if the respective CSV has been loaded. 
     * Returns true if the database has been initalized. 
     */
    bool isPublications();
    bool isTeaching();
    bool isFunding();
    bool isPresentations();
};
