#-------------------------------------------------
#
# Project created by QtCreator 2015-01-08T17:47:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GUI
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

INCLUDEPATH += ../application/source/ \
               ../application/include/

SOURCES += main.cpp\
        mainwindow.cpp \
    ../application/source/Category.cpp \
    ../application/source/Category_Manager.cpp \
    ../application/source/Core.cpp \
    ../application/source/File_IO.cpp \
    ../application/source/Link.cpp \
    ../application/source/Link_manager.cpp \
    ../application/source/Node.cpp \
    ../application/source/Task.cpp \
    ../application/source/Task_Manager.cpp \
    Task_Setup.cpp \
    tsd_deleteprompt.cpp \
    tsd_taskeditdialog.cpp

HEADERS  += mainwindow.h \
    ../application/include/Category.h \
    ../application/include/Category_Manager.h \
    ../application/include/Core.h \
    ../application/include/DEBUG.h \
    ../application/include/directories.h \
    ../application/include/File_IO.h \
    ../application/include/Link.h \
    ../application/include/Link_Manager.h \
    ../application/include/Node.h \
    ../application/include/Node_Manager.h \
    ../application/include/Node_Manager.hxx \
    ../application/include/OS.h \
    ../application/include/Task.h \
    ../application/include/Task_Manager.h \
    Task_Setup.h \
    tsd_deleteprompt.h \
    tsd_taskeditdialog.h

FORMS    += mainwindow.ui \
    Task_Setup.ui \
    tsd_deleteprompt.ui \
    tsd_taskeditdialog.ui

DISTFILES +=
