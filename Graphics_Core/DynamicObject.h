#pragma once
#include "GraphicsData.h"

const int MAX_TIME = 1000;

class DynamicObject
{
private:
	GraphicsData Visual;
	int objectID;
	bool isDead;
	int CounterToRender;

public:
	DynamicObject();
	DynamicObject(Position, int, int, sf::Color, int, int);
	~DynamicObject();

	int GetID();		// Get objectID

	/*
		SetVisual sets member Visual using:
		-	@param pos : Set the Position of the shape
			-	Use Position variable or Position(X, Y)
		-	ALT TO POS
			- @param X : X position
			- @param Y : Y position
		-	@param size : Set the Size of the shape
		-	@param numSides : Set number of sides
			-	Use 0 for circle and anything greater than
				3 for other shapes 
		-	@param color : Set color of shape
			-	Use sf::Color(r, g, b) or sf::Color::COLORNAME
		-	@param layerNum : sset the layer number
			-	The lower numbers will be rendered first
	*/
	void SetVisual(float X, float Y, int size, int numSides, sf::Color color, int layerNum);
	void SetVisual(Position pos, int size, int numSides, sf::Color color, int layerNum);

	void SetColor(sf::Color);		// Set object Color

	/*
		Update translates member Visual using:
		-	@param TrasnformType : Transform Shape
			-	0 = MOVE
			-	1 = ROTATE
			-	2 = SCALE
		-	@param X : Set X Value (by how much to move/scale along X-Axis)
			-	Use X also as angle to rotate shape
		-	@param Y : Set Y Value (by how much to move/scale along Y-Axis)
			-	When rotating, use 0 for Y
	*/
	void Transform(int TransformType, float X, float Y, float & newX, float & newY);

	/*
		-	Returns Visual.GetShape() to render window
	*/
	sf::CircleShape Render(); 

	/*
		-	Return Layer Number for priority queue
	*/
	int GetLayerNum();

	void ChangePosition(float X, float Y);	// Change the absolute position of an object

	void SetDeath(bool);	//Set var isAlive based on input bool value
	void UpdateTimer();
	bool CanRender();	//Determine if the shape can be rendered. Shape will not render if player shoots it (it's "dead" if true)
};