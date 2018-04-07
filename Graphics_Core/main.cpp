#include <iostream>

#include "AssetHouse.h"

int main()
{
	AssetHouse graphicsCore;
	
	sf::RenderWindow renderWindow(sf::VideoMode(640, 480), "Graphics Core");

	//sf::Event event;

	//sf::CircleShape circleShape(200);
	//circleShape.setFillColor(sf::Color::Blue);

	graphicsCore.SetGraphics(0.0f, 0.0f, 200, 4, sf::Color::Blue, 1, false, 1);
	graphicsCore.SetGraphics(0.0f, 0.0f, 100, 3, sf::Color::Red, 0, false, 2);

	int loopCount = 0;
	bool loopState = true;
	while (loopState)
	{
		loopState = graphicsCore.Update(renderWindow);

		if (loopCount == 900)
		{
			graphicsCore.ChangeColor(sf::Color::Green, 1);
		}

		if (loopCount == 1800)
		{
			graphicsCore.RemoveGraphic(2);
		}
		graphicsCore.Transform(1, 0.002, 0, 1);
		
		loopCount++;
	}

	/*while (graphicsCore.window.isOpen()) 
	{
		while (graphicsCore.window.pollEvent(event))
		{
			if (event.type == sf::Event::EventType::Closed)
				graphicsCore.window.close();
		}

		graphicsCore.window.clear();
		graphicsCore.window.draw(circleShape);
		graphicsCore.window.display();
	}*/

	return 0;
}