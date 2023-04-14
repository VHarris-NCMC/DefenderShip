
#include "thruster.h"

Thruster::Thruster()
{

}
qreal Thruster::thrust(bool engineOn)
{
    if (engineOn)
    {
        if (currentThrust < maxThrust)
        {
            currentThrust += acceleration;
        }
    }
    else
    {
        if (currentThrust >= 0)
        {
            currentThrust-= acceleration*2;

        }
        else
        {
            currentThrust = 0;
        }
    }

    return currentThrust / maxThrust;
}
