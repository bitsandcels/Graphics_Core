#include "DynamicObject.h"

DynamicObject::DynamicObject()
{
	objectID = 0;
}

DynamicObject::DynamicObject(Position pos, int size, int numSides, sf::Color color, int layerNum, int ID)
{
	Visual = GraphicsData(pos, size, numSides, color, layerNum);
	objectID = ID;
}


DynamicObject::~DynamicObject()
{

}

int DynamicObject::GetID()
{
	return objectID;
}

void DynamicObject::SetVisual(float X, float Y, int size, int numSides, sf::Color color, int layerNum)
{
	Visual = GraphicsData(X, Y, size, numSides, color, layerNum);
}

void DynamicObject::SetVisual(Position pos, int size, int numSides, sf::Color color, int layerNum)
{
	Visual = GraphicsData(pos, size, numSides, color, layerNum);
}

void DynamicObject::SetColor(sf::Color newColor)
{
	Visual.SetColor(newColor);
}

void DynamicObject::Transform(int TransformType, float X, float Y, float & newX, float & newY)
{
	switch (TransformType)
	{
	case 0:		//MOVE OBJECT
		Visual.MoveShape(X, Y, newX, newY);
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

void DynamicObject::ChangePosition(float X, float Y)
{
	Visual.ChangePosition(X, Y);
}
