QT += core gui quick multimedia websockets concurrent
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Common/Log/VTILog.cpp \
    Controller/StandbyController.cpp \
    Manager/DatabaseManager.cpp \
    Manager/ScreenManager.cpp \
    Model/StandbyModel.cpp \
    main.cpp \
    AppEngine.cpp \
    Common/VTIUtility.cpp\
    Manager/PeopleDetectManager.cpp\
    Controller/MouseController.cpp \
    Model/TechScrModel.cpp \
    Model/StartupScrModel.cpp \
    Model/NewsScrModel.cpp \
    Controller/BaseController.cpp \
    Controller/TechScrController.cpp \
    Controller/NewsScrController.cpp \
    Controller/StartUpScrController.cpp

RESOURCES += \
    Qml.qrc \

INCLUDEPATH += Common \
                Common/Log \
                Controller \
                Manager \
                Model
DEFINES +=SOURCE_PATH=\\\"$$PWD\\\"
# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

dataSam.path = $$PWD/data
INSTALLS += dataSam

HEADERS += \
    Common/Log/VTILog.h \
    Common/ConstDefines.h \
    Common/StringDefines.h \
    Common/VTIEnum.h \
    Controller/StandbyController.h \
    Manager/DatabaseManager.h \
    Manager/ScreenManager.h \
    Manager/PeopleDetectManager.h\
    Model/StandbyModel.h \
    AppEngine.h \
    Common/VTIUtility.h\
    Manager/PeopleDetectManager.h \
    Controller/MouseController.h \
    Model/TechScrModel.h \
    Model/StartupScrModel.h \
    Model/NewsScrModel.h \
    Common/GlobalTypes.h \
    Controller/BaseController.h \
    Controller/TechScrController.h \
    Controller/NewsScrController.h \
    Controller/StartUpScrController.h
