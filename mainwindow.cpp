#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pcservice.h"
#include "programmer.h"
#include "computer.h"
#include "utilities/utils.h"

#include "data.h"
#include "programmerform.h"
#include "computerform.h"


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
    ui->tableProgrammers->setColumnWidth( 1, 200);  // Name
    ui->tableProgrammers->setColumnWidth( 2, 100);  // Gender
    ui->tableProgrammers->setColumnWidth( 3, 60 );   // BirthYear
    ui->tableProgrammers->setColumnWidth( 4, 60 );   // DeadYear
    displayProgrammers("");

    QStringList f;

    ui->tableComputers->setColumnCount(5);
    f << "ID" << "Name" << "Type" << "Built" << "Year";
    ui->tableComputers->setHorizontalHeaderLabels(f);
    ui->tableComputers->setColumnWidth( 0, 60 );   // programmerID
    ui->tableComputers->setColumnWidth( 1, 200);  // Name
    ui->tableComputers->setColumnWidth( 2, 100);  // Gender
    ui->tableComputers->setColumnWidth( 3, 60 );   // BirthYear
    ui->tableComputers->setColumnWidth( 4, 60 );   // DeadYear
    displayComputers("");


    QStringList g;
    ui->tableConnections->setColumnCount(4);
    g << "ID" << "ProgrammerName" << "ID" << "ComputerName" << "year";
    ui->tableConnections->setHorizontalHeaderLabels(g);
    ui->tableConnections->setColumnWidth( 0, 60 );   // programmerID
    ui->tableConnections->setColumnWidth( 1, 200);  // programmer Name
    ui->tableConnections->setColumnWidth( 2, 60 );  // computerID
    ui->tableConnections->setColumnWidth( 3, 200);   // computer Name
    displayConnections("");
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
    else if(ui->tabs->currentIndex()== 2){
        displayConnections(ui->eFind->text().toStdString());
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
    for (unsigned int i = 0; i < computers.size();  i++) {

         ui->tableComputers->insertRow(ui->tableComputers->rowCount());
         ui->tableComputers->setItem(ui->tableComputers->rowCount() - 1, 0, new QTableWidgetItem(intToString(computers[i].computerID).c_str()));
         ui->tableComputers->setItem(ui->tableComputers->rowCount() - 1, 1, new QTableWidgetItem(computers[i].Name.c_str()));
         ui->tableComputers->setItem(ui->tableComputers->rowCount() - 1, 2, new QTableWidgetItem(computers[i].Type.c_str()));
         ui->tableComputers->setItem(ui->tableComputers->rowCount() - 1, 3, new QTableWidgetItem(intToYesNo(computers[i].WasItBuilt).c_str()));
         ui->tableComputers->setItem(ui->tableComputers->rowCount() - 1, 4, new QTableWidgetItem(intToString(computers[i].YearBuilt).c_str()));
    }
}

void MainWindow::displayConnections(string search)
{
    ui->tableConnections->setRowCount(0);

    vector<Programmer> programmers = pcservice.findProgrammers(search);
    vector<Computer> computers; // ath...
    for (unsigned int i = 0; i<programmers.size();  i++) {
        computers = pcservice.getComputers(programmers[i].programmerID);

        for (unsigned int c = 0; c < computers.size();  c++) {
            ui->tableConnections->insertRow(ui->tableConnections->rowCount());

            ui->tableConnections->setItem(ui->tableConnections->rowCount() - 1, 0, new QTableWidgetItem(intToString(programmers[i].programmerID).c_str()));
            ui->tableConnections->setItem(ui->tableConnections->rowCount() - 1, 1, new QTableWidgetItem(programmers[i].Name.c_str()));

            ui->tableConnections->setItem(ui->tableConnections->rowCount() - 1, 2, new QTableWidgetItem(intToString(computers[c].computerID).c_str()));
            ui->tableConnections->setItem(ui->tableConnections->rowCount() - 1, 3, new QTableWidgetItem(computers[c].Name.c_str()));
        }
    }
}



void MainWindow::on_buttonProgrammerDel_clicked()
{
    int r = ui->tableProgrammers->currentRow();
    pcservice.deleteProgrammer(ui->tableProgrammers->item(r, 0)->text().toInt());  //gefið er programmer ID
    ui->tableProgrammers->removeRow(r);
}

void MainWindow::on_buttonComputersDel_clicked()
{
    int s = ui->tableComputers->currentRow();
    pcservice.deleteComputer(ui->tableComputers->item(s, 0)->text().toInt());  //gefið er computer ID
    ui->tableComputers->removeRow(s);
}

void MainWindow::on_eFind_textChanged(const QString &arg1)
{
    displayProgrammers(ui->eFind->text().toStdString());
    displayComputers(ui->eFind->text().toStdString());
    displayConnections(ui->eFind->text().toStdString());

}

void MainWindow::on_buttonConnectionsDel_clicked()
{
    int t = ui->tableConnections->currentRow();
    pcservice.disconnect(ui->tableConnections->item(t, 0)->text().toInt(), ui->tableConnections->item(t, 2)->text().toInt());  //gefið er computer ID
    ui->tableConnections->removeRow(t);
}

void MainWindow::on_buttonProgrammerAdd_clicked()
{
    int res;
    programmerForm pf(this);
    pf.setWindowTitle(QString::fromStdString("Add Programmer"));
    res = pf.exec();
    if (res == QDialog::Rejected){
        return;
    }
    Programmer p;
    p.Name = pf.getName();
    p.Gender = stringToGender(pf.getGender());
    p.BirthYear = pf.getBirthYear();
    p.DeadYear = pf.getDearYear();
    pcservice.addProgrammer(p);
    displayProgrammers(ui->eFind->text().toStdString());
}

void MainWindow::on_buttonProgrammerEdit_clicked()
{

    int r = ui->tableProgrammers->currentRow();
    if(r<0){
        return;  // if no programmer is selected
    }
    programmerForm pf(this);
    pf.setName(ui->tableProgrammers->item(r, 1)->text().toStdString());
    pf.setGender(ui->tableProgrammers->item(r, 2)->text().toStdString());
    pf.setBirthYear(ui->tableProgrammers->item(r, 3)->text().toInt());
    pf.setDeadYear(ui->tableProgrammers->item(r, 4)->text().toInt());

    int res;
    pf.setWindowTitle(QString::fromStdString(string("Edit Programmer ") + ui->tableProgrammers->item(r, 0)->text().toStdString()));
    res = pf.exec();
    if (res == QDialog::Rejected){
        return;
    }

    Programmer p;
    p.programmerID = ui->tableProgrammers->item(r, 0)->text().toInt();
    p.Name = pf.getName();
    p.Gender = stringToGender(pf.getGender());
    p.BirthYear = pf.getBirthYear();
    p.DeadYear = pf.getDearYear();

    pcservice.updateProgrammer(p);

    displayProgrammers(ui->eFind->text().toStdString());
}

void MainWindow::on_connectionAdd_clicked()
{
    if(ui->connProgrammerID->value()>0 && ui->connComputerID->value()>0){
        pcservice.connectProgrammerToComputer(ui->connComputerID->value(), ui->connProgrammerID->value());
        displayConnections(ui->eFind->text().toStdString());
    }
}

/*void MainWindow::on_buttonProgrammerAdd_clicked()
{
    addProgrammer addp;
    addp.exec();

}*/

void MainWindow::on_buttonComputersAdd_clicked()
{

    int res;
    computerForm cf(this);
    cf.setWindowTitle(QString::fromStdString("Add Computer"));
    res = cf.exec();
    if (res == QDialog::Rejected){
        return;
    }
    Computer c;
    c.Name = cf.getName();
    c.Type = cf.getType();
    c.WasItBuilt = yesNoToInt(cf.getWasItBuilt());
    c.YearBuilt = cf.getYearBuilt();
    pcservice.addComputer(c);
    displayComputers(ui->eFind->text().toStdString());

}

