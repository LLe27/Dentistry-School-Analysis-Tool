QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = project
TEMPLATE = app


SOURCES += ../src/parsetestFTN.cpp \
    ../src/PublicationProcessing.cpp \
    ../src/CSVProcessing.cpp \
	../src/main.cpp

HEADERS  += ../src/parsetestFTN.h \
	../src/csv.h \
	../src/PublicationProcessing.h \
    ../src/CSVProcessing.h

CONFIG += c++11
