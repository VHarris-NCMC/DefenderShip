

#include <GameManager.h>
#include <QApplication>
#include <QGraphicsView>
#include <SceneManager.h>
#include <UpdateManager.h>
#include <WindowManager.h>
#include<Box2D/Box2D.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //create a sceneManager

    WindowManager* windowManager = WindowManager::Instance();
    SceneManager * sceneManager = SceneManager::Instance();
       GameManager* gameManager = GameManager::Instance();
     UpdateManager* UPDATER = new UpdateManager();

//           //a static body
//           b2BodyDef myBodyDef;
//           myBodyDef.type = b2_staticBody;
//           myBodyDef.position.Set(0, 0);
//           b2Body* staticBody = sceneManager->getWorld()->CreateBody(&myBodyDef);

//           //shape definition
//           b2PolygonShape polygonShape;

//           //fixture definition
//           b2FixtureDef myFixtureDef;
//           myFixtureDef.shape = &polygonShape;

//           //add four walls to the static body
//           polygonShape.SetAsBox( 20, 1, b2Vec2(0, 0), 0);//ground
//           staticBody->CreateFixture(&myFixtureDef);
//           polygonShape.SetAsBox( 20, 1, b2Vec2(0, 40), 0);//ceiling
//           staticBody->CreateFixture(&myFixtureDef);
//           polygonShape.SetAsBox( 1, 20, b2Vec2(-20, 20), 0);//left wall
//           staticBody->CreateFixture(&myFixtureDef);
//           polygonShape.SetAsBox( 1, 20, b2Vec2(20, 20), 0);//right wall
//           staticBody->CreateFixture(&myFixtureDef);







    return a.exec();





}
