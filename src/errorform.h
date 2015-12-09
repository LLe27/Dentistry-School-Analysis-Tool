#ifndef ERRORFORM_H
#define ERRORFORM_H

#include <QWidget>
#include <vector>
#include <string>
#include "csvprocessing/CSVProcessing.h"
using namespace std;

namespace Ui {
class ErrorForm;
}

class ErrorForm : public QWidget
{
    Q_OBJECT

public:

    /**
     * Constructors
     *
     * @brief ErrorForm
     * @param parent
     */
    explicit ErrorForm(QWidget *parent = 0);

    /**
     * Destructor
     *
    */
    ~ErrorForm();

    /**
     * Populates the table widget with the data of the csv
     *
     * @brief popTable
     */
    void popTable(vector<vector<string>>*);

    /**
     * Sets the value of the instance variable errorIndicies (vector<vector<int>>)
     *
     * @brief setErrorIndices
     */
    void setErrorIndices(vector<vector<int>>);

    /**
     * Sets the value of the instance variable ep (CSVProcessing *)
     *
     * @brief setCSVProccessor
     */
    void setCSVProccessor(CSVProcessing *);

    /**
     * Sets the value of the instance variable csvtype (int)
     *
     * @brief setCSVType
     */
    void setCSVType(int);


private slots:
    /**
     * Button response function. Saves the csv (unimplemented)
     */
    void on_saveButton_clicked();

    /**
     * Button response function. Returns the filename of the csv to be opened (unimplimented)
     *
     * @return
     */
    QString on_openButton_clicked();

    /**
     * Button response function. Updates the csv after editing
     */
    void on_checkButton_clicked();

private:
   /*
    * Instance Variables
    */

    Ui::ErrorForm *ui;
    vector<vector<int>> errorIndicies;
    vector<int> rowError;
    vector<int> colError;
    CSVProcessing* ep;
    int csvtype;

};

#endif // ERRORFORM_H
