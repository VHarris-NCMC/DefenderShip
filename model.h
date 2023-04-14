#ifndef MODEL_H
#define MODEL_H

#include <list>
#include <map>
#include <qpoint.h>
#include <converter.h>
#include <Box2D/Dynamics/b2Body.h>
#include <qdebug.h>
#include <qgraphicsitem.h>
#include <Box2D/Collision/Shapes/b2PolygonShape.h>



struct Model
{


	public:
		Model(int i);
		std::list<QPointF>* getVertices(){return &vertices;};
		b2BodyDef* getBodyDef(){return bodyDef;};
		b2Body* getBody(){return body;};
		QGraphicsPolygonItem* getPoly(){return poly;};
		void setPoly(QGraphicsPolygonItem* poly_){poly = poly_;};
		void setBody(b2Body body_){body = &body_;};
		void setBody(b2Body* body_){ body = body_;};
		void setBody(const b2Body& body_){body = new b2Body(body_);};
	private:
		b2Body* body = {nullptr};
		std::list<QPointF> vertices;
		b2BodyDef*  bodyDef = {nullptr};
		QGraphicsPolygonItem* poly={nullptr};
		Model(std::list<QPointF>* pts, b2BodyDef* body);

		//TODO: Convert Statics to saved XML Objects
		inline static std::list<QPointF> playerObject= {	QPointF(-5, 2), QPointF(-7.5, 9),
											   QPointF(-7.5,-15), QPointF(-4, -15), QPointF(-4, -4), QPointF(-2, -4),
											   QPointF(-2, -6), QPointF(0, -7), QPointF(0,0)
											};
		inline static std::list<QPointF> defaultObject= { QPointF(10,10),  QPointF(-10,10), QPointF(-10,-10), QPointF(10,-10), QPointF(10,10)};

		inline static b2BodyDef* defaultBodyDef(){
			auto body = new b2BodyDef();
			body->active = true;
			body->awake = true;

			return body;
		};
		inline static b2BodyDef* playerBodyDef(){
			auto body = new b2BodyDef();
			body->type = b2BodyType::b2_dynamicBody;
			body->linearVelocity(10);
			body->linearDamping =.001;
			//FIX: size set for testing
			b2PolygonShape dynamicBox;
			dynamicBox.SetAsBox(50,50);
			/* TODO: Make boxes polygonal (logic is done, but there is a max polygon limit per object
			b2Vec2 points[playerObject.size()];
			int i = 0;
			for (QPointF p : playerObject)
			{
				auto b2pt =  converter::convertToB2Point(p);
				points[i] = b2pt;
			}
			dynamicBox.Set(points, playerObject.size());
*/
			return body;
		}




		static Model getModel(int i);

};

#endif // MODEL_H
