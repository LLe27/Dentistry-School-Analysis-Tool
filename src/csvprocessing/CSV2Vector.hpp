#include <vector>
#include <string>
#include <cctype>

using namespace std;

/*TODO: These names make sense?? */
enum publicationField {vm_name, vp_domain, vp_status, vp_type, vs_date, vrole, vauthor, vjn_pi_bt, vtitle};
enum documentType {publications, teaching, funding, presentations};

class myData {

private:
	vector<vector<string>> *publications, *teaching, *funding, *presentations;
	vector<vector<string >> parseTeaching(string filePath);
	vector<vector<string >> parseFunding(string filePath);
	vector<vector<string >> parsePresentations(string filePath);

public:
    myData();

    vector<vector<string >> parsePublications(string filePath);
    void changePublicationField(publicationField myField, int userNumber, string newField);
    vector<vector<string >> getErrorPublications();
    vector<vector<string>> invertPublicationsVector();


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
