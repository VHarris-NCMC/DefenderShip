#include<gamemanager.h>



GameManager::GameManager()
{
}

Player * GameManager::_player_ = nullptr;
void GameManager::SetPlayer(Player* player){
    try {
        if (_player_ != nullptr) { throw std::runtime_error("ERROR: PLAYER ALREADY EXISTS");}
            _player_ = player;
        }catch(const std::exception& error){
           qDebug() << error.what();
        }
}
Player* GameManager::GetPlayer()
{
    try {
            return _player_;
    } catch (const std::exception& ex) {
        qDebug() << "Error getting player: " << ex.what();
        return nullptr;
    }
}

