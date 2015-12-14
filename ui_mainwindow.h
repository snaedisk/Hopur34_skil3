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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
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
    QPushButton *pushButton;
    QTabWidget *tabs;
    QWidget *tabProgrammers;
    QTableWidget *tableProgrammers;
    QPushButton *buttonProgrammerAdd;
    QPushButton *buttonProgrammerDel;
    QWidget *tabComputers;
    QTableWidget *tableComputers;
    QWidget *tabConnections;
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
        eFind->setGeometry(QRect(100, 10, 133, 20));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 10, 75, 23));
        tabs = new QTabWidget(centralWidget);
        tabs->setObjectName(QStringLiteral("tabs"));
        tabs->setGeometry(QRect(10, 30, 571, 571));
        tabProgrammers = new QWidget();
        tabProgrammers->setObjectName(QStringLiteral("tabProgrammers"));
        tableProgrammers = new QTableWidget(tabProgrammers);
        tableProgrammers->setObjectName(QStringLiteral("tableProgrammers"));
        tableProgrammers->setGeometry(QRect(10, 60, 541, 481));
        buttonProgrammerAdd = new QPushButton(tabProgrammers);
        buttonProgrammerAdd->setObjectName(QStringLiteral("buttonProgrammerAdd"));
        buttonProgrammerAdd->setGeometry(QRect(20, 10, 75, 23));
        buttonProgrammerDel = new QPushButton(tabProgrammers);
        buttonProgrammerDel->setObjectName(QStringLiteral("buttonProgrammerDel"));
        buttonProgrammerDel->setGeometry(QRect(140, 10, 75, 23));
        tabs->addTab(tabProgrammers, QString());
        tabComputers = new QWidget();
        tabComputers->setObjectName(QStringLiteral("tabComputers"));
        tableComputers = new QTableWidget(tabComputers);
        tableComputers->setObjectName(QStringLiteral("tableComputers"));
        tableComputers->setGeometry(QRect(20, 10, 501, 471));
        tabs->addTab(tabComputers, QString());
        tabConnections = new QWidget();
        tabConnections->setObjectName(QStringLiteral("tabConnections"));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Display", 0));
        buttonProgrammerAdd->setText(QApplication::translate("MainWindow", "Add", 0));
        buttonProgrammerDel->setText(QApplication::translate("MainWindow", "Delete", 0));
        tabs->setTabText(tabs->indexOf(tabProgrammers), QApplication::translate("MainWindow", "Programmers", 0));
        tabs->setTabText(tabs->indexOf(tabComputers), QApplication::translate("MainWindow", "Computers", 0));
        tabs->setTabText(tabs->indexOf(tabConnections), QApplication::translate("MainWindow", "Connections", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
