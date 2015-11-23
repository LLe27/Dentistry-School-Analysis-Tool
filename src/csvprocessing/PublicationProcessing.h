/*
 * Child to CSVProcessing. Contains query methods for publications.
 *
 * Author(s): Kevin Stubbs
 */
#ifndef PUBLICATIONPROCESSING_H
#define PUBLICATIONPROCESSING_H
#include "../mainwindow.h"

#include "CSVProcessing.h"

using namespace std;

class PublicationProcessing : public CSVProcessing {

public:
    /*
     * "data" columns
     */
    static const int COLUMN_STATUS = 2;
    static const int COLUMN_TYPE = 3;
    static const int COLUMN_ROLE = 4;
    static const int COLUMN_AUTHORS = 5;
    static const int COLUMN_JOURNAL_NAME = 6;
    static const int COLUMN_TITLE = 7;

    /**
     * Constructor.
     *
     * @brief PublicationProcessing
     * @param filename
     */
    PublicationProcessing(string filename, int csvtype);

    /**
     * Getter for publication type. Return a vector<string> of all UNIQUE values.
     *
     * @brief getListOfTypes
     * @return
     */
    vector<string> getListOfTypes();

    /**
     * Getter/Refiner for status (e.g., Published). Considers all indecies.
     *
     * @brief getIndicesStatus
     * @param status
     * @return
     */
    vector<int> getIndicesStatus(string status);

    /**
     * Getter/Refiner for status (e.g., Published). Considers specified indecies.
     *
     * @brief getIndicesStatus
     * @param status
     * @param indToConsider
     * @return
     */
    vector<int> getIndicesStatus(string status, vector<int> indToConsider);

    /**
     * Getter/Refiner for type (e.g., Journal Article). Considers all indecies.
     *
     * @brief getIndicesType
     * @param type
     * @return
     */
    vector<int> getIndicesType(string type);

    /**
     * Getter/Refiner for type (e.g., Journal Article). Considers specified indecies.
     *
     * @brief getIndicesType
     * @param type
     * @param indToConsider
     * @return
     */
    vector<int> getIndicesType(string type, vector<int> indToConsider);

private:
    /**
     * Populates types and typesIndices.
     *
     * @brief populateTypes
     */
    void populateTypes();

    /**
     * Identifies and merges similar types (e.g., "Books" and "Book" would be merged).
     * The more commonly used type name is preserved.
     *
     * Alters the values of types and typesIndicies.
     *
     * @brief mergeSimilarTypes
     */
    void mergeSimilarTypes();

    /*
     * Private Instance Variables
     *
     * These lists of strings and int indices are be maintained in the object to hasten queries.
     */
    vector<string> types;
    vector<vector<int>> typesIndices;
};

#endif // PUBLICATIONPROCESSING_H
