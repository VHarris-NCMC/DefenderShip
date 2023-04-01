#ifndef MODEL_H
#define MODEL_H

#include <list>
#include <map>
#include <qpoint.h>

#include <Box2D/Dynamics/b2Body.h>



struct Model
{


	public:
		Model(int i);
		std::list<QPointF>* getVertices(){return &vertices;};
		b2BodyDef* getBody(){return bodyDef;};

	private:
		std::list<QPointF> vertices;
		b2BodyDef*  bodyDef;
		Model(std::list<QPointF>* pts, b2BodyDef* body);
		inline static std::list<QPointF> playerObject= {	QPointF(-5, 2), QPointF(-7.5, 9),
											   QPointF(-7.5,-15), QPointF(-4, -15), QPointF(-4, -4), QPointF(-2, -4),
											   QPointF(-2, -6), QPointF(0, -7), QPointF(0,0)
											};
		inline static std::list<QPointF> defaultObject= { QPointF(10,10),  QPointF(-10,10), QPointF(-10,-10), QPointF(10,-10), QPointF(10,10)};

		inline static b2BodyDef* defaultBodyDef(){
			auto body = new b2BodyDef();
			return body;
		};




		static Model getModel(int i);

};

#endif // MODEL_H
