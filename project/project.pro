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
	../src/csvprocessing/PresentationProcessing.cpp \
	../src/csvprocessing/GrantProcessing.cpp \
	../src/csvprocessing/TeachingProcessing.cpp \
    ../src/csvprocessing/CSV2Vector.cpp \
    ../src/mainwindow.cpp \
    ../src/main.cpp \
    ../lib/nightcharts/nightcharts.cpp \
    ../lib/nightcharts/nightchartswidget.cpp

HEADERS  += \
    ../lib/qcustomplot.h \
    ../src/csvprocessing/CSVProcessing.h \
    ../src/csvprocessing/PublicationProcessing.h \
	../src/csvprocessing/PresentationProcessing.h \
	../src/csvprocessing/GrantProcessing.h \
	../src/csvprocessing/TeachingProcessing.h \
    ../src/csvprocessing/CSV2Vector.hpp \
	../src/csvprocessing/csv.h \
    ../src/csv.h \
    ../src/mainwindow.h \
    ../lib/nightcharts/nightcharts.h \
    ../lib/nightcharts/nightchartswidget.h

FORMS    += \
    ../src/mainwindow.ui \
    ../src/errorform.ui
CONFIG	 += c++11

RESOURCES += \
    myfiles.qrc
