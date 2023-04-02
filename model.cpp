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
