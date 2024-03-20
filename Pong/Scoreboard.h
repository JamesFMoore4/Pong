#pragma once
#include <SFML\Graphics.hpp>
#include <string>
#include <iostream>

class Scoreboard
{
private:

	sf::Font font;
	sf::Text text;
	sf::RenderWindow* window;

	int rightScore;
	int leftScore;

public:

	Scoreboard(sf::RenderWindow* window);
	void Update();
	void Draw();
};

