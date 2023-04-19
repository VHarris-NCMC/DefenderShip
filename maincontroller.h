
#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <bits/std_mutex.h>

#include <GameManager.h>
#include <scenemanager.h>
#include<windowmanager.h>




class MAINCONTROLLER
{
    friend class SceneManager;
    friend class GameManager;
public:
    MAINCONTROLLER();
    static void BeginGame();
    static b2Body* ADD_TO_WORLD(b2BodyDef* bodyDef);
    static void ADD_TO_SCENE(QGraphicsItem* graphic);
    static SceneManager* SCENE();
    static WindowManager* WINDOW();
    static GameManager* GAME();
private:
    inline static MAINCONTROLLER* _MC_INSTANCE ={nullptr};
    inline static SceneManager* SCENE_INSTANCE = {nullptr};
    inline static WindowManager* WINDOW_INSTANCE = {nullptr};
    inline static GameManager* GAME_INSTANCE = {nullptr};
    static MAINCONTROLLER* INSTANCE()
    {
        //lock
        std::lock_guard<std::mutex> lock(mutex_);
        //If instance does not exist, create a new one
        if (_MC_INSTANCE == nullptr){  _MC_INSTANCE= new MAINCONTROLLER();}
        // return signleton instance;
        return _MC_INSTANCE;
    }
    ~MAINCONTROLLER();
    inline static std::mutex mutex_;
    //Prevent Singleton from being copied.
    MAINCONTROLLER(MAINCONTROLLER const&);;
    void operator=(MAINCONTROLLER const&);;
};

#endif // MAINCONTROLLER_H
