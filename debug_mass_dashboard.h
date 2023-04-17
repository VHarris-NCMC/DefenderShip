
#ifndef DEBUG_MASS_DASHBOARD_H
#define DEBUG_MASS_DASHBOARD_H

#include <DashboardField.h>

class DEBUG_MASS_DASHBOARD : public DashboardField
{

public:
    friend class debugger;
explicit    DEBUG_MASS_DASHBOARD(QWidget* parent = nullptr);

    // DashboardField interface
protected:
    QString fieldName() override;
    QWidget* ContentWidget() override;

protected slots:
    void onUpButtonPressed() override;
    void onDownButtonPressed() override;
};

#endif // DEBUG_MASS_DASHBOARD_H
