#ifndef WEAPON_H
#define WEAPON_H

#include <QPolygonF>

class Weapon
{
    public:
        explicit Weapon(float rx, float ry);

        void fireProjectile(qreal qx, qreal qy);
        float getRelativeX() const;

        float getRelativeY() const;

    private:
        float relativeX;
        float relativeY;
};

#endif // WEAPON_H
