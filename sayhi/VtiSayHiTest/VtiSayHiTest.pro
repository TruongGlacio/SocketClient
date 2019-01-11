QT += testlib quick
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase c++11
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  \
    main.cpp \
    UT_ScreenManager.cpp \
    UT_AppEngine.cpp
INCLUDEPATH += $$PWD/../vtisayhi

HEADERS += \
    UT_ScreenManager.h \
    TestCollector.h \
    UT_AppEngine.h
