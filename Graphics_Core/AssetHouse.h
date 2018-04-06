#include "PQueue.h"
#include <vector>
#include <string>

#pragma once
using namespace std;

class AssetHouse
{
private:
	
	vector<DynamicObject> dynamicObjects;		// Dynamic array of objects that are moveable
	vector<DynamicObject>::iterator dynObjIt;	// Iterator for Dynamic Array
	vector<StaticObject> staticObjects;			// Dynamic array of objects that are not moveable
	vector<StaticObject>::iterator staObjIt;	// Iterator for Static Array
	PQueue graphicsQueue;						// Pqueue holds objects in layers, lower layer numbers are rendered first, with higher numbers rendered over top.

	void LoadStaticAssets(Position, int, int, sf::Color, int);			// Creates a temp StaticObject to be loaded into the staticObjects vector
	void SetDynamicAssets(Position, int, int, sf::Color, int);			// Creates a temp DynamicObject to be loaded into the dynamicObjects vector

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
	*/

	void SetGraphics(float , float , int , int , sf::Color , int , bool);					
	void SetGraphics(Position, int, int, sf::Color, int, bool);
	void SetGraphics(GraphicsData, bool);


	bool Update();						// Primary graphics loop, checks for window close event, calls Render()
	bool Update(sf::RenderWindow &);	// Graphics Loop that accepts window reference. Otherwise identical
	void Render();						// Empties priority queue and calls draw() for each object in queue.
	void Render(sf::RenderWindow &);	// Render loop that accepts window reference. Otherwise Identical

};