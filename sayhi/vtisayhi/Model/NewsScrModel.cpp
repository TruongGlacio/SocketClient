#include "NewsScrModel.h"
#include "AppEngine.h"

#include "AppEngine.h"
#include <QMetaObject>
#include <QQmlComponent>
#include <QQmlContext>
#include "Common/ConstDefines.h"
#include <QtDebug>


NewsScrModel::NewsScrModel(QObject *parent) : QObject(parent)
{
    setLeftContent("123");
    setRightContent("345");
}

int NewsScrModel::RegisterObjectToQml(QQmlApplicationEngine * engine)
{
    engine->rootContext()->setContextProperty(OBJ_NEWSSCR_MODEL, this);
    return  1;
}


QString NewsScrModel::leftContent() const
{
    return m_leftContent;
}

void NewsScrModel::setLeftContent(QString leftContent)
{
    if (m_leftContent != leftContent) {
        m_leftContent = leftContent;
        emit leftContentChanged(m_leftContent);
    }


}

QString NewsScrModel::rightContent() const
{
    return m_rightContent;
}

void NewsScrModel::setRightContent(QString rightContent)
{
    if (m_rightContent != rightContent) {
        m_rightContent = rightContent;
        emit rightContentChanged(m_rightContent);
    }
}
