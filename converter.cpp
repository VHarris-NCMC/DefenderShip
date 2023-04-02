#include "converter.h"


converter::converter()
{
}

QPointF converter::convert(b2Vec2 vector)
{
	auto qpf = (QPointF(vector.x,vector.y));
		return qpf;

}

b2Vec2 converter::convertToB2Point(QPointF qp)
{
		b2Vec2 b2pt;
		b2pt.x =  qp.x();
		b2pt.y = qp.y();
		return b2pt;
}
//b2Vec2 converter::convert(QVector2D vector)
//{
//	return b2Vec2(vector.x, vector.y);
//}
