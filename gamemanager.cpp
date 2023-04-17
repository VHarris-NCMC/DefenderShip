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
Player& GameManager::getPlayerInstance()
{
    return *player;
}
Player* GameManager::getPlayer()
{
    return player;
}


