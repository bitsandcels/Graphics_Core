#pragma once

#include "Position.h"
#include "SFML/Graphics.hpp"

/*
	-Handles the essentcial data needed for the sprite.

	-LAYERNUM:	The layernum param will be used in a priority queue
				to render out the sprites. What will be rendered first
				(the background for example) will have a lower layer number
				then something in the foreground (ie the player)

	-SF::COLOR: For sf::Color param, use either a color from sf::Color or use 
				sf::Color(r, g, b) for the color param where r, g, and b 
				are floats denoting a custom color

	-INT NUMSIDES:	For constructors and SetShape function that require a size, 
					use 0 to denote a circle. 1 and 2 are not valid numbers.
*/

class GraphicsData
{
private:
	Position position;			//Position/origin point of sprite
	int LayerNum;				//The order the sprite should be rendered in
	sf::CircleShape Shape;		//Shape of the sprite
	
	int size;					// Store the int size of the shape
	int numSides;				// store number of sides of the shape
	sf::Color color;			// Store color of the shape

	bool CheckSideNumerValidity(int);		//Check if the number of sides inputted is valid
	void DetermineShape(int, int);					//Determine if the shape will be a circle or not

	void SetPosition(float, float);					//Set the sprite position
	void SetShape(int, int, sf::Color);				//Set the shape of the sprite using SFML color
	void SetLayerNum(int);							//Set layer number

public:
	GraphicsData();		//Constructor
	GraphicsData(Position, int, int, sf::Color, int);		//Set using position, size, num sides, color, layernum
	GraphicsData(float, float, int, int, sf::Color, int);	//Set using X value, Y value, size, num sides, color and layernum
	~GraphicsData();	//Destructor

	float GetXPosition();							//Return X position
	float GetYPosition();							//Return Y position
	sf::CircleShape GetShape();						//Return shape
	int GetIntSize();								//Return int size of shape
	int GetLayerNum();								//Return layer number
	int GetNumSides();								//Return number of sides
	sf::Color GetColor();							//Return color
	void MoveShape(float, float, float&, float&);					//Move shape
	void RotateShape(float);						//Rotate shape
	void ScaleShape(float, float);					//Scale shape
	void SetColor(sf::Color);						//Set Color
	void ChangePosition(float X, float Y);	// Change the absolute position of an object

	GraphicsData(const GraphicsData&);	//Copy Constructor
	void operator = (const GraphicsData&);	//Set new GraphicsData to the current GraphicsData
};