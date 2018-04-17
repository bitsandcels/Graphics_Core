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
