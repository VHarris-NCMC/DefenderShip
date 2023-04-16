#ifndef WEAPON_H
#define WEAPON_H

#include <Component.h>
#include <Projectile.h>
#include <ProjectileDef.h>
#include <QPolygonF>

class Weapon : public Component
{
    public:
    explicit Weapon(const b2Vec2* localPos, b2Body* parent, ProjectileDef* projectileDef);
        void Fire();
    private:
    ProjectileDef projectile;

};

#endif // WEAPON_H
