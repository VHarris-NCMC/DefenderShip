
#include "engine.h"

Engine::Engine(const b2Vec2* localPos,  b2Body* parent_, Thruster* thrust_) : Component(localPos, parent_)
{
    this->mThruster = thrust_;
    isActive = false;
}
float Engine::getForce()
{



    return 100;
}

void Engine::setActive(bool b)
{
    isActive = b;
}
Plume& Engine::getPlume(){return mPlume ;}
void Engine::go()
{
    b2Vec2*  force = new b2Vec2(0, getForce());
    parent->ApplyForce(*force, *this->Component::getGlobalPosition(), true);
}
