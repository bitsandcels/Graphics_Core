#pragma once
#include "DynamicObject.h"
#include "UI.h"



class Player
{
private:
	DynamicObject PlayerChar;
	DynamicObject PlayerAmmo;

	bool playerForward, playerRotate;
	float playerSpeed, playerTorque;
	float playerDir;

	bool ammoReady;
	float ammoSpeed, ammoDir, ammoOffset;

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
	bool GetDeath(int);

	void playerMove();
	void playerShoot();

	void Render(sf::RenderWindow & renderWindow);
	void Update(sf::RenderWindow & renderWindow);
};