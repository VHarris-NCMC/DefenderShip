#include <gameObject.h>
#include <qDebug>
#include<maincontroller.h>
#include <Box2D/Dynamics/b2Fixture.h>




//void GameObject::GenerateObject(QGraphicsPolygonItem* graphic_, b2BodyDef* bodyDef_)
//{
//	auto body = MAINCONTROLLER::SCENE->Instance()->getWorld()->CreateBody(bodyDef_);

//	//set graphic*
//	auto poly = graphic_;
//	//notify SM that object was created
//	MAINCONTROLLER::SCENE->Instance()->addToScene(poly);


//	//Start Timer
//	timer = new QTimer();
//	connect(timer, SIGNAL(timeout()),this,SLOT(update()));
//	connect(timer,SIGNAL(timeout()), this,SLOT(MyTimerSlot()));
//	timer->start(CONFIG::GameSpeed());
//	qDebug() << "Object Created";
//}
GameObject::GameObject(Model* m, QPixmap* pixmap)
{
    try {
        GenerateObject(m);
         if (m == nullptr){throw std::runtime_error("Model is null");}
    }catch (std::exception e)
    {
         qDebug() << e.what();
    }
    Sprite* sprite   = new Sprite(new b2Vec2(b2Vec2_zero), getBody());
    MAINCONTROLLER::ADD_TO_SCENE(sprite);



}
void GameObject::GenerateObject(Model* model_)
{
	model = model_;
	if (model == nullptr)
	{
		qDebug() << "Model not found, exiting";
		return;
	}
	// if model does not contain body, default body will be used
	if (model->getBodyDef() == nullptr){
		qDebug() << "body definition not specified, using default body for object";
    }
    b2PolygonShape* shape = new b2PolygonShape(*model->getShape());
    b2FixtureDef fixDef;
    fixDef.shape = shape;
    fixDef.friction = 0;
    fixDef.density = .5;
    QPolygonF* polyF = (model->getVertices() == nullptr) ? buildPoly() : buildPoly(model->getVertices());

            //set graphic*
    polygon = new QGraphicsPolygonItem();
    polygon->setPolygon(*polyF);
    polygon->show();

    //notify SM that object was created


    MAINCONTROLLER::ADD_TO_SCENE(polygon);
    body = MAINCONTROLLER::ADD_TO_WORLD(model->getBodyDef());
    //activate pixmap    Sprite* sprite = new Sprite(localvec,  model->getBody());

	//Start Timer
	timer = new QTimer();
	connect(timer, SIGNAL(timeout()),this,SLOT(update()));
	timer->start(CONFIG::GameSpeed());

}







//	//set focus on player object
//	graphic_->setFlags(QGraphicsItem::ItemIsFocusable);
//	graphic_->setFocus();

//}



void GameObject::moveForward()
{
    qDebug() << "move forward";

}
void GameObject::update()
{
//		 Adjust Angle & Position of GraphicPolygon  to match body
    //model->getPoly()->setRotation(model->getBody()->GetWorldVector(b2Vec2(0,1)).y);

    if ( body != nullptr && polygon != nullptr)
    {

        model->syncTransform(body, polygon);
    }



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




/* Best to use Model as parameter, but in leaving the method that accepts points for objects
 * that may not have bodys in the future */
QPolygonF* GameObject::buildPoly(struct Model* m)
{
	auto pts = m->getVertices();
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

QPolygonF* GameObject::buildPoly(std::list<QPointF>* pts)
{
	qDebug() << "Model definition not found, using default model";
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
// Construct GameObject with default poly (x-shape)
QPolygonF* GameObject::buildPoly()
{
	QPolygonF* pt = new QPolygonF();
	*pt << QPointF(0,0) << QPointF(-10,-10)<< QPointF(10,10)<< QPointF(0,0)<< QPointF(-10,10)<< QPointF(10,-10);
	return pt;
}

