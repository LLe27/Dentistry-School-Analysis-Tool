#ifndef CSVPROCESSING_H
#define CSVPROCESSING_H

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include "csv.h"
#include <unordered_map>

using namespace std;

class CSVProcessing
{
public:
    CSVProcessing(vector<vector<string>> data);
protected:
    vector<vector<string>> data;

    /*
     * Feel free to make any of these public if needed.
     */

    /**
     * Finds unique strings in specified column and returns a vector containing only those strings.
     *
     * @brief getUniqueInColumn
     * @param column
     * @return
     */
    pair<vector<string>,vector<vector<int>>> getUniqueInColumn(int column);

    /**
     * Returns vector of the specified indicies from the specified column.
     *
     * @brief getColumnSublist
     * @param column
     * @param indices
     * @return
     */
    vector<string> getColumnIndices(int column, vector<int> indices);

    /**
     * Search column for matches to specifies string. Returns vector of int indices.
     * Search is case-sensitive.
     *
     * @brief getColumnMatch
     * @param column
     * @param target
     * @return
     */
    vector<int> getColumnMatch(int column, string target);

    /**
     * Search column for cells containing the specified string. Returns vector of int indices.
     * Search is case-sensitive.
     *
     * @brief getColumnContains
     * @param column
     * @param target
     * @return
     */
    vector<int> getColumnContains(int column, string target);

    /**
     * Returns the intersect of two int vectors, for example the intersect of multiple returns from getColumnMatch.
     * The returned index is sorted and has no repeats.
     *
     * @brief getIndexIntersect
     * @param ind1
     * @param ind2
     * @return
     */
    vector<int> getIndexIntersect(vector<int> ind1, vector<int> ind2);
};

#endif // CSVPROCESSING_H
