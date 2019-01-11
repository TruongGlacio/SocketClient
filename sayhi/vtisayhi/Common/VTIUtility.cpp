#include "VTIUtility.h"
#include <QDir>
#include<QJsonObject>
#include <VTIEnum.h>
#include<PeopleDetectManager.h>
#include <ConstDefines.h>
#include <GlobalTypes.h>
#include<QIODevice>
VTIUtility::VTIUtility(QObject *parent) : QObject(parent)
{

}

bool VTIUtility::CopyRecursively(QString sourceFolder, QString destFolder)
{
    bool success = false;
    QDir sourceDir(sourceFolder);

    if(!sourceDir.exists())
        return false;

    QDir destDir(destFolder);
    if(!destDir.exists())
        destDir.mkdir(destFolder);

    QStringList files = sourceDir.entryList(QDir::Files);
    for(int i = 0; i< files.count(); i++) {
        QString srcName = sourceFolder + QDir::separator() + files[i];
        QString destName = destFolder + QDir::separator() + files[i];
        success = QFile::copy(srcName, destName);
        if(!success)
            return false;
    }

    files.clear();
    files = sourceDir.entryList(QDir::AllDirs | QDir::NoDotAndDotDot);
    for(int i = 0; i< files.count(); i++)
    {
        QString srcName = sourceFolder + QDir::separator() + files[i];
        QString destName = destFolder + QDir::separator() + files[i];
        success = CopyRecursively(srcName, destName);
        if(!success)
            return false;
    }

    return true;
}

QJsonObject VTIUtility::ReadJsonDataFile(QString filepath)
{
    QString jsonString;
    QFile file(filepath);
    QJsonObject jsonObject;
    if(file.exists()){
        qDebug()<<" File path  correct"<<endl;
        if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
            jsonString = file.readAll();
            file.close();
            qWarning() << jsonString;
            QJsonDocument doc = QJsonDocument::fromJson(jsonString.toUtf8());
            if(doc.isObject()){
                qDebug()<<"Json file is json format"<<endl;
                jsonObject = doc.object();
            }
            else {
                qDebug()<<"Json file not json format"<<endl;
            }
        }
        else {
            qDebug()<<"Can't open json file"<<endl;
        }
    }
    else {
        qDebug()<<" File path incorrect"<<endl;
    }
    return jsonObject;
}

void VTIUtility::WriteJsonFile(QString data, QString filepath)
{
    QFile file(filepath);
    if ( file.open(QIODevice::WriteOnly| QIODevice::Text) )
    {
        QTextStream stream( &file );
        stream << data << endl;
        qDebug()<<"Write json file finished"<<endl;
        file.close();
    }
    else {
        qDebug()<<"Can't open json file"<<endl;
    }
}

DectectData VTIUtility::ReadDectectDataJson(QJsonObject jsonObject)
{
    DectectData dectectData;
    QString     event;
    QJsonValue  data;
    QString     source;

    event = jsonObject.value(DETECT_EVENT).toString();
    data = jsonObject.value(DETECT_DATA);
    source = jsonObject.value(DETECT_SOURCE).toString();

    dectectData.event=event;
    dectectData.data=data;
    dectectData.source=source;
    qDebug()<<"DectectDataJson"<<endl;
    return  dectectData;
}

DectectHandData VTIUtility::ReadDectectHandDataJson( QJsonObject jsonObject)
{
    DectectHandData dectectHandData;
    QJsonArray scoreArray ;
    QJsonArray boxArray;
    QJsonArray box_centerArray;

    if(!jsonObject.isEmpty())
    {
        dectectHandData.className = jsonObject.value(DETECT_CLASS).toString();
        scoreArray = jsonObject.value(DETECT_SCORE).toArray();
        boxArray = jsonObject.value(DETECT_BOX).toArray();
        box_centerArray = jsonObject.value(DETECT_BOX_CENTRER).toArray();
        qDebug() << "handJson is an json object : \n className=" << dectectHandData.className<<"\n scoreString="<<scoreArray<<"\n boxString="<<boxArray<<"\n box_centerString= "<<box_centerArray<< endl;
        //detect score list
        for (int i = 0;i<scoreArray.count();i++) {
            dectectHandData.score.append(scoreArray.at(i).toString());
            qDebug()<<"dectectHandData.score.at("<<i<<")"<<dectectHandData.score.at(i)<<endl;
        }
        for (int i = 0;i<boxArray.count();i++) {
            dectectHandData.box.append(boxArray.at(i).toString());
            qDebug()<<"dectectHandData.box.at("<<i<<")"<<dectectHandData.box.at(i)<<endl;

        }
        dectectHandData.box_center.setX(box_centerArray.at(DETECT_X).toString().toInt());
        dectectHandData.box_center.setY(box_centerArray.at(DETECT_Y).toString().toInt());
        qDebug() << "box_center value :X=" <<dectectHandData.box_center.x()
                 <<"Y="<<dectectHandData.box_center.y()<< endl;
    }
    else
    {
        qDebug() << "handJson is empty object" << endl;
    }
    return dectectHandData;
}

CompanyData VTIUtility::ReadCompanyDataJson(QJsonObject jsonObject)
{
    CompanyData companyData;

    companyData.name = jsonObject.value(COMPANY_NAME).toString();
    companyData.createDate = jsonObject.value(COMPANY_CREATDATE).toString();
    qDebug()<<"DataJson parse from jsonObject \n companyDataName="<<companyData.name+"\n CompanyDataCreatDate="<<companyData.createDate<<endl;

    return  companyData;
}

CustomerData VTIUtility::ReadCustomerDataJson(QJsonObject jsonObject)
{

    CustomerData customerData;
    QJsonArray jsonArray;
    CustomerInfo customerInfo;
    QJsonObject jsonObjectItem;

    customerData.createDate = jsonObject.value(CUSTOMER_CREATDATE).toString();
    jsonArray = jsonObject.value(CUSTOMER_DATA).toArray();
    try {
        for(int i = 0;i<jsonArray.count();i++){
            jsonObjectItem = jsonArray.at(i).toObject();
            if(!jsonObjectItem.isEmpty()){
                customerInfo.name = jsonObjectItem.value(CUSTOMER_NAME).toString();
                customerInfo.company = jsonObjectItem.value(CUSTOMER_COMPANY).toString();
                customerInfo.detail = jsonObjectItem.value(CUSTOMER_DETAIL).toString();
                customerInfo.visitDate = jsonObjectItem.value(CUSTOMER_VISITDATE).toString();
                customerInfo.duration = jsonObjectItem.value(CUSTOMER_DURATION).toString().toInt();
                customerData.info.append(customerInfo);
                qDebug()<<"DataJson parse from jsonObject \n customerInfoName="
                       << customerInfo.name + "\n customerInfocompany="
                       << customerInfo.company + "\n customerInfo.detail= "
                       << customerInfo.detail + "\n customerInfo.visitDate="
                       << customerInfo.visitDate + "\n customerInfo.duration= "
                       << customerInfo.duration << endl;
            }

        }
    } catch (QException e) {
        qDebug()<<"Error when read json object"<<endl;
    }

    return  customerData;
}

GuilineVideo VTIUtility::ReadGuilineVideoDataJson(QJsonObject jsonObject)
{
    GuilineVideo  guilineVideo;

    guilineVideo.name = jsonObject.value(GUILINE_NAME).toString();
    guilineVideo.creatdate = jsonObject.value(GUILINE_CREATDATE).toString();
    qDebug()<<"DataJson parse from jsonObject \n  guilineVideo.name="
           <<guilineVideo.name+"\n guilineVideo.creatdate="
          <<guilineVideo.creatdate<<endl;
    return  guilineVideo;
}

StandbyVideo VTIUtility::ReadStandbyVideoDataJson(QJsonObject jsonObject)
{
    StandbyVideo standbyVideo;


    standbyVideo.name = jsonObject.value(STANDBY_VIDEO_NAME).toString();
    standbyVideo.creatdate = jsonObject.value(STANDBY_VIDEO_CREATDATE).toString();
    qDebug()<<"DataJson parse from jsonObject \n  standbyVideo.name="
           <<standbyVideo.name+"\n standbyVideo.creatdate="
          <<standbyVideo.creatdate<<endl;
    return  standbyVideo;
}

OtherInforData VTIUtility::ReadOtherInfoJsonJson(QJsonObject jsonObject)
{
    OtherInforData forFunData;
    QJsonArray jsonArray;

    forFunData.createDate = jsonObject.value(FORFUN_CREATDATE).toString();
    jsonArray = jsonObject.value(FORFUN_DATA).toArray();
    try {
        for(int i = 0; i<jsonArray.count();i++){
            forFunData.data.append(jsonArray.at(i).toString());
            qDebug()<<"DataJson parse from jsonObject \n   forFunData.data("<<i<<")="
                   <<forFunData.data.at(i)
                  <<endl;
        }
    } catch (QException e) {
        qDebug()<<"Error when read json object"<<endl;
    }
    return  forFunData;
}

NewsData VTIUtility::ReadNewsDataJson(QJsonObject jsonObject)
{
    NewsData newsData;
    QJsonArray jsonArray;

    newsData.createDate = jsonObject.value(NEWS_CREATDATE).toString();
    jsonArray = jsonObject.value(NEWS_DATA).toArray();
    try {
        for (int i = 0;i<jsonArray.count();i++) {
            newsData.data.append(jsonArray.at(i).toString());
            qDebug()<<"DataJson parse from jsonObject \n  newsData.data("<<i<<")="
                   <<newsData.data.at(i)
                  <<endl;
        }
    } catch (QException e) {
        qDebug()<<"Error when read json object"<<endl;
    }
    return newsData;
}

ConfigTechnologies VTIUtility::ReadTechInfoDataJson(QJsonObject jsonObject)
{
    ConfigTechnologies techInfoData;
    QJsonArray aIInfoArray;
    QJsonArray iOTnfoArray;
    QJsonArray cloudInfoArray;
    QJsonArray embeddedInfoArray;

    techInfoData.createDate = jsonObject.value(TECHINFO_CREATDATE).toString();
    techInfoData.mainImagePath = jsonObject.value(TECHINFO_IMAGEPATH).toString();
    aIInfoArray = jsonObject.value(TECHINFO_AI).toArray();
    iOTnfoArray = jsonObject.value(TECHINFO_IOT).toArray();
    cloudInfoArray = jsonObject.value(TECHINFO_CLOUD).toArray();
    embeddedInfoArray = jsonObject.value(TECHINFO_EMBEDDED).toArray();
    for (int i = 0;i<aIInfoArray.count();i++) {
        techInfoData.aIInfo.append(aIInfoArray.at(i).toString());
        qDebug()<<"DataJson parse from jsonObject \n  techInfoData.aIInfo("<<i<<")="
               <<techInfoData.aIInfo.at(i)
              <<endl;
    }
    for(int i = 0;i<iOTnfoArray.count();i++){
        techInfoData.iOTInfo.append(iOTnfoArray.at(i).toString());
        qDebug()<<"DataJson parse from jsonObject \n  techInfoData.iOTInfo("<<i<<")="
               <<techInfoData.iOTInfo.at(i)
              <<endl;

    }
    for (int i = 0;i<cloudInfoArray.count();i++) {
        techInfoData.cloudInfo.append(cloudInfoArray.at(i).toString());
        qDebug()<<"DataJson parse from jsonObject \n techInfoData.cloudInfo("<<i<<")="
               <<techInfoData.cloudInfo.at(i)
              <<endl;
    }
    for(int i = 0;i<embeddedInfoArray.count();i++){
        techInfoData.embeddedInfo.append(embeddedInfoArray.at(i).toString());
        qDebug()<<"DataJson parse from jsonObject \n  newsData.data("<<i<<")="
               <<techInfoData.embeddedInfo.at(i)
              <<endl;
    }
    return  techInfoData;
}

UpdateStatusData VTIUtility::ReadUpdateStatusDataJson(QJsonObject jsonObject)
{
    UpdateStatusData updateStatusData;

    if(!jsonObject.isEmpty())
    {
        updateStatusData.newsInfo = jsonObject.value(UPDATESTATUS_NEWSINFO).toBool();
        updateStatusData.customerInfo = jsonObject.value(UPDATESTATUS_CUSTOMERINFO).toBool();
        updateStatusData.othersScreenInfo = jsonObject.value(UPDATESTATUS_OTHERSSCREENINFO).toBool();
        updateStatusData.techInfo = jsonObject.value(UPDATESTATUS_TECHINFO).toBool();
        updateStatusData.companyStructureInfo = jsonObject.value(UPDATESTATUS_COMPANYSTRUCTUREINFO).toBool();
        updateStatusData.standbyVideo = jsonObject.value(UPDATESTATUS_STANDBYVIDEO).toBool();
        updateStatusData.guidelineVideo = jsonObject.value(UPDATESTATUS_GUIDELINEVIDEO).toBool();
        qDebug()<<"DataJson parse from jsonObject \n  standbyVideo.name="
               <<updateStatusData.newsInfo <<"\n updateStatusData.customerInfo="
              <<updateStatusData.customerInfo<<"\n updateStatusData.othersScreenInfo="
             <<updateStatusData.othersScreenInfo<<"\n updateStatusData.techInfo="
            <<updateStatusData.techInfo<<"\n updateStatusData.companyStructureInfo="
           <<updateStatusData.companyStructureInfo <<"\n updateStatusData.standbyVideo="
          <<updateStatusData.standbyVideo <<"\n updateStatusData.guidelineVideo="
         <<updateStatusData.guidelineVideo<<endl;
    }
    return  updateStatusData;
}

GenaralJson VTIUtility::ReadDataJson(QJsonObject jsonObject, VTIEnum::DataType dataType)
{
    GenaralJson genaralJson;
    switch (dataType) {
    case VTIEnum::DataType::News:
    {
        genaralJson.newsData = ReadNewsDataJson(jsonObject);
        break;
    }
    case VTIEnum::DataType::CompanyStructureInfo:
        genaralJson.companyData = ReadCompanyDataJson(jsonObject);
        break;
    case VTIEnum::DataType::CustomerInfo:
        genaralJson.customerData = ReadCustomerDataJson(jsonObject);
        break;
    case VTIEnum::DataType::GuiLineVideoInfo:
        genaralJson.guilineVideo = ReadGuilineVideoDataJson(jsonObject);
        break;
    case VTIEnum::DataType::StandbyVideoInfo:
        genaralJson.standbyVideo = ReadStandbyVideoDataJson(jsonObject);
        break;
    case VTIEnum::DataType::OtherInfo:
        genaralJson.otherInforData = ReadOtherInfoJsonJson(jsonObject);
        break;
    case VTIEnum::DataType::PeopleDectectHandInfo:
        genaralJson.dectectHandData = ReadDectectHandDataJson(jsonObject);
        break;
    case VTIEnum::DataType::PeopleDectectInfo:
        genaralJson.dectectData = ReadDectectDataJson(jsonObject);
        break;
    case VTIEnum::DataType::TechInfo:
        genaralJson.configTechnologies = ReadTechInfoDataJson(jsonObject);
        break;
    case VTIEnum::DataType::UpdateStatus:
        genaralJson.updateStatusData = ReadUpdateStatusDataJson(jsonObject);
        break;
    default :break;
    }
}

Config VTIUtility::ReadConfigDataJson(QString filepath)
{

    Config config;
    QJsonArray newinfoArray;
    QJsonArray customerInfoArray;
    QJsonObject techoInfoObject;
    QJsonArray otherInfoArray;
    QJsonArray techIOTInfoArray;
    QJsonArray techAIInfoArray;
    QJsonArray techCloudArray;
    QJsonArray techEmbeddedInfoArray;
    QJsonObject customerInfoJsonItem;
    CustomerInfo customerInfoItem;
    QJsonObject jsonObject;

    jsonObject = ReadJsonDataFile(filepath);
    config.creatDate = jsonObject.value(CONFIG_CREATDATE).toString();
    config.data.companyStructureImagePath = jsonObject.value(CONFIG_DATA_COMPANYSTRUCTURE).toString();
    config.data.standbyVideoPath = jsonObject.value(CONFIG_DATA_STANDBYVIDEO).toString();
    config.data.menuVideoPath = jsonObject.value(CONFIG_DATA_MENU_VIDEO).toString();
    newinfoArray = jsonObject.value(CONFIG_DATA_NEWS).toArray();
    customerInfoArray = jsonObject.value(CONFIG_DATA_CUSTOMERINFO).toArray();
    techoInfoObject = jsonObject.value(CONFIG_DATA_TECHNOLOGIES).toObject();
    otherInfoArray = jsonObject.value(CONFIG_DATA_OTHERSINFO).toArray();
    qDebug()<< "Data parse from json object is: \n config.creatDate="<< config.creatDate
            << "\n config.data.companyStructureImagePath="<<config.data.companyStructureImagePath
            << "\n config.data.standbyVideoPath"<<config.data.standbyVideoPath
            <<"\n  config.data.menuVideoPath"<<  config.data.menuVideoPath<< endl;

    // parse data for Newinfor
    for(int i = 0;i<newinfoArray.count();i++){
        config.data.newsInfo.append(newinfoArray.at(i).toString());
        qDebug()<< "config.data.newsInfo..at("<<i<<")="<< config.data.newsInfo.at(i)<<endl;

    }

    // parse data for TechnologiesInfor
    if(!techoInfoObject.isEmpty()){
        config.data.technologies.mainImagePath = techoInfoObject.value(CONFIG_DATA_TECHNOLOGIES_IMAGEPATH).toString();
        techAIInfoArray = techoInfoObject.value(CONFIG_DATA_TECHNOLOGIES_AI).toArray();
        techIOTInfoArray = techoInfoObject.value(CONFIG_DATA_TECHNOLOGIES_IOT).toArray();
        techCloudArray = techoInfoObject.value(CONFIG_DATA_TECHNOLOGIES_CLOUD).toArray();
        techEmbeddedInfoArray = techoInfoObject.value(CONFIG_DATA_TECHNOLOGIES_EMBEDDED).toArray();

        for (int i = 0;i<techAIInfoArray.count();i++) {
            config.data.technologies.aIInfo.append(techAIInfoArray.at(i).toString());
            qDebug()<< " config.data.technologies.aIInfo.at("<<i<<")="<< config.data.technologies.aIInfo.at(i)<<endl;
        }
        for(int i = 0;i<techIOTInfoArray.count();i++){
            config.data.technologies.iOTInfo.append(techIOTInfoArray.at(i).toString());
            qDebug()<< " config.data.technologies.iOTInfo.at("<<i<<")="<< config.data.technologies.iOTInfo.at(i)<<endl;

        }
        for (int i = 0;i<techCloudArray.count();i++) {
            config.data.technologies.cloudInfo.append(techCloudArray.at(i).toString());
            qDebug()<< " config.data.technologies.cloudInfo.at("<<i<<")="<< config.data.technologies.cloudInfo.at(i)<<endl;

        }
        for(int i = 0;i<techEmbeddedInfoArray.count();i++){
            config.data.technologies.embeddedInfo.append(techEmbeddedInfoArray.at(i).toString());
            qDebug()<< " config.data.technologies.embeddedInfo.at("<<i<<")="<< config.data.technologies.embeddedInfo.at(i)<<endl;
        }
    }

    // parse data for customerInfo
    for(int i=0;i<customerInfoArray.count();i++){

        customerInfoJsonItem = customerInfoArray.at(i).toObject();
        if(!customerInfoJsonItem.isEmpty()){
            customerInfoItem.name = customerInfoJsonItem.value(CONFIG_DATA_NAME).toString();
            customerInfoItem.company = customerInfoJsonItem.value(CONFIG_DATA_COMPANY).toString();
            customerInfoItem.detail = customerInfoJsonItem.value(CONFIG_DATA_DETAIL).toString();
            customerInfoItem.visitDate = customerInfoJsonItem.value(CONFIG_DATA_VISITDATE).toString();
            customerInfoItem.duration = customerInfoJsonItem.value(CONFIG_DATA_DURATION).toInt();
            qDebug()<< "Data parse from json object is: \ncustomerInfoItem.name="<< customerInfoItem.name
                    << "\n customerInfoItem.company="<<customerInfoItem.company
                    << "\n customerInfoItem.detail"<<customerInfoItem.detail
                    <<"\n  customerInfoItem.visitDate"<<  customerInfoItem.visitDate
                   << "\n customerInfoItem.duration"<<customerInfoItem.duration
                   << endl;
            config.data.customerInfo.append(customerInfoItem);
        }
    }

    // parse data for otherInfo
    for (int i = 0;i<otherInfoArray.count();i++) {
        config.data.othersInfo.append(otherInfoArray.at(i).toString());
        qDebug()<< "config.data.othersInfo.at("<<i<<")="<< config.data.othersInfo.at(i)<<endl;

    }
    return config;
}

void VTIUtility::WriteConfigDataJson(Config config,QString filepath)
{
    QJsonArray newinfoArray;
    QJsonArray customerInfoArray;
    QJsonObject techoInfoObject;
    QJsonArray otherInfoArray;
    QJsonArray techIOTInfoArray;
    QJsonArray techAIInfoArray;
    QJsonArray techCloudArray;
    QJsonArray techEmbeddedInfoArray;
    QJsonObject customerInfoJsonItem;
    CustomerInfo customerInfoItem;
    QJsonObject jsonConfig;

    jsonConfig.insert(CONFIG_CREATDATE, QJsonValue(config.creatDate));
    jsonConfig.insert(CONFIG_DATA_COMPANYSTRUCTURE, QJsonValue(config.data.companyStructureImagePath));
    jsonConfig.insert(CONFIG_DATA_STANDBYVIDEO, QJsonValue(config.data.standbyVideoPath));
    jsonConfig.insert(CONFIG_DATA_MENU_VIDEO, QJsonValue(config.data.menuVideoPath));
    // insert data for Newinfor
    for(int i = 0;i< config.data.newsInfo.count();i++){
        newinfoArray.insert(i,config.data.newsInfo.at(i));
        qDebug()<< "newinfoArray.at("<<i<<")="<< newinfoArray.at(i)<<endl;
    }

    jsonConfig.insert(CONFIG_DATA_NEWS, QJsonValue(newinfoArray));
    // insert data for otherInfo
    for (int i = 0;i<config.data.othersInfo.count();i++) {
        otherInfoArray.insert(i,config.data.othersInfo.at(i));
        qDebug()<< "otherInfoArray.at("<<i<<")="<< otherInfoArray.at(i)<<endl;
    }
    jsonConfig.insert(CONFIG_DATA_OTHERSINFO, QJsonValue(otherInfoArray));

    // insert data for TechnologiesInfor
    for (int i = 0;i<config.data.technologies.aIInfo.count();i++) {
        techAIInfoArray.insert(i,config.data.technologies.aIInfo.at(i));
        qDebug()<< " techAIInfoArray.at("<<i<<")="<< techAIInfoArray.at(i)<<endl;
    }
    for(int i = 0;i<config.data.technologies.iOTInfo.count();i++){
        techIOTInfoArray.insert(i,config.data.technologies.iOTInfo.at(i));
        qDebug()<< "techIOTInfoArray.at("<<i<<")="<<techIOTInfoArray.at(i)<<endl;

    }
    for (int i = 0;i<config.data.technologies.cloudInfo.count();i++) {
        techCloudArray.insert(i,config.data.technologies.cloudInfo.at(i));
        qDebug()<< " techCloudArray.at("<<i<<")="<<techCloudArray.at(i)<<endl;

    }
    for(int i = 0;i<config.data.technologies.embeddedInfo.count();i++){
        techEmbeddedInfoArray.insert(i,config.data.technologies.embeddedInfo.at(i));
        qDebug()<< " techEmbeddedInfoArray.at("<<i<<")="<< techEmbeddedInfoArray.at(i)<<endl;
    }
    techoInfoObject.insert(CONFIG_DATA_TECHNOLOGIES_AI,QJsonValue(techAIInfoArray));
    techoInfoObject.insert(CONFIG_DATA_TECHNOLOGIES_IOT,QJsonValue(techIOTInfoArray));
    techoInfoObject.insert(CONFIG_DATA_TECHNOLOGIES_CLOUD,QJsonValue(techCloudArray));
    techoInfoObject.insert(CONFIG_DATA_TECHNOLOGIES_EMBEDDED,QJsonValue(techEmbeddedInfoArray));
    techoInfoObject.insert(CONFIG_DATA_TECHNOLOGIES_IMAGEPATH,QJsonValue(config.data.technologies.mainImagePath));
    jsonConfig.insert(CONFIG_DATA_TECHNOLOGIES,QJsonValue(techoInfoObject));

    // parse data for customerInfo
    for(int i = 0;i< config.data.customerInfo.count();i++){

        customerInfoItem = config.data.customerInfo.at(i);
        customerInfoJsonItem.insert(CONFIG_DATA_NAME,QJsonValue(customerInfoItem.name));
        customerInfoJsonItem.insert(CONFIG_DATA_COMPANY,QJsonValue( customerInfoItem.company));
        customerInfoJsonItem.insert(CONFIG_DATA_DETAIL,QJsonValue(customerInfoItem.detail));
        customerInfoJsonItem.insert(CONFIG_DATA_VISITDATE,QJsonValue( customerInfoItem.visitDate));
        customerInfoJsonItem.insert(CONFIG_DATA_DURATION,QJsonValue(customerInfoItem.duration));
        customerInfoArray.insert(i,QJsonValue(customerInfoJsonItem));
    }
    jsonConfig.insert(CONFIG_DATA_CUSTOMERINFO, QJsonValue(customerInfoArray));

    QJsonDocument doc(jsonConfig);
    QString strJson(doc.toJson(QJsonDocument::Compact));
    WriteJsonFile(strJson,filepath);
}

