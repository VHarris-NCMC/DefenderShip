#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <GameObject.h>
#include<QGraphicsRectItem>
#include<QObject>
#include <ProjectileDef.h>
class Projectile : public GameObject, public QGraphicsRectItem
{
        Q_OBJECT
    public:
        explicit Projectile(int model, ProjectileDef def);
        explicit Projectile(struct Model* m);
        Projectile(const Projectile &) = delete;
        Projectile(Projectile &&) = delete;
        Projectile &operator =(Projectile&&) =delete;
        Projectile &operator =(Projectile&) = delete;

        const static Projectile* Bullet1();
       enum MissileType{
            Bullet = 0, Missile = 1, Rocket = 2, Area = 3
        };
        Projectile(Projectile* pProj);
    public slots:
        void move();
    private:
        int lifespan;
        const double speed = .2;
};
enum DamageType{
    Kinetic = 0, Explosive = 1, Flame = 2, EMP = 3, Sticky = 4
};

#endif // PROJECTILE_H
