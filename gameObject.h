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
#include<debugger.h>

 class GameObject : public  QObject
{
	Q_OBJECT
	protected:

		 //Model* model ={nullptr}; TODO: determine if model is needed after construction -- Other todo in GenerateObject() can be uncommented to re-implement
		 QTimer* timer = {nullptr};

        virtual void moveForward();
        virtual void moveBackward();
        virtual void turnLeft();
        virtual void turnRight();
        virtual void strafeLeft();
        virtual void strafeRight();
		 Model* model = {nullptr};
		GameObject(struct Model model_);
		GameObject(Model* m);


        virtual ~GameObject(){qDebug() <<  "Error, Gameobject destroyed";};

public:

		 friend class Player;


		 void GenerateObject(Model* m);

	 private:
		float accelerationSpeed =1;
		QPolygonF* buildPoly(std::list<QPointF>* points);
		QPolygonF* buildPoly(struct Model* m);
		QPolygonF* buildPoly();


	 protected slots:
		void update();
 };






#endif // GAMEOBJECT_H
