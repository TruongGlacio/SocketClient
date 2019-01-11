#ifndef TECHSCRMODEL_H
#define TECHSCRMODEL_H

#include <QObject>
#include <QDateTime>
#include <QMap>
#include <QQmlApplicationEngine>
#include <QStack>

class TechScrModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(QString techInfoPath READ techInfoPath WRITE setTechInfoPath NOTIFY techInfoPathChanged)
    Q_PROPERTY(QString techDeConLeft READ techDeConLeft WRITE setTechDeConLeft NOTIFY techDeConLeftChanged)
    Q_PROPERTY(QString techDeConRight READ techDeConRight WRITE setTechDeConRight NOTIFY techDeConRightChanged)
    QString m_title;

    QString m_techInfoPath;

    QString m_techDeConLeft;

    QString m_techDeConRight;

public:
    explicit TechScrModel(QObject *parent = nullptr);

    QString title() const;
    QString techInfoPath() const;
    QString techDeConLeft() const;
    QString techDeConRight() const;

    int RegisterObjectToQml(QQmlApplicationEngine * engine);

signals:

void titleChanged(QString title);

void techInfoPathChanged(QString techInfoPath);

void techDeConLeftChanged(QString techDeConLeft);

void techDeConRightChanged(QString techDeConRight);

public slots:
void setTitle(QString title);
void setTechInfoPath(QString techInfoPath);
void setTechDeConLeft(QString techDeConLeft);
void setTechDeConRight(QString techDeConRight);
};

#endif // TECHSCRMODEL_H
