#include <iostream>
#include "UI.h"
#include "Asteroids.h"
#include <time.h>
#pragma once


int main()
{
	AssetHouse graphicsCore;
	int playerScore = 0;
	int asteroidID = 100;
	srand(time(NULL));
	float playerXPos = GLOBAL_X_WIN_SIZE/2, playerYPos = GLOBAL_Y_WIN_SIZE /2;	// Needed for Asteroid code, will need to be updated by player code


	sf::RenderWindow renderWindow(sf::VideoMode(GLOBAL_X_WIN_SIZE, GLOBAL_Y_WIN_SIZE), "Graphics Core");

	sf::Font font;

	if (!font.loadFromFile("arial.ttf"))
	{
		std::cout << "FAILED LOADING FILE" << std::endl;
	}

	/*sf::Text text[6];

	text[0].setFont(font);
	text[0].setString("Change to Red");
	text[0].setPosition(400.0f, 190.0f);

	text[1].setFont(font);
	text[1].setString("Change to Blue");
	text[1].setPosition(400.0f, 350.0f);

	text[2].setFont(font);
	text[2].setString("It Disappeared!");
	text[2].setPosition(15.0f, 425.0f);

	graphicsCore.SetGraphics(0.0f, 0.0f, 40, 4, sf::Color::Magenta, 1, false, 7, false);
	graphicsCore.SetGraphics(0.0f, 400.0f, 50, 3, sf::Color::White, 0, false, 8, false);*/

	
	
	/*
	Creating the first asteroid
	*/
	vector<Asteroid> asteroidList;
	GenerateAsteroids(playerScore, asteroidList, playerXPos, playerYPos, graphicsCore, asteroidID);

	//const int numButtons = 2;
	//Button buttons[numButtons];

	//buttons[0] = *new Button(400.0f, 115.0f, 100, graphicsCore, 1, sf::Color::Red);
	//buttons[1] = *new Button(400.0f, 275.0f, 100, graphicsCore, 2, sf::Color::Blue);

	Player player(playerXPos, playerYPos);

	int loopCount = 0;
	bool loopState = true;
	float newX = 0, newY = 0;	// Temp vars for transforms.
	while (loopState)
	{
		newX = 0;
		newY = 0;
		
		/*if (loopCount == 900)
		{
			graphicsCore.ChangeColor(sf::Color::Green, 7);
		}

		if (loopCount == 1800)
		{
			graphicsCore.RemoveGraphic(8);
		}*/
		
		graphicsCore.Transform(0, 0.0, 0.02, 7, newX, newY, false);		//Rotate shape at 0.02 with index 7

		
		// Update the Asteroids
		GenerateAsteroids(playerScore, asteroidList, playerXPos, playerYPos, graphicsCore, asteroidID);
		UpdateAsteroids(asteroidList, graphicsCore, player);
		
		//CheckEvent(renderWindow, graphicsCore, buttons, numButtons);

		loopCount++;

		loopState = graphicsCore.Update(renderWindow, false);
		player.Render(renderWindow);
		//renderWindow.draw(text[0]); //render text above button
		//renderWindow.draw(text[1]); //render text above button
		
		

		if (loopCount > 1200)
		{
			playerScore = 50;
		}

		renderWindow.display();
		renderWindow.clear(sf::Color::Black);
	}

	return 0;
}