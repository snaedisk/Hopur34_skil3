#include "programmers.h"
#include "ui_programmers.h"

Programmers::Programmers(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Programmers)
{
    ui->setupUi(this);
}

Programmers::~Programmers()
{
    delete ui;
}
