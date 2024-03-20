#include "Ball.h"

Ball::Ball(sf::RenderWindow* gameWindow) : 
	window(gameWindow),
	rectangle(sf::RectangleShape(sf::Vector2f(15.0f, 15.0f))),
	speed(0.25f),
	acceleration(0.25f),
	direction(Direction(-1, 1))
{
	rectangle.setPosition(392.5f, 292.5f);
}

void Ball::Update(sf::Time deltaTime, Paddle& leftPaddle, Paddle& rightPaddle)
{
	rectangle.setPosition(rectangle.getPosition() + sf::Vector2f(direction.x, direction.y) 
		* speed * (float)deltaTime.asMilliseconds());

	//If ball hits top or bottom of screen, reverse y direction
	if (rectangle.getPosition().y <= 0 || rectangle.getPosition().y + rectangle.getSize().y >= window->getSize().y)
	{
		direction.y *= -1;
	}
	// If ball hits left or right wall, reset ball
	else if (rectangle.getPosition().x <= 0 || rectangle.getPosition().x + rectangle.getSize().x >= window->getSize().x)
	{
		rectangle.setPosition(392.5f, 292.5f);
		direction.x = -1;
		direction.y = 1;
		speed = 0.25f;
	}
	//If ball hits left or right paddle, reverse x direction
	else if (CheckRectCollision(rectangle.getGlobalBounds(), leftPaddle.rectangle.getGlobalBounds())
		|| CheckRectCollision(rectangle.getGlobalBounds(), rightPaddle.rectangle.getGlobalBounds()))
	{
		direction.x *= -1;
	}
	
}

void Ball::Draw()
{
	window->draw(rectangle);
}
