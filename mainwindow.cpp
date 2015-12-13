#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QtCore>
#include <QtGui>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Main Menu - clicked on P
void MainWindow::on_Programmers_clicked()
{
    QMessageBox::information(this,"Programmer here", "Programming Text here");
}

void MainWindow::on_Computer_clicked()
{
    QMessageBox::question(this,"Computer List", "ComputerText here", "bla bla bla");
}

void MainWindow::on_progrAndComputers_clicked()
{
    QMessageBox::information(this,"Programmer here", "comp og prog Text here");

}

void MainWindow::on_Quit_clicked()
{
    QMessageBox::StandardButton replay;
    replay = QMessageBox::question (this,"Quit", "Are you sure you want to quit?");
        QMessageBox::Yes| QMessageBox::No;
                if(replay==QMessageBox::Yes){
            //allt lokast??
        }
}
