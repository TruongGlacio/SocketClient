#include "AppEngine.h"
#include "ScreenManager.h"
#include <QMetaObject>
#include <QQmlComponent>
#include <QQmlContext>
#include "Common/ConstDefines.h"
#include <QtDebug>
ScreenManager::ScreenManager(QObject *parent) : QObject(parent)
{

}

ScreenManager::~ScreenManager()
{

}

void ScreenManager::Init()
{
    // init screen Map
    mScreenMap.insert(VTIEnum::ScreenStartup, "qrc:/Qml/Screens/StartupScreen.qml");
    mScreenMap.insert(VTIEnum::ScreenStandby, "qrc:/Qml/Screens/StandbyScreen.qml");
    mScreenMap.insert(VTIEnum::ScreenMenu, "qrc:/Qml/Screens/MenuScreen.qml");
    mScreenMap.insert(VTIEnum::ScreenNews, "qrc:/Qml/Screens/NewsScreen.qml");
    mScreenMap.insert(VTIEnum::ScreenCompanyStructure, "qrc:/Qml/Screens/CompanyStructureScreen.qml");
    mScreenMap.insert(VTIEnum::ScreenPersonInfo, "qrc:/Qml/Screens/PersonInfoScreen.qml");
    mScreenMap.insert(VTIEnum::ScreenForFun, "qrc:/Qml/Screens/ForFunScreen.qml");
    mScreenMap.insert(VTIEnum::ScreenTechnology, "qrc:/Qml/Screens/TechnologyScreen.qml");
    mScreenMap.insert(VTIEnum::ScreenTechnologyDetails, "qrc:/Qml/Screens/TechnologyDetailsScreen.qml");
}

int ScreenManager::RegisterObjectToQml(QQmlApplicationEngine * engine)
{
    engine->rootContext()->setContextProperty(OBJ_SCREEN_MANAGER, this);
    return  1;
}

void ScreenManager::reqGoTo(int id)
{
    if(id == VTIEnum::ScreenNone)
    {
        if(!mScreenStack.isEmpty())
            mScreenStack.pop();
    }else {
        mScreenStack.push(id);
    }

    int screenID = id;
    if(!mScreenStack.isEmpty())
        screenID = mScreenStack.top();

    if(mScreenMap.contains(id))
    {
        QVariant returnedValue;
        QString screenPath = mScreenMap[id];
        QMetaObject::invokeMethod( AppEngine::GetEngine()->rootObjects().first(), "switchLoader",
                Q_RETURN_ARG(QVariant, returnedValue),
                                   Q_ARG(QVariant, screenPath));
    } else {
        qWarning() << "Screen does not have in map. please init screen first.";
    }
}

