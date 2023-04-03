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
#include <QQuaternion>
#include <QTimer>
#include <components.h>
using namespace components;


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

		   auto poly = model->getPoly();
		   if(body==nullptr)
		   {
			   qDebug() << "Body is null";
			   return;
		   }
		qDebug() << "Body Position: "  << body->GetPosition().x << body->GetPosition().y ;
		qDebug() << "Poly Position: " << poly->pos().rx()<<poly->pos().ry();

		auto world =  body->GetWorld();
		b2Vec2 forceDirection= body-> GetWorldVector(body->GetPosition());
	 qDebug() << world->GetBodyList();

		 forceDirection = getForwardSpd() * forceDirection;
		 b2Vec2 pointOfImpulse = body->GetPosition();
		 pointOfImpulse.y -= 5;
		 body->ApplyLinearImpulse(forceDirection, body->GetPosition(), true);


		 if(body->GetLinearDamping()>=0)
		 {
			 body->SetLinearDamping(body->GetLinearDamping()-1);
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
		   auto body = model->getBody();
			auto poly = model->getPoly();
			b2Vec2 currentVelocity = body->GetLinearVelocityFromLocalPoint(body->GetPosition());
		   for (components::Engine* e  : engines)
		   {

			   b2Vec2 rPos = *e->getGlobalPosition(b2Vec2 (body->GetPosition()));
			   b2Vec2*  force = new b2Vec2(0, e->getForce(currentVelocity.y));
			   body->ApplyForce(
						   *force,
						   rPos,
						   true);
			   qDebug() << "Engine RPosition: " << rPos.x << ", "<<rPos.y;

		   }
		   qDebug() << "Body Position: "  << body->GetPosition().x << body->GetPosition().y ;
			qDebug() << "Current Velocity: "  << currentVelocity.x << ", " <<currentVelocity.y ;
		   qDebug() << "Poly Position: " << poly->pos().rx()<<poly->pos().ry();
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
		components::Engine* engines[2]= {
			new components::Engine(new b2Vec2(-4, 4), new components::Thrust(0.5f, 1000.0f, 500.0f)),
			new components::Engine(new b2Vec2(4, 4), new components::Thrust(0.5f, 1000.0f, 500.0f))
		};
		//vehicle controls
        void drawVehicle();
        void configureWeapons();
        void keyPressEvent(QKeyEvent* event);
        void handleInput(QKeyEvent* event);
        bool isPlayerVehicle;
};
#endif // VEHICLE_H
