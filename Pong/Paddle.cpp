#include "Paddle.h"

Paddle::Paddle(sf::RenderWindow* gameWindow, sf::Vector2f position, sf::Keyboard::Key ctrlKeyUp,
	sf::Keyboard::Key ctrlKeyDown) :
	window(gameWindow),
	rectangle(sf::RectangleShape(sf::Vector2f(15.0f, 100.0f))),
	upKey(ctrlKeyUp),
	downKey(ctrlKeyDown),
	speed(1.0f),
	middleUpperBoundary(position.y + 100.0f * (2.0f / 5.0f)),
	middleLowerBoundary(position.y + 100.0f * (3.0f / 5.0f)),
	isRunning(true)
{
	rectangle.setPosition(position);
}

void Paddle::Update(sf::Time deltaTime)
{
	if (sf::Keyboard::isKeyPressed(upKey) && rectangle.getPosition().y >= 0)
	{
		rectangle.setPosition(rectangle.getPosition() + sf::Vector2f(0, -1) * speed * (float)deltaTime.asMilliseconds());
		middleUpperBoundary = rectangle.getPosition().y + 100.0f * (2.0f / 5.0f);
		middleLowerBoundary = rectangle.getPosition().y + 100.0f * (3.0f / 5.0f);
	}

	if (sf::Keyboard::isKeyPressed(downKey)
		&& rectangle.getPosition().y + rectangle.getSize().y <= window->getSize().y)
	{
		rectangle.setPosition(rectangle.getPosition() + sf::Vector2f(0, 1) * speed * (float)deltaTime.asMilliseconds());
		middleUpperBoundary = rectangle.getPosition().y + 100.0f * (2.0f / 5.0f);
		middleLowerBoundary = rectangle.getPosition().y + 100.0f * (3.0f / 5.0f);
	}
}

void Paddle::Draw()
{
	window->draw(rectangle);
}

sf::FloatRect Paddle::GetGlobalBounds()
{
	return rectangle.getGlobalBounds();
}

float Paddle::getMiddleUpperBoundary()
{
	return middleUpperBoundary;
}

float Paddle::getMiddleLowerBoundary()
{
	return middleLowerBoundary;
}
