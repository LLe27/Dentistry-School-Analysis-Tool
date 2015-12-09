//
//  main.cpp
//  parseCSV
//
//  Created by Long Le on 2015-10-22.
//  Copyright © 2015 Long Le. All rights reserved.
//

#include "PublicationProcessing.h"
#include "parsetestFTN.h"

using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Constructor(s)
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

PublicationProcessing::PublicationProcessing(vector<vector<string>> data) : CSVProcessing(data) {
    //note that data is assigned in the super-constructor

    //find all unique publication type (column 3 - should eventually make these const rather than magic numbers)
    pair<vector<string>,vector<vector<int>>> uniqueType = getUniqueInColumn(parsetestFTN::COLUMN_TYPE);
    types = uniqueType.first;
    typesIndices = uniqueType.second;

    //merge redundent types
    //we may or may not want to run this as it will merge:
    //FOR BETTER: "* Journal Article, Meta-Analysis, Review" into "Journal Article"
    //FOR WORSE?: "Books Edited" into "Books"
    mergeRedundantTypes();

    //in the interest of keeping the program running smooth for large csv files, several subsets (those for which there are getters)
    //are generated once rather than for each call
    populateGetterVars();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Public Functions
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

vector<string> PublicationProcessing::getTypes() {
    return types;
}

int PublicationProcessing::getCountAll() {
   return  getCountAll(-1);
}

int PublicationProcessing::getCountPublished() {
    return getCountPublished(-1);
}

int PublicationProcessing::getCountAccepted() {
    return getCountAccepted(-1);
}

int PublicationProcessing::getCountSubmitted() {
    return getCountSubmitted(-1);
}

int PublicationProcessing::getCountAll(int type) {
    //type must be -1 (all types) or within the range of types
    if (type==-1) type = types.size();
    else if (type<-1 || type>=types.size()) return -1;

    return countAll.at(type);
}

int PublicationProcessing::getCountPublished(int type) {
    //type must be -1 (all types) or within the range of types
    if (type==-1) type = types.size();
    else if (type<-1 || type>=types.size()) return -1;

    return countPublished.at(type);
}

int PublicationProcessing::getCountAccepted(int type) {
    //type must be -1 (all types) or within the range of types
    if (type==-1) type = types.size();
    else if (type<-1 || type>=types.size()) return -1;

    return countAccepted.at(type);
}

int PublicationProcessing::getCountSubmitted(int type) {
    //type must be -1 (all types) or within the range of types
    if (type==-1) type = types.size();
    else if (type<-1 || type>=types.size()) return -1;

    return countSubmitted.at(type);
}

vector<string> PublicationProcessing::getAuthorsAll() {
    return getAuthorsAll(-1);
}

vector<string> PublicationProcessing::getAuthorsPublished() {
    return getAuthorsPublished(-1);
}

vector<string> PublicationProcessing::getAuthorsAccepted() {
    return getAuthorsAccepted(-1);
}

vector<string> PublicationProcessing::getAuthorsSubmitted() {
    return getAuthorsSubmitted(-1);
}

vector<string> PublicationProcessing::getAuthorsAll(int type) {
    //type must be -1 (all types) or within the range of types
    if (type==-1) type = types.size();
    else if (type<-1 || type>=types.size()) return {};

    return authorsAll.at(type);
}

vector<string> PublicationProcessing::getAuthorsPublished(int type) {
    //type must be -1 (all types) or within the range of types
    if (type==-1) type = types.size();
    else if (type<-1 || type>=types.size()) return {};

    return authorsPublished.at(type);
}

vector<string> PublicationProcessing::getAuthorsAccepted(int type) {
    //type must be -1 (all types) or within the range of types
    if (type==-1) type = types.size();
    else if (type<-1 || type>=types.size()) return {};

    return authorsAccepted.at(type);
}

vector<string> PublicationProcessing::getAuthorsSubmitted(int type) {
    //type must be -1 (all types) or within the range of types
    if (type==-1) type = types.size();
    else if (type<-1 || type>=types.size()) return {};

    return authorsSubmitted.at(type);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Private Functions
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PublicationProcessing::populateGetterVars() {
    //clear vars
    countAll.clear();
    countPublished.clear();
    countAccepted.clear();
    countSubmitted.clear();
    authorsAll.clear();
    authorsPublished.clear();
    authorsAccepted.clear();
    authorsSubmitted.clear();

    //declarations
    int total, count;
    vector<string> authorsTotal, authors;
    vector<int> ind;
    string pubType;

    //pointers
    vector<int> * varCount;
    vector<vector<string>> * varAuthors;

    for (int p=0; p<=3; p++) {
        switch (p) {
            case 0:
                pubType = "";
                varCount = &countAll;
                varAuthors = &authorsAll;
                break;
            case 1:
                pubType = "Published";
                varCount = &countPublished;
                varAuthors = &authorsPublished;
                break;
            case 2:
                pubType = "Accepted";
                varCount = &countAccepted;
                varAuthors = &authorsAccepted;
                break;
            case 3:
                pubType = "Submitted";
                varCount = &countSubmitted;
                varAuthors = &authorsSubmitted;
                break;
        }

        //clear totals
        total = 0;
        authorsTotal.clear();
        for (int i=0; i<types.size(); i++) {
            //get index
            if (pubType.length()<1) {
                //if there is no pubType, use everything
                ind = typesIndices.at(i);
            }
            else {
                //if there is a pubType, use the intersect of the type and the pubType
                ind = getIndexIntersect( typesIndices.at(i) , getColumnContains(parsetestFTN::COLUMN_STATUS,pubType) );
            }

            //count
            count = ind.size();
            total += count;
            varCount->push_back(count);

            //authors
            authors = getColumnIndices(parsetestFTN::COLUMN_AUTHORS,ind);
            varAuthors->push_back(authors);
            for (string auth : authors) authorsTotal.push_back(auth);
        }
        varCount->push_back(total);
        varAuthors->push_back(authorsTotal);
    }

}

void PublicationProcessing::mergeRedundantTypes() {
    /*
     *Note: all types are unique so either t1 is found in t2 or the opposite, but not both
     */

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
