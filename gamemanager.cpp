#include<gamemanager.h>



GameManager::GameManager(Player* player)
{
}

Player * GameManager::_player_ = nullptr;
void GameManager::SetPlayer(Player* player){
    if (_player_ == nullptr)
    {
        _player_ = player;
    }
    else{
        qDebug() << "ERROR, PLAYER ALREADY EXISTS";
    }
}

Player* GameManager::GetPlayer()
{
    if (_player_ == nullptr)
    {
        qDebug() << " ERROR, PLAYER NOT INSTANTIATED";
        return nullptr;
    }
    return _player_;
}

