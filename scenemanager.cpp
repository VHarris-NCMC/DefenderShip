#include "scenemanager.h"





// Initialize Singleton and mutex
SceneManager::SceneManager()
{
	InitializeScene();


   //groundBodyDef.position.Set(0.0f, 0.0f);
   //groundBody = world->CreateBody(&groundBodyDef);
   //groundBox.SetAsBox(100.0f, 100.0f);
   //groundBody->CreateFixture(&groundBox, 0.0f);

	QTimer* timer = new QTimer();
    wakeWorld();

	//ob->connect(timer,SIGNAL(timeout()),this,SLOT(step()));
	timer->start(CONFIG::GameSpeed());

}

QGraphicsScene* SceneManager::getScene()
{
	return scene;
}

void SceneManager::safeStep(/*UpdateManager* updater_*/)
{
	/* // REMOVED DUE TO RECURSIVE CLASS INCLUSION
	try {
		if (updater == updater_)
		{
			*/step();/*
		}else{throw updater_;}
	} catch (UpdateManager* up) {
		if (updater == nullptr) { updater = updater_;}
		else{ qDebug() << "Error, multiple updaters detected";
	}
	*/

}

b2World* SceneManager::getWorld()
{
	return world;
}
void SceneManager::addToScene(QGraphicsItem* graphic)
{

	scene->addItem(graphic);

	graphic->show();


}
void SceneManager::wakeWorld()
{
    for (b2Body* b = world->GetBodyList(); b; b = b->GetNext())
    {
        b->SetAwake(true);
        b->SetActive(true);
	}

}

void SceneManager::step()
{
world->Step(10, 5, 4);
}

void SceneManager::InitializeScene()
{
	//Initialize Scene
	scene = new QGraphicsScene();

	// Set Scene size to match window size
	auto screenSize = WindowManager::Instance()->getCurrentScreenSize();
	scene->setSceneRect(0-screenSize.rwidth()/2, 0-screenSize.rheight()/2, screenSize.rwidth(), screenSize.rheight());
	qDebug() << "Scene Dimensions - Height: " <<scene->sceneRect().size().height() << " Width: " << scene->sceneRect().size().width();
	//Configure World
	gravity = new b2Vec2(0.0f, 0.0f);
	world = new b2World(*gravity);



	WindowManager::getView()->setScene(scene);

}


