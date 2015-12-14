#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "pcservice.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void displayProgrammers(string search);
    void displayComputers(string search);

    void on_buttonProgrammerDel_clicked();

private:
    Ui::MainWindow *ui;
    pcService pcservice;
};

#endif // MAINWINDOW_H
