#include "UT_AppEngine.h"
#include "TestCollector.h"

UT_AppEngine::UT_AppEngine()
{

}

UT_AppEngine::~UT_AppEngine()
{

}
void UT_AppEngine::TestCase1(){
    QVERIFY(1 + 1 == 2);
}
