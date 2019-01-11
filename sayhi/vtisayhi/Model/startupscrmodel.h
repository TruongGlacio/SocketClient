#ifndef STARTUPSCRMODEL_H
#define STARTUPSCRMODEL_H

#include <QObject>
#include <QDateTime>
#include <QMap>
#include <QQmlApplicationEngine>
#include <QStack>

class StartUpScrModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    QString m_title;

public:
explicit StartUpScrModel(QObject *parent = nullptr);
QString title() const;
int RegisterObjectToQml(QQmlApplicationEngine * engine);

public slots:
void setTitle(QString title);
signals:
void titleChanged(QString title);
};

#endif // STARTUPSCRMODEL_H
