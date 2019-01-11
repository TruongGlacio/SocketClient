#ifndef STANDBYCONTROLLER_H
#define STANDBYCONTROLLER_H
#include <QObject>
#include <qguiapplication.h>
#include <qqmlapplicationengine.h>
#include "StandbyModel.h"
#include "AppEngine.h"
#include "BaseController.h"

class StandbyController : public BaseController
{
public:
    StandbyController(AppEngine *engine = nullptr);
    ~StandbyController();

    void Init();
    int RegisterObjectToQml(QQmlApplicationEngine * engine);
    virtual bool LoadData();
private:
    StandbyModel *mStandbyModel;
    AppEngine *mAppEngine;
signals:

public slots:
    void OnRequestShowScreen();
    bool OnNewData();

};

#endif // STANDBYCONTROLLER_H
