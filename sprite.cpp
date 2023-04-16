
#include "sprite.h"

Sprite::Sprite(const b2Vec2* localPosition_,  b2Body* anchor) : Component(localPosition_, anchor)
{
    QTimer* timer = new QTimer();

    //Centers Sprite by default
     setPixmap(QPixmap("src/default.gif", "gif", Qt::AutoColor));

    show();
    timer->start(CONFIG::GameSpeed());
    SceneManager::Instance()->addToScene(this);
}

void Sprite::updateComponent()
{

}
void Sprite::center()
{
   setOffset(-pixmap().size().rwidth() /2, +pixmap().size().rheight()/2);
}

