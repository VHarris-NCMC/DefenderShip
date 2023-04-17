#include "Player.h"



Player::Player()
{
	qDebug() << "Player Constructor 1";
		QWidget::grabKeyboard();
		vehicle = new Vehicle(new Model(1));
		InputTimer = new QTimer();
        InputTimer->start(25);
        //draw the player vehicle



}

Vehicle* Player::getVehicle()
{
        return vehicle;
}
void Player::InitializeInput()
{
	input =  new InputManager();
}
void Player::keyPressEvent(QKeyEvent* event)
{
	if(event->isAutoRepeat())
	{
		return;
	}
	startKeyAction(event);
}
void Player::keyReleaseEvent(QKeyEvent* event)
{
	if(event->isAutoRepeat())
	{
		return;
	}
	stopKeyAction(event);
}
void Player::startKeyAction(QKeyEvent* event)
{
    vehicle->startInput(InputTimer, event);
}

void Player::increaseMass()
    {

    };
void Player::stopKeyAction(QKeyEvent* event)
{
	vehicle->stopInput(InputTimer, event);
};






