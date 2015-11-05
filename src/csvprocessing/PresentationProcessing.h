/*
 * Child to CSVProcessing. Contains query methods for publications.
 *
 * Author(s): Kevin Stubbs
 */
#ifndef PRESENTATIONPROCESSING_H
#define PRESENTATIONPROCESSING_H
#include "../mainwindow.h"

#include "CSVProcessing.h"

using namespace std;

class PresentationProcessing : public CSVProcessing {

public:
/*
     * "data" columns
     */
    static const int COLUMN_TYPE = 2;
    static const int COLUMN_ROLE = 3;

    /**
     * Constructor.
     *
     * @brief PresentationProcessing
     * @param filename
     */
    PresentationProcessing(string filename);

    /**
     * Getter for presentation type. Return a vector<string> of all UNIQUE values.
     *
     * @brief getListOfTypes
     * @return
     */
    vector<string> getListOfTypes();

    /**
     * Getter/Refiner for role (e.g., Visiting Professor). Considers all indecies.
     *
     * @brief getIndicesStatus
     * @param role
     * @return
     */
    vector<int> getIndicesRole(string role);

    /**
     * Getter/Refiner for role (e.g., Visiting Professor). Considers specified indecies.
     *
     * @brief getIndicesStatus
     * @param role
     * @param indToConsider
     * @return
     */
    vector<int> getIndicesRole(string role, vector<int> indToConsider);

    /**
     * Getter/Refiner for type (e.g., Invited Lectures). Considers all indecies.
     *
     * @brief getIndicesType
     * @param type
     * @return
     */
    vector<int> getIndicesType(string type);

    /**
     * Getter/Refiner for type (e.g., Invited Lectures). Considers specified indecies.
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

    /*
     * Private Instance Variables
     *
     * These lists of strings and int indices are be maintained in the object to hasten queries.
     */
    vector<string> types;
    vector<vector<int>> typesIndices;
};

#endif // PRESENTATIONPROCESSING_H
