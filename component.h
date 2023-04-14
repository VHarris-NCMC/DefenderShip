
#ifndef COMPONENT_H
#define COMPONENT_H

#include <GameObject.h>
#include <QObject>



class Component : public QObject
{
    Q_OBJECT

public:
    explicit Component(const b2Vec2* localPos_,  b2Body* anchor);

    b2Vec2* getGlobalPosition();


protected:
    const b2Vec2* mlocalPosition;
    b2Body* parent;

private:


protected slots:
    virtual void updatePosition();
    virtual void updateComponent();


};
inline void Component::updateComponent(){}
inline void Component::updatePosition(){}

#endif // COMPONENT_H
