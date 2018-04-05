#include "StaticObject.h"

StaticObject::StaticObject()
{

}

StaticObject::~StaticObject()
{

}

StaticObject::StaticObject(float X, float Y, int size, int numSides, sf::Color color, int layerNum)
{
	Visual = GraphicsData(X, Y, size, numSides, color, layerNum);
}

StaticObject::StaticObject(Position pos, int size, int numSides, sf::Color color, int layerNum)
{
	Visual = GraphicsData(pos, size, numSides, color, layerNum);
}

StaticObject::StaticObject(GraphicsData gData)
{
	Visual = gData;
}

void StaticObject::Transform(int TransformType, float X, float Y=0)
{
	switch (TransformType)
	{
	case 1:		//ROTATE OBJECT
		Visual.RotateShape(X);
		break;

	case 2:		//SCALE OBJECT
		Visual.ScaleShape(X, Y);
		break;

	default:	//DO NOTHING
		break;
	}
}

sf::CircleShape StaticObject::Render()
{
	return Visual.GetShape();
}

int StaticObject::GetLayerNum()
{
	return Visual.GetLayerNum();	//Return Shape's layer number
}