#ifndef PUBLICATIONPROCESSING_H
#define PUBLICATIONPROCESSING_H

#include "CSVProcessing.h"

using namespace std;

class PublicationProcessing : public CSVProcessing {

public:
    PublicationProcessing(vector<vector<string>> data);

    /**
     * Returns a vector of the unique types (e.g., Journal Article).
     *
     * @brief getTypes
     * @return
     */
    vector<string> getTypes();

    /*
     * Returns int number of entries.
     *
     * Functionn may accept a type which corresponds to the types returned by getTypes().
     *
     * Returns -1 or empty vector if type number is outside bounds.
     */
    int getCountAll();
    int getCountPublished();
    int getCountAccepted();
    int getCountSubmitted();
    int getCountAll(int type);
    int getCountPublished(int type);
    int getCountAccepted(int type);
    int getCountSubmitted(int type);

    /*
     * Returns vector of authors.
     *
     * Functionn may accept a type which corresponds to the types returned by getTypes().
     *
     * Returns null if type number is out of bounds.
     */
    vector<string> getAuthorsAll();
    vector<string> getAuthorsPublished();
    vector<string> getAuthorsAccepted();
    vector<string> getAuthorsSubmitted();
    vector<string> getAuthorsAll(int type);
    vector<string> getAuthorsPublished(int type);
    vector<string> getAuthorsAccepted(int type);
    vector<string> getAuthorsSubmitted(int type);


private:
    /**
     * Identifies and merges redundant types (e.g., "Books" and "Book" would be merged).
     * The more commonly used type name is preserved.
     *
     * Alters the values of types and typesIndicies.
     *
     * @brief mergeRedundantTypes
     */
    void mergeRedundantTypes();

    /**
     * Clears all vars for which there are getters and (re)assigns their values.
     *
     * @brief populateGetterVars
     */
    void populateGetterVars();

    /*
     * Private Instance Variables
     */
    vector<string> types;
    vector<vector<int>> typesIndices;

    vector<int> countAll;
    vector<int> countPublished;
    vector<int> countAccepted;
    vector<int> countSubmitted;

    vector<vector<string>> authorsAll;
    vector<vector<string>> authorsPublished;
    vector<vector<string>> authorsAccepted;
    vector<vector<string>> authorsSubmitted;

};

#endif // PUBLICATIONPROCESSING_H
