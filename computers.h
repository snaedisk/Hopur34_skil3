#ifndef COMPUTERS_H
#define COMPUTERS_H

#include <QWidget>

namespace Ui {
class computers;
}

class computers : public QWidget
{
    Q_OBJECT

public:
    explicit computers(QWidget *parent = 0);
    ~computers();

private:
    Ui::computers *ui;
};

#endif // COMPUTERS_H
