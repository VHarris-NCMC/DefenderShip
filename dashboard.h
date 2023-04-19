
#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QWidget>
#include <QGraphicsProxyWidget>
#include <QLayout>
#include <QDockWidget>
#include <UI_BUTTON.h>
#include <DashPanel.h>
#include <QPushButton>
#include <debug_dashboard.h>

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
    
    
    std::map<UI_BUTTON*,bool> fields = {
                                                     {new DASHBOARD_DEBUG_MASS(), true},
        {new DASHBOARD_DEBUG_LINEARDAMPING(), true},
        {new DASHBOARD_DEBUG_THRUST(), true},
        {new DASHBOARD_DEBUG_MAXTHRUST(), true}

    };
};

#endif // DASHBOARD_H
