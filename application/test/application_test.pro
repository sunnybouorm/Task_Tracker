TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++11

INCLUDEPATH +=  ../include \
                ../source \
                ../Program files \
                ../../test

SOURCES += main.cpp \
    ../source/Category.cpp \
    ../source/Category_Manager.cpp \
    ../source/Core.cpp \
    ../source/File_IO.cpp \
    ../source/Link.cpp \
    ../source/Link_manager.cpp \
    ../source/Node.cpp \
    ../source/Task.cpp \
    ../source/Task_Manager.cpp \
    Category_Test.cpp \
    Core_Test.cpp \
    File_IO_Test.cpp \
    Link_Test.cpp \
    Task_Test.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    ../include/Category.h \
    ../include/Category_Manager.h \
    ../include/Core.h \
    ../include/DEBUG.h \
    ../include/directories.h \
    ../include/File_IO.h \
    ../include/Link.h \
    ../include/Link_Manager.h \
    ../include/Node.h \
    ../include/Node_Manager.h \
    ../include/Node_Manager.hxx \
    ../include/OS.h \
    ../include/Task.h \
    ../include/Task_Manager.h \
    FILE_DIRECTORIES.h \
    TEST_CASE_DEBUG_FILE.h

