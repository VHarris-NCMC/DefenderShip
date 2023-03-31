#include "Player.h"
#include <array>






Player::Player(Vehicle* v)
{
    //draw the player vehicle
    vehicle = v;

}

Moveable* Player::getVehicle()
{
    if (vehicle == nullptr)
    {
        qDebug() << "Null";
    }
    return vehicle;
}

QGraphicsItem* Player::getGraphic()
{
    if (vehicle == nullptr)
    {
        qDebug() << "Graphic not found";
    }
    return vehicle;
}





