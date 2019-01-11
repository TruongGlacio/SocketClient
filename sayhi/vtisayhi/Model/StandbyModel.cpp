#include "StandbyModel.h"

StandbyModel::StandbyModel(QObject *parent) : QObject (parent)
{
    isCustomerVisit = false;
    mNewsList.append("file:///E:\\projects\\VTISayHi_New\\source\\vtisayhi\\vtisayhi\\DataSample\\VTISayHi\\StandBy\\News\\1.jpg");
    mNewsList.append("file:///E:\\projects\\VTISayHi_New\\source\\vtisayhi\\vtisayhi\\DataSample\\VTISayHi\\StandBy\\News\\2.jpg");
    mNewsList.append("file:///E:\\projects\\VTISayHi_New\\source\\vtisayhi\\vtisayhi\\DataSample\\VTISayHi\\StandBy\\News\\3.jpg");
    mNewsList.append("file:///E:\\projects\\VTISayHi_New\\source\\vtisayhi\\vtisayhi\\DataSample\\VTISayHi\\StandBy\\News\\4.jpg");
    mNewsList.append("file:///E:\\projects\\VTISayHi_New\\source\\vtisayhi\\vtisayhi\\DataSample\\VTISayHi\\StandBy\\News\\5.jpg");
    mNewsList.append("file:///E:\\projects\\VTISayHi_New\\source\\vtisayhi\\vtisayhi\\DataSample\\VTISayHi\\StandBy\\News\\6.jpg");

    mCurrentNewsIndex = 0;
    setImageScr(mNewsList.at(mCurrentNewsIndex));
    setVideoScr("file:///E:\\projects\\VTISayHi\\source\\vtisayhi\\vtisayhi\\DataSample\\VTISayHi\\StandBy\\Videos\\1.mp4");
}

StandbyModel::~StandbyModel()
{

}

QString StandbyModel::imageScr() const
{
    return mImageScr;
}

void StandbyModel::setImageScr(QString scr)
{
    mImageScr = scr;
    emit imageScrChanged(scr);
}

QString StandbyModel::videoScr() const
{
    return mVideoScr;
}

void StandbyModel::setVideoScr(QString scr)
{
    if (mVideoScr != scr){
        mVideoScr = scr;
        emit videoScrChanged(scr);
    }
}


QList<QString> StandbyModel::newsList()
{
    return mNewsList;
}

void StandbyModel::setNewsList(QList<QString> list)
{
    if(list.count() != 0)
    {
        mNewsList.clear();
        mNewsList = list;
        emit newsListChanged(list);
    }
}

bool StandbyModel::IsCustomerVisitUsToday()
{
    //TODO Check Date Time and return if
    // Cus visit us today.
    return false;
}
