#include "computerform.h"
#include "ui_computerform.h"

computerForm::computerForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::computerForm)
{
    ui->setupUi(this);
}

computerForm::~computerForm()
{
    delete ui;
}
