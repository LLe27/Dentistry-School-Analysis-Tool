#include <vector>
#include <string>
#include <cctype>

using namespace std;

/*TODO: These names make sense?? */
enum publicationField {vm_name, vp_domain, vp_status, vp_type, vs_date, vrole, vauthor, vjn_pi_bt, vtitle};
enum CSVType {pubType, presType, teachType, fundType};

class myData {

private:
	vector<vector<string>> *publications, *teaching, *funding, *presentations;

public:
    myData();

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
    vector<vector<string >> parseTeaching(string filePath);
    vector<vector<string >> parseFunding(string filePath);
    vector<vector<string >> parsePresentations(string filePath);
    vector<vector<string >> parsePublications(string filePath);



    /* Invert the prased vector */
    vector<vector<string>> invertVector(vector<vector<string>> myVector);

    /* Error subsets */
    vector<vector<int>> getErrors(CSVType type);
    void changeField(int myField, int userNumber, CSVType type, string newMsg);


	/* Read and create the CSV */
	bool createParsePublications(string filePath);
	bool createParseTeaching(string filePath);
	bool createParseFunding(string filePath);
	bool createParsePresentations(string filePath);

	/* Check if the respective CSV has been loaded */
	bool isPublications();
	bool isTeaching();
	bool isFunding();
	bool isPresentations();

	/* Read Publications*/
#if 0
	string * readPublications(publicationField, int entryNum);
#endif

};
