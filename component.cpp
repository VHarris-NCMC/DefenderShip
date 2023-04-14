
#include "component.h"


Component::Component(const b2Vec2* localPos_,  b2Body* anchor)
{
    parent = anchor;
    mlocalPosition = localPos_;
    QTimer* timer = new QTimer();
   connect(timer, SIGNAL(timeout()),this,SLOT(updatePosition()));
    connect(timer, SIGNAL(timeout()),this,SLOT(updateComponent()));
    timer->start(CONFIG::GameSpeed());
}


b2Vec2* Component::getGlobalPosition()
{
    b2Vec2* rPos = new b2Vec2();
    b2Vec2 bodyPosition = parent->GetPosition();
    rPos->x = bodyPosition.x + mlocalPosition->x;
    rPos->y = bodyPosition.y + mlocalPosition->y;
    return rPos;
}



