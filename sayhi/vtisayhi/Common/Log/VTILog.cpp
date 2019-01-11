#include "VTILog.h"
#include <qlogging.h>
#include <qthread.h>

QWaitCondition VTILog::mWait;
QMutex VTILog::mMutex;
QQueue<QString> VTILog::mQueue;

VTILog::VTILog(QObject *parent) : QThread(parent)
{
    mOutfile.open("app.log", std::ios_base::app);
    mIsRunning = true;
    mQueue.append("===================================================================================================================\n");
    mQueue.append("===================================================================================================================\n");
    mQueue.append("===================================== Welcome to VTI Say Hi =======================================================\n");
    mQueue.append("===================================================================================================================\n");
    mQueue.append("===================================================================================================================\n");
    mQueue.append( "\n\n\n" );
    start();
}

VTILog::~VTILog()
{
    CRITICAL;
    mIsRunning = false;
    quit();
    wait();

    mOutfile << "\n\n\n";
    mOutfile << "===================================================================================================================\n";
    mOutfile << "===================================== Good Bye ====================================================================\n";
    mOutfile << "===================================================================================================================\n";
    mOutfile << "\n\n\n";
    mOutfile.close();
}

void VTILog::run()
{
    QString transact = "";
    while(mIsRunning)
    {
        msleep(100); // sleep 100 ms.
        QMutexLocker locker(&mMutex);
        if (mQueue.isEmpty())
            mWait.wait(&mMutex);
        transact = mQueue.dequeue();
        if(!transact.isEmpty())
        {
            mOutfile << transact.toStdString();
            transact.clear();
        }
    }

}

// Get the default Qt message handler.
static const QtMessageHandler QT_DEFAULT_MESSAGE_HANDLER = qInstallMessageHandler(nullptr);

void VTILog::OnLogHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QByteArray localMsg = msg.toLocal8Bit();
    QString message;
    switch (type)
    {
    case QtDebugMsg:
        message = QString("[DBG]: %1 (%2:%3, %4) %5\n").arg(localMsg.constData()).arg( context.file).arg( context.line).arg( context.function);
        break;
    case QtInfoMsg:
        message = QString("[INF]: %1 (%2:%3, %4)\n").arg(localMsg.constData()).arg( context.file).arg( context.line).arg( context.function);
        break;
    case QtWarningMsg:
        message = QString("[WRN]: %1 (%2:%3, %4)\n").arg(localMsg.constData()).arg( context.file).arg( context.line).arg( context.function);
        break;
    case QtCriticalMsg:
        message = QString("[CRT]: %1 (%2:%3, %4)\n").arg(localMsg.constData()).arg( context.file).arg( context.line).arg( context.function);
        break;
    case QtFatalMsg:
        message = QString("[FAT]: %1 (%2:%3, %4)\n").arg(localMsg.constData()).arg( context.file).arg( context.line).arg( context.function);
        abort();
    }

    QMutexLocker locker(&mMutex);
    mQueue.enqueue(message);
    mWait.wakeOne();

    // Call the default handler.
    (*QT_DEFAULT_MESSAGE_HANDLER)(type, context, msg);
}
