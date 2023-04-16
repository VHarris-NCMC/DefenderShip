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
#include <Box2D/Collision/Shapes/b2Shape.h>



struct Model
{


	public:
		Model(int i);
		std::list<QPointF>* getVertices(){return &vertices;};
		b2BodyDef* getBodyDef(){return bodyDef;};
		b2Body* getBody(){return body;};
        b2PolygonShape* getShape();
        QGraphicsPolygonItem* getPoly(){return poly;};
		void setPoly(QGraphicsPolygonItem* poly_){poly = poly_;};
		void setBody(b2Body body_){body = &body_;};
		void setBody(b2Body* body_){ body = body_;};
		void setBody(const b2Body& body_){body = new b2Body(body_);};

        void syncTransform();
	private:
		b2Body* body = {nullptr};
        b2PolygonShape* shape = { nullptr };
		std::list<QPointF> vertices;
		b2BodyDef*  bodyDef = {nullptr};
		QGraphicsPolygonItem* poly={nullptr};
		Model(std::list<QPointF>* pts, b2BodyDef* body);

		//TODO: Convert Statics to saved XML Objects
		inline static std::list<QPointF> playerObject= {	QPointF(-5, 2), QPointF(-7.5, 9),
											   QPointF(-7.5,-15), QPointF(-4, -15), QPointF(-4, -4), QPointF(-2, -4),
											   QPointF(-2, -6), QPointF(0, -7), QPointF(0,0)
											};
        inline static std::list<QPointF> defaultObject= { QPointF(-10,10),  QPointF(-10,-10)};

		inline static b2BodyDef* defaultBodyDef(){
            auto _bodyDef_default = new b2BodyDef();
            _bodyDef_default->active = true;
            _bodyDef_default->awake = true;
            _bodyDef_default->type = b2BodyType::b2_dynamicBody;
            _bodyDef_default->linearVelocity(0);
            _bodyDef_default->linearDamping =100;
            _bodyDef_default->angularDamping = 0;
            _bodyDef_default->fixedRotation = false;
            return _bodyDef_default;
		};
        inline static b2BodyDef* playerBodyDef(){
            auto _bodyDef = new b2BodyDef();
            _bodyDef->type = b2BodyType::b2_dynamicBody;
            _bodyDef->linearVelocity(0);
            _bodyDef->linearDamping =0.8f;
            _bodyDef->angularDamping = 6;
            _bodyDef->active = true;
            _bodyDef->awake = true;
            _bodyDef->fixedRotation = false;
            _bodyDef->gravityScale = 0;
			//FIX: size set for testing


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
            return _bodyDef;
		}




		static Model getModel(int i);

};

#endif // MODEL_H
