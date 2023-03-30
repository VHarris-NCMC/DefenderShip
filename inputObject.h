#ifndef INPUTOBJECT_H
#define INPUTOBJECT_H

#include <QGraphicsScene>
#include <QKeyEvent>
#include <moveable.h>


class InputObject
{
    public:


        virtual void keyEventHandler(QKeyEvent* event);
    private:
};

#endif // INPUTOBJECT_H
