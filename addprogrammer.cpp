#include "addprogrammer.h"
#include "ui_addprogrammer.h"

addProgrammer::addProgrammer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addProgrammer)
{
    ui->setupUi(this);
}

addProgrammer::~addProgrammer()
{
    delete ui;
}
