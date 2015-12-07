/*
 * Child to CSVProcessing. Contains query methods for grants.
 *
 * Author(s): Kevin Stubbs
 */
#include "GrantProcessing.h"

using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Constructor(s)
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

GrantProcessing::GrantProcessing(string filename, int csvtype) : CSVProcessing(filename, csvtype) {
    //note that data, memberNames, and memberNamesIndices are assigned in the super-constructor

    //populate list of types and its indices
    populateTypes();

    //populate list of roles and its indices
    populateRoles();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Public Functions
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

vector<string> GrantProcessing::getListOfTypes() {
    return types;
}

vector<string> GrantProcessing::getListOfRoles() {
    return roles;
}

vector<int> GrantProcessing::getIndicesType(string type) {
    return getIndicesType(type,allInd);
}

//uses stored type indices
vector<int> GrantProcessing::getIndicesType(string type, vector<int> indToConsider) {
    //get type ind or return empty vector
    int indType = -1;
    for (unsigned int i=0; i<types.size(); i++) {
        if (types.at(i)==type) {
            indType = i;
            break;
        }
    }
    if (indType==-1) return {};

    //retrurn intersect between known type indicies and indToConsider
    return getIndicesIntersect( typesIndices.at(indType) , indToConsider );
}

vector<int> GrantProcessing::getIndicesStatus(string status) {
    return getIndicesStatus(status,allInd);
}

vector<int> GrantProcessing::getIndicesStatus(string status, vector<int> indToConsider) {
    return getIndicesIntersect( getColumnMatch(COLUMN_STATUS,status) , indToConsider );
}

vector<int> GrantProcessing::getIndicesPeerReviewed() {
    return getIndicesPeerReviewed(allInd);
}

vector<int> GrantProcessing::getIndicesPeerReviewed(vector<int> indToConsider) {
    return getIndicesIntersect( getColumnMatch(COLUMN_PEER_REVIEWED,"True") , indToConsider );
}

vector<int> GrantProcessing::getIndicesIndustry() {
    return getIndicesIndustry(allInd);
}

vector<int> GrantProcessing::getIndicesIndustry(vector<int> indToConsider) {
    return getIndicesIntersect( getColumnMatch(COLUMN_INDUSTRY,"True") , indToConsider );
}

vector<int> GrantProcessing::getIndicesRole(string role) {
    return getIndicesRole(role,allInd);
}

vector<int> GrantProcessing::getIndicesRole(string role, vector<int> indToConsider) {
    //get role ind or return empty vector
    int indRole = -1;
    for (unsigned int i=0; i<roles.size(); i++) {
        if (roles.at(i)==role) {
            indRole = i;
            break;
        }
    }
    if (indRole==-1) return {};

    //retrurn intersect between known type indicies and indToConsider
    return getIndicesIntersect( rolesIndices.at(indRole) , indToConsider );
}

vector<int> GrantProcessing::getIndicesAmount(int minAmount, int maxAmount) {
    return getIndicesAmount(minAmount,maxAmount,allInd);
}

double GrantProcessing::getAmount(int index) {
    int Str_index = 0;
   string str = data.at(COLUMN_AMOUNT).at(index);
   str.erase(str.begin() + 0);

   for(char& c: str ){
        if(c == ','){
            str.erase(str.begin() + Str_index);
        }
        Str_index++;
   }

   //cout << "Total: " <<str << endl;
   //cout << "A Total" <<atof(str.c_str()) << endl;

   return atof(str.c_str());
}

vector<int> GrantProcessing::getIndicesAmount(int minAmount, int maxAmount, vector<int> indToConsider) {
    vector<int> result;
    for (int i : indToConsider) {
        if (grantsNumberWithinBounds(data.at(COLUMN_AMOUNT).at(i),minAmount,maxAmount)) result.push_back(i);
    }
    return result;
}

vector<int> GrantProcessing::getIndicesTitle(string title) {
    return getIndicesTitle(title,allInd);
}

vector<int> GrantProcessing::getIndicesTitle(string title, vector<int> indToConsider) {
    //NOTE: uses getColumnContains rather than getColumnMatch
    return getIndicesIntersect( getColumnContains(COLUMN_TITLE,title) , indToConsider );
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Private Functions
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void GrantProcessing::populateTypes() {
    pair<vector<string>,vector<vector<int>>> uniqueType = getUniqueInColumn(COLUMN_TYPE);
    types = uniqueType.first;
    typesIndices = uniqueType.second;
}

void GrantProcessing::populateRoles() {
    pair<vector<string>,vector<vector<int>>> uniqueType = getUniqueInColumn(COLUMN_ROLE);
    roles = uniqueType.first;
    rolesIndices = uniqueType.second;
}
