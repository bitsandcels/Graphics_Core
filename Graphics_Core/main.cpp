#include <iostream>

#include "AssetHouse.h"

int main()
{
	AssetHouse graphicsCore;
	
	sf::RenderWindow renderWindow(sf::VideoMode(640, 480), "Graphics Core");

	sf::Event event;

	sf::CircleShape circleShape(200);
	circleShape.setFillColor(sf::Color::Blue);

	graphicsCore.SetGraphics(0.0f, 0.0f, 200, 0, sf::Color::Blue, 0, false);

	bool loopState = true;
	while (loopState)
	{
		loopState = graphicsCore.Update(renderWindow);
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