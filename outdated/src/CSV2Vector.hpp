#include <vector>
#include <string>
#include <string>
#include <cctype>

using namespace std;

/*TODO: These names make sense?? */
enum publicationField {vm_name, vp_domain, vp_status, vp_type, vs_date, vrole, vauthor, vjn_pi_bt, vtitle};

class myData {

private:
	vector<vector<string>> *publications, *teaching, *funding, *presentations;
	vector<vector<string >> parsePublications(string filePath);
	vector<vector<string >> parseTeaching(string filePath);
	vector<vector<string >> parseFunding(string filePath);
	vector<vector<string >> parsePresentations(string filePath);

public:
	void myData();

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
	string * readPublications(publicationField, int entryNum);

};
