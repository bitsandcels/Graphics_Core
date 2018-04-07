#include <iostream>
#include "SFML\Graphics.hpp"

int main()
{
	sf::RenderWindow renderWindow(sf::VideoMode(640, 480), "Graphics Core");

	sf::Event event;

	sf::CircleShape circleShape(200);
	circleShape.setFillColor(sf::Color::Red);

	while (renderWindow.isOpen()) 
	{
		while (renderWindow.pollEvent(event)) 
		{
			if (event.type == sf::Event::EventType::Closed)
				renderWindow.close();
		}

		renderWindow.clear();
		renderWindow.draw(circleShape);
		renderWindow.display();
	}

	return 0;
}