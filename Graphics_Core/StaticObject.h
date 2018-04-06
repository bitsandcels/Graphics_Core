#pragma once
#include "GraphicsData.h"

class StaticObject
{
private:
	GraphicsData Visual;

public:
	StaticObject();
	StaticObject(float X, float Y, int size, int numSides, sf::Color color, int layerNum);
	StaticObject(Position pos, int size, int numSides, sf::Color color, int layerNum);
	StaticObject(GraphicsData gData);
	~StaticObject();

	/*
	Update translates member Visual using:
	-	@param TrasnformType : Transform Shape
	-	1 = ROTATE
	-	2 = SCALE
	-	@param X : Set X Value (by how much to move/scale along X-Axis)
	-	Use X also as angle to rotate shape
	-	@param Y : Set Y Value (by how much to move/scale along Y-Axis)
	*/
	void Transform(int TransformType, float X, float Y);

	//Returns Visual.GetShape() to render window
	sf::CircleShape Render();

	//Return Layer Number for priority queue
	int GetLayerNum();
};