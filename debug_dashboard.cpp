
#include "debug_dashboard.h"
#include "player.h"
#include<scenemanager.h>


//TODO: THIS SHOULD BE CONVERTED TO USE TEMPLATES OF 'CONTENT WIDGET' TYPE
DASHBOARD_DEBUG_MASS::DASHBOARD_DEBUG_MASS(QWidget* parent) : DashboardField(parent, QString("Vehicle Mass: "), new QLabel(QString::number(SceneManager::debugger::debugMass(0)))){}
void DASHBOARD_DEBUG_MASS::onUpButtonPressed()
{
    float32 val = SceneManager::Instance()->debug.debugLinearDamping(DEBUG_CHANGE_VALUE);
    auto label = (QLabel*)Content;
    label->setText(QString::number(val));
}
void DASHBOARD_DEBUG_MASS::onDownButtonPressed(){
    float32 val = SceneManager::Instance()->debug.debugLinearDamping(-DEBUG_CHANGE_VALUE);
    auto label = (QLabel*)Content;
    label->setText(QString::number(val));
}


DASHBOARD_DEBUG_LINEARDAMPING::DASHBOARD_DEBUG_LINEARDAMPING(QWidget* parent) : DashboardField(parent, QString("Linear Damping: "), new QLabel(QString::number(SceneManager::debugger::debugLinearDamping(0)))){}
void DASHBOARD_DEBUG_LINEARDAMPING::onUpButtonPressed()
{
    auto val = SceneManager::debugger::debugLinearDamping(DEBUG_CHANGE_VALUE);
    auto label = (QLabel*)Content;
    label->setText(QString::number(val));
}
void DASHBOARD_DEBUG_LINEARDAMPING::onDownButtonPressed()
{
    auto val = SceneManager::debugger::debugLinearDamping(-DEBUG_CHANGE_VALUE);
    auto label = (QLabel*)Content;
    label->setText(QString::number(val));
}

DASHBOARD_DEBUG_THRUST::DASHBOARD_DEBUG_THRUST(QWidget* parent) : DashboardField(parent, QString("Engine Thrust: "), new QLabel(QString::number(SceneManager::debugger::debugThrust(0)))){}
void DASHBOARD_DEBUG_THRUST::onUpButtonPressed()
{
    auto val = SceneManager::debugger::debugThrust(DEBUG_CHANGE_VALUE);
    auto label = (QLabel*)Content;
    label->setText(QString::number(val));
}
void DASHBOARD_DEBUG_THRUST::onDownButtonPressed()
{
    auto val = SceneManager::debugger::debugThrust(-DEBUG_CHANGE_VALUE);
    auto label = (QLabel*)Content;
    label->setText(QString::number(val));
}
DASHBOARD_DEBUG_MAXTHRUST::DASHBOARD_DEBUG_MAXTHRUST(QWidget* parent) : DashboardField(parent, QString("Engine Max Thrust: "), new QLabel(QString::number(SceneManager::debugger::debugMaxThrust(0)))){}
void DASHBOARD_DEBUG_MAXTHRUST::onUpButtonPressed()
{
    auto val = SceneManager::debugger::debugMaxThrust(DEBUG_CHANGE_VALUE);
    auto label = (QLabel*)Content;
    label->setText(QString::number(val));
}
void DASHBOARD_DEBUG_MAXTHRUST::onDownButtonPressed()
{
auto val = SceneManager::debugger::debugMaxThrust(-DEBUG_CHANGE_VALUE);
    auto label = (QLabel*)Content;
    label->setText(QString::number(val));
}
