#include "model.h"



Model::Model(int i)
{
	//TODO: extract switch from constructor
	switch (i)
	{
    case 1:
    bodyDef = playerBodyDef();
    vertices = playerObject;
        break;
    case 2:
    bodyDef = playerBodyDef();
    vertices = defaultObject;
    break;
    default:
        bodyDef = defaultBodyDef();
        //vertices = defaultObject;
        break;
    }
    //MAINCONTROLLER::ADD_TO_WOLD(bodyDef);

}

b2PolygonShape* Model::getShape()
{
    if (shape == nullptr)
    {
        qDebug() << "DEFAULT SHAPE USED";
        b2PolygonShape* defaultShape = new b2PolygonShape;
        defaultShape->SetAsBox(6,10);
        return defaultShape;
    }
    else{
        return shape;
    }
}

void Model::syncTransform(b2Body* body, QGraphicsItem* poly)
{
    if (body == nullptr){ qDebug() << "BODY NULL PTR"; return;
        if (poly == nullptr){qDebug()<< "POLY NULLPTR"; return;}
   // b2Transform t = body->GetTransform();
    poly->setRotation(qRadiansToDegrees(body->GetAngle()));
    auto pos = QPointF(converter::convertToQPointF(body->GetPosition()));
    poly->setPos(pos);
}
}
