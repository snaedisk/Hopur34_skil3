#ifndef ADDPROGRAMMER_H
#define ADDPROGRAMMER_H

#include <QDialog>
#include <QWidget>


namespace Ui {
class addProgrammer;
}

class addProgrammer : public QDialog
{
    Q_OBJECT

public:
    explicit addProgrammer(QWidget *parent = 0);
    ~addProgrammer();

private:
    Ui::addProgrammer *ui;
};

#endif // ADDPROGRAMMER_H
