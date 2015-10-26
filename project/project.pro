#-------------------------------------------------
#
# Project created by QtCreator 2015-10-21T21:17:06
#
#-------------------------------------------------

QT       += core gui

<<<<<<< HEAD
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++11
TARGET = project
TEMPLATE = app

INCLUDEPATH += ../lib

SOURCES += ../src/main.cpp\
        ../src/mainwindow.cpp \
    ../lib/qcustomplot.cpp \
    ../src/publicationprocessing/CSVProcessing.cpp \
    ../src/publicationprocessing/parsetestFTN.cpp \
    ../src/publicationprocessing/PublicationProcessing.cpp

HEADERS  += ../src/mainwindow.h \
    ../lib/qcustomplot.h \
    ../src/publicationprocessing/CSVProcessing.h \
    ../src/publicationprocessing/parsetestFTN.h \
    ../src/publicationprocessing/PublicationProcessing.h \
    ../src/publicationprocessing/csv.h

FORMS    += ../forms/mainwindow.ui

CONFIG += c++11
=======
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = project
TEMPLATE = app


SOURCES += ../src/main.cpp\
        ../src/mainwindow.cpp

HEADERS  += ../src/mainwindow.h

FORMS    += ../forms/mainwindow.ui
>>>>>>> Demo1
