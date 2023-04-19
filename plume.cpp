#include <plume.h>

Plume::Plume(const b2Vec2* localPosition_,  b2Body* anchor) : Sprite(localPosition_, anchor)
{
    pixmap = new QPixmap(":/sprites/src/plume_with_smoke-modified.png", "png", Qt::AutoColor);
    setPixmap(*pixmap);
    center();
    //setPixmap(QPixmap("src/plume.gif", "gif", Qt::AutoColor ));


    engineIsOn(false);
//    QTimer* timer = new QTimer();
//    setOffset(-pixmap().size().rwidth() /2, +pixmap().size().rheight()/3);
//    show();
//    timer->start(CONFIG::GameSpeed());


}
void Plume::engineIsOn(bool b)
{
    isOn = b;
}
void Plume::showPlume()
{
    setRotation(qRadiansToDegrees(mBody->GetAngle()));
    setScale(maxScale * thrust);
    setPos(converter::convertToQPointF(mBody->GetPosition()));
}
void Plume::setPlumeThrust(qreal thrust_)
{
    thrust = thrust_;
}
