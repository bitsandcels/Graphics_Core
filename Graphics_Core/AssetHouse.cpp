#include "AssetHouse.h"

void AssetHouse::LoadStaticAssets(Position pos, int size, int numSides, sf::Color color, int layerNum, int ID)
{
	StaticObject tempObj(pos, size, numSides, color, layerNum, ID);
	staObjIt = staticObjects.begin();
	staticObjects.insert(staObjIt, tempObj);
}

void AssetHouse::SetDynamicAssets(Position pos, int size, int numSides, sf::Color color, int layerNum, int ID)
{
	DynamicObject tempObj(pos, size, numSides, color, layerNum, ID);
	dynObjIt = dynamicObjects.begin();
	dynamicObjects.insert(dynObjIt, tempObj);
}

void AssetHouse::SetAsteroid(Position pos, int size, int numSides, sf::Color color, int layerNum, int ID)
{
	DynamicObject tempObj(pos, size, numSides, color, layerNum, ID);
	asteroids.push_back(tempObj);
}

AssetHouse::AssetHouse()
{
	window.setSize(sf::Vector2u(640, 480));
	window.setTitle("Graphics Core");
}

AssetHouse::AssetHouse(int xSize, int ySize, string windowName)
{
	window.setSize(sf::Vector2u(xSize, ySize));
	window.setTitle(windowName);

}

AssetHouse::~AssetHouse()
{

}


void AssetHouse::OrganizePriorityQueue()
{
	graphicsQueue.MakeEmpty();
	DataStructure tempData;
	for (int i = 0; i < dynamicObjects.size(); i ++)
	{
		tempData.dObject = dynamicObjects[i];
		//tempData->sObject = NULL;
		tempData.staticObject = false;
		tempData.priority = dynamicObjects[i].GetLayerNum();
		graphicsQueue.Enqueue(tempData);
	}
	for (int i = 0; i < staticObjects.size(); i++)
	{
		tempData.sObject = staticObjects[i];
		//tempData->dObject = NULL;
		tempData.staticObject = true;
		tempData.priority = staticObjects[i].GetLayerNum();
		graphicsQueue.Enqueue(tempData);
	}
	for (int i = 0; i < asteroids.size(); i++)
	{
		tempData.dObject = asteroids[i];
		tempData.staticObject = false;
		tempData.priority = asteroids[i].GetLayerNum();
		graphicsQueue.Enqueue(tempData);
	}
}

void AssetHouse::Render()
{
	OrganizePriorityQueue();
	DataStructure tempData;
	while (graphicsQueue.GetLength() != 0)
	{

		graphicsQueue.Dequeue(tempData);
		if (tempData.staticObject)
		{
			window.draw(tempData.sObject.Render());
		}
		else
		{
			window.draw(tempData.dObject.Render());
		}
	}

}

void AssetHouse::Render(sf::RenderWindow & windowRef)
{
	OrganizePriorityQueue();
	DataStructure tempData;

	while (graphicsQueue.GetLength() != 0)
	{
		graphicsQueue.Dequeue(tempData);
		if (tempData.staticObject)
		{
			windowRef.draw(tempData.sObject.Render());
		}
		else
		{
			windowRef.draw(tempData.dObject.Render());
		}
	}
}

void AssetHouse::ChangePosition(int ID, float X, float Y)
{
	asteroids[ID].ChangePosition(X, Y);
}

sf::CircleShape AssetHouse::getShapeObj(int ID)
{
	for (int i = 0; i < asteroids.size(); i++)
	{
		if (asteroids[i].GetID() == ID)
		{
			return asteroids[i].Render();
		}
	}
	for (int i = 0; i < dynamicObjects.size(); i++)
	{
		if (dynamicObjects[i].GetID() == ID)
		{
			return dynamicObjects[i].Render();
		}
	}
	for (int i = 0; i < staticObjects.size(); i++)
	{
		if (staticObjects[i].GetID() == ID)
		{
			return staticObjects[i].Render();
		}
	}
}


void AssetHouse::SetGraphics(float x, float y, int size, int numSides, sf::Color color, int layerNum, bool isStatic, int ID, bool isAster)
{
	Position pos(x, y);
	if (isAster)
	{
		SetAsteroid(pos, size, numSides, color, layerNum, ID);
	}
	else if (isStatic)
	{
		LoadStaticAssets(pos, size, numSides, color, layerNum, ID);
	}
	else
	{
		SetDynamicAssets(pos, size, numSides, color, layerNum, ID);
	}
}

void AssetHouse::SetGraphics(Position pos, int size, int numSides, sf::Color color, int layerNum, bool isStatic, int ID, bool isAster)
{
	if (isAster)
	{
		SetAsteroid(pos, size, numSides, color, layerNum, ID);
	}
	else if (isStatic)
	{
		LoadStaticAssets(pos, size, numSides, color, layerNum, ID);
	}
	else
	{
		SetDynamicAssets(pos, size, numSides, color, layerNum, ID);
	}
}

void AssetHouse::SetGraphics(GraphicsData gData, bool isStatic, int ID, bool isAster)
{
	Position pos(gData.GetXPosition(), gData.GetYPosition());
	
	if (isAster)
	{
		SetAsteroid(pos, gData.GetIntSize(), gData.GetNumSides(), gData.GetColor(), gData.GetLayerNum(), ID);
	}
	else if (isStatic)
	{
		LoadStaticAssets(pos, gData.GetIntSize(), gData.GetNumSides(), gData.GetColor(), gData.GetLayerNum(), ID);
	}
	else
	{
		SetDynamicAssets(pos, gData.GetIntSize(), gData.GetNumSides(), gData.GetColor(), gData.GetLayerNum(), ID);
	}
}

void AssetHouse::Transform(int transformType, float X, float Y, int ID, float & newX, float & newY, bool isAster)
{
	if (isAster)
	{
		asteroids[ID].Transform(transformType, X, Y, newX, newY);
	}
	else
	{
		for (int i = 0; i < dynamicObjects.size(); i++)
		{
			if (dynamicObjects[i].GetID() == ID)
			{
				dynamicObjects[i].Transform(transformType, X, Y, newX, newY);
			}
		}
	}
}

void AssetHouse::RemoveGraphic(int ID)
{
	int size = 0;
	int place;
	bool didRemoveElement = false;

	size = asteroids.size();
	if (size == 0)
	{
		return;
	}

	for (int i = 0; i < size; i++)
	{
		if (asteroids[i].GetID() == ID)
		{
			place = i;
			didRemoveElement = true;
			i = size;
		}
	}

	if (didRemoveElement)
	{
		std::swap(asteroids[place], asteroids.back());
		asteroids.pop_back();
		didRemoveElement = false;
	}
	

	size = dynamicObjects.size();
	for (int i = 0; i < size; i++)
	{
		if (dynamicObjects[i].GetID() == ID)
		{
			place = i;
			didRemoveElement = true;
			i = size;
		}
	}
	if (didRemoveElement)
	{
		std::swap(dynamicObjects[place], dynamicObjects.back());
		dynamicObjects.pop_back();
		didRemoveElement = false;
	}

	size = staticObjects.size();
	for (int i = 0; i < size; i++)
	{
		if (staticObjects[i].GetID() == ID)
		{
			place = i;
			didRemoveElement = true;
			i = size;
		}
	}
	if (didRemoveElement)
	{
		std::swap(staticObjects[place], staticObjects.back());
		staticObjects.pop_back();
		didRemoveElement = false;
	}

}

void AssetHouse::ChangeColor(sf::Color newColor, int ID)
{
	for (int i = 0; i < dynamicObjects.size(); i++)
	{
		if (dynamicObjects[i].GetID() == ID)
		{
			dynamicObjects[i].SetColor(newColor);
			i = dynamicObjects.size();
		}
	}
	for (int i = 0; i < staticObjects.size(); i++)
	{
		if (staticObjects[i].GetID() == ID)
		{
			staticObjects[i].SetColor(newColor);
			i = staticObjects.size();
		}
	}
}

bool AssetHouse::Update(bool clearAndDisplayWnd)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		// "close requested event
		if (event.type == sf::Event::Closed)
		{
			window.close();
			return false;
		}
	}
	if(clearAndDisplayWnd == true)
		window.clear(sf::Color::Black);

	Render();

	if (clearAndDisplayWnd == true)
		window.display();
	return true;
}

bool AssetHouse::Update(sf::RenderWindow & windowRef, bool clearAndDisplayWnd)
{
	sf::Event event;
	while (windowRef.pollEvent(event))
	{
		// "close requested event
		if (event.type == sf::Event::Closed)
		{
			windowRef.close();
			return false;
		}
	}
	if (clearAndDisplayWnd == true)
		windowRef.clear(sf::Color::Black);

	Render(windowRef);

	if (clearAndDisplayWnd == true)
		windowRef.display();
	return true;
}