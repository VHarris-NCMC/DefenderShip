#ifndef PLUME_H
#define PLUME_H

#include <qlabel.h>
#include <qpixmap.h>
#include<QPainter>
#include <qgraphicsitem.h>
#include <qvector2d.h>
#include <GameObject.h>
#include <QLabel>
#include <QPixmap>
#include <QStyleOptionGraphicsItem>
#include <Component.h>

class Plume :  public Component, public QGraphicsPixmapItem
{


Q_OBJECT
public:

Plume(const b2Vec2* localPosition_,  b2Body* anchor);
        void engineIsOn(bool b);
        void stop();
        void getThrust(qreal thrust_);
    protected  slots:
        void updateComponent() override {showPlume();}
        void updatePosition() override {setPos(converter::convert(*getGlobalPosition()));}

    private:
        bool isOn;
        qreal thrust;
        const qreal minScale = .10;
        const qreal maxScale = 1.6;
        void showPlume();

};

#endif // PLUME_H
