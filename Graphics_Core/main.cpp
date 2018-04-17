#include <iostream>

#include "AssetHouse.h"
#include "UI.h"
#include "Asteroids.h"
#include <time.h>
#pragma once



//ID numbers greater than 1000 reserved for asteroids

void GenerateAsteroids(int playerScore, vector<Asteroid> & asteroids, float playerXPos, float playerYPos, AssetHouse & graphicsCore, int & asteroidID);
void UpdateAsteroids(vector<Asteroid> &asteroids, AssetHouse & graphicsCore);

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

	graphicsCore.SetGraphics(0.0f, 0.0f, 40, 4, sf::Color::Magenta, 1, false, 7, false);
	graphicsCore.SetGraphics(0.0f, 400.0f, 50, 3, sf::Color::White, 0, false, 8, false);

	
	
	/*
	Creating the first asteroid
	*/
	vector<Asteroid> asteroidList;
	GenerateAsteroids(playerScore, asteroidList, playerXPos, playerYPos, graphicsCore, asteroidID);

	const int numButtons = 2;
	Button buttons[numButtons];

	buttons[0] = *new Button(400.0f, 115.0f, 100, graphicsCore, 1, sf::Color::Red);
	buttons[1] = *new Button(400.0f, 275.0f, 100, graphicsCore, 2, sf::Color::Blue);


	int loopCount = 0;
	bool loopState = true;
	float newX = 0, newY = 0;	// Temp vars for transforms.
	while (loopState)
	{
		newX = 0;
		newY = 0;
		
		if (loopCount == 900)
		{
			graphicsCore.ChangeColor(sf::Color::Green, 7);
		}

		if (loopCount == 1800)
		{
			graphicsCore.RemoveGraphic(8);
		}
		
		graphicsCore.Transform(0, 0.0, 0.02, 7, newX, newY);		//Rotate shape at 0.02 with index 7

		
		// Update the Asteroids
		GenerateAsteroids(playerScore, asteroidList, playerXPos, playerYPos, graphicsCore, asteroidID);
		UpdateAsteroids(asteroidList, graphicsCore);
		
		
		CheckEvent(renderWindow, graphicsCore, buttons, numButtons);

		loopCount++;

		loopState = graphicsCore.Update(renderWindow, false);
		renderWindow.draw(text[0]); //render text above button
		renderWindow.draw(text[1]); //render text above button

		if (loopCount > 1800 && loopCount < 2700)
		{
			renderWindow.draw(text[2]);
		}
		
		if (loopCount > 1200)
		{
			playerScore = 50;
		}

		renderWindow.display();
		renderWindow.clear(sf::Color::Black);
	}

	return 0;
}

void GenerateAsteroids(int playerScore, vector<Asteroid> & asteroids, float playerXPos, float playerYPos, AssetHouse & graphicsCore, int & asteroidID)
{
	float tempX = 0, tempY = 0;
	if (playerScore == 0 && asteroids.size() == 0)
	{
		Asteroid newAsteroid(playerXPos, playerYPos, asteroidID);
		newAsteroid.GetPos(tempX, tempY);
		graphicsCore.SetGraphics(tempX, tempY, newAsteroid.GetSize(), 4, sf::Color::White, 3, false, asteroidID, true);
		asteroidID++;
		asteroids.push_back(newAsteroid);
	}
	if (((playerScore + 10) / 10) > asteroids.size())
	{
		Asteroid newAsteroid(playerXPos, playerYPos, asteroidID);
		newAsteroid.GetPos(tempX, tempY);
		graphicsCore.SetGraphics(tempX, tempY, newAsteroid.GetSize(), 4, sf::Color::White, 3, false, asteroidID, true);
		asteroidID++;
		asteroids.push_back(newAsteroid);
	}
}

void UpdateAsteroids(vector<Asteroid> &asteroids, AssetHouse & graphicsCore)
{
	float tempXPos = 0, tempYPos = 0, newX = 0, newY = 0;
	int asteroidID = 0;
	for (int i = 0; i < asteroids.size(); i++)
	{
		asteroids[i].GetTransform(newX, newY);
		asteroidID = asteroids[i].GetID();
		graphicsCore.Transform(0, newX, newY, asteroidID, tempXPos, tempYPos);
		asteroids[i].UpdatePos(tempXPos, tempYPos);

		if (tempXPos > GLOBAL_X_WIN_SIZE)
		{
			graphicsCore.ChangePosition(asteroidID, 1, tempYPos);
			asteroids[i].UpdatePos(1, tempYPos);
		}
		else if (tempXPos < 0)
		{
			graphicsCore.ChangePosition(asteroidID, GLOBAL_X_WIN_SIZE - 1, tempYPos);
			asteroids[i].UpdatePos(GLOBAL_X_WIN_SIZE - 1, tempYPos);
		}
		else if (tempYPos > GLOBAL_Y_WIN_SIZE)
		{
			graphicsCore.ChangePosition(asteroidID, tempXPos, 1);
			asteroids[i].UpdatePos(tempXPos, 1);
		}
		else if (tempYPos < 0)
		{
			graphicsCore.ChangePosition(asteroidID, tempXPos, GLOBAL_Y_WIN_SIZE - 1);
			asteroids[i].UpdatePos(tempXPos, GLOBAL_Y_WIN_SIZE - 1);
		}
	}
	
}