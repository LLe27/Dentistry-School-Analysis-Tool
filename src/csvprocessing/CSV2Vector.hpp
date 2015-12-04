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

    vector<vector<string >> parseTeaching(string filePath);
    vector<vector<string >> parseFunding(string filePath);
    vector<vector<string >> parsePresentations(string filePath);
    vector<vector<string >> parsePublications(string filePath);



    /* Invert the prased vector */
    vector<vector<string>> invertVector(vector<vector<string>> myVector);

    /* Error subsets */
    vector<vector<int>> getErrors(CSVType type);
    void changeField(int myField, int userNumber, CSVType type, string newMsg);
    vector<vector<string>> getDatabaseCopy(CSVType type);

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
