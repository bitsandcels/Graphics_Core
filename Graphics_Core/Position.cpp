#include "Position.h"

Position::Position()
{
	x = 0.0f;
	y = 0.0f;
}

Position::Position(float xIn, float yIn)
{
	x = xIn;
	y = yIn;
}

Position::Position(const Position &posIn)
{
	x = posIn.x;
	y = posIn.y;
}


bool Position::SetXYPos(float xIn, float yIn)
{
	x = xIn;
	y = yIn;
	if (x == xIn && y == yIn)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Position::SetXPos(float xIn)
{
	x = xIn;
	if (x == xIn)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Position::SetYPos(float yIn)
{
	y = yIn;
	if (y == yIn)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Position::TranslatePos(float xIn, float yIn)
{
	x += xIn;
	y += yIn;
	return true;
}

float Position::GetXPos()
{
	return x;
}

float Position::GetYPos()
{
	return y;
}

Position & Position::operator=(const Position & other)
{
	Position newPos;
	newPos.x = other.x;
	newPos.y = other.y;

	return newPos;
}
