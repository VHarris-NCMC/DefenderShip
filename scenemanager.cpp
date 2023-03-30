#include "scenemanager.h"
#include "qapplication.h"

#include <QGraphicsScene>


SceneManager::SceneManager()
{

   scene = new QGraphicsScene();
   view = new QGraphicsView(scene);

   setWindowSize();

    generateSceneWithPlayer();

}

void SceneManager::generateSceneWithPlayer()
{
    player = new Player();
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

