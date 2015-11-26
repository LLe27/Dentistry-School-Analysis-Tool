/*
 * Parent object to PublicationProcessing, PresentationProcessing, GrantsProcessing, and TeachingProcessing.
 *
 * Author(s): Kevin Stubbs
 */
#include "CSVProcessing.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Constructor(s)
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

CSVProcessing::CSVProcessing(string filename, int csvtype)
{
    switch(csvtype){
    case(1):
        this->data = csvData.parsePublications(filename);
        break;
    case(2):
        this->data = csvData.parseTeaching(filename);
        break;
    case(3):
        this->data = csvData.parsePresentations(filename);
        break;
    case(4):
        this->data = csvData.parseFunding(filename);
        break;

    }


    //populate default index of all entries
    for (int i=0; i<(int)data.at(0).size(); i++) allInd.push_back(i);

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
        for (int j=0; j<(int)data.size(); j++) {
            tostr += data.at(j).at(i);
            if (j<(int)(data.size()-1)) tostr += "|";
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
    for (int i=0; i<(int)data.at(column).size(); i++) {
        item = data.at(column).at(i);
        found = false;
        for (int j=0; j<(int)unique.size(); j++) {
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
    for (int i=0; i<(int)data.at(column).size(); i++) {
        if (data.at(column).at(i) == target) {
            indices.push_back(i);
        }
    }
    return indices;
}


vector<int> CSVProcessing::getColumnContains(int column, string target) {
    vector<int> indices;
    string str;
    for (int i=0; i<(int)data.at(column).size(); i++) {
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

bool CSVProcessing::numberWithinBounds(string numStr, double min, double max) {
    //convert from string to double
    double numDouble = atof(numStr.c_str());

    //test bounds
    if (numDouble>=min && numDouble<=max) return true;
        else return false;
}

bool CSVProcessing::grantsNumberWithinBounds(string numStr, double min, double max) {
    //convert from string to double
    numStr.erase(numStr.begin() + 0);
    double numDouble = atof(numStr.c_str());

    //test bounds
    if (numDouble>=min && numDouble<=max) return true;
        else return false;
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
     *
     * After demo1, we should determine the year/month/day of each entry once upon loading. Calling this script repeatedly
     * during runtime is very inefficient.
     *
     * There is very little checking in this function at present. For example 1999-31-07 would produce year 1999, month 31, day 07.
     *
     * It would be better if day-less entries were include only when the entire month is included, and if month-less entires were
     * included only when the entire month is included. Add this later?
     *
     */

    //get date string
    string date = data.at(COLUMN_DATE).at(ind);

    //check for alphabetic month
    string dateNonNumeric;
    char c;
    for (int i=0; i<(int)date.size(); i++) {
        c = date.at((i));
        if (c!='-' && !isdigit(c)) dateNonNumeric += c;
    }

    //declare/init year, month, dat
    int year, month, day;
    year = month = day = -1;

    //if date contains alphabetic month, set month
    if (dateNonNumeric.length()>0) {
        //consider lower case
        transform(dateNonNumeric.begin(),dateNonNumeric.end(),dateNonNumeric.begin(),::tolower);
        if (dateNonNumeric.find("jan") != string::npos) month = 1;
        else if (dateNonNumeric.find("feb") != string::npos) month = 2;
        else if (dateNonNumeric.find("mar") != string::npos) month = 3;
        else if (dateNonNumeric.find("apr") != string::npos) month = 4;
        else if (dateNonNumeric.find("may") != string::npos) month = 5;
        else if (dateNonNumeric.find("jun") != string::npos) month = 6;
        else if (dateNonNumeric.find("jul") != string::npos) month = 7;
        else if (dateNonNumeric.find("aug") != string::npos) month = 8;
        else if (dateNonNumeric.find("sep") != string::npos) month = 9;
        else if (dateNonNumeric.find("oct") != string::npos) month = 10;
        else if (dateNonNumeric.find("nov") != string::npos) month = 11;
        else if (dateNonNumeric.find("dec") != string::npos) month = 12;
    }

    //note1: the year is always present
    //note2: the year is always the first number
    //note3: year may be 2-digit if after 2000?
    //note4: always sets in the order of year -> month -> day

    //parse
    string str;
    int strInt;
    for (int i=0; i<(int)date.size(); i++) {
        c = date.at(i);
        if (isdigit(c)) str += c;

        if (str.length()==2 && ((i<(int)(date.size()-1) && !isdigit(date.at(i+1))) || i==(int)(date.size()-1))) {
            strInt = atoi(str.c_str());

            //2-ditit year, month, or day
            if (year==-1) {
                //set year (assume 2000 and beyond)
                year = (strInt+2000);
            }
            else if (month==-1) {
                //set month
                month = strInt;
            }
            else if (day==-1) {
                //set day
                day = strInt;
            }
            else {
                //shouldn't happen
            }
            //clear str
            str = "";
        }
        else if(str.length()==4) {
            //4-digit year
            strInt = atoi(str.c_str());
            year = strInt;
            str = "";
        }
    }

    /*
     * compare dates
     */
    //year too early
    if (year<yearStart) return false;
    //year too late
    if (year>yearEnd) return false;
    //year within bounds (but not equal)
    if (year>yearStart && year<yearEnd) return true;
    else {
        //either equal to start or end year
        //have to check month...

        //if no month, assume match
        if (month==-1) return true;

        //start and end within same year
        if (yearStart==yearEnd) {
            //month outside bounds
            if (month<monthStart || month>monthEnd) return false;

            //month within but not equal to bounds
            if (month>monthStart && month<monthEnd) return true;

            //if no day, assume match
            if (day==-1) return true;

            //during start month..
            if (month==monthStart) {
                if (day>=dayStart) return true;
                else return false;
            }
            //during end month...
            else {
                if (day<=dayEnd) return true;
                else return false;
            }

        }
        else if (year==yearStart) {
            //is during start year...

            //month too soon
            if (month<monthStart) return false;
            //month after start
            else if (month>monthStart) return true;
            //same month, have to check day
            else {
                //if no day, assume match
                if (day==-1) return true;

                //day too soon
                if (day<dayStart) return false;
                else {
                    //day is equal or great
                    return true;
                }
            }

        }
        else {
            //is during end year...

            //month too late
            if (month>monthEnd) return false;
                //month before start
            else if (month<monthEnd) return true;
            //same month, have to check day
            else {
                //if no day, assume match
                if (day==-1) return true;

                //day too late
                if (day>dayEnd) return false;
                else {
                    //day is equal or lesst
                    return true;
                }
            }
        }
    }

    //default to false
    return false;
}
