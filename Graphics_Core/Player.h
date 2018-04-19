#pragma once
#include "DynamicObject.h"

class Player
{
private:
	DynamicObject PlayerChar;
	DynamicObject PlayerAmmo;

public:
	Player(float x, float y);
	~Player();


	sf::CircleShape ReturnPlayerShape();
	sf::CircleShape ReturnAmmoShape();
	void ResetAmmo();
	/*
	- Use 0 for Player
	- Use 1 for Ammo
	- bool false = not dead, true = dead
	*/
	void SetDeath(int, bool);
	void Render(sf::RenderWindow & renderWindow);
	void Update();
};