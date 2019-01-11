#ifndef BASECONTROLLER_H
#define BASECONTROLLER_H

#include <QObject>
#include <QVariant>

class BaseController : public QObject
{
    Q_OBJECT
public:
    BaseController();
    virtual ~BaseController();
    virtual bool LoadData();
protected:
public slots:
    void OnDataChanged();
signals:
};

#endif // BASECONTROLLER_H
