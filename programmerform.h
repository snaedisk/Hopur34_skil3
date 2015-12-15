#ifndef PROGRAMMERFORM_H
#define PROGRAMMERFORM_H

#include <QDialog>

using namespace std;
namespace Ui {
class programmerForm;
}

class programmerForm : public QDialog
{
    Q_OBJECT

public:
    explicit programmerForm(QWidget *parent = 0);
    ~programmerForm();

    void setName(string Name);
    string getName();
    void setGender(string Gender);
    string getGender();
    void setBirthYear(int BirthYear);
    int getBirthYear();
    void setDeadYear(int DeadYear);
    int getDearYear();

private slots:

    void on_buttonCancel_clicked();

    void on_buttonOK_clicked();

    void on_pDeadYear_valueChanged(int arg1);

    void on_pBirthYear_valueChanged(int arg1);

private:
    Ui::programmerForm *ui;
};

#endif // PROGRAMMERFORM_H
