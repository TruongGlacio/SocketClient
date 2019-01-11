#include "AppEngine.h"

#include <Common/VTIEnum.h>
#include <Controller/StandbyController.h>
#include <QDir>
#include <QStandardPaths>
#include <VTILog.h>
#include <ConstDefines.h>
#include "VTIUtility.h"
#include <PeopleDetectManager.h>
#include <MouseController.h>
#include <Controller/TechScrController.h>
#include <Controller/NewsScrController.h>
#include <Controller/StartUpScrController.h>

QGuiApplication *AppEngine::mApp = nullptr;
QQmlApplicationEngine *AppEngine::mEngine = nullptr;
AppEngine::AppEngine(QGuiApplication *app, QQmlApplicationEngine *engine, QObject *parent) :
    QObject(parent)
{
    mApp = app;
    mEngine = engine;

}

int AppEngine::Exec()
{
    return  mApp->exec();
}

QQmlApplicationEngine *AppEngine::GetEngine()
{
    return  mEngine;
}

QString AppEngine::GetDataPath()
{
    return QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + PATH_VTISAYHI;
}

ScreenManager *AppEngine::GetScreenManager()
{
    return mScreenManager;
}

bool AppEngine::ConnectSignalsSlots()
{
    connect(this, &AppEngine::dataChanged, mStandByController, &StandbyController::OnDataChanged);
    connect(this, &AppEngine::dataChanged, mTechScreenController, &TechScrController::OnDataChanged);
    connect(this, &AppEngine::dataChanged, mNewsScrController, &NewsScrController::OnDataChanged);
    connect(this, &AppEngine::dataChanged, mNewsScrController, &StartUpScrController::OnDataChanged);
    return true;
}

bool AppEngine::DisConnectSignalsSlots()
{
    disconnect(this, &AppEngine::dataChanged, mStandByController, &StandbyController::OnDataChanged);
    disconnect(this, &AppEngine::dataChanged, mTechScreenController, &TechScrController::OnDataChanged);
    disconnect(this, &AppEngine::dataChanged, mNewsScrController, &NewsScrController::OnDataChanged);
    disconnect(this, &AppEngine::dataChanged, mNewsScrController, &StartUpScrController::OnDataChanged);
    return true;
}

int AppEngine::LoadMainQml()
{
    if(!mApp || !mEngine)
        return  -1;
    mEngine->load(QUrl(QStringLiteral("qrc:/Qml/main.qml")));
    if (mEngine->rootObjects().isEmpty())
        return -1;
    mScreenManager->reqGoTo(1);
    return  Exec();
}

AppEngine::~AppEngine()
{
    this->DisConnectSignalsSlots();

    if(!mApp)
    {
        delete mApp;
        mApp = nullptr;
    }

    if(!mEngine)
    {
        delete  mEngine;
        mEngine = nullptr;
    }

    if(!mScreenManager)
    {
        delete  mScreenManager;
        mScreenManager = nullptr;
    }

    if (!mStandByController)
    {
        delete mStandByController;
        mStandByController = nullptr;
    }

    if (!mTechScreenController)
    {
        delete mTechScreenController;
        mTechScreenController = nullptr;
    }

    if (!mNewsScrController)
    {
        delete mNewsScrController;
        mNewsScrController = nullptr;
    }

    if (!mStartUpScrController)
    {
        delete mStartUpScrController;
        mStartUpScrController = nullptr;
    }
}

int AppEngine::CreateObjects()
{
    mScreenManager = new ScreenManager();
    mStandByController = new StandbyController(this);
    mPeopleDetectManager = new PeopleDetectManager();
    mTechScreenController = new  TechScrController(this);
    mNewsScrController= new NewsScrController(this);
    mStartUpScrController = new StartUpScrController(this);
    return 1;
}

int AppEngine::InitObject()
{
    InitFolderPath();
    VTIEnum::declareQML();
    mScreenManager->Init();
    mPeopleDetectManager->SetUrl(DEFAULT_ADDRESS_WEBSERVER);
    mPeopleDetectManager->OpenConnection();
    return 1;
}

int AppEngine::InitFolderPath()
{
    QString vtiPath = GetDataPath();
    if(!QDir(vtiPath).exists())
    {
        QString source = SOURCE_PATH;
        VTIUtility::CopyRecursively(source + "/DataSample/VTISayHi/", vtiPath);
    }
    return  1;
}
int AppEngine::RegisterObjectToQml()
{
    mScreenManager->RegisterObjectToQml(mEngine);
    mStandByController->RegisterObjectToQml(mEngine);
    mTechScreenController->RegisterObjectToQml(mEngine);
    mNewsScrController->RegisterObjectToQml(mEngine);
    return  1;
}
