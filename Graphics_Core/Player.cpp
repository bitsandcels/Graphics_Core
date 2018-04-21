#include "Player.h"
#include <iostream>

Player::Player(float x, float y)
{
	PlayerChar.SetVisual(x, y, 30, 3, sf::Color::Cyan, 0);

	ammoOffset = -102;

	playerForward = playerRotate = false;
	playerSpeed = -0.4f;
	playerTorque = 0.1f;

	PlayerChar.Transform(2, 1, 2, x, y);
	playerDir = 90.0f;

	ammoReady = true;
	ammoSpeed = -1;
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

bool Player::GetDeath(int VAL)
{
	if (VAL == 0)
	{
		return PlayerChar.CanRender();
	}
	if (VAL == 1)
	{
		return PlayerAmmo.CanRender();
	}
	return false;
}



void Player::playerMove()
{

	float movex, movey;
	//	PlayerChar.Transform(0, 0, playerSpeed*playerForward, movex, movey);

	if (playerForward)
	{
		PlayerChar.Transform(0, (cos(playerDir*PI / 180)*playerSpeed), (sin(playerDir*PI / 180)*playerSpeed), movex, movey);
	}

	if (playerRotate)
	{
		PlayerChar.Transform(1, playerTorque*playerRotate, 0, movex, movey);
		playerDir += playerTorque;
		//cout << playerDir << endl;
	}

	PlayerAmmo.Transform(0, (cos(ammoDir*PI / 180)*ammoSpeed), (sin(ammoDir*PI / 180)*ammoSpeed), movex, movey);


	//check position off screen 

	if (PlayerChar.Render().getPosition().x < 0)
	{
		PlayerChar.Transform(0, GLOBAL_X_WIN_SIZE - 20, 0, movex, movey);
	}
	else if (PlayerChar.Render().getPosition().y < 0)
	{
		PlayerChar.Transform(0, 0, GLOBAL_Y_WIN_SIZE - 20, movex, movey);
	}
	else if (PlayerChar.Render().getPosition().x > GLOBAL_X_WIN_SIZE)
	{
		PlayerChar.Transform(0, -GLOBAL_X_WIN_SIZE + 20, 0, movex, movey);
	}
	else if (PlayerChar.Render().getPosition().y > GLOBAL_Y_WIN_SIZE)
	{
		PlayerChar.Transform(0, 0, -GLOBAL_Y_WIN_SIZE + 20, movex, movey);
	}

	if (PlayerAmmo.Render().getPosition().x < 0)
	{
		PlayerAmmo.Transform(0, GLOBAL_X_WIN_SIZE - 20, 0, movex, movey);
	}
	else if (PlayerAmmo.Render().getPosition().y < 0)
	{
		PlayerAmmo.Transform(0, 0, GLOBAL_Y_WIN_SIZE - 20, movex, movey);
	}
	else if (PlayerAmmo.Render().getPosition().x > GLOBAL_X_WIN_SIZE)
	{
		PlayerAmmo.Transform(0, -GLOBAL_X_WIN_SIZE + 20, 0, movex, movey);
	}
	else if (PlayerAmmo.Render().getPosition().y > GLOBAL_Y_WIN_SIZE)
	{
		PlayerAmmo.Transform(0, 0, -GLOBAL_Y_WIN_SIZE + 20, movex, movey);
	}

}

void Player::playerShoot()
{
	if (ammoReady)
	{
		PlayerAmmo.SetVisual(PlayerChar.Render().getPosition().x + cos(playerDir*PI / 180) * ammoOffset, PlayerChar.Render().getPosition().y + sin(playerDir*PI / 180) * ammoOffset, 10, 0, sf::Color::Red, 1);
		ammoDir = playerDir;
		PlayerAmmo.SetDeath(false);
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

void Player::Update(sf::RenderWindow & renderWindow)
{
	if (PlayerChar.CanRender()) //don't take player character input if dead
		return;

	sf::Event event;
	//When there is an Event
	while (renderWindow.pollEvent(event))
	{
		//figure out what type of event there is
		switch (event.type)
		{
			// window closed
		case sf::Event::Closed:
			renderWindow.close();
			break;

			// key pressed
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Space)
			{
				playerShoot();
			}
			else if (event.key.code == sf::Keyboard::A)
			{
				playerRotate = true;
				playerTorque = -1 * (abs(playerTorque));
			}
			/*else if (event.key.code == sf::Keyboard::S)
			{

			}*/
			else if (event.key.code == sf::Keyboard::D)
			{
				playerRotate = true;
				playerTorque = (abs(playerTorque));

			}
			else if (event.key.code == sf::Keyboard::W)
			{
				playerForward = true;
			}
			break;

		case sf::Event::KeyReleased:
			/*if (event.key.code == sf::Keyboard::Space)
			{

			}*/
			if (event.key.code == sf::Keyboard::A)
			{
				playerRotate = false;

			}
			/*else if (event.key.code == sf::Keyboard::S)
			{

			}*/
			else if (event.key.code == sf::Keyboard::D)
			{
				playerRotate = false;

			}
			else if (event.key.code == sf::Keyboard::W)
			{
				playerForward = false;
			}
			break;
		default:
			break;
		}
	}
	this->playerMove();
}