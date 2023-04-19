#ifndef CONVERTER_H
#define CONVERTER_H

#include <Box2D/Common/b2Math.h>

#include <list>


class converter
{
	public:
        converter();
        static QPointF convertToQPointF(b2Vec2 vector);
        static b2Vec2 convertToB2Vec2(QPointF q_point);
        static b2Vec2 convertToB2Vec2(QPoint q_point);


};

#endif // CONVERTER_H
