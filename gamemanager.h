#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <Player.h>
#include <mutex>
#include <InputManager.h>
#include <scenemanager.h>


class GameManager{

    friend class MAINCONTROLLER;
    private:
        inline static InputManager* input{ nullptr};
         GameManager();
         ~GameManager(){};
         static  Player* _player_;

    public:
         static void SetPlayer(Player* player);
        static Player*GetPlayer();
        static void update();
};




#endif // GAMEMANAGER_H
