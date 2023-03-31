#include "scenemanager.h"
#include "qapplication.h"

#include <QGraphicsScene>
#include <QTimer>


SceneManager::SceneManager()
{

   scene = new QGraphicsScene();
   view = new QGraphicsView(scene);
   gravity = new b2Vec2(0.0f, 0.0f);
   world = new b2World(*gravity);
   groundBodyDef.position.Set(0.0f, 0.0f);
   //groundBody = world->CreateBody(&groundBodyDef);
   //groundBox.SetAsBox(100.0f, 100.0f);
   //groundBody->CreateFixture(&groundBox, 0.0f);


   setWindowSize();

    addPlayerToScene();

    QTimer* timer = new QTimer();


    wakeWorld();
    connect(timer,SIGNAL(timeout()),this,SLOT(Step()));
    timer->start(CONFIG::GameSpeed());

}
void SceneManager::Step()
{
    float timeStep = 1.0f / 60.f;
    int32 velocityIterations = 10;
    int32 positionIterations = 8;
            world->Step(timeStep, velocityIterations, positionIterations);
}
void SceneManager::wakeWorld()
{
    for (b2Body* b = world->GetBodyList(); b; b = b->GetNext())
    {
        b->SetAwake(true);
        b->SetActive(true);
    }
}
void SceneManager::addPlayerToScene()
{
    Vehicle* v = new Vehicle(true);
    v->setBody(world->CreateBody(v->getBodyDef()));
     player = new Player(v);

    scene->addItem(player->getGraphic());


}

void SceneManager::setWindowSize()
{


    QSize screenSize = qApp->primaryScreen()->availableSize();

    view->setFixedSize(screenSize);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show();
    scene->setSceneRect(0-screenSize.rwidth()/2, 0-screenSize.rheight()/2, screenSize.rwidth(), screenSize.rheight());
}

