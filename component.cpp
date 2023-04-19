
#include "component.h"
#include <GameObject.h>
#include <Box2D/Dynamics/b2Fixture.h>
#include <maincontroller.h>
#include <converter.h>
#include <CONFIG.h>



Component::Component(const b2Vec2* localPos_,  b2Body* anchor) :  QObject()
{
    try {
        parent = anchor;
        mRelativePosition = localPos_;
        if (localPos_ == nullptr) { throw std::runtime_error("Local Position Not Defined");}
        if (anchor == nullptr) { throw std::runtime_error("Anchor Not Defined");}
    } catch (std::exception e) {
        qDebug() << "Unable to construct component " << e.what();}


    QTimer* timer = new QTimer();
   //connect(timer, SIGNAL(timeout()),this,SLOT(updatePosition()));
    connect(timer, SIGNAL(timeout()),this,SLOT(updateComponent()));
    timer->start(CONFIG::GameSpeed());

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.active = true;
    bodyDef.angularDamping = 2;

    try{
        mBody = MAINCONTROLLER::ADD_TO_WORLD(&bodyDef);
        b2PolygonShape shape;
        shape.SetAsBox(1,1);
        mBody->CreateFixture(&shape, 1);
        mBody->SetTransform(parent->GetPosition() + *localPos_, mBody->GetAngle());

    }catch(std::exception e)
    {
        qDebug() << e.what();
    }
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

    weldJoint = (b2WeldJoint*)MAINCONTROLLER::SCENE()->getWorld()->CreateJoint(&jointDef);

   weldJoint->SetDampingRatio(0);
    //weldJoint->SetFrequency(0);
}




