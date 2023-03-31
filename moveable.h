#ifndef MOVEABLE_H
#define MOVEABLE_H

class Moveable
{
    public:
        virtual void moveForward();
        virtual void moveBackward();
        virtual void turnLeft();
        virtual void turnRight();
        virtual void strafeLeft();
        virtual void strafeRight();


        float getForwardSpd() const;
        void setForwardSpd(float newforwardSpd);

        float getBackwardSpeed() const;
        void setBackwardSpeed(float newbackwardSpeed);

        float getStrafeSpeed() const;
        void setStrafeSpeed(float newstrafeSpeed);

        float getTurnSpeed() const;
        void setTurnSpeed(float newturnSpeed);

    private:
        float forwardSpeed=200;
        float backwardSpeed=-1;
        float strafeSpeed =1;
        float turnSpeed =1;
        float accelerationSpeed =1;
};






#endif // MOVEABLE_H
