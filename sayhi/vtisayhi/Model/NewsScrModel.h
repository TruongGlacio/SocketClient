#ifndef NEWSSCRMODEL_H
#define NEWSSCRMODEL_H

#include <QObject>

#include <QObject>
#include <QDateTime>
#include <QMap>
#include <QQmlApplicationEngine>
#include <QStack>

class NewsScrModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString leftContent READ leftContent WRITE setLeftContent NOTIFY leftContentChanged)
    Q_PROPERTY(QString rightContent READ rightContent WRITE setRightContent NOTIFY rightContentChanged)

    QString m_leftContent;

    QString m_rightContent;

public:
explicit NewsScrModel(QObject *parent = nullptr);
int RegisterObjectToQml(QQmlApplicationEngine * engine);

QString leftContent() const;
QString rightContent() const;

public slots:

void setLeftContent(QString leftContent);
void setRightContent(QString rightContent);

signals:

void leftContentChanged(QString leftContent);
void rightContentChanged(QString rightContent);
};

#endif // NEWSSCRMODEL_H
