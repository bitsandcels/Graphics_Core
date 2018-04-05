#include "GraphicsData.h"

GraphicsData::GraphicsData()
{

}

GraphicsData::GraphicsData(Position pos, int inSize, int numInSides, sf::Color inColor, int layer)
{
	position = pos;
	size = inSize;
	numSides = numInSides;
	color = inColor;
	SetShape(size, numSides, color);
	SetLayerNum(layer);
}

GraphicsData::GraphicsData(float X, float Y, int inSize, int numInSides, sf::Color inColor, int layer)
{
	size = inSize;
	numSides = numInSides;
	color = inColor;
	SetPosition(X, Y);
	SetShape(size, numSides, color);
	SetLayerNum(layer);
}

GraphicsData::~GraphicsData()
{

}

bool GraphicsData::CheckSideNumerValidity(int num)
{
	if (num == 0 || num >= 3)	//if the shape is a circle or has 3 sides or greater
	{
		return true;
	}

	return false;
}

void GraphicsData::DetermineShape(int size, int numSides)
{
	if (CheckSideNumerValidity(numSides))
	{
		if (numSides == 0)
		{
			Shape = sf::CircleShape(size);
		}
		else
		{
			Shape = sf::CircleShape(size, numSides);
		}
	}
}

void GraphicsData::SetPosition(float X, float Y)
{
	if (position.SetXYPos(X, Y))
	{
		return;
	}
}

float GraphicsData::GetXPosition()
{
	return position.GetXPos();
}

float GraphicsData::GetYPosition()
{
	return position.GetYPos();
}

void GraphicsData::SetShape(int size, int numSides, sf::Color color)
{
	DetermineShape(size, numSides);
	Shape.setFillColor(color);
	Shape.setPosition(sf::Vector2f(position.GetXPos(), position.GetYPos()));
}

sf::CircleShape GraphicsData::GetShape()
{
	return Shape;
}

sf::Color GraphicsData::GetColor()
{
	return color;
}

void GraphicsData::SetLayerNum(int num)
{
	LayerNum = num;
}

int GraphicsData::GetLayerNum()
{
	return LayerNum;
}

int GraphicsData::GetNumSides()
{
	return numSides;
}

int GraphicsData::GetIntSize()
{
	return size;
}

GraphicsData::GraphicsData(const GraphicsData& other)
{
	position = other.position;
	Shape = other.Shape;
	LayerNum = other.LayerNum;
}

void GraphicsData::operator =(const GraphicsData& other)
{
	position = other.position;
	Shape = other.Shape;
	LayerNum = other.LayerNum;
}

void GraphicsData::MoveShape(float X, float Y)
{
	Shape.move(X, Y);
}

void GraphicsData::RotateShape(float Angle)
{
	Shape.rotate(Angle);
}

void GraphicsData::ScaleShape(float X, float Y)
{
	Shape.scale(X, Y);
}