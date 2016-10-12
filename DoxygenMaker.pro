#-------------------------------------------------
#
# Project created by QtCreator 2016-09-29T08:30:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DoxygenMaker
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mdi/mditextchild.cpp \
    tools/analyser.cpp \
    data/statement.cpp \
    dlgtemplates.cpp

HEADERS  += mainwindow.h \
    mdi/mditextchild.h \
    tools/analyser.h \
    data/statement.h \
    dlgtemplates.h

FORMS    += mainwindow.ui \
    dlgtemplates.ui

RESOURCES += \
    res.qrc
