
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

    //b2Vec2  force = b2Vec2((cos(mBody->GetAngle()) * getForce()), (sin(mBody->GetAngle()-90)* getForce()));
    b2Vec2 force = mBody->GetWorldVector(b2Vec2(0,-1* getForce())) ;


    //auto globalPos = *this->Component::getGlobalPosition();
    auto position = mBody->GetPosition();
    mBody->ApplyForce(force, position, true);
//    qDebug() <<mBody->GetAngle();
//    qDebug() << "THIS::" << mBody->GetWorldVector(b2Vec2(0, -1)).y;


    //mBody->ApplyForce(force, globalPos, true);


    //b2Vec2 force = b2Vec2((cos(body->GetAngle()-4.7) * magnitude) , (sin(body->GetAngle()-4.7) * magnitude));
    //body->ApplyLinearImpulse(force, body->GetPosition());


}
