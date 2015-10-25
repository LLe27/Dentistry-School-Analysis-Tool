/*
 * Parent object to PublicationProcessing, PresentationProcessing, GrantsProcessing, and TeachingProcessing.
 *
 * Author(s): Kevin Stubbs
 */
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
    /*
     * Constants for column ordering.
     */
    //for all
    static const int COLUMN_MEMBER_NAME = 0;
    //for publication
    static const int COLUMN_DOMAIN = 1;
    static const int COLUMN_STATUS = 2;
    static const int COLUMN_TYPE = 3;
    static const int COLUMN_DATE = 4;
    static const int COLUMN_ROLE = 5;
    static const int COLUMN_AUTHORS = 6;
    static const int COLUMN_JOURNAL_NAME = 7;
    static const int COLUMN_TITLE = 8;
    //for presentation only
    //for grants only
    //for teaching only

    /**
     * Constructor.
     *
     * @brief CSVProcessing
     * @param data
     */
    CSVProcessing(vector<vector<string>> data);

    /**
     * Returns a vector<string> of all UNIQUE member names.
     *
     * @brief getListOfMemberNames
     * @return
     */
    vector<string> getListOfMemberNames();

    /**
     * Returns vector<int> of indices for specified member.
     *
     * @brief getIndicesMemberName
     * @param memberName
     * @return
     */
    vector<int> getIndicesMemberName(string memberName);

    /**
     * Returns vector<int> of indices for specified member. Considers only entries indexed by indToConsider.
     *
     * @brief getIndicesMemberName
     * @param memberName
     * @param indToConsider
     * @return
     */
    vector<int> getIndicesMemberName(string memberName, vector<int> indToConsider);

    /**
     * Returns vector<int> of indices within specified timeframe.
     *
     * If the entry has no month, it will match all months within its year. If the entry has no day, it will match all days within its year/month.
     *
     * Currently, this function is not very efficient. If anyone has time, they could improve upon it.
     *
     * @brief getIndicesDate
     * @param dayStart
     * @param monthStart
     * @param yearStart
     * @param dayEnd
     * @param monthEnd
     * @param yearEnd
     * @return
     */
    vector<int> getIndicesDate(int dayStart, int monthStart, int yearStart, int dayEnd, int monthEnd, int yearEnd);

    /**
     * Returns vector<int> of indices within specified timeframe. Considers only entries indexed by indToConsider.
     *
     * If the entry has no month, it will match all months within its year. If the entry has no day, it will match all days within its year/month.
     *
     * Currently, this function is not very efficient. If anyone has time, they could improve upon it.
     *
     * @brief getIndicesDate
     * @param dayStart
     * @param monthStart
     * @param yearStart
     * @param dayEnd
     * @param monthEnd
     * @param yearEnd
     * @param indToConsider
     * @return
     */
    vector<int> getIndicesDate(int dayStart, int monthStart, int yearStart, int dayEnd, int monthEnd, int yearEnd, vector<int> indToConsider);

    /**
     * Test function which returns strings containing all data on entries in the format of "data.at(0)|data.at(1)..."
     *
     * @brief toStringTest
     * @param indecies
     * @return
     */
    vector<string> toStringTest(vector<int> indices);

protected:
    /*
     * Vector of string vectors "data" structure.
     */
    vector<vector<string>> data;

    /*
     * Helper Functions
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
     * @brief getIndicesIntersect
     * @param ind1
     * @param ind2
     * @return
     */
    vector<int> getIndicesIntersect(vector<int> ind1, vector<int> ind2);

    /*
     * Protected instance variables
     */
    vector<int> allInd;
    vector<string> memberNames;
    vector<vector<int>> memberNamesIndices;
private:
    /**
     * Populates memberNames and memberNamesIndicies.
     *
     * @brief populateMemberNames
     */
    void populateMemberNames();

    /**
     * Returns true if the index is between the specified dates, otherwise false. If the entry does not contain a day or month then it is
     * considered as spanning all days and/or all months of the entry's year.
     *
     * @brief isWithinTimeframe
     * @param ind
     * @param dayStart
     * @param monthStart
     * @param yearStart
     * @param dayEnd
     * @param monthEnd
     * @param yearEnd
     * @return
     */
    bool isWithinTimeframe(int ind, int dayStart, int monthStart, int yearStart, int dayEnd, int monthEnd, int yearEnd);
};

#endif // CSVPROCESSING_H
