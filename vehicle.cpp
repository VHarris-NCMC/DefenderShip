#include "vehicle.h"

#include <Projectile.h>
#include <QTimer>
#include <QVector2D>

Vehicle::Vehicle(bool isPlayer)
{
     drawVehicle();
    drag = 0.90;
     isPlayerVehicle = isPlayer;
     this->setFlag(QGraphicsItem::ItemIsFocusable);
     this->setFocus();

     QTimer* timer = new QTimer();
     if (isPlayer){
        connect(timer,SIGNAL(timeout()),this,SLOT(applyDrag()));
        connect(timer,SIGNAL(timeout()),this,SLOT(move()));
     }
     else{
         connect(timer,SIGNAL(timeout()), this,SLOT(move()));
     }
     timer->start(CONFIG::GameSpeed());
}

void Vehicle::pursuePlayer(){

}
void Vehicle::applyDrag()
{
 momentum *= drag;
}
void Vehicle::move()
{
    setPos(x() + momentum.x(), y() + momentum.y());
}


void Vehicle::drawVehicle()
{
    QPolygonF polygon;
    for (QPointF p : vertices)
    {
            polygon << p*4;
    }
    for (QPointF p : vertices)
    {
        p.rx() = p.rx() *  -1;
        polygon << p*4;
    }
    polygon << this->vertices[0];
    this->setPolygon(polygon);



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



