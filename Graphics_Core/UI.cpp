#include "UI.h"
#include <iostream>

void CheckEvent(sf::RenderWindow & hwin, AssetHouse & core, Button button[], int numButtons)

{
	sf::Event event;
	int clickedButton = -1;

	//When there is an Event
	while (hwin.pollEvent(event))
	{
		//figure out what type of event there is
		switch (event.type)
		{
			// window closed
		case sf::Event::Closed:
			hwin.close();
			break;

			// key pressed
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape)
			{
				std::cout << "the escape key was pressed" << std::endl;
			}
			else if (event.key.code == sf::Keyboard::A)
			{
				std::cout << "the A key was pressed" << std::endl;
			}
			else if (event.key.code == sf::Keyboard::S)
			{
				std::cout << "the S key was pressed" << std::endl;
			}
			else if (event.key.code == sf::Keyboard::D)
			{
				std::cout << "the D key was pressed" << std::endl;
			}
			else if (event.key.code == sf::Keyboard::W)
			{
				std::cout << "the W key was pressed" << std::endl;
			}
			break;

			//mouse button clicked
		case sf::Event::MouseButtonPressed:
			if (event.mouseButton.button == sf::Mouse::Right)
			{
				std::cout << "the right mouse button was pressed" << std::endl;
				std::cout << "mouse x: " << event.mouseButton.x << std::endl;
				std::cout << "mouse y: " << event.mouseButton.y << std::endl;
			}
			else if (event.mouseButton.button == sf::Mouse::Left)
			{
				for (int i = 0; i < numButtons; ++i)
				{
					int buttonId = button[i].getID();
					if (button[i].getShape(core).getGlobalBounds().contains(hwin.mapPixelToCoords(sf::Mouse::getPosition(hwin))))
					{
						button[i].Click();
						clickedButton = buttonId;
						std::cout << "the left mouse button was pressed" << std::endl;
						std::cout << "mouse x: " << event.mouseButton.x << std::endl;
						std::cout << "mouse y: " << event.mouseButton.y << std::endl;
						break;
					}
				}
				std::cout << "the left mouse button was pressed" << std::endl;
				std::cout << "mouse x: " << event.mouseButton.x << std::endl;
				std::cout << "mouse y: " << event.mouseButton.y << std::endl;
			}
			break;


		default:
			break;
		}
	}

	if (clickedButton != -1)
		std::cout << "BUTTON ID " << clickedButton << " CLICKED" << std::endl;

	//check Button Click
	if (button[0].getClicked())
	{
		core.ChangeColor(sf::Color::Red, 7);
		//std::cout << "BUTTON 1 CLICKED" << std::endl;
	}

	else if (button[1].getClicked())
	{
		core.ChangeColor(sf::Color::Blue, 7);
		//std::cout << "BUTTON 2 CLICKED" << std::endl;
	}

	/*else if (button[2].getClicked())
	{
		std::cout << "BUTTON 3 CLICKED" << std::endl;
	}

	else if (button[3].getClicked())
	{
		std::cout << "BUTTON 4 CLICKED" << std::endl;
	}
	else if (button[4].getClicked())
	{
		std::cout << "BUTTON 5 CLICKED" << std::endl;
	}
	else if (button[5].getClicked())
	{
		std::cout << "BUTTON 6 CLICKED" << std::endl;
	}*/


	for (int i = 0; i < numButtons; ++i) { button[i].UnClick(); } //turn off each button


}
