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
    static const int COLUMN_DOMAIN = 1;
    static const int COLUMN_STATUS = 2;
    static const int COLUMN_TYPE = 3;
    static const int COLUMN_ROLE = 5;
    static const int COLUMN_AUTHORS = 6;
    static const int COLUMN_JOURNAL_NAME = 7;
    static const int COLUMN_TITLE = 8;

    /**
     * Constructor.
     *
     * @brief PublicationProcessing
     * @param data
     */
    PublicationProcessing(vector<vector<string>> data);

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

    /**
     * Draw graph onto windows canvas
     *
     * @param w
     * @param yAxisData
     * @param title
     * @return
     */
    void makeGraph(MainWindow &w, QVector<double> yAxisData, QString title );

private:
    /**
     * Populates types and typesIndices.
     *
     * @brief PublicationProcessing::populateTypes
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


    //temp
    int format(string date);

    /*
     * Private Instance Variables
     *
     * These lists of strings and int indices are be maintained in the object to hasten queries.
     */
    vector<string> types;
    vector<vector<int>> typesIndices;
};

#endif // PUBLICATIONPROCESSING_H
