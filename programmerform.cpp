#include "programmerform.h"
#include "ui_programmerform.h"
#include "utilities/utils.h"

using namespace utils;

programmerForm::programmerForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::programmerForm)
{
    ui->setupUi(this);
    ui->pGender->addItem(QString::fromStdString("Male"));
    ui->pGender->addItem(QString::fromStdString("Female"));
}

programmerForm::~programmerForm()
{
    delete ui;
}

void programmerForm::setName(string Name){
    ui->pName->setText(QString::fromStdString(Name));
}

string programmerForm::getName(){
    return ui->pName->text().toStdString();
}

void programmerForm::setGender(string Gender){
    if(stringToLower(Gender.substr(0, 1))== "f"){
        ui->pGender->setCurrentIndex(1);
    }else{
        ui->pGender->setCurrentIndex(0);
    }
}

string programmerForm::getGender(){
    return ui->pGender->currentText().toStdString();
}

void programmerForm::setBirthYear(int BirthYear){
    ui->pBirthYear->setValue(BirthYear);

}
int programmerForm::getBirthYear(){
    return ui->pBirthYear->value();
}

void programmerForm::setDeadYear(int DeadYear){
    ui->pDeadYear->setValue(DeadYear);
}

int programmerForm::getDearYear(){
    return ui->pDeadYear->value();
}
