#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "Box2D/Collision/Shapes/b2PolygonShape.h"
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
    friend class GameManager;
    friend class UpdateManager;
    friend class WindowManager;
		void safeStep();
    static b2Body* addToWorld(b2BodyDef*);
		// Get Singleton Instance

		static SceneManager* Instance()
		{
			//lock
			std::lock_guard<std::mutex> lock(mutex_);
			//If instance does not exist, create a new one
			if (_instance_ == nullptr){ _instance_= new SceneManager();}
			// return signleton instance;
			return _instance_;
		}

        b2World* getWorld();
		QGraphicsScene* getScene();


		void addToScene(QGraphicsItem* graphic);


	private:

        friend class debugger;
		// Singleton Stuff
		SceneManager();
		~SceneManager(){};
		static inline SceneManager* _instance_{nullptr};
		static inline std::mutex mutex_;
		//Prevent Singleton from being copied.
		SceneManager(SceneManager const&)=delete;
		void operator=(SceneManager const&) {};


		//Member Functions
		void InitializeScene();
		void wakeWorld();
		//Member fields
		QGraphicsScene* scene;
        b2World* world;
        b2Vec2* gravity;
        b2Body* wallBody;


        // debug Stuff


		//UpdateManager* updater ={nullptr};

		void keyEventHandler(QKeyEvent* event);
        void keyPressEvent(QKeyEvent* event);
        void add(QGraphicsItem q);

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
        static const bool DEBUGGING = false;
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
        void debug();
    public:
        static  float32 debugLinearDamping(double change);
        static  float32 debugMass(double change);
        static float32 debugThrust(double change);
        static float32 debugMaxThrust(double change);
};
debugger debug;
};
#endif // SCENEMANAGER_H
