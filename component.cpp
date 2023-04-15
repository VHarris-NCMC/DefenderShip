
#include "component.h"

#include <Box2D/Dynamics/b2Fixture.h>




Component::Component(const b2Vec2* localPos_,  b2Body* anchor)
{
    parent = anchor;
    mRelativePosition = localPos_;
    QTimer* timer = new QTimer();
   //connect(timer, SIGNAL(timeout()),this,SLOT(updatePosition()));
    connect(timer, SIGNAL(timeout()),this,SLOT(updateComponent()));
    timer->start(CONFIG::GameSpeed());

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.active = true;
    bodyDef.angularDamping = 2;
    mBody = SceneManager::Instance()->getWorld()->CreateBody(&bodyDef);

    b2MassData* data = new b2MassData();
    data->mass = 1;
    mBody->SetMassData(data);

    b2PolygonShape shape;
    shape.SetAsBox(1,1);

    mBody->CreateFixture(&shape, 1);
    mBody->SetTransform(parent->GetPosition() + *localPos_, mBody->GetAngle());

    weld();




}


b2Vec2* Component::getGlobalPosition()
{
    b2Vec2* rPos = new b2Vec2(mBody->GetPosition());
    b2Vec2 bodyPosition = parent->GetPosition();
    rPos->x = bodyPosition.x + mRelativePosition->x;
    rPos->y = bodyPosition.y + mRelativePosition->y;
    return rPos;
}
void Component::weld()
{
    b2WeldJointDef jointDef;
    jointDef.collideConnected = false;
    jointDef.bodyA = mBody;
    jointDef.bodyB = parent;
//    jointDef.referenceAngle  = 0.0f;
   // jointDef.localAnchorA.Set(mBody->GetLocalCenter().x, mBody->GetLocalCenter().y);
   // jointDef.localAnchorB.Set(-mRelativePosition->x, -mRelativePosition->y);

    jointDef.Initialize(mBody, parent, b2Vec2(*mRelativePosition));

    weldJoint = (b2WeldJoint*)SceneManager::Instance()->getWorld()->CreateJoint(&jointDef);

   weldJoint->SetDampingRatio(0);
    //weldJoint->SetFrequency(0);
}




