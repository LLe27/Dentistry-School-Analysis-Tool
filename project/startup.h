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
    explicit StartUp(QWidget *parent = 0);
    int getCsvType();
    ~StartUp();

private slots:
    void on_radioButton_toggled(bool checked);

    void on_radioButton_3_toggled(bool checked);

    void on_radioButton_4_toggled(bool checked);

    void on_radioButton_2_toggled(bool checked);

    void on_buttonBox_accepted();

private:
    Ui::StartUp *ui;
    int csvtype;
};

#endif // STARTUP_H
