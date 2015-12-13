#ifndef PROGRAMMERS_H
#define PROGRAMMERS_H

#include <QWidget>

namespace Ui {
class Programmers;
}

class Programmers : public QWidget
{
    Q_OBJECT

public:
    explicit Programmers(QWidget *parent = 0);
    ~Programmers();

private:
    Ui::Programmers *ui;
};

#endif // PROGRAMMERS_H
