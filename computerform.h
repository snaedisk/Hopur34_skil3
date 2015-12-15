#ifndef COMPUTERFORM_H
#define COMPUTERFORM_H

#include <QDialog>
using namespace std;

namespace Ui {
class computerForm;
}

class computerForm : public QDialog
{
    Q_OBJECT

public:

    explicit computerForm(QWidget *parent = 0);
    ~computerForm();

    void setName(string Name);
    string getName();
    void setType(string Type);
    string getType();
    void setWasItBuilt(string WasItBuilt);
    string getWasItBuilt();
    void setYearBuilt(int YearBuilt);
    int getYearBuilt();



private:
    Ui::computerForm *ui;
};

#endif // COMPUTERFORM_H
