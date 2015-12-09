/*
 * Temporary function based on Evan/Long's code for reading publication csv.
 *
 * Author(s): Long Le, Evan Finnigan, Kevin Subbs
 */
#ifndef PARSETESTFTN_H
#define PARSETESTFTN_H

#include "csv.h"

using namespace std;

class parsetestFTN
{

public:
    /**
     * Loads the specified csv and returns the vector of string vectors.
     *
     * @brief loadData
     * @param filename
     * @return
     */
    static vector<vector<string>> loadData(string filename);
};

#endif // PARSETESTFTN_H
