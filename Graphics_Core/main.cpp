#include <iostream>
//#include "UI.h"
#include "Asteroids.h"
#include <time.h>
#pragma once


int main()
{
	AssetHouse graphicsCore;
	int playerScore = 0;
	int asteroidID = 100;
	srand(time(NULL));
	float playerXPos = GLOBAL_X_WIN_SIZE / 2, playerYPos = GLOBAL_Y_WIN_SIZE / 2;	// Needed for Asteroid code, will need to be updated by player code


	sf::RenderWindow renderWindow(sf::VideoMode(GLOBAL_X_WIN_SIZE, GLOBAL_Y_WIN_SIZE), "Graphics Core");

	sf::Font font;

	sf::Text scoreText;
	scoreText.setFont(font);
	scoreText.setString("Score: ");
	std::string scoreString;

	scoreText.setPosition(GLOBAL_X_WIN_SIZE - 150, 25);

	if (!font.loadFromFile("arial.ttf"))
	{
		std::cout << "FAILED LOADING FILE" << std::endl;
	}


	/*
	Creating the first asteroid
	*/
	vector<Asteroid> asteroidList;
	GenerateAsteroids(playerScore, asteroidList, playerXPos, playerYPos, graphicsCore, asteroidID);


	Player player(playerXPos, playerYPos);

	int loopCount = 0;
	bool loopState = true;
	float newX = 0, newY = 0;	// Temp vars for transforms.
	while (loopState)
	{
		newX = 0;
		newY = 0;

		graphicsCore.Transform(0, 0.0, 0.02, 7, newX, newY, false);		//Rotate shape at 0.02 with index 7


		// Update the Asteroids
		GenerateAsteroids(playerScore, asteroidList, playerXPos, playerYPos, graphicsCore, asteroidID);
		UpdateAsteroids(asteroidList, graphicsCore, player, playerScore);
		player.Update(renderWindow);

		loopCount++;

		loopState = graphicsCore.Update(renderWindow, false);
		player.Render(renderWindow);


		if (player.GetDeath(0)) //if player state is dead bring up game over screen
		{
			sf::Text text;
			text.setFont(font);
			text.setString("GAME OVER");
			text.setPosition(GLOBAL_X_WIN_SIZE / 2, GLOBAL_Y_WIN_SIZE / 2);
			renderWindow.draw(text);
		}

		scoreText.setString("Score: " + std::to_string(playerScore));
		renderWindow.draw(scoreText);
		renderWindow.display();
		renderWindow.clear(sf::Color::Black);
	}

	return 0;
}