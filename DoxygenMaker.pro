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
    data/db.cpp \
    data/templatedao.cpp \
    data/templatedto.cpp \
    data/templatecontentdto.cpp \
    tools/templatemngr.cpp \
    data/valuesdto.cpp \
    data/valuesdao.cpp \
    tools/valuesmngr.cpp \
    dlgsettings.cpp \
    settings/wdgsettingglobal.cpp \
    settings/wdgsettingstemplates.cpp \
    settings/wdgsettingsvalues.cpp \
    settings/dlgtemplate.cpp

HEADERS  += mainwindow.h \
    mdi/mditextchild.h \
    tools/analyser.h \
    data/statement.h \
    data/db.h \
    data/templatedao.h \
    data/templatedto.h \
    data/templatecontentdto.h \
    tools/templatemngr.h \
    data/valuesdto.h \
    data/valuesdao.h \
    tools/valuesmngr.h \
    dlgsettings.h \
    settings/wdgsettingglobal.h \
    settings/wdgsettingstemplates.h \
    settings/wdgsettingsvalues.h \
    settings/dlgtemplate.h

FORMS    += mainwindow.ui \
    dlgsettings.ui \
    settings/wdgsettingglobal.ui \
    settings/wdgsettingstemplates.ui \
    settings/wdgsettingsvalues.ui \
    settings/dlgtemplate.ui

RESOURCES += \
    res.qrc
