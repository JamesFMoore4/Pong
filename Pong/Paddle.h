#pragma once
#include <SFML\Graphics.hpp>

class Paddle
{

private:

	sf::RenderWindow* window;
	sf::Keyboard::Key upKey;
	sf::Keyboard::Key downKey;
	sf::RectangleShape rectangle;

	float speed;
	float middleUpperBoundary;
	float middleLowerBoundary;
	bool isRunning;

public:

	Paddle(sf::RenderWindow* gameWindow, 
		sf::Vector2f position, 
		sf::Keyboard::Key ctrlKeyUp, 
		sf::Keyboard::Key ctrlKeyDown);
	void Update(sf::Time deltaTime);
	void Draw();
	sf::FloatRect GetGlobalBounds();
	float getMiddleUpperBoundary();
	float getMiddleLowerBoundary();

};

