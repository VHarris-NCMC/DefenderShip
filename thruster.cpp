
#include "thruster.h"

Thruster::Thruster()
{

}
qreal Thruster::thrust(bool engineOn)
{
    float max = (!isBraking) ? maxThrust : maxThrust * BRAKE_VALUE;
    if (engineOn)
    {
        if (currentThrust < max)
        {
            currentThrust += acceleration;
        }
        if (currentThrust > max)
        {
            currentThrust -= acceleration;
        }
    }
    else
    {
        if (currentThrust >= 0)
        {
            currentThrust-= acceleration;

        }
        else
        {
            currentThrust = 0;
        }
        return currentThrust / max;
    }

    qreal out = currentThrust / maxThrust;
    return out;
}
