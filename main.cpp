

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








    return a.exec();





}
