#ifndef PLUME_H
#define PLUME_H

#include <Sprite.h>

class Plume :   public Sprite
{

public:

explicit Plume(const b2Vec2* localPosition_,  b2Body* anchor);
        void engineIsOn(bool b);
        void stop();
        void setPlumeThrust(qreal thrust_);
    protected  slots:
        void updateComponent() override {
            showPlume();

        }
        //void updatePosition() override {setPos(converter::convert(*getGlobalPosition()));}
//          void updatePosition() override {
//              qDebug()<< "Plume" << mBody->GetPosition().x << "," << mBody->GetPosition().y;
//              log();
//              setPos(converter::convert(mBody->GetPosition()));
//              setRotation(parent->GetAngle());
//          }
    private:
        bool isOn;
        qreal thrust;
        const qreal minScale = .10;
        const qreal maxScale = 1.6;
        void showPlume();


};

#endif // PLUME_H
