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
#include <Sprite.h>

 class GameObject: public QObject
{
	Q_OBJECT
    protected:
    Sprite* sprite;

		 //Model* model ={nullptr}; TODO: determine if model is needed after construction -- Other todo in GenerateObject() can be uncommented to re-implement
		 QTimer* timer = {nullptr};

        virtual void moveForward();
        virtual void moveBackward();
        virtual void turnLeft();
        virtual void turnRight();
        virtual void strafeLeft();
        virtual void strafeRight();
		 Model* model = {nullptr};

         explicit GameObject(Model* m, QPixmap* pixmap = new QPixmap(":/sprites/src/default.gif"));
        //Sprite* sprite;

        virtual ~GameObject(){qDebug() <<  "Error, Gameobject destroyed";};

public:
        b2Body* getBody(){return body;};
        QGraphicsPolygonItem* poly;
		 friend class Player;


		 void GenerateObject(Model* m);

	 private:
		float accelerationSpeed =1;
		QPolygonF* buildPoly(std::list<QPointF>* points);
		QPolygonF* buildPoly(struct Model* m);
        QPolygonF* buildPoly();
        b2Body* body = {nullptr};
        QGraphicsPolygonItem* polygon;
	 protected slots:
		void update();
 };






#endif // GAMEOBJECT_H
