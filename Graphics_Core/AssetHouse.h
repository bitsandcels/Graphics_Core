#include "PQueue.h"
#include <vector>
#include <string>

const int GLOBAL_X_WIN_SIZE = 1200;
const int GLOBAL_Y_WIN_SIZE = 800;

#pragma once
using namespace std;

class AssetHouse
{
private:
	
	vector<DynamicObject> dynamicObjects;			// Dynamic array of objects that are moveable
	vector<DynamicObject>::iterator dynObjIt;		// Iterator for Dynamic Array
	vector<DynamicObject> asteroids;				// Dynamic array of Asteroids
	vector<DynamicObject>::iterator asteroidsIt;	// Iterator for Asteroids
	vector<StaticObject> staticObjects;				// Dynamic array of objects that are not moveable
	vector<StaticObject>::iterator staObjIt;		// Iterator for Static Array
	PQueue graphicsQueue;							// Pqueue holds objects in layers, lower layer numbers are rendered first, with higher numbers rendered over top.

	void LoadStaticAssets(Position, int, int, sf::Color, int, int);			// Creates a temp StaticObject to be loaded into the staticObjects vector
	void SetDynamicAssets(Position, int, int, sf::Color, int, int);			// Creates a temp DynamicObject to be loaded into the dynamicObjects vector
	void SetAsteroid(Position, int, int, sf::Color, int, int);				// Creates a temp DynamicObject to be loaded into the asteroids vector

	sf::RenderWindow window;

public:
	AssetHouse();						// Default constructor
	AssetHouse(int, int, string);		// Constructor that accepts parameters for window X size, window Y size, and window title
	~AssetHouse();						// default destructor

	

	void OrganizePriorityQueue();		// Fills priority queue with all dynamic and static objects
	
	/*
	Processes the adding of pre-defined objects into the rendering loop

	Shapes can be defined as either
	1) float x, float y, int size, int numSides, sf::Color color, int layerNum, bool isStatic
	2) Position pos, int size, int numSides, sf::Color color, int layerNum, bool isStatic
	3) GraphicsData gData, bool isStatic

	2 is the prefered format as it involves the least data conversion operations inside the AssetHouse code.

	-	@param pos : Set the Position of the shape
		-	Use Position variable or Position(X, Y)
		-	ALT TO POS
			- @param x : X position
			- @param y : Y position
	-	@param size : Set the Size of the shape
	-	@param numSides : Set number of sides
		-	Use 0 for circle and anything greater than
			3 for other shapes
	-	@param color : Set color of shape
		-	Use sf::Color(r, g, b) or sf::Color::COLORNAME
	-	@param layerNum : sset the layer number
		-	The lower numbers will be rendered first (bottom layer)
	-	@param isAster : is the object an asteroid
		-	if true, use asteroid array, if false, use other checks.
	*/

	void SetGraphics(float , float , int , int , sf::Color , int , bool, int, bool);					
	void SetGraphics(Position, int, int, sf::Color, int, bool, int, bool);
	void SetGraphics(GraphicsData, bool, int, bool);


	/*
	Update translates member Visual using:
	-	@param TrasnformType : Transform Shape
	-	0 = MOVE
	-	1 = ROTATE
	-	2 = SCALE
	-	@param X : Set X Value (by how much to move/scale along X-Axis)
	-	Use X also as angle to rotate shape
	-	@param Y : Set Y Value (by how much to move/scale along Y-Axis)
	-	When rotating, use 0 for Y
	*/
	void Transform(int transformType, float X, float Y, int ID, float & newX, float & newY, bool isAster);

	void RemoveGraphic(int);			// Used to remove an object from the graphics loop
	void ChangeColor(sf::Color, int);	// Used to change the color of an object

	bool Update(bool clearAndDisplayWnd = true);						// Primary graphics loop, checks for window close event, calls Render()
	bool Update(sf::RenderWindow &, bool clearAndDisplayWnd = true);	// Graphics Loop that accepts window reference. Otherwise identical
	void Render();						// Empties priority queue and calls draw() for each object in queue.
	void Render(sf::RenderWindow &);	// Render loop that accepts window reference. Otherwise Identical

	void ChangePosition(int ID, float X, float Y);	// Change the absolute position of an object

	sf::CircleShape getShapeObj(int ID);
};