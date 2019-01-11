#include "StartupScrModel.h"
#include "AppEngine.h"

#include "AppEngine.h"
#include <QMetaObject>
#include <QQmlComponent>
#include <QQmlContext>
#include "Common/ConstDefines.h"
#include <QtDebug>


StartUpScrModel::StartUpScrModel(QObject *parent) : QObject(parent)
{
    setTitle("Weltome to VTI");
}

int StartUpScrModel::RegisterObjectToQml(QQmlApplicationEngine * engine)
{
    engine->rootContext()->setContextProperty(OBJ_STARTSCR_MODEL, this);
    return  1;
}

QString StartUpScrModel::title() const
{
    return m_title;
}

void StartUpScrModel::setTitle(QString title)
{
    if (m_title != title) {
        m_title = title;
        emit titleChanged(m_title);
    }
}
