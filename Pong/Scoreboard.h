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
	sf::Text text;
	sf::RenderWindow* window;
	Collision lastCollision;

	int rightScore;
	int leftScore;

public:

	Scoreboard(sf::RenderWindow* window);
	void incrementRightScore();
	void incrementLeftScore();
	void Update();
	void Draw();
	Collision getLastCollision();
	void setLastCollision(Collision collision);
};

