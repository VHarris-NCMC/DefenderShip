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
	qDebug() << "Vehicle Constructor 1";
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
        connect(timer_, SIGNAL(timeout()),this,SLOT(turnLeft()));
        engines[0]->applyBrake();
        break;

    case Qt::Key_S:
        connect(timer_, SIGNAL(timeout()),this,SLOT(moveBackward()));

        break;

    case Qt::Key_D:
        connect(timer_, SIGNAL(timeout()),this,SLOT(turnRight()));

        break;
    }
}

void Vehicle::stopInput(QTimer* timer_, QKeyEvent* event)
{
	qDebug()<<"End Key: " << event->key();
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
        engines[0]->stopBrake();
        break;

    case Qt::Key_S:
        disconnect(timer_, SIGNAL(timeout()),this,SLOT(moveBackward()));
        this->killEngines();

        break;

    case Qt::Key_D:
        disconnect(timer_, SIGNAL(timeout()),this,SLOT(turnRight()));
        this->killEngines();
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
//    for (Weapon* w : BulletWeapons)
//    {
//        auto pos = this->pos();
//        pos.setX(pos.rx() + w->getRelativeX());
//        pos.setY(pos.ry() + w->getRelativeY());

//        Projectile* p = new Projectile(pos);
//        scene()->addItem(p);



//    }
}




