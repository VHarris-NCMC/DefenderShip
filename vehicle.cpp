#include "vehicle.h"
#include "Box2D/Dynamics/b2Fixture.h"
#include <Math.h>
#include <QQuaternion>
#include <QTimer>
#include <QVector2D>

Vehicle::Vehicle(bool isPlayer)
{
     drawVehicle();
     isPlayerVehicle = isPlayer;
     this->setFlag(QGraphicsItem::ItemIsFocusable);
     this->setFocus();

     QTimer* timer = new QTimer();
     if (isPlayer){
        connect(timer,SIGNAL(timeout()),this,SLOT(move()));
     }
     else{
         connect(timer,SIGNAL(timeout()), this,SLOT(move()));
     }
     timer->start(CONFIG::GameSpeed());

}

void Vehicle::pursuePlayer(){

}

void Vehicle::move()
{
    // Adjust Position Of GraphicPolygon
    auto pos = QPointF(body->GetPosition().x, body->GetPosition().y);
    setPos(pos);

    // Adjust Angle of GraphicPolygon
    //b2Vec2 rot = body->GetWorldVector( b2Vec2(0,1) );
    auto  f_rot = body->GetAngle();

    //auto deg = qreal(qRadiansToDegrees(rot.x));

//if (rot.x < 0)
//{
   // deg = 360 -deg;
//}
     setRotation(f_rot);
    qDebug()<< "WorldVector" << (f_rot) << " ";// << rot.y;
    qDebug() << rotation();


}
void Vehicle::setBody(b2Body* b)
{
    body = b;
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(1.0f, 1.0f);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.5f;
    body->CreateFixture(&fixtureDef);

}

b2BodyDef* Vehicle::getBodyDef()
{
    return &bodyDef;
}


void Vehicle::drawVehicle()
{


    QPolygonF polygon;
    for (QPointF p : vertices)
    {
            p*=4;
            polygon << p;

    }
    for (QPointF p : vertices)
    {
        p.rx() = p.rx() *  -1;
        polygon << p*4;

    }

    polygon << this->vertices[0];
    this->setPolygon(polygon);
    bodyDef.type = b2_dynamicBody;

    bodyDef.fixedRotation = false;
    bodyDef.position.Set(this->pos().x(), this->pos().y());





}

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
    for (Weapon* w : BulletWeapons)
    {
        auto pos = this->pos();
        pos.setX(pos.rx() + w->getRelativeX());
        pos.setY(pos.ry() + w->getRelativeY());

        Projectile* p = new Projectile(pos);
        scene()->addItem(p);



    }
}
bool Vehicle::getIsPlayerVehicle() const
{
    return isPlayerVehicle;
}



