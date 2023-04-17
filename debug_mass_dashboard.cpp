
#include "debug_mass_dashboard.h"
#include<scenemanager.h>
DEBUG_MASS_DASHBOARD::DEBUG_MASS_DASHBOARD(QWidget* parent) : DashboardField(parent)
{

}

QString DEBUG_MASS_DASHBOARD::fieldName(){ return  "Vehicle Mass : ";}

QWidget* DEBUG_MASS_DASHBOARD::ContentWidget(){ return new QLabel("VALUE"); }

void DEBUG_MASS_DASHBOARD::onUpButtonPressed()
{
    int val = SceneManager::Instance()->debug.debugMass(5);
//    QLabel label = (QLabel)Content;
//    label.setText("" + val);
   //GameManager::Instance()->getPlayer()->getVehicle()
}

void DEBUG_MASS_DASHBOARD::onDownButtonPressed(){

//    int val = SceneManager::Instance()->debug.debugMass(-5);
//    QLabel label = (QLabel)Content;
//    label.setText("" + val);
}

