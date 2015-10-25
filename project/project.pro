#-------------------------------------------------
#
# Project created by QtCreator 2015-10-21T21:17:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = project
TEMPLATE = app

INCLUDEPATH += ../lib

SOURCES += ../src/main.cpp\
        ../src/mainwindow.cpp \
    ../lib/qcustomplot.cpp \
    ../src/marcgraph.cpp

HEADERS  += ../src/mainwindow.h \
    ../lib/qcustomplot.h \
    ../src/marcgraph.h

FORMS    += ../forms/mainwindow.ui
