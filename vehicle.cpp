#include <vehicle.h>

//Updates based on game speed, adjust vehicle graphics position / rotation
void Vehicle::move()
{

}
Vehicle::Vehicle() : GameObject(new struct Model(1))
{
    qDebug() << "Vehicle Constructor 1: Vehicle Instantiated";
}
Vehicle::Vehicle(struct Model* m, QPixmap* pixmap) : GameObject(m, pixmap)
{
    qDebug() << "Vehicle Constructor 2: Vehicle Instantiated";
}

b2BodyDef* Vehicle::getBodyDef()
{
    return model->getBodyDef();
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
        getBody()->SetTransform(b2Vec2_zero,0);
        break;
    }
}

float32 Vehicle::debugChangeLinearDampening(float32 change)
{
    qDebug() << "DEBUG: CHANGE LINEAR DAMPENING";
    auto linearDampening = getBody()->GetLinearDamping();
    if (linearDampening + change < 0)
    {
        linearDampening = 0;
    }
    else {
        linearDampening += change;
    }
    getBody()->SetLinearDamping(linearDampening);
    return linearDampening;
}
float32 Vehicle::debugChangeThrust(float32 change)
{
    float32 val;
    qDebug() << "DEBUG: CHANGE THRUST";
    for (Engine* e : engines)
    {
        e->adjustAcceleration(change);
        val = e->getAcceleration();
    }

    return val;
}

float32 Vehicle::debugChangeMaxThrust(float32 change)
{
    qDebug() << "DEBUG: CHANGE MAX THRUST";
    float32 val;
    qDebug() << "DEBUG: CHANGE THRUST";
    for (Engine* e : engines)
    {
        e->adjustMaxThrust(change);
        val = e->getMaxThrust();
    }
    return val;
}
float32 Vehicle::debugChangeMass(float32 change)
{
    qDebug() << "DEBUG: CHANGE VEHICLE MASS";
    auto mass = getBody()->GetMass();
    if (mass + change < 0)
    {
        mass = 0;
    }
    else {
        mass += change;
    }
    b2MassData data;
    getBody()->GetMassData(&data);
    data.mass = mass;
    getBody()->SetMassData(&data);
    return mass;
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

void Vehicle::keyPressEvent(QKeyEvent* event)
{
    startInput(timer, event);
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




