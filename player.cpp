#include "Player.h"



Player::Player()
{
    QWidget::grabKeyboard();
    vehicle = new Vehicle(new Model(1), new QPixmap(":/sprites/src/Spaceship1.PNG", "png", Qt::AutoColor));

    qDebug() << "Player Constructor 1: Player Created";
    StartTimer();

}
void Player::StartTimer()
{
    InputTimer = new QTimer();
    InputTimer->start(CONFIG::GameSpeed());
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
void Player::stopKeyAction(QKeyEvent* event)
{
	vehicle->stopInput(InputTimer, event);
};






