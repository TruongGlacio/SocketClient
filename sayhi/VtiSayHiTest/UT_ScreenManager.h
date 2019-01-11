#ifndef UT_SCREENMANAGER_H
#define UT_SCREENMANAGER_H
#include <QTest>
#include "Manager/ScreenManager.h"
#include "TestCollector.h"

class UT_ScreenManager: public QObject
{
    Q_OBJECT
public:
    UT_ScreenManager();
    ~UT_ScreenManager();
private slots:
    void TestCase1();
};
ADD_TEST(UT_ScreenManager)
#endif // UT_SCREENMANAGER_H
