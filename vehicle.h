#ifndef VEHICLE_H
#define VEHICLE_H

#include "weapon.h"
#include <inputObject.h>
#include <QGraphicsPolygonItem>
#include <CONFIG.h>
#include <QVector2D>



class Vehicle : public QObject, public QGraphicsPolygonItem,  public Moveable
{
    Q_OBJECT
    public:
       explicit Vehicle(bool isPlayer);
       QGraphicsPolygonItem* getPoly();



       bool getIsPlayerVehicle() const;
    public slots:
       void pursuePlayer();
       void applyDrag();
       void move();


    private:
        const QPointF vertices[9] ={
            QPointF(-5, 2), QPointF(-7.5, 9),
            QPointF(-7.5,-15), QPointF(-4, -15), QPointF(-4, -4), QPointF(-2, -4),
            QPointF(-2, -6), QPointF(0, -7), QPointF(0,0)
                                   };
        Weapon* BulletWeapons[2] = {new Weapon(-4, 5), new Weapon(4, 5)};
        const Weapon* MissileWeapons[0] = {};
        const Weapon* RocketWeapons[0] = {};
        const Weapon* AreaWeapons[0] = {};
        QVector2D momentum;
        float drag;



        void drawVehicle();
        void configureWeapons();
        void keyPressEvent(QKeyEvent* event);
        void handleInput(QKeyEvent* event);
        bool isPlayerVehicle;
        virtual void moveForward()
        {
            momentum.setY(momentum.y() + getForwardSpd());
        }
        virtual void moveBackward()
        {
            momentum.setY(momentum.y() + getBackwardSpeed());
        }
        virtual void strafeLeft()
        {
           momentum.setX(momentum.x() - getStrafeSpeed());

        }
        virtual void strafeRight()
        {
            momentum.setX(momentum.x() + getStrafeSpeed());
        }
        virtual void turnLeft()
        {

            qreal qr = rotation();
            setRotation(qr+getTurnSpeed());




        }
        virtual void turnRight()
        {

            qreal qr = rotation();
            setRotation(qr-getTurnSpeed());

        }
        void fire();





};
#endif // VEHICLE_H
