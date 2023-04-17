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


class Vehicle :  public  GameObject
{

		Q_OBJECT
    public:
        explicit Vehicle();
        explicit Vehicle(struct Model *m);
        Vehicle(const Vehicle &) = delete;
        Vehicle(Vehicle &&) = delete;
        Vehicle &operator=(const Vehicle &) = delete;
        Vehicle &operator=(Vehicle &&) = delete;
        QGraphicsPolygonItem *getPoly();
        b2BodyDef *getBodyDef();

        void startInput(QTimer *timer_, QKeyEvent *event_);
        void stopInput(QTimer *timer_, QKeyEvent *event_);

        int changeMass(int change);

    public slots:
        void move();

    protected:
        virtual std::pair<QGraphicsPolygonItem *, b2BodyDef *> *
        Model(std::list<QPointF> *points) {
            QPolygonF polygon;
            for (QPointF p : *points) {
                p.rx() = p.rx() * -1;
                polygon << p * 4;
            }
            for (QPointF p : *points) {
                p.rx() = p.rx();
                polygon << p * 4;
            }
            b2BodyDef *bodyDef = new b2BodyDef();
            bodyDef->fixedRotation = false;
            // FIX: set position correctly, for testing only.
            bodyDef->position.SetZero();
            return new std::pair<QGraphicsPolygonItem *, b2BodyDef *>(
                new QGraphicsPolygonItem(polygon), bodyDef);
	   }
       virtual void stopTurnRight();
       virtual void stopTurnLeft();
       virtual void fullBrake();
       virtual void stopFullBrake();




protected slots:

//       virtual void moveForward()
//    {
//        auto body = model->getBody();
//           for (Engine* e  : engines)
//		   {
//               b2Vec2 rPos = *e->Component::getGlobalPosition();
//               b2Vec2*  force = new b2Vec2(0, e->getForce());
//			   force->y *= -2;
//			   body->ApplyForce(*force, rPos, true);
//               Plume* p = &e->getPlume();
//               //p->setPos(converter::convert(*e->Component::getGlobalPosition()));
//               p->engineIsOn(true);
//       }
//        }
    virtual void moveForward()
    {
           for (Engine* e  : engines)
           {
               e->setActive(true);
               e->go();
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

	   }
	   virtual void strafeRight()
	   {

	   }
	   virtual void turnLeft()
          {
           engines[0]->applyBrake();
          }
	   virtual void turnRight()
       {
           engines[1]->applyBrake();
	   }
	   void fire();

       void releaseBrake()
       {
           for (Engine* e : engines)
           {
               e->stopBrake();
           }
       }

    private:
       Weapon* BulletWeapons[2] = {
                                    new Weapon(new b2Vec2(-1, 0), model->getBody(), new ProjectileDef()),
            new Weapon(new b2Vec2(1, 0), model->getBody(), new ProjectileDef())
        };
        const Weapon* MissileWeapons[0] = {};
        const Weapon* RocketWeapons[0] = {};
        const Weapon* AreaWeapons[0] = {};
        Engine* engines[2]= {
                              new Engine(new b2Vec2(-6 + model->getBody()->GetPosition().x, model->getBody()->GetPosition().y+1), model->getBody(), new Thruster(*components::THRUSTER_1)),
            new Engine(new b2Vec2(6 + model->getBody()->GetPosition().x, 1 + model->getBody()->GetPosition().y), model->getBody(), new Thruster(*components::THRUSTER_1))
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
