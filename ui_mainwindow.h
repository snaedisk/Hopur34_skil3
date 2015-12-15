/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLineEdit *eFind;
    QTabWidget *tabs;
    QWidget *tabProgrammers;
    QTableWidget *tableProgrammers;
    QPushButton *buttonProgrammerAdd;
    QPushButton *buttonProgrammerDel;
    QPushButton *buttonProgrammerEdit;
    QWidget *tabComputers;
    QTableWidget *tableComputers;
    QPushButton *buttonComputersAdd;
    QPushButton *buttonComputersDel;
    QPushButton *buttonComputersEdit;
    QWidget *tabConnections;
    QTableWidget *tableConnections;
    QPushButton *buttonConnectionsDel;
    QSpinBox *connProgrammer;
    QSpinBox *connComputer;
    QPushButton *connectionAdd;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(590, 660);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        eFind = new QLineEdit(centralWidget);
        eFind->setObjectName(QStringLiteral("eFind"));
        eFind->setGeometry(QRect(10, 10, 401, 20));
        tabs = new QTabWidget(centralWidget);
        tabs->setObjectName(QStringLiteral("tabs"));
        tabs->setGeometry(QRect(10, 40, 571, 571));
        tabProgrammers = new QWidget();
        tabProgrammers->setObjectName(QStringLiteral("tabProgrammers"));
        tableProgrammers = new QTableWidget(tabProgrammers);
        tableProgrammers->setObjectName(QStringLiteral("tableProgrammers"));
        tableProgrammers->setGeometry(QRect(10, 50, 561, 491));
        tableProgrammers->setSelectionMode(QAbstractItemView::SingleSelection);
        tableProgrammers->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableProgrammers->setSortingEnabled(true);
        buttonProgrammerAdd = new QPushButton(tabProgrammers);
        buttonProgrammerAdd->setObjectName(QStringLiteral("buttonProgrammerAdd"));
        buttonProgrammerAdd->setGeometry(QRect(20, 10, 75, 23));
        buttonProgrammerDel = new QPushButton(tabProgrammers);
        buttonProgrammerDel->setObjectName(QStringLiteral("buttonProgrammerDel"));
        buttonProgrammerDel->setGeometry(QRect(220, 10, 75, 23));
        buttonProgrammerEdit = new QPushButton(tabProgrammers);
        buttonProgrammerEdit->setObjectName(QStringLiteral("buttonProgrammerEdit"));
        buttonProgrammerEdit->setGeometry(QRect(120, 10, 75, 23));
        tabs->addTab(tabProgrammers, QString());
        tabComputers = new QWidget();
        tabComputers->setObjectName(QStringLiteral("tabComputers"));
        tableComputers = new QTableWidget(tabComputers);
        tableComputers->setObjectName(QStringLiteral("tableComputers"));
        tableComputers->setGeometry(QRect(10, 50, 551, 491));
        tableComputers->setSelectionMode(QAbstractItemView::SingleSelection);
        tableComputers->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableComputers->setSortingEnabled(true);
        buttonComputersAdd = new QPushButton(tabComputers);
        buttonComputersAdd->setObjectName(QStringLiteral("buttonComputersAdd"));
        buttonComputersAdd->setGeometry(QRect(30, 10, 93, 28));
        buttonComputersDel = new QPushButton(tabComputers);
        buttonComputersDel->setObjectName(QStringLiteral("buttonComputersDel"));
        buttonComputersDel->setGeometry(QRect(250, 10, 93, 28));
        buttonComputersEdit = new QPushButton(tabComputers);
        buttonComputersEdit->setObjectName(QStringLiteral("buttonComputersEdit"));
        buttonComputersEdit->setGeometry(QRect(140, 10, 93, 28));
        tabs->addTab(tabComputers, QString());
        tabConnections = new QWidget();
        tabConnections->setObjectName(QStringLiteral("tabConnections"));
        tableConnections = new QTableWidget(tabConnections);
        tableConnections->setObjectName(QStringLiteral("tableConnections"));
        tableConnections->setGeometry(QRect(10, 60, 551, 481));
        tableConnections->setSelectionMode(QAbstractItemView::SingleSelection);
        tableConnections->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableConnections->setSortingEnabled(true);
        buttonConnectionsDel = new QPushButton(tabConnections);
        buttonConnectionsDel->setObjectName(QStringLiteral("buttonConnectionsDel"));
        buttonConnectionsDel->setGeometry(QRect(10, 30, 75, 23));
        connProgrammer = new QSpinBox(tabConnections);
        connProgrammer->setObjectName(QStringLiteral("connProgrammer"));
        connProgrammer->setGeometry(QRect(250, 30, 81, 22));
        connComputer = new QSpinBox(tabConnections);
        connComputer->setObjectName(QStringLiteral("connComputer"));
        connComputer->setGeometry(QRect(340, 30, 81, 22));
        connectionAdd = new QPushButton(tabConnections);
        connectionAdd->setObjectName(QStringLiteral("connectionAdd"));
        connectionAdd->setGeometry(QRect(170, 30, 75, 23));
        label = new QLabel(tabConnections);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(250, 10, 81, 16));
        label_2 = new QLabel(tabConnections);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(340, 10, 71, 16));
        tabs->addTab(tabConnections, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 590, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabs->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Programmers and Computers", 0));
        eFind->setPlaceholderText(QApplication::translate("MainWindow", "search...", 0));
        buttonProgrammerAdd->setText(QApplication::translate("MainWindow", "Add", 0));
        buttonProgrammerDel->setText(QApplication::translate("MainWindow", "Delete", 0));
        buttonProgrammerEdit->setText(QApplication::translate("MainWindow", "Edit", 0));
        tabs->setTabText(tabs->indexOf(tabProgrammers), QApplication::translate("MainWindow", "Programmers", 0));
        buttonComputersAdd->setText(QApplication::translate("MainWindow", "Add", 0));
        buttonComputersDel->setText(QApplication::translate("MainWindow", "Delete", 0));
        buttonComputersEdit->setText(QApplication::translate("MainWindow", "Edit", 0));
        tabs->setTabText(tabs->indexOf(tabComputers), QApplication::translate("MainWindow", "Computers", 0));
        buttonConnectionsDel->setText(QApplication::translate("MainWindow", "Delete", 0));
        connectionAdd->setText(QApplication::translate("MainWindow", "Add", 0));
        label->setText(QApplication::translate("MainWindow", "Programmer ID", 0));
        label_2->setText(QApplication::translate("MainWindow", "Computers ID", 0));
        tabs->setTabText(tabs->indexOf(tabConnections), QApplication::translate("MainWindow", "Connections", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
