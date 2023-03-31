#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H



#include "Box2D/Collision/Shapes/b2PolygonShape.h"
#include <Player.h>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <Box2D/Dynamics/b2Body.h>
#include <Box2D/Dynamics/b2World.h>





class SceneManager : public QObject
{
        Q_OBJECT
    public:
        explicit SceneManager();

        void keyPressEvent(QKeyEvent* event);
        void add(QGraphicsItem q);
        b2World* world;
        b2Vec2* gravity;
        b2Body* groundBody;
        b2BodyDef groundBodyDef;
        b2PolygonShape groundBox;
     public slots:
        void Step();






        void wakeWorld();
    private:

        QGraphicsScene* scene;
        Player * player;
        QGraphicsView* view;
        void addPlayerToScene();
        void setWindowSize();
        void move();
    };

#endif // SCENEMANAGER_H
