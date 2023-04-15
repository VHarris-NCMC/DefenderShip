
#ifndef ENGINE_H
#define ENGINE_H

#include <Component.h>
#include <Plume.h>
#include <Thruster.h>




class Engine : public Component
{
public:
    explicit Engine(const b2Vec2* localPos,  b2Body* parent_, Thruster* thrust_);


    float getForce();

    void setActive(bool b);
    Plume& getPlume();
    void go();
    void applyBrake();
    void stopBrake();
    b2Body* getBody();
private:
    Plume mPlume = Plume(&mBody->GetPosition(), parent);
    Thruster* mThruster;
    bool isActive;



    // Component interface
protected slots:
//    void updatePosition()override{
//        mBody->SetTransform(mBody->GetPosition(), parent->GetAngle());
//        qDebug()<< "Engine" << mBody->GetPosition().x << "," << mBody->GetPosition().y;
//    };
    void updateComponent()override{
        
        
        mPlume.setPlumeThrust(mThruster->thrust(isActive));

    };
};

#endif // ENGINE_H
