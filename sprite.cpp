
#include "sprite.h"

Sprite::Sprite(const b2Vec2* localPosition_,  b2Body* anchor) : Component(localPosition_, anchor)
{


    //Centers Sprite by default
    pixmap = new QPixmap("src/default.gif", "gif", Qt::AutoColor);
    setPixmap(*pixmap);

    show();

    SceneManager::Instance()->addToScene(this);
}

void Sprite::updateComponent()
{

}
void Sprite::center()
{
    setOffset(-pixmap->size().rwidth() /2, +pixmap->size().rheight()/2);
}


