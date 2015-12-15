#include "computerform.h"
#include "ui_computerform.h"
#include "utilities/utils.h"

using namespace utils;


computerForm::computerForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::computerForm)
{
    ui->setupUi(this);
    ui->cWasItBuilt->addItem(QString::fromStdString("No"));
    ui->cWasItBuilt->addItem(QString::fromStdString("Yes"));
}

computerForm::~computerForm()
{
    delete ui;
}

void computerForm::setName(string Name){
    ui->cName->setText(QString::fromStdString(Name));
}

string computerForm::getName(){
    return ui->cName->text().toStdString();
}

void computerForm::setType(string Type){
    ui->cType->setText(QString::fromStdString(Type));
}

string computerForm::getType(){
    return ui->cType->text().toStdString();
}

void computerForm::setWasItBuilt(string WasItBuilt){
    if(stringToLower(WasItBuilt.substr(0, 1))== "y"){
        ui->cWasItBuilt->setCurrentIndex(1);
    }else{
        ui->cWasItBuilt->setCurrentIndex(0);
    }
}

string computerForm::getWasItBuilt(){
    return ui->cWasItBuilt->currentText().toStdString();
}

void computerForm::setYearBuilt(int YearBuilt){
    ui->cYearBuilt->setValue(YearBuilt);

}
int computerForm::getYearBuilt(){
    return ui->cYearBuilt->value();
}

/*
void computerForm::setGender(string Gender){
    if(stringToLower(Gender.substr(0, 1))== "f"){
        ui->pGender->setCurrentIndex(1);
    }else{
        ui->pGender->setCurrentIndex(0);
    }
}

string computerForm::getGender(){
    return ui->pGender->currentText().toStdString();
}

void computerForm::setBirthYear(int BirthYear){
    ui->pBirthYear->setValue(BirthYear);

}
int computerForm::getBirthYear(){
    return ui->pBirthYear->value();
}

void computerForm::setDeadYear(int DeadYear){
    ui->pDeadYear->setValue(DeadYear);
}

int computerForm::getDearYear(){
    return ui->pDeadYear->value();
}
*/
