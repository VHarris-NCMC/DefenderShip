#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <Box2D/Dynamics/b2Body.h>
#include <qgraphicsitem.h>
#include <converter.h>
#include <CONFIG.h>
#include <qtimer.h>
#include <scenemanager.h>
#include <vehiclepicker.h>
#include <Model.h>


 class GameObject : public QObject
{
	Q_OBJECT
	protected:

		Model* model;


        virtual void moveForward();
        virtual void moveBackward();
        virtual void turnLeft();
        virtual void turnRight();
        virtual void strafeLeft();
        virtual void strafeRight();

		GameObject(struct Model model_);
		GameObject(Model* m);


		 virtual ~GameObject(){qDebug() << "Error, Gameobject destroyed";};

public:

		 friend class Player;
		virtual float getForwardSpd() const;
		virtual void setForwardSpd(float newforwardSpd);

		virtual float getBackwardSpeed() const;
		virtual void setBackwardSpeed(float newbackwardSpeed);

		virtual float getStrafeSpeed() const;
		virtual void setStrafeSpeed(float newstrafeSpeed);

		virtual float getTurnSpeed() const;
		virtual void setTurnSpeed(float newturnSpeed);

	//FIX:	virtual b2Body getBody()	{return body;	}


		 void GenerateObject();

	 private:
        float forwardSpeed=200;
        float backwardSpeed=-1;
        float strafeSpeed =1;
        float turnSpeed =1;
		float accelerationSpeed =1;
		QPolygonF* buildPoly(std::list<QPointF>* points);
		QPolygonF* buildPoly(struct Model* m);
		QTimer* timer;

	 protected slots:
		void update();
		void MyTimerSlot();
 };






#endif // GAMEOBJECT_H
