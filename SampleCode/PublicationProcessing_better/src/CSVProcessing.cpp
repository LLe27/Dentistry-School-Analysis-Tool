#include "CSVProcessing.h"

CSVProcessing::CSVProcessing(vector<vector<string>> data)
{
    this->data = data;
}

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

vector<int> CSVProcessing::getIndexIntersect(vector<int> ind1, vector<int> ind2) {
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
