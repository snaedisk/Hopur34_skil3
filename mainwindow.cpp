#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pcservice.h"
#include "programmer.h"
#include "utilities/utils.h"
#include "addprogrammer.h"

#include <QApplication>
#include <QMessageBox>
#include <QPixmap>
#include <QFileDialog>
#include <string>
#include <QMenu>
#include <QtCore>
#include <QtGui>
#include <QDebug>
#include<QtPlugin>

using namespace std;
using namespace utils;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList l;
    ui->tableProgrammers->setColumnCount(5);
    l << "ID" << "Name" << "Gender" << "Birth" << "Dead";
    ui->tableProgrammers->setHorizontalHeaderLabels(l);
    ui->tableProgrammers->setColumnWidth( 0, 60 );   // programmerID
    ui->tableProgrammers->setColumnWidth( 1, 200 );  // Name
    ui->tableProgrammers->setColumnWidth( 2, 100 );  // Gender
    ui->tableProgrammers->setColumnWidth( 3, 60 );   // BirthYear
    ui->tableProgrammers->setColumnWidth( 4, 60 );   // DeadYear
    displayProgrammers("");

    ui->tableComputers->setColumnCount(5);
    l << "ID" << "Name" << "Type" << "Built" << "Year";
    ui->tableComputers->setHorizontalHeaderLabels(l);
    ui->tableComputers->setColumnWidth( 0, 60 );   // programmerID
    ui->tableComputers->setColumnWidth( 1, 200 );  // Name
    ui->tableComputers->setColumnWidth( 2, 100 );  // Gender
    ui->tableComputers->setColumnWidth( 3, 60 );   // BirthYear
    ui->tableComputers->setColumnWidth( 4, 60 );   // DeadYear
    displayComputers("");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    if(ui->tabs->currentIndex()== 0){
        displayProgrammers(ui->eFind->text().toStdString());
    }
    else if(ui->tabs->currentIndex()== 1){
        displayComputers(ui->eFind->text().toStdString());
    }
                   // TODO mögulega taka út if setningar og leita í báðum í einu....- KSV

}

void MainWindow::displayProgrammers(string search)
{
    ui->tableProgrammers->setRowCount(0);
    vector<Programmer> programmers = pcservice.findProgrammers(search);
    for (unsigned int i = 0; i<programmers.size();  i++) {
         ui->tableProgrammers->insertRow(ui->tableProgrammers->rowCount());
         ui->tableProgrammers->setItem(ui->tableProgrammers->rowCount() - 1, 0, new QTableWidgetItem(intToString(programmers[i].programmerID).c_str()));
         ui->tableProgrammers->setItem(ui->tableProgrammers->rowCount() - 1, 1, new QTableWidgetItem(programmers[i].Name.c_str()));
         ui->tableProgrammers->setItem(ui->tableProgrammers->rowCount() - 1, 2, new QTableWidgetItem(genderToString(programmers[i].Gender).c_str()));
         ui->tableProgrammers->setItem(ui->tableProgrammers->rowCount() - 1, 3, new QTableWidgetItem(intToString(programmers[i].BirthYear).c_str()));
         ui->tableProgrammers->setItem(ui->tableProgrammers->rowCount() - 1, 4, new QTableWidgetItem(intToString(programmers[i].DeadYear).c_str()));
    }
}

void MainWindow::displayComputers(string search)
{
    ui->tableComputers->setRowCount(0);
    vector<Computer> computers = pcservice.findComputers(search);
    for (unsigned int i = 0; i<computers.size();  i++) {
         ui->tableComputers->insertRow(ui->tableComputers->rowCount());
         ui->tableComputers->setItem(ui->tableComputers->rowCount() - 1, 0, new QTableWidgetItem(intToString(computers[i].computerID).c_str()));
         ui->tableComputers->setItem(ui->tableComputers->rowCount() - 1, 1, new QTableWidgetItem(computers[i].Name.c_str()));
         ui->tableComputers->setItem(ui->tableComputers->rowCount() - 1, 2, new QTableWidgetItem(computers[i].Type.c_str()));
         ui->tableComputers->setItem(ui->tableComputers->rowCount() - 1, 3, new QTableWidgetItem(intToYesNo(computers[i].WasItBuilt).c_str()));
         ui->tableComputers->setItem(ui->tableComputers->rowCount() - 1, 4, new QTableWidgetItem(intToString(computers[i].YearBuilt).c_str()));
    }
}

void MainWindow::on_buttonProgrammerDel_clicked()
{
    int r = ui->tableProgrammers->currentRow();
    pcservice.deleteProgrammer(ui->tableProgrammers->item(r, 0)->text().toInt());  //gefið er programmer ID
    ui->tableProgrammers->removeRow(r);
}


void MainWindow::on_buttonProgrammerAdd_clicked()
{
    addProgrammer addp;
    addp.exec();
}
