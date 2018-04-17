#include "Button.h"

Button::Button(float _posX, float _posY, int _size, AssetHouse &buttonShape, int _ID, sf::Color _color)
{
	posX = _posX;
	posY = _posY;
	size = _size;
	ID = _ID;
	clicked = false;
	color = _color;
	buttonShape.SetGraphics(_posX, _posY, _size, 4, color, 4, false, _ID, false);
	float trashX = 0, trashY = 0;	// CHECK IF NEEDED
	buttonShape.Transform(1, 45, 0, _ID, trashX, trashY); 
}

Button::~Button()
{

}

float Button::getX()
{
	return posX;
}

float Button::getY()
{
	return posY;
}

int Button::getSize()
{
	return size;
}

int Button::getID()
{
	return ID;
}

bool Button::getClicked()
{
	return clicked;
}

sf::Color Button::getColor()
{
	return color;
}

sf::CircleShape Button::getShape(AssetHouse &buttonShape)
{
	return buttonShape.getShapeObj(ID);
}

void Button::Click()
{
	clicked = true;
}
void Button::UnClick()
{
	clicked = false;
}

