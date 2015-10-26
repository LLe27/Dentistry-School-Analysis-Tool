/*
 * Child to CSVProcessing. Contains query methods for publications.
 *
 * Author(s): Kevin Stubbs
 */
#include "PublicationProcessing.h"

using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Constructor(s)
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

PublicationProcessing::PublicationProcessing(vector<vector<string>> data) : CSVProcessing(data) {
    //note that data, memberNames, and memberNamesIndices are assigned in the super-constructor

    //populate list of types and its indices
    populateTypes();

    //merge redundent types
    //we may or may not want to run this as it will merge:
    //FOR BETTER: "* Journal Article, Meta-Analysis, Review" into "Journal Article"
    //FOR WORSE?: "Books Edited" into "Books"
    //mergeSimilarTypes();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Public Functions
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

vector<string> PublicationProcessing::getListOfTypes() {
    return types;
}

vector<int> PublicationProcessing::getIndicesStatus(string status) {
    return getIndicesStatus(status,allInd);
}

vector<int> PublicationProcessing::getIndicesStatus(string status, vector<int> indToConsider) {
    return getIndicesIntersect( getColumnMatch(COLUMN_STATUS,status) , indToConsider );
}

vector<int> PublicationProcessing::getIndicesType(string type) {
    return getIndicesType(type,allInd);
}

//uses stored type indices
vector<int> PublicationProcessing::getIndicesType(string type, vector<int> indToConsider) {
    //get type ind or return empty vector
    int indType = -1;
    for (int i=0; i<types.size(); i++) {
        if (types.at(i)==type) {
            indType = i;
            break;
        }
    }
    if (indType==-1) return {};

    //retrurn intersect between known type indicies and indToConsider
    return getIndicesIntersect( typesIndices.at(indType) , indToConsider );
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Private Functions
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PublicationProcessing::populateTypes() {
    pair<vector<string>,vector<vector<int>>> uniqueType = getUniqueInColumn(COLUMN_TYPE);
    types = uniqueType.first;
    typesIndices = uniqueType.second;
}

void PublicationProcessing::mergeSimilarTypes() {
    //Note: all types are unique so either t1 is found in t2 or the opposite, but not both

    /*
     * Find pairs for which t1 contains t2
     */
    string t1,t2;
    vector<int> pairs[2];
    for (int i=0; i<types.size(); i++) {
        //get type
        t1 = types.at(i);
        //type must have length
        if (t1.length()<=0) continue;
        //consider lower case
        transform(t1.begin(),t1.end(),t1.begin(),::tolower);

        for (int j=0; j<types.size(); j++) {
            //don't compare to self
            if (i==j) continue;
            //get type
            t2 = types.at(j);
            //type must have length
            if (t2.length()<=0) continue;
            //consider lower case
            transform(t2.begin(),t2.end(),t2.begin(),::tolower);

            //find type2 in type1
            if (t1.find(t2) != string::npos) {
                //MATCH FOUND
                pairs[0].push_back(i);
                pairs[1].push_back(j);
            }
        }
    }

    /*
     * Do merging of types indices
     */
    vector<int> toRemove;
    int indSource, indTarget;
    for (int i=0; i<pairs[0].size(); i++) {
        //keep whichever name is more common
        if (typesIndices.at(pairs[0].at(i)).size() > typesIndices.at(pairs[1].at(i)).size()) {
            indSource = pairs[1].at(i);
            indTarget = pairs[0].at(i);
        }
        else {
            indSource = pairs[0].at(i);
            indTarget = pairs[1].at(i);
        }

        //append source
        for (int j=0; j<typesIndices.at(indSource).size(); j++) {
            typesIndices.at(indTarget).push_back( typesIndices.at(indSource).at(j) );
        }

        //merge names (may want to comment out this step?)
        types.at(indTarget) += " & " + types.at(indSource);

        //mark source for delete
        toRemove.push_back(indSource);
    }

    /*
     * Delete source types
     */
    //first, sort
    sort(toRemove.begin(),toRemove.end());
    //second, remove (highest index to lowest index)
    for (int i=toRemove.size()-1; i>=0; i--) {
        typesIndices.erase(typesIndices.begin()+toRemove.at(i));
        types.erase(types.begin()+toRemove.at(i));
    }
}
