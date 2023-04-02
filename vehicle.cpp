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
	qDebug()<<"Begin Key: " << event->key();

	if (event->key() == Qt::Key_W)
	{

		connect(timer_, SIGNAL(timeout()),this,SLOT(moveForward()));
	}
}

void Vehicle::stopInput(QTimer* timer_, QKeyEvent* event)
{
	qDebug()<<"End Key: " << event->key();
	if (event->key() == Qt::Key_W)
	{
		disconnect(timer_, SIGNAL(timeout()),this,SLOT(moveForward()));
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




