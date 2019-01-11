#ifndef TECHSCRCONTROLLER_H
#define TECHSCRCONTROLLER_H
#include <QObject>
#include "BaseController.h"
#include <qqmlapplicationengine.h>
class AppEngine;
class TechScrModel;

class TechScrController : public BaseController
{
public:
    TechScrController(AppEngine* engine);
    ~TechScrController();

    int RegisterObjectToQml(QQmlApplicationEngine * engine);
    virtual bool LoadData();

private:
    AppEngine *mAppEngine = nullptr;
    TechScrModel *mTechScrModel = nullptr;
};

#endif // TECHSCRCONTROLLER_H
