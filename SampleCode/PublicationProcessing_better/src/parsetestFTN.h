#ifndef PARSETESTFTN_H
#define PARSETESTFTN_H

#include "csv.h"

using namespace std;

class parsetestFTN
{

public:
    /*
     * Vector order
     */
    static const int COLUMN_MEMBER_NAME = 0;
    static const int COLUMN_DOMAIN = 1;
    static const int COLUMN_STATUS = 2;
    static const int COLUMN_TYPE = 3;
    static const int COLUMN_DATE = 4;
    static const int COLUMN_ROLE = 5;
    static const int COLUMN_AUTHORS = 6;
    static const int COLUMN_JOURNAL_NAME = 7;
    static const int COLUMN_TITLE = 8;

    /**
     * Loads the specified csv and returns the vector of string vectors.
     *
     * @brief loadData
     * @param filename
     * @return
     */
    static vector<vector<string>> loadData(string filename);
};

#endif // PARSETESTFTN_H
