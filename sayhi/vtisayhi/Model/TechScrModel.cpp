#include "TechScrModel.h"
#include "AppEngine.h"

#include "AppEngine.h"
#include <QMetaObject>
#include <QQmlComponent>
#include <QQmlContext>
#include "Common/ConstDefines.h"
#include <QtDebug>
#include <Model/TechScrModel.h>


TechScrModel::TechScrModel(QObject *parent) : QObject(parent)
{
    setTitle("VTI say 2");
    setTechInfoPath("");
    setTechDeConLeft("In computer science, artificial intelligence (AI), sometimes called machine intelligence, is intelligence demonstrated by machines, in contrast to the natural intelligence displayed by humans and other animals. Computer science defines AI research as the study of \"intelligent agents\": any device that perceives its environment and takes actions that maximize its chance of successfully achieving its goals.[1] More in detail, Kaplan and Haenlein define AI as “a system’s ability to correctly interpret external data, to learn from such data, and to use those learnings to achieve specific goals and tasks through flexible adaptation”.[2] Colloquially, the term \"artificial intelligence\" is applied when a machine mimics \"cognitive\" functions that humans associate with other human minds, such as \"learning\" and \"problem solving\"");
    setTechDeConRight("The scope of AI is disputed: as machines become increasingly capable, tasks considered as requiring \"intelligence\" are often removed from the definition, a phenomenon known as the AI effect, leading to the quip in Tesler's Theorem, \"AI is whatever hasn't been done yet.\"[4] For instance, optical character recognition is frequently excluded from \"artificial intelligence\", having become a routine technology.[5] Modern machine capabilities generally classified as AI include successfully understanding human speech,[6] competing at the highest level in strategic game systems (such as chess and Go),[7] autonomously operating cars, and intelligent routing in content delivery networks and military simulations.");
}

int TechScrModel::RegisterObjectToQml(QQmlApplicationEngine * engine)
{
    engine->rootContext()->setContextProperty(OBJ_TECHSCR_MODEL, this);
    return  1;
}

QString TechScrModel::title() const
{
    return m_title;
}

void TechScrModel::setTitle(QString title)
{
    if (m_title != title) {
        m_title = title;
        emit titleChanged(m_title);
    }
}

QString TechScrModel::techInfoPath() const
{
    return m_techInfoPath;
}

void TechScrModel::setTechInfoPath(QString techInfoPath)
{
    if (m_techInfoPath != techInfoPath) {
        m_techInfoPath = techInfoPath;
        emit techInfoPathChanged(m_techInfoPath);
    }
}


QString TechScrModel::techDeConLeft() const
{
    return m_techDeConLeft;
}

void TechScrModel::setTechDeConLeft(QString techDeConLeft)
{
    if (m_techDeConLeft != techDeConLeft){
        m_techDeConLeft = techDeConLeft;
        emit techDeConLeftChanged(m_techDeConLeft);
    }
}

QString TechScrModel::techDeConRight() const
{
    return m_techDeConRight;
}

void TechScrModel::setTechDeConRight(QString techDeConRight)
{
    if (m_techDeConRight != techDeConRight){
        m_techDeConRight = techDeConRight;
        emit techDeConRightChanged(m_techDeConRight);
    }
}
