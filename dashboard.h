
#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QWidget>
#include<scenemanager.h>
#include <QGraphicsProxyWidget>
#include <QLayout>
#include <QDockWidget>




class Dashboard : public QDockWidget
{
    Q_OBJECT

public:
    Dashboard(QWidget* parent = nullptr);
    virtual ~Dashboard(){};


};

#endif // DASHBOARD_H
