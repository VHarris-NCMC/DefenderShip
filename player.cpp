#include "Player.h"
#include <array>






Player::Player()
{
    //draw the player vehicle
    vehicle = new Vehicle(true);

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





