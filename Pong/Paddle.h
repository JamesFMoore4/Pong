#pragma once
#include <SFML\Graphics.hpp>

class Paddle
{

private:

	sf::RenderWindow* window;
	sf::Keyboard::Key upKey;
	sf::Keyboard::Key downKey;

	float speed;

public:

	sf::RectangleShape rectangle;

	Paddle(sf::RenderWindow* gameWindow, 
		sf::Vector2f position, 
		sf::Keyboard::Key ctrlKeyUp, 
		sf::Keyboard::Key ctrlKeyDown);
	void Update(sf::Time deltaTime);
	void Draw();

};

