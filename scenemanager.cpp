#include "scenemanager.h"




// Initialize Singleton and mutex
SceneManager::SceneManager()
{
    InitializeScene();



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

b2Body* SceneManager::addToWorld(b2BodyDef* bDef)
{
    return Instance()->world->CreateBody(bDef);
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

    world->SetDebugDraw(&debug);
    debug.SetFlags(b2Draw::e_shapeBit);

}

void SceneManager::step()
{
    auto timeStep = 1.0f/10.0f;

world->Step(timeStep, 4, 4);
    debug.Clear();
    world->DrawDebugData();


}

void SceneManager::InitializeScene()
{
	//Initialize Scene
	scene = new QGraphicsScene();


	// Set Scene size to match window size
	auto screenSize = WindowManager::Instance()->getCurrentScreenSize();
    scene->setSceneRect(0-screenSize.rwidth()/2, 0-screenSize.rheight()/2, screenSize.rwidth(), screenSize.rheight()- 250);

	qDebug() << "Scene Dimensions - Height: " <<scene->sceneRect().size().height() << " Width: " << scene->sceneRect().size().width();
	//Configure World
	gravity = new b2Vec2(0.0f, 0.0f);
    world = new b2World(*gravity);


    // declare world edge
        b2BodyDef wallBodyDef;
        wallBodyDef.position.Set(0,0);
        wallBody = world->CreateBody(&wallBodyDef);
        wallBody->SetType(b2_staticBody);

        b2EdgeShape worldEdge;
        b2FixtureDef wallFixtureDef;
        wallFixtureDef.shape = &worldEdge;

    //reference scene size
        auto rect  = scene->sceneRect().toRect();

    //    //left edge
        worldEdge.Set(converter::convertToB2Vec2(rect.bottomLeft()),converter::convertToB2Vec2(rect.topLeft()));
        wallBody->CreateFixture(&wallFixtureDef);

        //top edge
        worldEdge.Set(converter::convertToB2Vec2(rect.topLeft()), converter::convertToB2Vec2(rect.topRight()));
        wallBody->CreateFixture(&wallFixtureDef);

        //right edge
        worldEdge.Set(converter::convertToB2Vec2(rect.bottomRight()), converter::convertToB2Vec2(rect.topRight()));
        wallBody->CreateFixture(&wallFixtureDef);

        //bottom edge
        worldEdge.Set(converter::convertToB2Vec2(rect.bottomLeft()), converter::convertToB2Vec2(rect.bottomRight()));
        wallBody->CreateFixture(&wallFixtureDef);

        WindowManager::getView()->setScene(scene);
        WindowManager::getView()->setStyleSheet("background-image: url(:/images/src/SpaceBackground.png);");

}


