#include<gamemanager.h>




GameManager::GameManager()
{
	InitializePlayer();
}





void GameManager::InitializePlayer()
{
	if  (player == nullptr)
	{
		player = new Player();
	}
}


