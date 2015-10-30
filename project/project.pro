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

SOURCES +=\
    ../lib/qcustomplot.cpp \
    ../src/csvprocessing/CSVProcessing.cpp \
    ../src/csvprocessing/PublicationProcessing.cpp \
    ../src/csvprocessing/CSV2Vector.cpp \
    ../src/mainwindow.cpp \
    ../src/main.cpp

HEADERS  += \
    ../lib/qcustomplot.h \
    ../src/csvprocessing/CSVProcessing.h \
    ../src/csvprocessing/PublicationProcessing.h \
    ../src/csvprocessing/csv.h \
    ../src/csvprocessing/CSV2Vector.hpp \
    ../src/csv.h \
    ../src/mainwindow.h

FORMS    += \
    ../src/mainwindow.ui
CONFIG	 += c++11

RESOURCES += \
    myfiles.qrc
