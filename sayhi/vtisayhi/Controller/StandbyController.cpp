#include "StandbyController.h"
#include "../Common/Log/VTILog.h"
#include <QCoreApplication>
#include <QDir>
#include <QStandardPaths>
#include <QQmlContext>
#include "ConstDefines.h"
StandbyController::StandbyController(AppEngine *engine)
{
    QString homeLocation = QStandardPaths::locate(QStandardPaths::HomeLocation, QString(), QStandardPaths::LocateDirectory);
    qDebug() <<QStandardPaths::writableLocation(QStandardPaths::ApplicationsLocation) + PATH_VTISAYHI;
    qDebug() << QCoreApplication::applicationDirPath();
    qDebug() << SOURCE_PATH;
    mStandbyModel = new StandbyModel();
    mAppEngine = engine;
}

StandbyController::~StandbyController()
{
    if (mStandbyModel != nullptr)
    {
        delete mStandbyModel;
        mStandbyModel = nullptr;
    }
}

void StandbyController::Init()
{
    LoadData();
}

int StandbyController::RegisterObjectToQml(QQmlApplicationEngine *engine)
{
    engine->rootContext()->setContextProperty(OBJ_SCREEN_STANDBY_CONTROLLER, this);
    engine->rootContext()->setContextProperty(OBJ_SCREEN_STANDBY_MODEL, mStandbyModel);
    return 1;
}

void StandbyController::OnRequestShowScreen()
{
    mAppEngine->GetScreenManager()->reqGoTo(VTIEnum::ScreenID::ScreenStandby);
}

bool StandbyController::LoadData()
{
    //Implement DataLoade
    return BaseController::LoadData();
}
