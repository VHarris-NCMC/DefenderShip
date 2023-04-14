#ifndef VEHICLE_H
#define VEHICLE_H

#include "Box2D/Dynamics/b2Body.h"
#include "components.h"
#include "weapon.h"
#include <inputObject.h>
#include <QGraphicsPolygonItem>
#include <QVector2D>
#include <Projectile.h>
#include <GameObject.h>
#include <Box2D/Collision/Shapes/b2PolygonShape.h>
#include <Engine.h>
#include <Plume.h>
#include <QQuaternion>
#include <QTimer>
#include <COMPONENTS.h>


class Vehicle :  public  GameObject
{
		Q_OBJECT
    public:
		explicit Vehicle();
	   explicit Vehicle(struct Model* m);
       QGraphicsPolygonItem* getPoly();
       b2BodyDef* getBodyDef();

	  void  startInput(QTimer* timer_,  QKeyEvent* event_);
	   void stopInput(QTimer* timer_, QKeyEvent* event_);


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
	protected slots:

	   virtual void moveForward()
	   {
		   auto body = model->getBody();

           for (Engine* e  : engines)
		   {

               b2Vec2 rPos = *e->Component::getGlobalPosition();
               b2Vec2*  force = new b2Vec2(0, e->getForce());
			   force->y *= -2;
			   body->ApplyForce(
						   *force,
						   rPos,
						   true);
               Plume* p = &e->getPlume();
               //p->setPos(converter::convert(*e->Component::getGlobalPosition()));
               p->engineIsOn(true);

       }
        }
	   virtual void moveBackward()
	   {
		   auto body = model->getBody();
		   if (body->GetLinearDamping() <=5){
			   body->SetLinearDamping(body->GetLinearDamping()+1);

		   }


	   }
	   virtual void strafeLeft()
       {
           for (Engine* e  : engines)
           {
               e->setActive(true);
               e->go();

           }
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


    private:
        Weapon* BulletWeapons[2] = {new Weapon(-4, 5), new Weapon(4, 5)};
        const Weapon* MissileWeapons[0] = {};
        const Weapon* RocketWeapons[0] = {};
        const Weapon* AreaWeapons[0] = {};
        Engine* engines[2]= {
                              new Engine(new b2Vec2(-4, 4), model->getBody(), new Thruster(components::THRUSTER_1)),
            new Engine(new b2Vec2(4, 4), model->getBody(), new Thruster(components::THRUSTER_1))
		};
        Plume* plume;
		//vehicle controls
        void drawVehicle();
        void configureWeapons();
        void keyPressEvent(QKeyEvent* event);
        void handleInput(QKeyEvent* event);
        void killEngines();
        bool isPlayerVehicle;
};
#endif // VEHICLE_H
