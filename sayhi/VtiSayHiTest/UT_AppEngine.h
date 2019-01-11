#ifndef UT_APPENGINE_H
#define UT_APPENGINE_H

#include <QObject>
#include "TestCollector.h"

class UT_AppEngine : public QObject
{
    Q_OBJECT
public:
    UT_AppEngine();
    ~UT_AppEngine();
private slots:
    void TestCase1();
};
ADD_TEST(UT_AppEngine)
#endif // UT_APPENGINE_H
