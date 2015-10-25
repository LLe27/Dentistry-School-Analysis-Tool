#ifndef PUBLICATIONPROCESSING_H
#define PUBLICATIONPROCESSING_H

#include "CSVProcessing.h"

using namespace std;

class PublicationProcessing : public CSVProcessing {

public:
    PublicationProcessing(vector<vector<string>> data);

    /*
     * Getters for member name and publication type. Return a vector<string> of all UNIQUE values.
     * 
     * NOTE: getListOfMemberNames will be inherted from CSVProcessing because all csv types can use the same method.
     *       I will remove getListOfMemberNames from the actual header.
     */
    vector<string> getListOfMemberNames();
    vector<string> getListOfTypes();

    /*
     * Getter/Refiner for member name. If no "indToConsier" is given, all indices are considered.
     * 
     * NOTE: This will be inherited from CSVProcessing because all cvs types can use the same method. I will remove this from the actual header.
     */ 
    vector<int> getIndMemberName(string memberName);
    vector<int> getIndMemberName(string memberName, vector<int> indToConsider);
    
    /*
     * Getter/Refiner for start/end date. If no "indToConsier" is given, all indices are considered.
     * 
     * NOTE: THIS WILL BE INHERITED FROM CSVProcessing because all cvs types can use the same method. I will remove this from the actual header.
     */ 
    vector<int> getIndDate(int dayStart, int monthStart, int yearStart, int dayEnd, int monthEnd, int yearEnd);
    vector<int> getIndDate(int dayStart, int monthStart, int yearStart, int dayEnd, int monthEnd, int yearEnd, vector<int> indToConsider);
    
    /*
     * Getter/Refiner for status (e.g., Published). If no "indToConsier" is given, all indices are considered.
     */ 
    vector<int> getIndStatus(string status);
    vector<int> getIndStatus(string status, vector<int> indToConsider);
    
    /*
     * Getter/Refiner for type (e.g., Journal Article). If no "indToConsier" is given, all indices are considered.
     */ 
    vector<int> getIndType(string type);
    vector<int> getIndType(string type, vector<int> indToConsider);   
    
private:
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
    vector<string> memberNames; //will be moved to CSVProcessing
    vector<vector<int>> memberNamesIndices; //will be moved to CSVProcessing
};

#endif // PUBLICATIONPROCESSING_H
