#ifndef VTILOG_H
#define VTILOG_H

#include <QMutex>
#include <QObject>
#include <QQueue>
#include <QThread>
#include <QWaitCondition>
#include <QtGlobal>
#include <fstream>
#include <QtDebug>
#include <QTime>

#define DEBUG qDebug() << "[" << QThread::currentThreadId() << "][" << QTime::currentTime().toString("hh:mm:ss.zzz") << "]"
#define WARNING qWarning() << "[" << QThread::currentThreadId() << "][" << QTime::currentTime().toString("hh:mm:ss.zzz") << "]"
#define CRITICAL qCritical() << "[" << QThread::currentThreadId() << "][" << QTime::currentTime().toString("hh:mm:ss.zzz") << "]"

class VTILog : public QThread
{
    Q_OBJECT
public:
    void static OnLogHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg);
    explicit VTILog(QObject *parent = nullptr);
    ~VTILog();
protected:
    void run();
signals:

public slots:

private:
    static QQueue<QString> mQueue;
    static QWaitCondition mWait;
    static QMutex mMutex;
    std::ofstream mOutfile;
    bool mIsRunning;
};

#endif // VTILOG_H
