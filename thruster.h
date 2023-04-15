
#ifndef THRUSTER_H
#define THRUSTER_H

#include <Component.h>




class  Thruster
{
public:
    const float BRAKE_VALUE = .5f;
    float acceleration;
    float maxThrust;
    float  maxSpeed;
    float currentThrust;
    Thruster(float acceleration, float maxThrust_, float maxSpeed_) : acceleration(acceleration), maxThrust(maxThrust_), maxSpeed(maxSpeed_){};
    qreal thrust(bool engineOn);

    bool isBraking;

    Thruster();
};

#endif // THRUSTER_H
