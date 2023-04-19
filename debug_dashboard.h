
#ifndef DEBUG_DASHBOARD_H
#define DEBUG_DASHBOARD_H

#include "Box2D/Common/b2Settings.h"
#include <DashboardField.h>

class DASHBOARD_DEBUG_MASS : public DashboardField
{

public:
    friend class debugger;
    explicit    DASHBOARD_DEBUG_MASS(QWidget* parent = nullptr);

    // DashboardField interface
protected:

protected slots:
    void onUpButtonPressed() override;
    void onDownButtonPressed() override;

private:
    const float32 DEBUG_CHANGE_VALUE = 0.25;

};
class DASHBOARD_DEBUG_LINEARDAMPING : public DashboardField
{

public:
    friend class debugger;
    explicit    DASHBOARD_DEBUG_LINEARDAMPING(QWidget* parent = nullptr);

    // DashboardField interface
protected:

protected slots:
    void onUpButtonPressed() override;
    void onDownButtonPressed() override;

private:
    const float32 DEBUG_CHANGE_VALUE = 0.2;
};

class DASHBOARD_DEBUG_THRUST : public DashboardField
{

public:
    friend class debugger;
    explicit DASHBOARD_DEBUG_THRUST(QWidget* parent = nullptr);

    // DashboardField interface
protected:

protected slots:
    void onUpButtonPressed() override;
    void onDownButtonPressed() override;

private:
    const float32 DEBUG_CHANGE_VALUE = 5;
};


class DASHBOARD_DEBUG_MAXTHRUST : public DashboardField
{

public:
    friend class debugger;
    explicit    DASHBOARD_DEBUG_MAXTHRUST(QWidget* parent = nullptr);

    // DashboardField interface
protected:

protected slots:
    void onUpButtonPressed() override;
    void onDownButtonPressed() override;

private:
    const float32 DEBUG_CHANGE_VALUE = 5;
};
#endif // DEBUG_DASHBOARD_H
