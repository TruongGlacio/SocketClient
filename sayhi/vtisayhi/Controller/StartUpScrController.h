#ifndef STARTUPSCRCONTROLLER_H
#define STARTUPSCRCONTROLLER_H
#include <QObject>
#include "BaseController.h"
#include <qqmlapplicationengine.h>

class AppEngine;
class StartUpScrModel;
class StartUpScrController : public BaseController
{
public:
    StartUpScrController(AppEngine* engine);
    ~StartUpScrController();

    int RegisterObjectToQml(QQmlApplicationEngine * engine);
    virtual bool LoadData();

private:
    AppEngine *mAppEngine = nullptr;
    StartUpScrModel *mStartUpScrModel = nullptr;
};

#endif // STARTUPSCRCONTROLLER_H
