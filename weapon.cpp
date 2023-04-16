#include "weapon.h"

Weapon::Weapon(const b2Vec2* localPos, b2Body* parent_, ProjectileDef* projectileDef) : Component(localPos, parent_)
{
    //projectile = *projectileDef;
}
void Weapon::Fire()
{
   //Projectile(1, projectile);
}



