#include "scenemanager.h"



// Initialize Singleton and mutex
SceneManager::SceneManager()
{

	InitializeScene();


   //groundBodyDef.position.Set(0.0f, 0.0f);
   //groundBody = world->CreateBody(&groundBodyDef);
   //groundBox.SetAsBox(100.0f, 100.0f);
   //groundBody->CreateFixture(&groundBox, 0.0f);

	//QTimer* timer = new QTimer();
    wakeWorld();
	//connect(timer,SIGNAL(timeout()),this,SLOT(Step()));
	//timer->start(CONFIG::GameSpeed());

}

QGraphicsScene* SceneManager::getScene() const
{
	return scene;
}

b2World* SceneManager::getWorld() const
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

void SceneManager::InitializeScene()
{
	//Initialize Scene
	scene = new QGraphicsScene();
	auto rect = new QGraphicsRectItem;
	rect->setRect(0,0,100,100);
	scene->addItem(rect);

	// Set Scene size to match window size
	auto screenSize = WindowManager::Instance()->getCurrentScreenSize();
	scene->setSceneRect(0-screenSize.rwidth()/2, 0-screenSize.rheight()/2, screenSize.rwidth(), screenSize.rheight());
	qDebug() << "Scene Dimensions - Height: " <<scene->sceneRect().size().height() << " Width: " << scene->sceneRect().size().width();
	//Configure World
	gravity = new b2Vec2(0.0f, 0.0f);
	world = new b2World(*gravity);


	WindowManager::getView()->setScene(scene);

}


