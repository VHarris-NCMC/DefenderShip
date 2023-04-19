
#ifndef SPRITE_H
#define SPRITE_H

#include <qpixmap.h>
#include<QPainter>
#include <qvector2d.h>
#include <QLabel>
#include <QPixmap>
#include <QStyleOptionGraphicsItem>
#include <Component.h>
#include <QGraphicsPixmapItem>
#include <scenemanager.h>

class Sprite : public Component, public QGraphicsPixmapItem
{
    Q_OBJECT

        public:
    Sprite(b2Vec2* localPosition_,  b2Body* anchor);

            QPixmap* pixmap;
        protected:
    void center();
        protected  slots:
    virtual void updateComponent();


};

#endif // SPRITE_H
