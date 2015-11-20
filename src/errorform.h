#ifndef ERRORFORM_H
#define ERRORFORM_H

#include <QWidget>
#include <vector>
#include <string>
using namespace std;

namespace Ui {
class ErrorForm;
}

class ErrorForm : public QWidget
{
    Q_OBJECT

public:
    explicit ErrorForm(QWidget *parent = 0);
    ~ErrorForm();
    void popTable(vector<vector<string>>*);

private slots:
    void on_saveButton_clicked();

    QString on_openButton_clicked();

    void on_checkButton_clicked();

private:
    Ui::ErrorForm *ui;
    
};

#endif // ERRORFORM_H
