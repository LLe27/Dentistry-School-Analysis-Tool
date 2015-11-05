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

TeachingProcessing::TeachingProcessing(string filename) : CSVProcessing(filename) {
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
    //TO DO
    return {};
}

vector<int> TeachingProcessing::getIndicesHours(int minHours, int maxHours, vector<int> indToConsider) {
    //TO DO
    return {};
}

vector<int> TeachingProcessing::getIndicesStudents(int minNumStudents, int maxNumStudents) {
    //TO DO
    return {};
}

vector<int> TeachingProcessing::getIndicesStudents(int minNumStudents, int maxNumStudents, vector<int> indToConsider) {
    //TO DO
    return {};
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Private Functions
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
