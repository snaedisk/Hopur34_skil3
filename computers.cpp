#include "computers.h"
#include "ui_computers.h"

computers::computers(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::computers)
{
    ui->setupUi(this);
}

computers::~computers()
{
    delete ui;
}
