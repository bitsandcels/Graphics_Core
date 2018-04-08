#include <iostream>

#include "AssetHouse.h"
#include "UI.h"

int main()
{
	AssetHouse graphicsCore;


	sf::RenderWindow renderWindow(sf::VideoMode(800, 600), "Graphics Core");

	sf::Font font;

	if (!font.loadFromFile("sansation.ttf"))
	{
		std::cout << "FAILED LOADING FILE" << std::endl;
	}

	sf::Text text[6];

	text[0].setFont(font);
	text[0].setString("Start Game");
	text[0].setPosition(325.0f, 125.0f);

	text[1].setFont(font);
	text[1].setString("Quit");
	text[1].setPosition(375.0f, 325.0f);

	//sf::Event event;
	//sf::CircleShape circleShape(200);
	//circleShape.setFillColor(sf::Color::Blue);

	graphicsCore.SetGraphics(0.0f, 0.0f, 200, 4, sf::Color::Blue, 1, false, 7);
	graphicsCore.SetGraphics(0.0f, 0.0f, 100, 3, sf::Color::Red, 0, false, 8);

	const int numButtons = 2;
	Button buttons[numButtons];

	buttons[0] = *new Button(400.0f, 25.0f, 100, graphicsCore, 1, sf::Color::Red);
	buttons[1] = *new Button(400.0f, 200.0f, 100, graphicsCore, 2, sf::Color::Blue);
	//buttons[2] = *new Button(400.0f, 175.0f, 50, graphicsCore, 3, sf::Color::Yellow);
	//buttons[3] = *new Button(400.0f, 275.0f, 50, graphicsCore, 4, sf::Color::Cyan);
	//buttons[4] = *new Button(400.0f, 400.0f, 50, graphicsCore, 5, sf::Color::Green);
	//buttons[5] = *new Button(400.0f, 500.0f, 50, graphicsCore, 6, sf::Color::Magenta);




	int loopCount = 0;
	bool loopState = true;
	while (loopState)
	{
		if (loopCount == 900)
		{
			graphicsCore.ChangeColor(sf::Color::Green, 7);
		}

		if (loopCount == 1800)
		{
			graphicsCore.RemoveGraphic(8);
		}

		graphicsCore.Transform(1, 0.002, 0, 7);

		CheckEvent(renderWindow, graphicsCore, buttons, numButtons);

		loopCount++;

		loopState = graphicsCore.Update(renderWindow, false);
		renderWindow.draw(text[0]); //render text above button
		renderWindow.draw(text[1]); //render text above button
		renderWindow.display();
		renderWindow.clear(sf::Color::Black);
	}

	/*
	while (graphicsCore.window.isOpen())
	{
	while (graphicsCore.window.pollEvent(event))
	{
	if (event.type == sf::Event::EventType::Closed)
	graphicsCore.window.close();
	}

	graphicsCore.window.clear();
	graphicsCore.window.draw(circleShape);
	graphicsCore.window.display();
	}
	*/

	return 0;
}