#ifndef VEHICLE_H
#define VEHICLE_H

#include "Box2D/Dynamics/b2Body.h"
#include "weapon.h"
#include <inputObject.h>
#include <QGraphicsPolygonItem>
#include <CONFIG.h>
#include <QVector2D>
#include <Projectile.h>
#include <GameObject.h>
#include <Box2D/Collision/Shapes/b2PolygonShape.h>
#include <QQuaternion>
#include <QTimer>
#include <QVector2D>
#include <VehiclePicker.h>

class Vehicle :  public GameObject
{
    public:
		Vehicle();
       QGraphicsPolygonItem* getPoly();
       b2Body* body;
       b2BodyDef* getBodyDef();

	public slots:
       void move();
	protected:
	   virtual std::pair<QGraphicsPolygonItem*, b2BodyDef*>* Model(std::list<QPointF>* points)
	   {

		   QPolygonF polygon;
		   for (QPointF p : *points)
		   {
			   p.rx() = p.rx() *  -1;
			   polygon << p*4;
		   }
		   for(QPointF p : *points)
		   {
			   p.rx() = p.rx();
			   polygon<< p*4;
		   }
		   b2BodyDef* bodyDef = new  b2BodyDef();
		   bodyDef->fixedRotation = false;
		   //FIX: set position correctly, for testing only.
		   bodyDef->position.Set(0,0);

		   return new std::pair<QGraphicsPolygonItem*, b2BodyDef*>(new QGraphicsPolygonItem(polygon),bodyDef);


	   }

    private:
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

			//body->ApplyTorque(float32(getTurnSpeed()), true);
        }
        virtual void turnRight()
        {
			//body->ApplyTorque(float32(-getTurnSpeed()), true);
        }
        void fire();


};
#endif // VEHICLE_H
