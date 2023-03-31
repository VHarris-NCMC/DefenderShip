#ifndef VEHICLE_H
#define VEHICLE_H
#include "Box2D/Dynamics/b2Body.h"
#include "weapon.h"
#include <inputObject.h>
#include <QGraphicsPolygonItem>
#include <CONFIG.h>
#include <QVector2D>
#include <Projectile.h>
#include <Box2D/Collision/Shapes/b2PolygonShape.h>




class Vehicle : public QObject, public QGraphicsPolygonItem,  public Moveable
{

    Q_OBJECT
    public:
       explicit Vehicle(bool isPlayer);
       QGraphicsPolygonItem* getPoly();
       b2BodyDef bodyDef;
       b2Body* body;
       b2BodyDef* getBodyDef();
       void setBody( b2Body* b);



       bool getIsPlayerVehicle() const;
    public slots:
       void pursuePlayer();
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



        void drawVehicle();
        void configureWeapons();
        void keyPressEvent(QKeyEvent* event);
        void handleInput(QKeyEvent* event);
        bool isPlayerVehicle;
        virtual void moveForward()
        {

            b2Vec2 forceDirection = body->GetWorldVector( b2Vec2(0,1));

            forceDirection = getForwardSpd() * forceDirection;
            body->ApplyLinearImpulse(forceDirection, body->GetPosition(), true);

            if(body->GetLinearDamping()>=0)
            {
                body->SetLinearDamping(body->GetLinearDamping()-1);
            }




        }

        virtual void moveBackward()
        {

            if (body->GetLinearDamping() <=5){
                body->SetLinearDamping(body->GetLinearDamping()+1);

            }


        }
        virtual void strafeLeft()
        {


        }
        virtual void strafeRight()
        {

        }
        virtual void turnLeft()
        {

            body->ApplyTorque(float32(getTurnSpeed()), true);
        }
        virtual void turnRight()
        {
            body->ApplyTorque(float32(-getTurnSpeed()), true);
        }
        void fire();





};
#endif // VEHICLE_H
