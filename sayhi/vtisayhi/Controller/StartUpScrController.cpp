#include "StartUpScrController.h"
#include <Common/ConstDefines.h>
#include "AppEngine.h"
#include <QQmlContext>


StartUpScrController::StartUpScrController(AppEngine *engine)
{
    mAppEngine = engine;
    mStartUpScrModel = new StartUpScrModel();
}

StartUpScrController::~StartUpScrController()
{
    if (mStartUpScrModel != nullptr)
    {
        delete mStartUpScrModel;
        mStartUpScrModel = nullptr;
    }
}

int StartUpScrController::RegisterObjectToQml(QQmlApplicationEngine *engine)
{
    engine->rootContext()->setContextProperty(OBJ_STARTSCR_CONTROLLER, this);
    engine->rootContext()->setContextProperty(OBJ_STARTSCR_MODEL, mStartUpScrModel);
}

bool StartUpScrController::LoadData()
{
    //Implement DataLoade
    return BaseController::LoadData();
}
