
#ifndef COMPONENT_H
#define COMPONENT_H

#include <QObject>
#include <Box2D/Dynamics/Joints/b2DistanceJoint.h>
#include <Box2D/Dynamics/Joints/b2WeldJoint.h>
#include <Box2D/Dynamics/b2Body.h>
#include <QTimer>

class Component : public QObject
{
    Q_OBJECT

public:
    explicit Component(const b2Vec2* localPos_,  b2Body* anchor);

    b2Vec2* getGlobalPosition();


protected:
    const b2Vec2* mRelativePosition;
    b2Body* parent;
     b2Body* mBody;
private:

    b2WeldJoint* weldJoint;
    void weld();

protected slots:
    //virtual void updatePosition();
    virtual void updateComponent();


};
inline void Component::updateComponent(){}
//inline void Component::updatePosition(){}

#endif // COMPONENT_H
