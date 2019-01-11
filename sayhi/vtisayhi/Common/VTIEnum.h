#ifndef VTIENUM_H
#define VTIENUM_H

#include <QObject>
#include <QQmlEngine>
#include <QPoint>
class VTIEnum : public QObject
{
    Q_OBJECT
public:
    VTIEnum() : QObject() {}

    enum ScreenID : int
    {
        ScreenNone = 0,
        ScreenStartup,
        ScreenStandby,
        ScreenMenu,
        ScreenNews,
        ScreenCompanyStructure,
        ScreenPersonInfo,
        ScreenForFun,
        ScreenTechnology,
        ScreenTechnologyDetails
    };
    enum DetectResult: int
    {
        No_Face=0,
        Face
    };

    enum  DetectDataType: int
    {
        Location=0,

    };

    enum  DataType: int
    {
        News = 0,
        CompanyStructureInfo,
        CustomerInfo,
        GuiLineVideoInfo,
        StandbyVideoInfo,
        OtherInfo,
        PeopleDectectHandInfo,
        PeopleDectectInfo,
        TechInfo,
        UpdateStatus,
    };

    Q_ENUMS( ScreenID)
    Q_ENUMS( DetectResult)
    Q_ENUMS( DataType)
    Q_ENUMS( DetectDataType)
    static void declareQML() {
        qmlRegisterType<VTIEnum>("VTIEnum", 1, 1, "VTIEnum");
    }
signals:

public slots:
};

#endif // VTIENUM_H
