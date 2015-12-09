/*
 * Child to CSVProcessing. Contains query methods for publications.
 */
#ifndef GRANTPROCESSING_H
#define GRANTPROCESSING_H
#include "../mainwindow.h"

#include "CSVProcessing.h"

using namespace std;

class GrantProcessing : public CSVProcessing {

public:
/*
     * "data" columns
     */
    static const int COLUMN_TYPE = 2;
    static const int COLUMN_STATUS = 3;
    static const int COLUMN_PEER_REVIEWED = 4;
    static const int COLUMN_INDUSTRY = 5;
    static const int COLUMN_ROLE = 6;
    static const int COLUMN_AMOUNT = 7;
    static const int COLUMN_TITLE = 8;

    /**
     * Constructor.
     *
     * @brief GrantProcessing
     * @param filename
     */
    GrantProcessing(string filename, int csvtype);


    /**
     * Getter for grant type. Return a vector<string> of all UNIQUE values.
     *
     * @brief getListOfTypes
     * @return
     */
    vector<string> getListOfTypes();

    /**
     * Getter for grant role. Return a vector<string> of all UNIQUE values.
     *
     *  @brief getListOfRoles
     * @return
     */
    vector<string> getListOfRoles();

    /**
     * Getter/Refiner for type (e.g., Clinical Trials). Considers all indecies.
     *
     * @brief getIndicesType
     * @param type
     * @return
     */
    vector<int> getIndicesType(string type);

    /**
     * Getter/Refiner for type (e.g., Clinical Trials). Considers specified indecies.
     *
     * @brief getIndicesType
     * @param type
     * @param indToConsider
     * @return
     */
    vector<int> getIndicesType(string type, vector<int> indToConsider);



    /**
     * Getter/Refiner for status (e.g., Applied). Considers all indecies.
     *
     * @brief getIndicesStatus
     * @param status
     * @return
     */
    vector<int> getIndicesStatus(string status);

    /**
     * Getter/Refiner for status (e.g., Applied). Considers specified indecies.
     *
     * @brief getIndicesStatus
     * @param status
     * @param indToConsider
     * @return
     */
    vector<int> getIndicesStatus(string status, vector<int> indToConsider);

    /**
     * Getter/Refiner for ONLY peer reviewed. Considers all indecies.
     * Context: peer review and industry sourced are generally exclusive
     *
     * @brief getIndicesPeerReviewed
     * @return
     */
    vector<int> getIndicesPeerReviewed();

    /**
     * Getter/Refiner for ONLY peer reviewed. Considers specified indecies.
     * Context: peer review and industry sourced are generally exclusive
     *
     * @brief getIndicesPeerReviewed
     * @param indToConsider
     * @return
     */
    vector<int> getIndicesPeerReviewed(vector<int> indToConsider);

    /**
     * Getter/Refiner for ONLY industry sourced. Considers all indecies.
     * Context: peer review and industry sourced are generally exclusive
     *
     * @brief getIndicesIndustry
     * @return
     */
    vector<int> getIndicesIndustry();

    /**
     * Getter/Refiner for ONLY industry sourced. Considers specified indecies.
     * Context: peer review and industry sourced are generally exclusive
     *
     * @brief getIndicesIndustry
     * @param indToConsider
     * @return
     */
    vector<int> getIndicesIndustry(vector<int> indToConsider);

    /**
     * Getter/Refiner for BOTH industry sourced and peer reviewed.
     * Context: peer review and industry sourced are generally exclusive
     *
     * @brief getIndicesBoth
     * @return
     */
    vector<int> getIndicesBoth();

    /**
     * Getter/Refiner for BOTH industry sourced and peer reviewed. Considers specified indecies.
     * Context: peer review and industry sourced are generally exclusive
     *
     * @brief getIndicesBoth
     * @param indToConsider
     * @return
     */
    vector<int> getIndicesBoth(vector<int> indToConsider);

    /**
     * Getter/Refiner for NEITHER industry sourced nor peer reviewed.
     * Context: peer review and industry sourced are generally exclusive
     *
     * @brief getIndicesNeither
     * @return
     */
    vector<int> getIndicesNeither();

    /**
     * Getter/Refiner for NEITHER industry sourced nor peer reviewed. Considers specified indecies.
     * Context: peer review and industry sourced are generally exclusive
     *
     * @brief getIndicesNeither
     * @param indToConsider
     * @return
     */
    vector<int> getIndicesNeither(vector<int> indToConsider);

    /**
     * Getter/Refiner for role (e.g., Collaborator). Considers all indecies.
     *
     * @brief getIndicesRole
     * @param role
     * @return
     */
    vector<int> getIndicesRole(string role);

    /**
     * Getter/Refiner for role (e.g., Collaborator). Considers specified indecies.
     *
     * @brief getIndicesRole
     * @param role
     * @param indToConsider
     * @return
     */
    vector<int> getIndicesRole(string role, vector<int> indToConsider);

    /**
     * Getter/Refiner for grant value. Considers all indecies.
     *
     * @brief getIndicesAmount
     * @param minAmount
     * @param maxAmount
     * @return
     */
    vector<int> getIndicesAmount(int minAmount, int maxAmount);

    /**
     * Getter/Refiner for grant value. Considers specified indecies.
     *
     * @brief getIndicesAmount
     * @param minAmount
     * @param maxAmount
     * @param indToConsider
     * @return
     */
    vector<int> getIndicesAmount(int minAmount, int maxAmount, vector<int> indToConsider);

    /**
     * Getter/Refiner for title. Considers all indecies.
     * Returns any title which CONTAINS the string.
     *
     * @brief getIndicesTitle
     * @param title
     * @return
     */
    vector<int> getIndicesTitle(string title);

    /**
     * Getter/Refiner for title. Considers specified indecies.
     * Returns any title which CONTAINS the string.
     *
     * @brief getIndicesTitle
     * @param title
     * @param indToConsider
     * @return
     */
    vector<int> getIndicesTitle(string title, vector<int> indToConsider);

    /**
     * Return the value (double) of specified grant.
     * If value is empty, 0.0 is returned.
     *
     * @param index
     * @return
     */
    double getAmount(int index);

private:
    /**
     * Populates types and typesIndices.
     *
     * @brief populateTypes
     */
    void populateTypes();

    /**
     * Populates roles and rolesIndices.
     *
     * @brief populateRoles
     */
    void populateRoles();

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
    vector<string> roles;
    vector<vector<int>> rolesIndices;
};

#endif // GRANTPROCESSING_H
