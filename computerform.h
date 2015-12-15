#ifndef COMPUTERFORM_H
#define COMPUTERFORM_H

#include <QDialog>

namespace Ui {
class computerForm;
}

class computerForm : public QDialog
{
    Q_OBJECT

public:
    explicit computerForm(QWidget *parent = 0);
    ~computerForm();

private:
    Ui::computerForm *ui;
};

#endif // COMPUTERFORM_H
