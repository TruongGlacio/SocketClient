#include "TechScrController.h"
#include "TechScrModel.h"
#include "AppEngine.h"
#include <QQmlContext>
#include <Common/ConstDefines.h>

TechScrController::TechScrController(AppEngine* engine)
{
    mAppEngine = engine;
    mTechScrModel = new TechScrModel();
}

TechScrController::~TechScrController()
{
    if (mTechScrModel != nullptr)
    {
        delete mTechScrModel;
        mTechScrModel = nullptr;
    }
}

int TechScrController::RegisterObjectToQml(QQmlApplicationEngine *engine)
{
    engine->rootContext()->setContextProperty(OBJ_TECHSCR_CONTROLLER, this);
    engine->rootContext()->setContextProperty(OBJ_TECHSCR_MODEL, mTechScrModel);
    return 1;
}

bool TechScrController::LoadData()
{
    //Implement DataLoade
    return BaseController::LoadData();
}
