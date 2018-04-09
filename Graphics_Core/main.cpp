#include <iostream>

#include "AssetHouse.h"
#include "UI.h"

int main()
{
	AssetHouse graphicsCore;


	sf::RenderWindow renderWindow(sf::VideoMode(800, 600), "Graphics Core");

	sf::Font font;

	if (!font.loadFromFile("arial.ttf"))
	{
		std::cout << "FAILED LOADING FILE" << std::endl;
	}

	sf::Text text[6];

	text[0].setFont(font);
	text[0].setString("Change to Red");
	text[0].setPosition(400.0f, 190.0f);

	text[1].setFont(font);
	text[1].setString("Change to Blue");
	text[1].setPosition(400.0f, 350.0f);

	text[2].setFont(font);
	text[2].setString("It Disappeared!");
	text[2].setPosition(15.0f, 425.0f);

	graphicsCore.SetGraphics(0.0f, 0.0f, 200, 4, sf::Color::Magenta, 1, false, 7);
	graphicsCore.SetGraphics(0.0f, 400.0f, 100, 3, sf::Color::White, 0, false, 8);

	const int numButtons = 2;
	Button buttons[numButtons];

	buttons[0] = *new Button(400.0f, 115.0f, 100, graphicsCore, 1, sf::Color::Red);
	buttons[1] = *new Button(400.0f, 275.0f, 100, graphicsCore, 2, sf::Color::Blue);


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

		graphicsCore.Transform(1, 0.02, 0, 7);		//Rotate shape at 0.02 with index 7

		CheckEvent(renderWindow, graphicsCore, buttons, numButtons);

		loopCount++;

		loopState = graphicsCore.Update(renderWindow, false);
		renderWindow.draw(text[0]); //render text above button
		renderWindow.draw(text[1]); //render text above button

		if (loopCount > 1800 && loopCount < 2700)
		{
			renderWindow.draw(text[2]);
		}

		renderWindow.display();
		renderWindow.clear(sf::Color::Black);
	}

	return 0;
}