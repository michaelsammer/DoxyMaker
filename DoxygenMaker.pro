#-------------------------------------------------
#
# Project created by QtCreator 2016-09-29T08:30:28
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DoxygenMaker
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mdi/mditextchild.cpp \
    tools/analyser.cpp \
    data/statement.cpp \
    dlgtemplates.cpp \
    data/db.cpp \
    data/templatedao.cpp \
    data/templatedto.cpp \
    data/templatecontentdto.cpp \
    dlgtemplate.cpp \
    tools/templatemngr.cpp

HEADERS  += mainwindow.h \
    mdi/mditextchild.h \
    tools/analyser.h \
    data/statement.h \
    dlgtemplates.h \
    data/db.h \
    data/templatedao.h \
    data/templatedto.h \
    data/templatecontentdto.h \
    dlgtemplate.h \
    tools/templatemngr.h

FORMS    += mainwindow.ui \
    dlgtemplates.ui \
    dlgtemplate.ui

RESOURCES += \
    res.qrc
