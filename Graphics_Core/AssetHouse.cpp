#include "AssetHouse.h"

void AssetHouse::LoadStaticAssets(Position pos, int size, int numSides, sf::Color color, int layerNum)
{
	DynamicObject tempObj(pos, size, numSides, color, layerNum);
	dynamicObjects.insert(tempObj);
}

void AssetHouse::SetDynamicAssets(Position pos, int size, int numSides, sf::Color color, int layerNum)
{
	StaticObject tempObj(pos, size, numSides, color, layerNum);
	staticObjects.insert(tempObj);
}

AssetHouse::AssetHouse()
{
	window.create(sf::VideoMode(800, 600), "Graphics_Core");
}

AssetHouse::AssetHouse(int xSize, int ySize, string windowName)
{
	window.create(sf::VideoMode(xSize, ySize), windowName);

}
AssetHouse::~AssetHouse()
{

}


void AssetHouse::OrganizePriorityQueue()
{
	graphicsQueue.MakeEmpty();
	DataStructure * tempData;
	for (int i = 0; i < dynamicObjects.size(); i ++)
	{
		tempData->dObject = dynamicObjects[i];
		//tempData->sObject = NULL;
		tempData->staticObject = false;
		tempData->priority = dynamicObjects[i].GetLayerNum();
		graphicsQueue.Enqueue(tempData);
	}
	for (int i = 0; i < staticObjects.size(); i++)
	{
		tempData->sObject = staticObjects[i];
		//tempData->dObject = NULL;
		tempData->staticObject = true;
		tempData->priority = staticObjects[i].GetLayerNum();
		graphicsQueue.Enqueue(tempData);
	}
}

void AssetHouse::Render()
{
	OrganizePriorityQueue();
	
	while (graphicsQueue.GetLength != 0)
	{
		DataStructure * tempData;
		graphicsQueue.Dequeue(tempData);
		if (tempData->staticObject)
		{
			window.draw(tempData->sObject.Render());
		}
		else
		{
			window.draw(tempData->dObject.Render());
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

void AssetHouse::Update()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		// "close requested event
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
	}
	window.clear(sf::Color::Black);

	Render();

	window.display();
}