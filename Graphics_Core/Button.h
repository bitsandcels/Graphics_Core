#pragma once
#include "AssetHouse.h"

class Button
{
private:
	float posX, posY;
	int size, ID;
	bool clicked;
	sf::Color color;

public:


	Button() {};										// Default constructor
	Button(float, float, int, AssetHouse&, int, sf::Color);		// Constructor that accepts parameters 
	~Button();											// default destructor

														//Accessors
	float getX();
	float getY();
	int getSize();
	int getID();
	bool getClicked();
	sf::Color getColor();
	sf::CircleShape getShape(AssetHouse &buttonShape);

	void Click();
	void UnClick();
};








