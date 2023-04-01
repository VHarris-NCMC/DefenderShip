#include <vehicle.h>


//Updates based on game speed, adjust vehicle graphics position / rotation
void Vehicle::move()
{


}
Vehicle::Vehicle() : GameObject(new struct Model(1))
{
	qDebug() << "Vehicle Constructor 1";

}

//sets dimensions of body and attaches fixture
//void Vehicle::setBody(b2Body* b)
//{
//	 TODO: implement vehicle attributes
//    body = b;
//    b2PolygonShape dynamicBox;
//   dynamicBox.SetAsBox(1.0f, 1.0f);

//	b2FixtureDef fixtureDef;
//    fixtureDef.shape = &dynamicBox;
//    fixtureDef.density = 1.0f;
//    fixtureDef.friction = 0.5f;
//    body->CreateFixture(&fixtureDef);

//}

void Vehicle::keyPressEvent(QKeyEvent* event)
{
    try
    {
        if (isPlayerVehicle)
        {
            handleInput(event);
        }
        else
        {
            throw(event);
        }

    }catch(bool e){
        qDebug() << e << " invalid, not player vehicle";
    }

}
void Vehicle::handleInput(QKeyEvent* event)
{

    switch(event->key())
    {
        case Qt::Key_W:
            moveForward();
            break;
        case Qt::Key_A:
            turnLeft();
            break;
        case Qt::Key_S:
            moveBackward();
            break;
        case Qt::Key_D:
            turnRight();
            break;
        case Qt::Key_Q:
            strafeLeft();
            break;
        case Qt::Key_E:
            strafeRight();
            break;
        case Qt::Key_Space:
            fire();
            break;
        default:
            qDebug() << "Invalid Input " << event->key();
            break;
    }


}
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




