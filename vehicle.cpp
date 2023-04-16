#include <vehicle.h>

//Updates based on game speed, adjust vehicle graphics position / rotation
void Vehicle::move()
{


}
Vehicle::Vehicle() : GameObject(new struct Model(1))
{
	qDebug() << "Vehicle Constructor 1";
}
Vehicle::Vehicle(struct Model* m) : GameObject(m)
{
    qDebug() << "Vehicle Constructor 2";
}

void Vehicle::startInput(QTimer* timer_, QKeyEvent* event)
{
    switch(event->key())
    {
    case Qt::Key_Q:

        connect(timer_, SIGNAL(timeout()),this,SLOT(strafeLeft()));

        break;

    case Qt::Key_W:
        connect(timer_, SIGNAL(timeout()),this,SLOT(moveForward()));

        break;

    case Qt::Key_E:
        connect(timer_, SIGNAL(timeout()),this,SLOT(strafeRight()));

        break;

    case Qt::Key_A:
        turnLeft();
        engines[0]->applyBrake();
        break;

    case Qt::Key_S:
        connect(timer_, SIGNAL(timeout()),this,SLOT(moveBackward()));
        fullBrake();
        break;

    case Qt::Key_D:
        turnRight();
        break;
    case Qt::Key_Space:
        fire();
        break;
    }
}

void Vehicle::stopInput(QTimer* timer_, QKeyEvent* event)
{
    //qDebug()<<"End Key: " << event->key();
    switch(event->key())
    {
    case Qt::Key_Q:
        disconnect(timer_, SIGNAL(timeout()),this,SLOT(strafeLeft()));
        this->killEngines();
        break;

    case Qt::Key_W:
        disconnect(timer_, SIGNAL(timeout()),this,SLOT(moveForward()));
        this->killEngines();
        break;

    case Qt::Key_E:
        disconnect(timer_, SIGNAL(timeout()),this,SLOT(strafeRight()));
        this->killEngines();
        this->releaseBrake();
        break;

    case Qt::Key_A:
        disconnect(timer_, SIGNAL(timeout()),this,SLOT(turnLeft()));
        this->killEngines();
        stopTurnLeft();

        break;

    case Qt::Key_S:
        disconnect(timer_, SIGNAL(timeout()),this,SLOT(moveBackward()));
        stopFullBrake();
        break;

    case Qt::Key_D:
        disconnect(timer_, SIGNAL(timeout()),this,SLOT(turnRight()));
        stopTurnRight();

        break;
    case Qt::Key_X:

        break;
    }
}
void Vehicle::killEngines()
{
    for (Engine* e : engines)
    {
        e->setActive(false);
    }
}

//void Vehicle::setBody(b2Body* b)
//{
//	 TODO: implement vehicle attributes
//    b2PolygonShape dynamicBox;
//   dynamicBox.SetAsBox(1.0f, 1.0f);

//	b2FixtureDef fixtureDef;
//    fixtureDef.shape = &dynamicBox;
//    fixtureDef.density = 1.0f;
//    fixtureDef.friction = 0.5f;
//    body->CreateFixture(&fixtureDef);

//}



void Vehicle::fire()
{
    //TODO: re-add fire effect
        for(Weapon * w : BulletWeapons)
    {
        w->Fire();
    }



}
void Vehicle::stopFullBrake(){
    for (Engine* e : engines)
    {
        e->stopBrake();
    }
}

void Vehicle::fullBrake(){
    for (Engine* e : engines)
    {
        e->applyBrake();
    }
}
void Vehicle::stopTurnRight()
{
    engines[1]->stopBrake();
}
void Vehicle::stopTurnLeft(){
    engines[0]->stopBrake();
}




