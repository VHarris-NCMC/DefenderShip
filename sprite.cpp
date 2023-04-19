
#include "sprite.h"

Sprite::Sprite(b2Vec2* localPosition_,  b2Body* anchor) : Component(localPosition_, anchor)
{
    //Centers Sprite by default
    try {
        if (localPosition_ != nullptr && anchor != nullptr)
        {
            pixmap = new QPixmap("src/:/sprites/src/default.gif", "gif", Qt::AutoColor);
            setPixmap(*pixmap);
            show();

        }else{
            if (localPosition_ == nullptr) { throw std::runtime_error("Local Position Not Defined in Sprite(b2Vec*, b2Body*)");}
            if (anchor == nullptr) { throw std::runtime_error("Anchor Not Defined in sprite()");}
        }
    }catch(std::exception e){
        qDebug() << " Unable to generate sprite" << e.what();
    }

}

void Sprite::updateComponent()
{

}
void Sprite::center()
{
    setOffset(-pixmap->size().rwidth() /2, +pixmap->size().rheight()/2);
}


