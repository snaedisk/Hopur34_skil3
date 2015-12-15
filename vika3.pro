#-------------------------------------------------
#
# Project created by QtCreator 2015-12-13T22:41:07
#
#-------------------------------------------------

QT  += core gui
QT  += core sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = vika3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    utilities/utils.cpp \
    data.cpp \
    pcservice.cpp \
    programmerform.cpp \
    computerform.cpp

HEADERS  += mainwindow.h \
    utilities/constants.h \
    utilities/utils.h \
    computer.h \
    data.h \
    pcservice.h \
    Programmer.h \
    programmerform.h \
    computerform.h

FORMS    += mainwindow.ui \
    programmerform.ui \
    computerform.ui
