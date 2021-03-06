/*
 * Parent object to PublicationProcessing, PresentationProcessing, GrantsProcessing, and TeachingProcessing.
 */
#include "CSVProcessing.h"


void CSVProcessing::UpdateProcessing(int type)
{
        CSVType i = (CSVType)type;
        data = csvData.getDatabaseCopy(i);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Constructor(s)
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int CSVProcessing::checkType()
{
    if (csvData.isPublications()) return 1;
    else if (csvData.isPresentations()) return 2;
    else if (csvData.isTeaching()) return 3;
    else if (csvData.isFunding()) return 4;

    return 0;
}

CSVProcessing::CSVProcessing(string filename, int csvtype)
{
    switch(csvtype){
    case(1):
        data = csvData.parsePublications(filename);
        break;
    case(2):
        data = csvData.parseTeaching(filename);
        break;
    case(3):
        data = csvData.parsePresentations(filename);
        break;
    case(4):
        data = csvData.parseFunding(filename);
        break;

    } //Cases for each file type

    //populate default index of all entries
    //fail safe: require a member name (length>0)
    for (int i=0; i<(int)data.at(COLUMN_MEMBER_NAME).size(); i++)
    {
        if (data.at(COLUMN_MEMBER_NAME).at(i).size()) allInd.push_back(i);
    }

    //populate date table (of y/m/d entries)
    populateDates(); 

    //change all empty fields to "Unspecified" (or "0" if numeric)
    setUnspecified();

    //populate member names
    populateMemberNames();
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Public Functions
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

vector<vector<int>> CSVProcessing::processErrors(CSVType type)
{
    return csvData.getErrors(type);
}

void CSVProcessing::processingChangeField(int myField, int userNumber, CSVType type, string newMsg)
{
    csvData.changeField(myField, userNumber, type, newMsg);
    data = csvData.getDatabaseCopy(type);
}

vector<vector<string>> CSVProcessing::processingGetDatabaseCopy(CSVType type)
{
    return csvData.getDatabaseCopy(type);
}

vector<string> CSVProcessing::getListOfMemberNames() {
    return memberNames;
}

vector<int> CSVProcessing::getIndicesMemberName(string memberName) {
    return getIndicesMemberName(memberName, allInd);
}

vector<int> CSVProcessing::getIndicesMemberName(string memberName, vector<int> indToConsider) {
    return getIndicesIntersect( getColumnMatch(COLUMN_MEMBER_NAME,memberName) , indToConsider );
}

string CSVProcessing::getMember(int ind) {
    return data.at(COLUMN_MEMBER_NAME).at(ind);
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

QDate CSVProcessing::earliestDate() {
    //if there is no data, return today as earliest
    QDate today = QDate::currentDate();
    if (!allInd.size()) return today;

    //initialize current
    int yearFirst = today.year();
    int monthFirst = today.month();
    int dayFirst = today.day();

    //iterate through all indecies and compare dates
    int year, month, day;
    for (unsigned int i=0; i<allInd.size(); i++) {
        year = dateTable[i][0];
        month = dateTable[i][1];
        day = dateTable[i][2];

        if (year>0 && ( (year<yearFirst) || (year==yearFirst && month<monthFirst) || (year==yearFirst && month==monthFirst && day<dayFirst) ) ) {
            //this entry is earlier
            yearFirst = year;
            monthFirst = month;
            dayFirst = day;
        }
    }

    //if month or day are -1 (undefined), set to 01
    if (monthFirst<=0) monthFirst = 01;
    if (dayFirst<=0) dayFirst = 01;

    //return QDate
    return *(new QDate(yearFirst,monthFirst,dayFirst));
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

vector<int> CSVProcessing::getIndicesSubtract(vector<int> ind1, vector<int> ind2) {
    int j;
    for (int i=ind1.size()-1; i>=0; i--) {
        j = ind1.at(i);
        for (int k : ind2) {
            if (j==k) {
                ind1.erase(ind1.begin()+i);
            }
        }
    }
    return ind1;
}

bool CSVProcessing::numberWithinBounds(string numStr, double min, double max) {
    //convert from string to double
    double numDouble = atof(numStr.c_str());

    //test bounds
    if (numDouble>=min && numDouble<=max) return true;
        else return false;
}

bool CSVProcessing::grantsNumberWithinBounds(string numStr, double min, double max) {
    //remove $
    //numStr.erase(numStr.begin() + 0);

    //remove non-numeric
    string newString= "";
    char c;
    for (unsigned int i=0; i<numStr.size(); i++) {
        c = numStr.at(i);
        if ((c>='0' && c<='9') || c=='.') newString += c;
    }

    //false if no numeric component
    if (!newString.size()) return false;

    //convert from string to double
    double numDouble = atof(newString.c_str());

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
    //GET DATE
    int year = dateTable[ind][0];
    int month = dateTable[ind][1];
    int day = dateTable[ind][2];

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

void CSVProcessing::setUnspecified() {
    vector<int> indUnspecified;
    string cellVal;
    int isNumeric;
    for (unsigned int i=0; i<data.size(); i++) {
        indUnspecified.clear();
        isNumeric = 0;
        for (unsigned int j=0; j<data.at(i).size(); j++) {
            cellVal = data.at(i).at(j);
            if (!cellVal.size()) {
                indUnspecified.push_back(j);
            }
            else if (!isNumeric && atof(cellVal.c_str())!=0) {
                isNumeric = 1;
            }
        }
        if (isNumeric) {
            for (int j:indUnspecified) {
                data.at(i).at(j) = "0";
            }
        }
        else {
            for (int j:indUnspecified) {
                data.at(i).at(j) = "Unspecified";
            }
        }
    }
}

vector<int> CSVProcessing::getDate(int ind) {
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

    vector<int> ret;
    ret.push_back(year);
    ret.push_back(month);
    ret.push_back(day);
    return  ret;
}

void CSVProcessing::populateDates() {
    for (int i:allInd) {
        dateTable.push_back(getDate(i));
    }
}

//END OF CLASS
