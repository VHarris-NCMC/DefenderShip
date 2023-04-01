#ifndef CONVERTER_H
#define CONVERTER_H

#include <Box2D/Common/b2Math.h>


class converter
{
	public:
		converter();
		static QPointF convert(b2Vec2 vector);

};

#endif // CONVERTER_H
