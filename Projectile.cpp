#include "Projectile.h"
#include <QTimer>
#include <CONFIG.h>


Projectile::Projectile(int model, ProjectileDef def) : GameObject(new struct Model(model))
{
    //draw and place  rect


    //connect slot
    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()), this,SLOT(move()));
    timer->start(CONFIG::GameSpeed());

    // set lifespan
    lifespan = 1000;

}


void Projectile::move()
{
   this->setPos(this->x(), this->y() +speed);
    lifespan-=1;
    if (lifespan<=0)
    {
            delete(this);
    }
}

