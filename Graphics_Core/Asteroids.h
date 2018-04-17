#include "AssetHouse.h"

class Asteroid
{
public:
	Asteroid(float&, float&, int); // takes the players current position to set motion towards that direction.
	~Asteroid();

	// Sets the new position of the asteroid after movement has been performed
	void UpdatePos(float, float);
	// Returns the asteroids position
	void GetPos(float&, float&);
	// returns the transformation information for movement.
	void GetTransform(float&, float&);
	// returns the size of the asteroid
	int GetSize();
	// returns the ID number
	int GetID();

private:
	float xPos;
	float yPos;
	float xTrans;
	float yTrans;
	int size;
	int graphicsCoreIDNum;

};

