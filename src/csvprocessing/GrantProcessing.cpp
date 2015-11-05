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

GrantProcessing::GrantProcessing(string filename) : CSVProcessing(filename) {
    //note that data, memberNames, and memberNamesIndices are assigned in the super-constructor

    //populate list of types and its indices
    populateTypes();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Public Functions
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

vector<string> GrantProcessing::getListOfTypes() {
    return types;
}

vector<int> GrantProcessing::getIndicesType(string type) {
    return getIndicesType(type,allInd);
}

//uses stored type indices
vector<int> GrantProcessing::getIndicesType(string type, vector<int> indToConsider) {
    //get type ind or return empty vector
    int indType = -1;
    for (int i=0; i<types.size(); i++) {
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
    //TO DO
    return {};
}

vector<int> GrantProcessing::getIndicesPeerReviewed(vector<int> indToConsider) {
    //TO DO
    return {};
}

vector<int> GrantProcessing::getIndicesIndustry() {
    //TO DO
    return {};
}

vector<int> GrantProcessing::getIndicesIndustry(vector<int> indToConsider) {
    //TO DO
    return {};
}

vector<int> GrantProcessing::getIndicesRole(string role) {
    //TO DO
    return {};
}

vector<int> GrantProcessing::getIndicesRole(string role, vector<int> indToConsider) {
    //TO DO
    return {};
}

vector<int> GrantProcessing::getIndicesAmount(int minAmount, int maxAmount) {
    //TO DO
    return {};
}

vector<int> GrantProcessing::getIndicesAmount(int minAmount, int maxAmount, vector<int> indToConsider) {
    //TO DO
    return {};
}

vector<int> GrantProcessing::getIndicesTitle(string title) {
    //TO DO
    return {};
}

vector<int> GrantProcessing::getIndicesTitle(string title, vector<int> indToConsider) {
    //TO DO
    return {};
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Private Functions
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void GrantProcessing::populateTypes() {
    pair<vector<string>,vector<vector<int>>> uniqueType = getUniqueInColumn(COLUMN_TYPE);
    types = uniqueType.first;
    typesIndices = uniqueType.second;
}
