/*
 * Child to CSVProcessing. Contains query methods for publications.
 */
#include "TeachingProcessing.h"

using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Constructor(s)
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TeachingProcessing::TeachingProcessing(string filename, int csvtype) : CSVProcessing(filename, csvtype) {
    //note that data, memberNames, and memberNamesIndices are assigned in the super-constructor

    //populate course types
    populateTypes();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Public Functions
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

vector<string> TeachingProcessing::getListOfTypes() {
    return types;
}

vector<int> TeachingProcessing::getIndicesType(string type) {
    return getIndicesType(type,allInd);
}

vector<int> TeachingProcessing::getIndicesType(string type, vector<int> indToConsider) {
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

vector<int> TeachingProcessing::getIndicesProgram(string program) {
    return getIndicesProgram(program,allInd);
}

vector<int> TeachingProcessing::getIndicesProgram(string program, vector<int> indToConsider) {
    return getIndicesIntersect( getColumnMatch(COLUMN_PROGRAM,program) , indToConsider );
}

vector<int> TeachingProcessing::getIndicesHours(int minHours, int maxHours) {
    return getIndicesHours(minHours,maxHours,allInd);
}

vector<int> TeachingProcessing::getIndicesHours(int minHours, int maxHours, vector<int> indToConsider) {
    vector<int> result;
    for (int i : indToConsider) {
        if (numberWithinBounds(data.at(COLUMN_HOURS).at(i),minHours,maxHours)) result.push_back(i);
    }
    return result;
}

vector<int> TeachingProcessing::getIndicesStudents(int minNumStudents, int maxNumStudents) {
    return getIndicesStudents(minNumStudents,maxNumStudents,allInd);
}

vector<int> TeachingProcessing::getIndicesStudents(int minNumStudents, int maxNumStudents, vector<int> indToConsider) {
    vector<int> result;
    for (int i : indToConsider) {
        if (numberWithinBounds(data.at(COLUMN_NUMBER_STUDENTS).at(i),minNumStudents,maxNumStudents)) result.push_back(i);
    }
    return result;
}

double TeachingProcessing::getHours(int index) {
     string str = data.at(COLUMN_HOURS).at(index);
     return atof(str.c_str());
} 

int TeachingProcessing::getStudents(int index) {
    string str = data.at(COLUMN_NUMBER_STUDENTS).at(index);
    return atoi(str.c_str());
}

string TeachingProcessing::getTitle(int index) {
    return data.at(COLUMN_TITLE).at(index);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Private Functions
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void TeachingProcessing::populateTypes() {
    pair<vector<string>,vector<vector<int>>> uniqueType = getUniqueInColumn(COLUMN_COURSE_TYPE);
    types = uniqueType.first;
    typesIndices = uniqueType.second;
}//Populate uniqueType with all unique types within teaching CSV

//END OF CLASS
