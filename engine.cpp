
#include "engine.h"

Engine::Engine(const b2Vec2* localPos,  b2Body* parent_, Thruster* thrust_) : Component(localPos, parent_)
{
    this->mThruster = thrust_;
    isActive = false;
}
float Engine::getForce()
{
    return mThruster->currentThrust;
}
void Engine::applyBrake()
{
    mThruster->isBraking = true;
}
void Engine::stopBrake()
{
    mThruster->isBraking = false;
}

b2Body* Engine::getBody()
{
    return mBody;
}
void Engine::setActive(bool b)
{
    isActive = b;
}
Plume& Engine::getPlume(){return mPlume ;}
void Engine::go()
{

    b2Vec2 force = mBody->GetWorldVector(b2Vec2(0,-1* getForce())) ;


    auto position = mBody->GetPosition();
    mBody->ApplyForce(force, position, true);
    mBody->ApplyLinearImpulse(force, position, true);







}
