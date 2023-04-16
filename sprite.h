
#ifndef SPRITE_H
#define SPRITE_H

#include <qpixmap.h>
#include<QPainter>
#include <qgraphicsitem.h>
#include <qvector2d.h>
#include <GameObject.h>
#include <QLabel>
#include <QPixmap>
#include <QStyleOptionGraphicsItem>
#include <Component.h>

class Sprite : public Component, public QGraphicsPixmapItem
{
    Q_OBJECT

        public:
    Sprite(const b2Vec2* localPosition_,  b2Body* anchor);

        protected:
    void center();
        protected  slots:
    virtual void updateComponent();


};

#endif // SPRITE_H
