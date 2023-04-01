#ifndef PLAYER_H
#define PLAYER_H
#include <GameObject.h>
#include <QGraphicsItem>
#include <vehicle.h>

class Player : public  Vehicle
{
    public:
		Player();


    private:
		int score;

};
#endif // PLAYER_H
