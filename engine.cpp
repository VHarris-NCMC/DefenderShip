
#include "engine.h"

Engine::Engine(const b2Vec2* localPos,  b2Body* parent_, Thruster* thrust_) : Component(localPos, parent_)
{
    this->mThruster = thrust_;
    b2Vec2* plumeLocation = new b2Vec2(b2Vec2_zero);
    mPlume = new Plume(plumeLocation, parent);
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

float32 Engine::adjustAcceleration(float32 f)
{
    if (f + mThruster->acceleration < 0)
    {
        mThruster->acceleration = 0;
        return mThruster->acceleration;
    }else{
        mThruster->acceleration += f;
        return mThruster->acceleration;
    }
}

float32 Engine::adjustMaxThrust(float32 f)
{

    if (f + mThruster->maxThrust < 0)
    {
        mThruster->maxThrust = 0;
        return mThruster->maxThrust;
    }else{
        mThruster->maxThrust += f;
        return mThruster->maxThrust;
    }
}

float32 Engine::getAcceleration()
{
    return mThruster->acceleration;
}

float32 Engine::getMaxThrust()
{
    return mThruster->maxThrust;
}
void Engine::setActive(bool b)
{
    isActive = b;
}
Plume& Engine::getPlume(){return *mPlume ;}
void Engine::go()
{

    b2Vec2 force = mBody->GetWorldVector(b2Vec2(0,-1* getForce())) ;


    auto position = mBody->GetPosition();
    mBody->ApplyForce(force, position, true);
    mBody->ApplyLinearImpulse(force, position, true);







}
