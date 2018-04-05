#include "DynamicObject.h"

DynamicObject::DynamicObject()
{

}

DynamicObject::~DynamicObject()
{

}

void DynamicObject::SetVisual(float X, float Y, int size, int numSides, sf::Color color, int layerNum)
{
	Visual = GraphicsData(X, Y, size, numSides, color, layerNum);
}

void DynamicObject::SetVisual(Position pos, int size, int numSides, sf::Color color, int layerNum)
{
	Visual = GraphicsData(pos, size, numSides, color, layerNum);
}

void DynamicObject::Transform(int TransformType, float X, float Y)
{
	switch (TransformType)
	{
	case 0:		//MOVE OBJECT
		Visual.MoveShape(X, Y);
		break;

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

sf::CircleShape DynamicObject::Render()
{
	return Visual.GetShape();
}

int DynamicObject::GetLayerNum()
{
	return Visual.GetLayerNum();	//Return Shape's layer number
}