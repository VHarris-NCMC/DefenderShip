#include <moveable.h>
#include <qDebug>


void Moveable::moveForward()
{


}

void Moveable::moveBackward()
{
    qDebug() << "Move backward";
}

void Moveable::turnLeft()
{
    qDebug() <<"Turn left";

}
void Moveable::turnRight()
{

    qDebug() <<"Turn right";
}
void Moveable::strafeRight()
{

}
void Moveable::strafeLeft()
{

}
float Moveable::getForwardSpd() const
{
    return forwardSpeed;
}

void Moveable::setForwardSpd(float speed)
{
    forwardSpeed = speed;
}

float Moveable::getBackwardSpeed() const
{
    return backwardSpeed;
}

void Moveable::setBackwardSpeed(float speed)
{
    backwardSpeed = speed;
}

float Moveable::getStrafeSpeed() const
{
    return strafeSpeed;
}

void Moveable::setStrafeSpeed(float speed)
{
    strafeSpeed = speed;
}

float Moveable::getTurnSpeed() const
{
    return turnSpeed;
}

void Moveable::setTurnSpeed(float speed)
{
    turnSpeed = speed;
}
