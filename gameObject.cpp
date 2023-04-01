#include <gameObject.h>
#include <qDebug>




//void GameObject::GenerateObject(QGraphicsPolygonItem* graphic_, b2BodyDef* bodyDef_)
//{
//	auto body = SceneManager::Instance()->getWorld()->CreateBody(bodyDef_);

//	//set graphic*
//	auto poly = graphic_;
//	//notify SM that object was created
//	SceneManager::Instance()->addToScene(poly);


//	//Start Timer
//	timer = new QTimer();
//	connect(timer, SIGNAL(timeout()),this,SLOT(update()));
//	connect(timer,SIGNAL(timeout()), this,SLOT(MyTimerSlot()));
//	timer->start(CONFIG::GameSpeed());
//	qDebug() << "Object Created";
//}
void GameObject::GenerateObject()
{
	b2BodyDef* bodyDef_ = new b2BodyDef();

	// body = SceneManager::Instance()->getWorld()->CreateBody(bodyDef_);

	//set graphic*
	auto graphic_ = new QGraphicsPolygonItem();
	auto poly = graphic_;


	QPolygonF* polyF = buildPoly(model->getVertices());
	graphic_->setPolygon(*polyF);
	graphic_->show();
	//notify SM that object was created
	SceneManager::Instance()->addToScene(poly);


	//Start Timer
	timer = new QTimer();
	connect(timer, SIGNAL(timeout()),this,SLOT(update()));
	connect(timer,SIGNAL(timeout()), this,SLOT(MyTimerSlot()));
	timer->start(CONFIG::GameSpeed());
	qDebug() << "Object Created";

}

GameObject::GameObject(Model* m)
{
	if (m == nullptr)
	{
		qDebug() << "Model is null";
	}
	model = m;
	GenerateObject();
}
//GameObject::GameObject(std::pair<QGraphicsPolygonItem*, b2BodyDef*>* model)
//{
//	qDebug() << "GameObject Constructor 1";
//	GenerateObject(model->first, model->second);
//}
//GameObject::GameObject(bool isPlayer, b2BodyDef* bodyDef_, QGraphicsPolygonItem* graphic_)
//{
//	qDebug() << "GameObject Constructor 2";
//	if(isPlayer)
//	{
//	}

//	//set body*
//	auto body= SceneManager::Instance()->getWorld()->CreateBody(bodyDef_);




//	//set focus on player object
//	graphic_->setFlags(QGraphicsItem::ItemIsFocusable);
//	graphic_->setFocus();

//}


void GameObject::MyTimerSlot()
{
	qDebug() << "Timer...";
}

void GameObject::moveForward()
{

}
void GameObject::update()
{

		// Adjust Angle & Position of GraphicPolygon  to match body
		//poly->setRotation(body->GetAngle());
		//auto pos = QPointF(converter::convert(body->GetPosition()));
	//poly->setPos(pos);
		//qDebug() << poly->pos();




}
void GameObject::moveBackward()
{
    qDebug() << "Move backward";
}

void GameObject::turnLeft()
{
    qDebug() <<"Turn left";
}
void GameObject::turnRight()
{
    qDebug() <<"Turn right";
}
void GameObject::strafeRight()
{
}
void GameObject::strafeLeft()
{
}
float GameObject::getForwardSpd() const
{
    return forwardSpeed;
}

void GameObject::setForwardSpd(float speed)
{
    forwardSpeed = speed;
}

float GameObject::getBackwardSpeed() const
{
    return backwardSpeed;
}

void GameObject::setBackwardSpeed(float speed)
{
    backwardSpeed = speed;
}

float GameObject::getStrafeSpeed() const
{
    return strafeSpeed;
}

void GameObject::setStrafeSpeed(float speed)
{
    strafeSpeed = speed;
}

float GameObject::getTurnSpeed() const
{
    return turnSpeed;
}

void GameObject::setTurnSpeed(float speed)
{
    turnSpeed = speed;
}


/* Best to use Model as parameter, but in leaving the method that accepts points for objects
 * that may not have bodys in the future */
QPolygonF* GameObject::buildPoly(struct Model* m)
{
	QPolygonF* pts = new QPolygonF();
	*pts << QPointF(10,10) << QPointF(-10,10) << QPointF(-10,-10) << QPointF(10,-10);
	return pts;
}
QPolygonF* GameObject::buildPoly(std::list<QPointF>* pts)
{
	if (pts == nullptr)
	{
		qDebug() << "QPoints list are null";
		QPolygonF* pt = new QPolygonF();
		*pt << QPointF(0,0) << QPointF(-10,-10)<< QPointF(10,10)<< QPointF(0,0)<< QPointF(-10,10)<< QPointF(10,-10);
		return pt;
	}
	QPolygonF* pt = new QPolygonF();
	for (QPointF p : *pts)
	{
		*pt << p;
	}
	for (QPointF p : *pts)
	{
		p.setX( p.x() *-1);
		*pt << p;
	}
	return pt;
}

