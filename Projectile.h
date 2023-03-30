#ifndef PROJECTILE_H
#define PROJECTILE_H

#include<QGraphicsRectItem>
#include<QObject>

class Projectile : public QObject, public QGraphicsRectItem
{
        Q_OBJECT
    public:
        Projectile(QPointF q);

        enum MissileType{
            Bullet = 0, Missile = 1, Rocket = 2, Area = 3
        };
    public slots:
        void move();
    private:
        int lifespan;
        const double speed = 20;
};
enum DamageType{
    Kinetic = 0, Explosive = 1, Flame = 2, EMP = 3, Sticky = 4
};

#endif // PROJECTILE_H
