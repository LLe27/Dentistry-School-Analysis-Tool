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
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Public Functions
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

double TeachingProcessing::getHours(int index){
     string str = data.at(COLUMN_HOURS).at(index);
     return atof(str.c_str());
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Private Functions
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
