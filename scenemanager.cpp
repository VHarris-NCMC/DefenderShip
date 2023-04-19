#include "scenemanager.h"

void SceneManager::Initialize()
{
    InitializeScene();
	QTimer* timer = new QTimer();
    wakeWorld();
    //ob->connect(timer,SIGNAL(timeout()),this,SLOT(step()));
	timer->start(CONFIG::GameSpeed());
}

b2Body* SceneManager::addToWorld(b2BodyDef* bDef){ return world->CreateBody(bDef);}
b2World* SceneManager::getWorld(){return world;}
QGraphicsScene* SceneManager::getScene(){ return scene;}
void SceneManager::addToView(QGraphicsItem* graphic){
    try{
        if (graphic == nullptr) { throw std::runtime_error("Graphic == nullptr");}
        if (scene == nullptr) { throw std::runtime_error("Scene == nullptr");}
        scene->addItem(graphic); graphic->show();
    }catch(const std::exception& error){
        qDebug() << "Error adding graphic to view: " << error.what();}

}

void SceneManager::addToView(QPixmap* pixmap){
    scene->addPixmap(*pixmap);
    scene->dumpObjectInfo();
    scene->dumpObjectTree();
}

void SceneManager::wakeWorld()
{
    for (b2Body* b = world->GetBodyList(); b; b = b->GetNext())
    {
        b->SetAwake(true);
        b->SetActive(true);
    }

//    world->SetDebugDraw(&mDebug);
   // SceneManager::mDebug.SetFlags(b2Draw::e_shapeBit);

}

void SceneManager::step()
{
    auto timeStep = 1.0f/10.0f;
    world->Step(timeStep, 4, 4);
   // mDebug.Clear();
if (debugger::DEBUGGING)
    {
    world->DrawDebugData();
    }
}

void SceneManager::resizeToWindow()
{
    auto screenSize = WindowManager::getCurrentScreenSize();
    scene->setSceneRect(0-screenSize.rwidth()/2, 0-screenSize.rheight()/2, screenSize.rwidth()-200, screenSize.rheight()- 250);


}

void SceneManager::InitializeScene()
{
    //Initialize Scene
    scene = new QGraphicsScene();


    // Set Scene size to match window size
    resizeToWindow();


	qDebug() << "Scene Dimensions - Height: " <<scene->sceneRect().size().height() << " Width: " << scene->sceneRect().size().width();
    //Configure World
    auto gravity = new b2Vec2(0.0f, 0.0f);
    world = new b2World(*gravity);


    // declare world edge
        b2BodyDef wallBodyDef;
        wallBodyDef.position.Set(0,0);
        auto wallBody = world->CreateBody(&wallBodyDef);
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



}


