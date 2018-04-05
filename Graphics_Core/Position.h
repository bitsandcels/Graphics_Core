#pragma once

class Position
{
public:
	Position();
	Position(float, float);
	Position(const Position&);

	bool SetXYPos(float, float);
	bool SetXPos(float);
	bool SetYPos(float);

	bool TranslatePos(float, float);

	float GetXPos();
	float GetYPos();

	Position& operator = (const Position& other);
private:
	float x;
	float y;
};