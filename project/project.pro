#-------------------------------------------------
#
# Project created by QtCreator 2015-10-21T21:17:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++11
TARGET = project
TEMPLATE = app

INCLUDEPATH += ../lib

SOURCES += ../src/main.cpp\
        ../src/mainwindow.cpp \
    ../lib/qcustomplot.cpp \
    ../src/marcgraph.cpp \
    ../src/publicationprocessing/CSVProcessing.cpp \
    ../src/publicationprocessing/parsetestFTN.cpp \
    ../src/publicationprocessing/PublicationProcessing.cpp

HEADERS  += ../src/mainwindow.h \
    ../lib/qcustomplot.h \
    ../src/marcgraph.h \
    ../src/publicationprocessing/CSVProcessing.h \
    ../src/publicationprocessing/parsetestFTN.h \
    ../src/publicationprocessing/PublicationProcessing.h \
    ../src/publicationprocessing/csv.h

FORMS    += ../forms/mainwindow.ui
