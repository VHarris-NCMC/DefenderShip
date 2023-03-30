#ifndef PLAYER_H
#define PLAYER_H


#include <QGraphicsItem>
#include <Vehicle.h>

class Player
{
    public:
        Player();


        Moveable* getVehicle();
        QGraphicsItem* getGraphic();



    private:
        Vehicle* vehicle;





};
#endif // PLAYER_H
