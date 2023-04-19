

#include <GameManager.h>
#include <QApplication>
#include <QGraphicsView>
#include <scenemanager.h>
#include <UpdateManager.h>
#include <windowmanager.h>
#include<Box2D/Box2D.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //create a sceneManager

    WindowManager* windowManager = WindowManager::Instance();
    SceneManager * sceneManager = SceneManager::Instance();
     UpdateManager* UPDATER = new UpdateManager();
    GameManager::SetPlayer(new Player());

    return a.exec();





}
