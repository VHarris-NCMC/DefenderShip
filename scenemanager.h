#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <QGraphicsView>
#include <QGraphicsItem>
#include <Box2D/Dynamics/b2Body.h>
#include <Box2D/Dynamics/b2World.h>
#include <mutex>
#include <windowmanager.h>
#include<CONFIG.h>
#include <Box2D/Common/b2Draw.h>
#include <qtimer.h>
#include<QBrush>
#include <QPen>
#include<converter.h>
#include <converter.h>
#include "Box2D/Dynamics/b2Fixture.h"
#include <Box2D/Collision/Shapes/b2EdgeShape.h>
//#include <debugger.h>

class SceneManager
{

    public:
    //Member Functions
    friend class GameManager;
    friend class WindowManager;
     void Initialize();
     void addToView(QGraphicsItem* graphic);
     void addToView(QPixmap* pixmap);
     void InitializeScene();
     b2World* getWorld();
     b2Body* addToWorld(b2BodyDef*);
     QGraphicsScene* getScene();
    void safeStep();

private:
    friend class debugger;
    friend QGraphicsScene* getScene();
    void wakeWorld();
    //Member fields
    QGraphicsScene* scene;
    b2World* world;





        // debug Stuff

    void keyEventHandler(QKeyEvent* event);
    void keyPressEvent(QKeyEvent* event);
    void step();

public:
  class debugger : public b2Draw
{
        friend class SceneManager;
        friend class GameManager;
        friend class Player;
        friend class Vehicle;
        friend class DASHBOARD_DEBUG_MASS;

    public:
        debugger();
        ~debugger();
        void log(int level, QString s);
        static const bool DEBUGGING = true;
        static b2World* getWorld();
        static void addToWorld(b2Body* b);

    private:
           const QString BACKGROUND = "/src/SpaceBackground.png";
        const int debugLevel = 0;
        std::list<QGraphicsItem*> debug_items = std::list<QGraphicsItem*>();
        // b2Draw interface
    public:
        void DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);
        void DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);
        void DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color);
        void DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color);
        void DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color);
        void DrawTransform(const b2Transform& xf);
        void Clear();
    public:
        static  float32 debugLinearDamping(double change);
        static  float32 debugMass(double change);
        static float32 debugThrust(double change);
        static float32 debugMaxThrust(double change);
};
//static debugger mDebug;
void resizeToWindow();
};
#endif // SCENEMANAGER_H
