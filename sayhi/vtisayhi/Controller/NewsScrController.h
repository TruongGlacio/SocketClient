#ifndef NEWSSCRCONTROLLER_H
#define NEWSSCRCONTROLLER_H
#include <QObject>
#include "BaseController.h"
#include <qqmlapplicationengine.h>

class AppEngine;
class NewsScrModel;

class NewsScrController : public BaseController
{
public:
    NewsScrController(AppEngine* engine);
    ~NewsScrController();

    int RegisterObjectToQml(QQmlApplicationEngine * engine);
    virtual bool LoadData();

private:
    AppEngine *mAppEngine = nullptr;
    NewsScrModel *mNewsScrModel = nullptr;
};

#endif // NEWSSCRCONTROLLER_H
