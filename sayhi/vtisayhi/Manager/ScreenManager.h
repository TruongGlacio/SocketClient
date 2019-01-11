#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include <QDateTime>
#include <QMap>
#include <QObject>
#include <QQmlApplicationEngine>
#include <QStack>
#include "Common/VTIEnum.h"
class ScreenManager : public QObject
{
    Q_OBJECT
public:
    explicit ScreenManager(QObject *parent = nullptr);
    ~ScreenManager();
    void Init();
    int RegisterObjectToQml(QQmlApplicationEngine * engine);

    Q_INVOKABLE void reqGoTo(int id = 0);

private:
    QMap<int, QString> mScreenMap;
    QStack<int> mScreenStack;
signals:

public slots:
};

#endif // SCREENMANAGER_H
