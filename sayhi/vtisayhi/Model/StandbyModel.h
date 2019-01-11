#ifndef STANDBYMODEL_H
#define STANDBYMODEL_H
#include <QObject>
#include <QList>
#include "Common/GlobalTypes.h"

class StandbyModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString imageScr READ imageScr WRITE setImageScr NOTIFY imageScrChanged)
    Q_PROPERTY(QString videoScr READ videoScr WRITE setVideoScr NOTIFY videoScrChanged)
    Q_PROPERTY(QList<QString> newsList READ newsList WRITE setNewsList NOTIFY newsListChanged)
public:
    explicit StandbyModel(QObject *parent = nullptr);
    ~StandbyModel();

    QString imageScr() const;
    void setImageScr(QString scr);

    QString videoScr() const;
    void setVideoScr(QString scr);

    QList<QString> newsList();
    void setNewsList(QList<QString> list);
    bool IsCustomerVisitUsToday();

private:
    QString mImageScr;
    QString mVideoScr;
    QList<QString> mNewsList;
    bool isCustomerVisit;
    int mCurrentNewsIndex;
    QList<CustomerInfo> mCustomerList;

signals:
    void imageScrChanged(QString scr);
    void newsListChanged(QList<QString> list);
    void videoScrChanged(QString scr);

public slots:

};

#endif // STANDBYMODEL_H
