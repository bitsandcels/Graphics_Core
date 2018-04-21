#include "AssetHouse.h"
#include "Player.h"

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
	//returns if remove
	bool GetRemove();
	//sets remove
	void SetRemove(bool);

private:
	float xPos;
	float yPos;
	float xTrans;
	float yTrans;
	int size;
	int graphicsCoreIDNum;
	bool Remove;

};

//ID numbers greater than 1000 reserved for asteroids
void GenerateAsteroids(int playerScore, vector<Asteroid> & asteroids, float playerXPos, float playerYPos, AssetHouse & graphicsCore, int & asteroidID);
void UpdateAsteroids(vector<Asteroid> &asteroids, AssetHouse & graphicsCore, Player & player, int& playerScore);
void DetectAsteriodCollision(vector<Asteroid> &asteroids, int i, AssetHouse & graphicsCore, Player & player, int asteroidID, int& playerScore);
void RemoveAsteriods(vector<Asteroid> &asteroids, int numToRemove);