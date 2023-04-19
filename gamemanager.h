#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <Player.h>
#include <mutex>
#include <InputManager.h>



class GameManager{


    private:
        inline static InputManager* input{ nullptr};
         GameManager(Player* player);
         ~GameManager(){};
         static  Player* _player_;
    public:
         static void SetPlayer(Player* player);
        static Player*GetPlayer();
        static void update();
};




#endif // GAMEMANAGER_H
