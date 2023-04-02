#include "updatemanager.h"

UpdateManager::UpdateManager()
{
	timer = new QTimer();
	connect(timer,SIGNAL(timeout()),this,SLOT(update()));
	timer->start(CONFIG::GameSpeed());

}

void UpdateManager::update()
{
	SceneManager::Instance()->safeStep();

}
