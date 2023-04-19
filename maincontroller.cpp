
#include "maincontroller.h"


MAINCONTROLLER::MAINCONTROLLER()
{
    _MC_INSTANCE = this;
    SCENE_INSTANCE = new SceneManager();
    SCENE_INSTANCE->Initialize();
    WINDOW_INSTANCE = new WindowManager();
    WINDOW_INSTANCE->view->setScene(SCENE()->getScene());
    SCENE_INSTANCE->resizeToWindow();
    GAME_INSTANCE =new GameManager();


}

b2Body* MAINCONTROLLER::ADD_TO_WORLD(b2BodyDef* bodyDef)
{
    try {
        return SCENE()->addToWorld(bodyDef);
    } catch (...) {
        qDebug() << "UNABLE TO ADD TO WORLD";
    }
}
void MAINCONTROLLER::ADD_TO_SCENE(QGraphicsItem* graphic)
{
    try {
        SCENE()->addToView(graphic);
    } catch (...) {
        qDebug() << "UNABLE TO ADD TO WORLD";
    }
}

SceneManager* MAINCONTROLLER::SCENE()
{
    return MAINCONTROLLER::INSTANCE()->SCENE_INSTANCE;
}

WindowManager* MAINCONTROLLER::WINDOW()
{
    return WINDOW_INSTANCE;
}

GameManager* MAINCONTROLLER::GAME()
{
    return GAME_INSTANCE;
}
void MAINCONTROLLER::BeginGame()
{
    WINDOW_INSTANCE->closeMenu();
    GAME_INSTANCE->SetPlayer(new Player());


}

