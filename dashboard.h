
#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QWidget>
#include <QGraphicsProxyWidget>
#include <QLayout>
#include <QDockWidget>
#include <DashboardField.h>
#include <DashPanel.h>
#include <QPushButton>

#include <debug_mass_dashboard.h>

class Dashboard : public QDockWidget
{
    Q_OBJECT
private:
    const int COLUMNS = 6;
    const int ROWS = 3;
public:
    Dashboard(QWidget* parent = nullptr);
    virtual ~Dashboard(){};



private:
    void addPanels(QLayout* layout);
    void addFields(QGridLayout* grid, QWidget* widget);


    std::map<DEBUG_MASS_DASHBOARD*,bool> fields = {
        {new DEBUG_MASS_DASHBOARD(), true},
        {new DEBUG_MASS_DASHBOARD(), true},
        {new DEBUG_MASS_DASHBOARD(), true},
        {new DEBUG_MASS_DASHBOARD(), true}

    };
};

#endif // DASHBOARD_H
