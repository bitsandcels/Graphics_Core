#include "Asteroids.h"

#include <random>

Asteroid::Asteroid(float& playerXPos, float& playerYPos, int ID)
{
	int top = rand() % 2;	// 0 == top/bottom, 1 == left/right
	int left = rand() % 2;	// 0 == left/top, 1 == right/bottom

	if (top == 0 && left == 0)
	{
		// Top Asteroid
		xPos = rand() % GLOBAL_X_WIN_SIZE;
		yPos = 0;
		
	}
	else if (top == 0 && left == 1)
	{
		// Bottom Asteroid
		xPos = rand() % GLOBAL_X_WIN_SIZE;
		yPos = GLOBAL_Y_WIN_SIZE;
		
	}
	else if (top == 1 && left == 0)
	{
		// Left Asteroid
		xPos = 0;
		yPos = rand() % GLOBAL_Y_WIN_SIZE;
	}
	else
	{
		// Right Asteroid
		xPos = GLOBAL_X_WIN_SIZE;
		yPos = rand() % GLOBAL_Y_WIN_SIZE;
	}
	size = rand() % 20 + 30;

	xTrans = playerXPos - xPos;
	yTrans = playerYPos - yPos;

	float xTemp = xTrans * xTrans;
	float yTemp = yTrans * yTrans;
	int length = xTemp + yTemp;
	length = sqrt(length);
	if (length != 0)
	{
		int speed = rand() % 10 + 3;
		xTrans = (xTrans / length) / speed;
		yTrans = (yTrans / length) / speed;
	}
	graphicsCoreIDNum = ID;
	Remove = false;
}

Asteroid::~Asteroid()
{
}

void Asteroid::UpdatePos(float newX, float newY)
{
	xPos = newX;
	yPos = newY;
}

void Asteroid::GetPos(float & xPosIn, float & yPosIn)
{
	xPosIn = xPos;
	yPosIn = yPos;
}

void Asteroid::GetTransform(float & xTransIn, float & yTransIn)
{
	xTransIn = xTrans;
	yTransIn = yTrans;
}

int Asteroid::GetSize()
{
	return size;
}

int Asteroid::GetID()
{
	return graphicsCoreIDNum;
}

bool Asteroid::GetRemove()
{
	return Remove;
}

void Asteroid::SetRemove(bool doRemove)
{
	Remove = doRemove;
}

void GenerateAsteroids(int playerScore, vector<Asteroid> & asteroids, float playerXPos, float playerYPos, AssetHouse & graphicsCore, int & asteroidID)
{
	float tempX = 0, tempY = 0;
	if (playerScore == 0 && asteroids.size() == 0)
	{
		Asteroid newAsteroid(playerXPos, playerYPos, asteroidID);
		newAsteroid.GetPos(tempX, tempY);
		graphicsCore.SetGraphics(tempX, tempY, newAsteroid.GetSize(), 4, sf::Color::White, 3, false, asteroidID, true);
		asteroidID++;
		asteroids.push_back(newAsteroid);
	}
	if (((playerScore + 10) / 10) > asteroids.size())
	{
		Asteroid newAsteroid(playerXPos, playerYPos, asteroidID);
		newAsteroid.GetPos(tempX, tempY);
		graphicsCore.SetGraphics(tempX, tempY, newAsteroid.GetSize(), 4, sf::Color::White, 3, false, asteroidID, true);
		asteroidID++;
		asteroids.push_back(newAsteroid);
	}
}

void UpdateAsteroids(vector<Asteroid> &asteroids, AssetHouse & graphicsCore, Player & player) 
{
	float tempXPos = 0, tempYPos = 0, newX = 0, newY = 0;
	int asteroidID = 0;
	int numAsterPushedBack = 0;
	for (int i = 0; i < asteroids.size(); i++)
	{
		asteroids[i].GetTransform(newX, newY);
		asteroidID = asteroids[i].GetID();
		graphicsCore.Transform(0, newX, newY, i, tempXPos, tempYPos, true);
		asteroids[i].UpdatePos(tempXPos, tempYPos);

		if (tempXPos > GLOBAL_X_WIN_SIZE)
		{
			graphicsCore.ChangePosition(i, 1, tempYPos);
			asteroids[i].UpdatePos(1, tempYPos);
		}
		else if (tempXPos < 0)
		{
			graphicsCore.ChangePosition(i, GLOBAL_X_WIN_SIZE - 1, tempYPos);
			asteroids[i].UpdatePos(GLOBAL_X_WIN_SIZE - 1, tempYPos);
		}
		else if (tempYPos > GLOBAL_Y_WIN_SIZE)
		{
			graphicsCore.ChangePosition(i, tempXPos, 1);
			asteroids[i].UpdatePos(tempXPos, 1);
		}
		else if (tempYPos < 0)
		{
			graphicsCore.ChangePosition(i, tempXPos, GLOBAL_Y_WIN_SIZE - 1);
			asteroids[i].UpdatePos(tempXPos, GLOBAL_Y_WIN_SIZE - 1);
		}

		DetectAsteriodCollision(asteroids, i, graphicsCore, player, asteroidID);
		if (asteroids[i].GetRemove() == true)
		{
			//asteroids[i] = asteroids.back();
			//++numAsterPushedBack;
			std::swap(asteroids[i], asteroids.back());
			asteroids.pop_back();
		}
	}
	//RemoveAsteriods(asteroids, numAsterPushedBack);
}

void DetectAsteriodCollision(vector<Asteroid> &asteroids,int i, AssetHouse & graphicsCore, Player & player, int asteroidID)
{
	//Check if there is a collision between the player ship and asteriod
	if (graphicsCore.getShapeObj(asteroidID).getGlobalBounds().intersects(player.ReturnPlayerShape().getGlobalBounds()))
	{
		player.SetDeath(0, true);
	}
	//Check if there is a collision between the ammo and asteriod
	if (graphicsCore.getShapeObj(asteroidID).getGlobalBounds().intersects(player.ReturnAmmoShape().getGlobalBounds()))
	{
		asteroids[i].SetRemove(true);
		graphicsCore.RemoveGraphic(asteroidID);
		player.SetDeath(1, true);
	}
}

void RemoveAsteriods(vector<Asteroid> &asteroids, int numToRemove)
{
	if (numToRemove == 0)
	{
		return;
	}
	else
	{
		for (int i = 0; i < numToRemove; ++i)
		{
			asteroids.pop_back();
		}
	}
}