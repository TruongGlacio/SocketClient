#include "BaseController.h"

BaseController::BaseController()
{

}

BaseController::~BaseController()
{

}

bool BaseController::LoadData()
{
    qDebug("BaseController::LoadData");
    //Derived class should implement them to load deserve data
    //Init and construct Data for use.
    //If everything OK, invoke method to send Data to Model

    return true;
}

void BaseController::OnDataChanged()
{
    LoadData();
}
