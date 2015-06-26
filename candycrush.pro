#-------------------------------------------------
#
# Project created by QtCreator 2015-06-08T21:49:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = candycrush
TEMPLATE = app


SOURCES += main.cpp\
        start.cpp \
    mainwindow.cpp \
    block.cpp

HEADERS  += start.h \
    mainwindow.h \
    block.h

FORMS    += start.ui \
    mainwindow.ui

RESOURCES += \
    res.qrc
