
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
    b2Vec2* getGlobalPosition(b2Vec2 bodyPosition);

    void setActive(bool b);
    Plume& getPlume();
    void go();
private:
    Plume mPlume = Plume(mlocalPosition, parent);
    Thruster* mThruster;
    bool isActive;


    // Component interface
protected slots:
    void updatePosition()override{};
    void updateComponent()override{

        mPlume.getThrust(mThruster->thrust(isActive));

    };
};

#endif // ENGINE_H
