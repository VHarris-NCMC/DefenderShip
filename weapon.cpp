#include "weapon.h"

Weapon::Weapon(float rx, float ry)
{
    relativeX = rx;
    relativeY = ry;

}

float Weapon::getRelativeX() const
{
    return relativeX;
}

float Weapon::getRelativeY() const
{
    return relativeY;
}




