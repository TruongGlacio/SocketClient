#ifndef APPENGINE_H
#define APPENGINE_H

#include "ScreenManager.h"
#include "Model/StartupScrModel.h"
#include "Model/NewsScrModel.h"
#include <QObject>
#include <qguiapplication.h>
#include <qqmlapplicationengine.h>
#include <Controller/BaseController.h>


class StandbyController;
class PeopleDetectManager;
class MouseController;
class TechScrController;
class NewsScrController;
class StartUpScrController;

class AppEngine : public QObject
{
    Q_OBJECT
public:
    explicit AppEngine(QGuiApplication *app, QQmlApplicationEngine *engine, QObject *parent = nullptr);
    ~AppEngine();

    int CreateObjects();
    int InitObject();
    int InitFolderPath();
    int RegisterObjectToQml();
    int LoadMainQml();
    int Exec();

    static QQmlApplicationEngine *GetEngine();
    static QString GetDataPath();
    ScreenManager *GetScreenManager();

    bool ConnectSignalsSlots();
    bool DisConnectSignalsSlots();
private:
    static QGuiApplication *mApp;
    static QQmlApplicationEngine *mEngine;
    ScreenManager *mScreenManager = nullptr;
    PeopleDetectManager *mPeopleDetectManager = nullptr;
    TechScrController *mTechScreenController = nullptr;
    NewsScrController *mNewsScrController = nullptr;
    StartUpScrController *mStartUpScrController = nullptr;
    StandbyController *mStandByController= nullptr;
signals:
    void dataChanged();
public slots:
};

#endif // APPENGINE_H
