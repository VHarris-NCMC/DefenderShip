#include <plume.h>

Plume::Plume(const b2Vec2* localPosition_,  b2Body* anchor) : Component(localPosition_, anchor)
{


    setPixmap(QPixmap("src/plume.gif", "gif", Qt::AutoColor ));
    SceneManager::Instance()->addToScene(this);
    engineIsOn(false);
    QTimer* timer = new QTimer();

    show();
    timer->start(CONFIG::GameSpeed());


}
void Plume::engineIsOn(bool b)
{
    isOn = b;
}
void Plume::showPlume()
{
    setScale(maxScale * thrust);
}
void Plume::getThrust(qreal thrust_)
{
    thrust = thrust_;
}
