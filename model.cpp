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
	default:
		vertices = defaultObject;
		bodyDef = defaultBodyDef();
            break;
    }
}

void Model::syncTransform()
{
    b2Transform t = body->GetTransform();
    poly->setRotation(qRadiansToDegrees(body->GetAngle()));
    auto pos = QPointF(converter::convert(t.p));
    poly->setPos(pos);
//    qDebug() << "Model::syncTransform() : notify: ANGLE:" << t.q.GetAngle() << ".. Y-AXIS: " << t.q.GetYAxis().x << "," << t.q.GetYAxis().y << ".. X-AXIS: "<< t.q.GetXAxis().x << "," << t.q.GetXAxis().y;
}
