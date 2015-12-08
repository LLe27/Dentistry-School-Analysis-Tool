/*
 * Child to CSVProcessing. Contains query methods for publications.
 *
 * Author(s): Kevin Stubbs
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
//Returns all types as string in vector 
vector<string> TeachingProcessing::getListOfTypes() {
    return types;
}
//Returns all indicies for types within Teaching CSV
vector<int> TeachingProcessing::getIndicesType(string type) {
    return getIndicesType(type,allInd);
}
//Returns all indicies for types within Teaching CSV, vector ouput
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
//Returns all indicies for programs within Teaching CSV
vector<int> TeachingProcessing::getIndicesProgram(string program) {
    return getIndicesProgram(program,allInd);
}
//Returns all indicies for programs within Teaching CSV, vector ouput
vector<int> TeachingProcessing::getIndicesProgram(string program, vector<int> indToConsider) {
    return getIndicesIntersect( getColumnMatch(COLUMN_PROGRAM,program) , indToConsider );
}
//Returns all indicies for hours within Teaching CSV
vector<int> TeachingProcessing::getIndicesHours(int minHours, int maxHours) {
    return getIndicesHours(minHours,maxHours,allInd);
}
//Returns all indicies for hours within Teaching CSV, vector ouput
vector<int> TeachingProcessing::getIndicesHours(int minHours, int maxHours, vector<int> indToConsider) {
    vector<int> result;
    for (int i : indToConsider) {
        if (numberWithinBounds(data.at(COLUMN_HOURS).at(i),minHours,maxHours)) result.push_back(i);
    }
    return result;
}
//Returns all indicies for students within Teaching CSV
vector<int> TeachingProcessing::getIndicesStudents(int minNumStudents, int maxNumStudents) {
    return getIndicesStudents(minNumStudents,maxNumStudents,allInd);
}
//Returns all indicies for students within Teaching CSV, vector output
vector<int> TeachingProcessing::getIndicesStudents(int minNumStudents, int maxNumStudents, vector<int> indToConsider) {
    vector<int> result;
    for (int i : indToConsider) {
        if (numberWithinBounds(data.at(COLUMN_NUMBER_STUDENTS).at(i),minNumStudents,maxNumStudents)) result.push_back(i);
    }
    return result;
}
//Get hours function, to get hours at specific index
double TeachingProcessing::getHours(int index){
     string str = data.at(COLUMN_HOURS).at(index);
     return atof(str.c_str());
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
