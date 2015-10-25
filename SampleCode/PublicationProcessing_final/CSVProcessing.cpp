/*
 * Parent object to PublicationProcessing, PresentationProcessing, GrantsProcessing, and TeachingProcessing.
 *
 * Author(s): Kevin Stubbs
 */
#include "CSVProcessing.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Constructor(s)
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

CSVProcessing::CSVProcessing(vector<vector<string>> data)
{
    this->data = data;

    //populate default index of all entries
    for (int i=0; i<data.at(0).size(); i++) allInd.push_back(i);

    //populate member names
    populateMemberNames();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Public Functions
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

vector<string> CSVProcessing::getListOfMemberNames() {
    return memberNames;
}

vector<int> CSVProcessing::getIndicesMemberName(string memberName) {
    return getIndicesMemberName(memberName, allInd);
}

vector<int> CSVProcessing::getIndicesMemberName(string memberName, vector<int> indToConsider) {
    return getIndicesIntersect( getColumnMatch(COLUMN_MEMBER_NAME,memberName) , indToConsider );
}

vector<int> CSVProcessing::getIndicesDate(int dayStart, int monthStart, int yearStart, int dayEnd, int monthEnd, int yearEnd) {
    return getIndicesDate(dayStart,monthStart, yearStart,dayEnd,monthEnd,yearEnd,allInd);
}

vector<int> CSVProcessing::getIndicesDate(int dayStart, int monthStart, int yearStart, int dayEnd, int monthEnd, int yearEnd, vector<int> indToConsider) {
    vector<int> result;
    for (int i : indToConsider) {
        if (isWithinTimeframe(i,dayStart,monthStart,yearStart,dayEnd,monthEnd,yearEnd)) result.push_back(i);
    }
    return result;
}

vector<string> CSVProcessing::toStringTest(vector<int> indices) {
    vector<string> result;
    string tostr;
    for (int i : indices) {
        tostr = "";
        for (int j=0; j<data.size(); j++) {
            tostr += data.at(j).at(i);
            if (j<(data.size()-1)) tostr += "|";
        }
        result.push_back(tostr);
    }
    return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Protected Functions
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

pair<vector<string>,vector<vector<int>>> CSVProcessing::getUniqueInColumn(int column) {
    vector<string> unique;
    vector<vector<int>> uniqueNum;
    string item;
    bool found;
    for (int i=0; i<data.at(column).size(); i++) {
        item = data.at(column).at(i);
        found = false;
        for (int j=0; j<unique.size(); j++) {
            if (item==unique.at(j)) {
                found = true;
                uniqueNum.at(j).push_back(i);
                break;
            }
        }
        if (!found) {
            unique.push_back(item);
            uniqueNum.push_back({i});
        }
    }

    return make_pair(unique,uniqueNum);
}

vector<string> CSVProcessing::getColumnIndices(int column, vector<int> indices) {
    vector<string> sublist;
    for (int i : indices) {
        sublist.push_back(data.at(column).at(i));
    }
    return sublist;
}



vector<int> CSVProcessing::getColumnMatch(int column, string target) {
    vector<int> indices;
    for (int i=0; i<data.at(column).size(); i++) {
        if (data.at(column).at(i) == target) {
            indices.push_back(i);
        }
    }
    return indices;
}


vector<int> CSVProcessing::getColumnContains(int column, string target) {
    vector<int> indices;
    string str;
    for (int i=0; i<data.at(column).size(); i++) {
        if (data.at(column).at(i).find(target) != string::npos) {
            indices.push_back(i);
        }
    }
    return indices;
}

vector<int> CSVProcessing::getIndicesIntersect(vector<int> ind1, vector<int> ind2) {
    //find overlap
    vector<int> overlap;
    for (int i : ind1) {
        for (int j : ind2) {
            if (i==j) {
                overlap.push_back(i);
                continue;
            }
        }
    }
    //sort
    sort(overlap.begin(),overlap.end());
    //remove repeats
    for (int i=overlap.size()-1; i>0; i--) {
        if (overlap.at(i)==overlap.at(i-1)) {
            overlap.erase(overlap.begin()+i);
        }
    }
    //return
    return overlap;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Private Functions
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void CSVProcessing::populateMemberNames() {
    pair<vector<string>,vector<vector<int>>> uniqueMember =  getUniqueInColumn(COLUMN_MEMBER_NAME);
    memberNames = uniqueMember.first;
    memberNamesIndices = uniqueMember.second;
}

bool CSVProcessing::isWithinTimeframe(int ind, int dayStart, int monthStart, int yearStart, int dayEnd, int monthEnd, int yearEnd) {

    /*
     * INCOMPLETE
     */
    return true;

}
