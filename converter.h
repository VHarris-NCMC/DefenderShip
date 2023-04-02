#ifndef CONVERTER_H
#define CONVERTER_H

#include <Box2D/Common/b2Math.h>

#include <list>


class converter
{
	public:
		converter();
		static QPointF convert(b2Vec2 vector);
		static b2Vec2 convertToB2Point(QPointF Qpoints);
};

#endif // CONVERTER_H
