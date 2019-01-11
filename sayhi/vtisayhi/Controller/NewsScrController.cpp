#include "NewsScrController.h"
#include "NewsScrModel.h"
#include "AppEngine.h"
#include <QQmlContext>
#include <Common/ConstDefines.h>
NewsScrController::NewsScrController(AppEngine *engine)
{
    mAppEngine = engine;
    mNewsScrModel = new NewsScrModel();
}

NewsScrController::~NewsScrController()
{
    if (mNewsScrModel != nullptr)
    {
        delete mNewsScrModel;
        mNewsScrModel = nullptr;
    }
}

int NewsScrController::RegisterObjectToQml(QQmlApplicationEngine *engine)
{
    engine->rootContext()->setContextProperty(OBJ_NEWSSCR_CONTROLLER, this);
    engine->rootContext()->setContextProperty(OBJ_NEWSSCR_MODEL, mNewsScrModel);
}

bool NewsScrController::LoadData()
{
    //Implement DataLoade
    return BaseController::LoadData();
}
