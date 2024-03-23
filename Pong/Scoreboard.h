#pragma once
#include <SFML\Graphics.hpp>
#include <string>
#include <iostream>

enum Collision
{
	left, right, none
};

class Scoreboard
{
private:

	sf::Font font;
	sf::Text scoreText;
	sf::Text pauseText;
	sf::Text endText;
	sf::RenderWindow* window;
	Collision lastCollision;

	int rightScore;
	int leftScore;
	bool isRunning;
	bool isOver;

public:

	Scoreboard(sf::RenderWindow* window);
	void IncrementRightScore();
	void IncrementLeftScore();
	void Update();
	void Draw();
	Collision GetLastCollision();
	void SetLastCollision(Collision collision);
	bool IsRunning();
	void SetRunning(bool isRunning);
	bool IsOver();
};

