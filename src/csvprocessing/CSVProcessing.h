/*
 * Parent object to PublicationProcessing, PresentationProcessing, GrantsProcessing, and TeachingProcessing.
 */
#ifndef CSVPROCESSING_H
#define CSVPROCESSING_H

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
#include <QDate>
#include "CSV2Vector.hpp"


using namespace std;

class CSVProcessing
{
public:
    /*
     * Constants for column ordering.
     */
    //for all
    static const int COLUMN_MEMBER_NAME = 0;
    static const int COLUMN_DATE = 1;

    /**
     * Constructor.
     *
     * @brief CSVProcessing
     * @param filename
     * @param csvtype
     */
    CSVProcessing(string filename, int csvtype);

    void UpdateProcessing(int type);
    int checkType();

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
     * If the entry has no month, it will match all months within its year. If the entry has no day,
     * it will match all days within its year/month.
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
     * If the entry has no month, it will match all months within its year. If the entry has no day,
     * it will match all days within its year/month.
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

    /**
     * Returns earliest date found in dataset.
     *
     * If the earliest date is missing the day, it is set to the 1st of the month.
     * If the earliest date is missing the month, it is set to January.
     *
     * @brief findEarliestDate
     * @return
     */
    QDate earliestDate();

    /**
     * Calls CSV2Vector method.
     * Changes field function to ensure CSV's which changed headers are accounted for.
     *
     * @brief processingChangeField
     * @param myField
     * @param userNumber
     * @param type
     * @param newMsg
     */
    void processingChangeField(int myField, int userNumber, CSVType type, string newMsg);

    /**
     * Calls CSV2Vector method.
     * CSV Type function to get database copy.
     *
     * @brief processingGetDatabaseCopy
     * @param type
     * @return
     */
    vector<vector<string>> processingGetDatabaseCopy(CSVType type);

    /**
     * Calls CSV2Vector method.
     * Part of error processing to retrieve all error information store in vector for errors.
     *
     * @brief processErrors
     * @param type
     * @return
     */
    vector<vector<int>> processErrors(CSVType type);

protected:
    /*
     * Protected instance variables
     */
    vector<vector<string>> data;
    vector<int> allInd;
    vector<string> memberNames;
    vector<vector<int>> memberNamesIndices;
    myData csvData;
    vector<vector<int>> dateTable;

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

    /**
     * Returns the first index after removing any overlap with the second.
     * Does not sort.
     *
     * @brief getIndicesSubtract
     * @param ind1
     * @param ind2
     * @return
     */
    vector<int> getIndicesSubtract(vector<int> ind1, vector<int> ind2);

    /**
     * Accepts a string number and tests whether it is within bounds.
     * If the string is empty or non-numeric, it is not within bounds.
     * The string number that is equal to the min or max is within bounds
     * (i.e., bounds are inclusive).
     *
     * Note that empty strings and non-numeric strings are treated as zero and
     * are therefore within a range which includes zero.
     *
     * @brief numberWithinBounds
     * @param numStr
     * @param min
     * @param max
     */
    bool numberWithinBounds(string numStr, double min, double max);

    /**
     * Accepts a string number and tests whether it is within bounds.
     * If the string is empty or non-numeric, it is not within bounds.
     * The string number that is equal to the min or max is within bounds
     * (i.e., bounds are inclusive).
     *
     * Ignores the first character (designed to ignore a $).
     *
     * @brief grantsNumberWithinBounds
     * @param numStr
     * @param min
     * @param max
     * @return
     */
    bool grantsNumberWithinBounds(string numStr, double min, double max);

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

    /**
     * Changes all empty cells in data to read "Unspecified" (or "0" if numeric).
     * If a single cell in a column is numeric, all empty cells of that column will
     * be set to "0".
     *
     * @brief setUnspecified
     */
    void setUnspecified();

    /**
     * Returns the year/month/day of the specfied item. Unspecified values are returned as -1.
     *
     * @brief getDate
     * @param ind
     * @return
     */
    vector<int> getDate(int ind);

    /**
     * Populates dateTable with y/m/d for all entries. dateTable is of size [#entry]x[3]
     *
     * @brief populateDates
     */
    void populateDates();
};

#endif // CSVPROCESSING_H
