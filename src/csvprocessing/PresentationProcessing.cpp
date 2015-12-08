/*
 * Child to CSVProcessing. Contains query methods for presentation.
 *
 * Author(s): Kevin Stubbs
 */
#include "PresentationProcessing.h"

using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Constructor(s)
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

PresentationProcessing::PresentationProcessing(string filename, int csvtype) : CSVProcessing(filename, csvtype) {
    //note that data, memberNames, and memberNamesIndices are assigned in the super-constructor

    //populate list of types and its indices
    populateTypes();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Public Functions
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Returns all types in string format within a vector from presenations CSV
vector<string> PresentationProcessing::getListOfTypes() {
    return types;
}
//Get indicies of all roles within presentations CSV
vector<int> PresentationProcessing::getIndicesRole(string role) {
    return getIndicesRole(role,allInd);
}
//Get indicies of all roles within presentations CSV, vector output
vector<int> PresentationProcessing::getIndicesRole(string role, vector<int> indToConsider) {
    return getIndicesIntersect( getColumnMatch(COLUMN_ROLE,role) , indToConsider );
}
//Get indicies of all types within presentations CSV
vector<int> PresentationProcessing::getIndicesType(string type) {
    return getIndicesType(type,allInd);
}

//Get indicies of all types within presentations CSV, vector output
vector<int> PresentationProcessing::getIndicesType(string type, vector<int> indToConsider) {
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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Private Functions
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PresentationProcessing::populateTypes() {
    pair<vector<string>,vector<vector<int>>> uniqueType = getUniqueInColumn(COLUMN_TYPE);
    types = uniqueType.first;
    typesIndices = uniqueType.second;
} //Populate unique type, with all unique columns to indicate types

//END OF CLASS

