#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "Box2D/Collision/Shapes/b2PolygonShape.h"
#include <QGraphicsView>
#include <QGraphicsItem>
#include <Box2D/Dynamics/b2Body.h>
#include <Box2D/Dynamics/b2World.h>
#include <mutex>
#include <windowmanager.h>

class SceneManager
{

	public:

		friend class GameManager;
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

		b2World* getWorld() const;
		QGraphicsScene* getScene() const;


		void addToScene(QGraphicsItem* graphic);


	private:


		// Singleton Stuff
		SceneManager();
		~SceneManager(){};
		static inline SceneManager* _instance_{nullptr};
		static inline std::mutex mutex_;
		//Prevent Singleton from being copied.
		SceneManager(SceneManager const&){};
		void operator=(SceneManager const&) {};

		//Member Functions
		void InitializeScene();
		void wakeWorld();
		//Member fields
		QGraphicsScene* scene;
		b2World* world;
		b2Vec2* gravity;
		b2Body* groundBody;
		b2BodyDef groundBodyDef;
		b2PolygonShape groundBox;




		void keyEventHandler(QKeyEvent* event);
        void keyPressEvent(QKeyEvent* event);
        void add(QGraphicsItem q);





};
#endif // SCENEMANAGER_H
