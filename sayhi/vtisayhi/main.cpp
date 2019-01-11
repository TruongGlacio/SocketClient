#include "AppEngine.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtGlobal>
#include <Common/Log/VTILog.h>
#include <QtDebug>
int main(int argc, char *argv[])
{
    VTILog log;
    qInstallMessageHandler(log.OnLogHandler); // Install the handler
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    AppEngine appEngine(&app, &engine);
    appEngine.CreateObjects();
    appEngine.InitObject();
    appEngine.RegisterObjectToQml();
    appEngine.ConnectSignalsSlots();
    return appEngine.LoadMainQml();
}
