#include "AssetHouse.h"

void AssetHouse::LoadStaticAssets(Position pos, int size, int numSides, sf::Color color, int layerNum)
{
	StaticObject tempObj(pos, size, numSides, color, layerNum);
	staObjIt = staticObjects.begin();
	staticObjects.insert(staObjIt, tempObj);
}

void AssetHouse::SetDynamicAssets(Position pos, int size, int numSides, sf::Color color, int layerNum)
{
	DynamicObject tempObj(pos, size, numSides, color, layerNum);
	dynObjIt = dynamicObjects.begin();
	dynamicObjects.insert(dynObjIt, tempObj);
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
			sf::CircleShape tempShape(tempData.dObject.Render());
			window.draw(tempShape);
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


void AssetHouse::SetGraphics(float x, float y, int size, int numSides, sf::Color color, int layerNum, bool isStatic)
{
	Position pos(x, y);
	if (isStatic)
	{
		LoadStaticAssets(pos, size, numSides, color, layerNum);
	}
	else
	{
		SetDynamicAssets(pos, size, numSides, color, layerNum);
	}
}

void AssetHouse::SetGraphics(Position pos, int size, int numSides, sf::Color color, int layerNum, bool isStatic)
{
	if (isStatic)
	{
		LoadStaticAssets(pos, size, numSides, color, layerNum);
	}
	else
	{
		SetDynamicAssets(pos, size, numSides, color, layerNum);
	}
}

void AssetHouse::SetGraphics(GraphicsData gData, bool isStatic)
{
	Position pos(gData.GetXPosition(), gData.GetYPosition());
	
	if (isStatic)
	{
		LoadStaticAssets(pos, gData.GetIntSize(), gData.GetNumSides(), gData.GetColor(), gData.GetLayerNum());
	}
	else
	{
		SetDynamicAssets(pos, gData.GetIntSize(), gData.GetNumSides(), gData.GetColor(), gData.GetLayerNum());
	}
}

bool AssetHouse::Update()
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
	window.clear(sf::Color::Black);

	Render();

	window.display();
	return true;
}

bool AssetHouse::Update(sf::RenderWindow & windowRef)
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
	windowRef.clear(sf::Color::Black);

	Render(windowRef);

	windowRef.display();
	return true;
}
