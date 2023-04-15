#include <plume.h>

Plume::Plume(const b2Vec2* localPosition_,  b2Body* anchor) : Component(localPosition_, anchor)
{


    setPixmap(QPixmap("src/plume.gif", "gif", Qt::AutoColor ));
    SceneManager::Instance()->addToScene(this);
    engineIsOn(false);
    QTimer* timer = new QTimer();
    setOffset(-pixmap().size().rwidth() /2, -pixmap().size().rheight()/2);
    show();
    timer->start(CONFIG::GameSpeed());


}
void Plume::engineIsOn(bool b)
{
    isOn = b;
}
void Plume::showPlume()
{
    setRotation(qRadiansToDegrees(mBody->GetAngle()));
    setScale(maxScale * thrust);
    setPos(converter::convert(mBody->GetPosition()));
}
void Plume::setPlumeThrust(qreal thrust_)
{
    thrust = thrust_;
}
