#include "StaticObject.h"

StaticObject::StaticObject()
{
	objectID = 0;
}

StaticObject::~StaticObject()
{

}

int StaticObject::GetID()
{
	return objectID;
}

void StaticObject::SetColor(sf::Color newColor)
{
	Visual.SetColor(newColor);
}

StaticObject::StaticObject(float X, float Y, int size, int numSides, sf::Color color, int layerNum, int ID)
{
	Visual = GraphicsData(X, Y, size, numSides, color, layerNum);
	objectID = ID;
}

StaticObject::StaticObject(Position pos, int size, int numSides, sf::Color color, int layerNum, int ID)
{
	Visual = GraphicsData(pos, size, numSides, color, layerNum);
	objectID = ID;
}

StaticObject::StaticObject(GraphicsData gData, int ID)
{
	Visual = gData;
	objectID = ID;
}

void StaticObject::Transform(int TransformType, float X, float Y)
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