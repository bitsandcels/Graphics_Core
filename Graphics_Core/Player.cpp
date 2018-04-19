#include "Player.h"

Player::Player(float x, float y)
{
	PlayerChar.SetVisual(x, y, 30, 3, sf::Color::Cyan, 0);
	PlayerAmmo.SetVisual(x + 20, y - 100, 10, 0, sf::Color::Red, 1);
	//PlayerAmmo.SetDeath(true);
}

Player::~Player()
{

}

sf::CircleShape Player::ReturnPlayerShape()
{
	return PlayerChar.Render();
}

sf::CircleShape Player::ReturnAmmoShape()
{
	return PlayerAmmo.Render();	//Will only show when the player clicks space and calls for it
}

void Player::ResetAmmo()
{
	PlayerAmmo.ChangePosition(PlayerChar.Render().getPosition().x, PlayerChar.Render().getPosition().y);
	PlayerAmmo.SetDeath(true);
}

void Player::SetDeath(int VAL, bool isDead)
{
	if (VAL == 0)
	{
		PlayerChar.SetDeath(true);
	}
	if (VAL == 1)
	{
		PlayerAmmo.SetDeath(true);
	}
}

void Player::Render(sf::RenderWindow & renderWindow)
{
	if (!PlayerAmmo.CanRender())
	{
		renderWindow.draw(PlayerAmmo.Render());		//Render ammo
	}
	if (!PlayerChar.CanRender())
	{
		renderWindow.draw(PlayerChar.Render());		//Render player
	}

}

void Player::Update()
{

}