#ifndef STARTUP_H
#define STARTUP_H

#include <QDialog>

namespace Ui {
class StartUp;
}

class StartUp : public QDialog
{
    Q_OBJECT

public:
    /**
     * Constructor
     *
     * @param parent
     */
    explicit StartUp(QWidget *parent = 0);

    /**
      *Destructor
      */
    ~StartUp();

    /**
     * Returns the type of CSV via integer value.
     *
     * @return
     */
    int getCsvType();

private slots:
    /**
     * Radio Button response function. Determines CSV type.
     *
     * @param checked
     */
    void on_radioButton_toggled(bool checked);

    /**
     * Radio Button response function. Determines CSV type.
     *
     * @param checked
     */
    void on_radioButton_3_toggled(bool checked);

    /**
     * Radio Button response function. Determines CSV type.
     *
     * @param checked
     */
    void on_radioButton_4_toggled(bool checked);

    /**
     * Radio Button response function. Determines CSV type.
     *
     * @param checked
     */
    void on_radioButton_2_toggled(bool checked);

    /**
     * Button response function. User is done input and closes Dialog and passes values to the mainwindow.
     *
     */
    void on_buttonBox_accepted();

private:
    /*
     * Private Instance Variables
     */
    Ui::StartUp *ui;
    int csvtype;
};

#endif // STARTUP_H
