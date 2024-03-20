#include "Paddle.h"

Paddle::Paddle(sf::RenderWindow* gameWindow, sf::Vector2f position, sf::Keyboard::Key ctrlKeyUp,
	sf::Keyboard::Key ctrlKeyDown) :
	window(gameWindow),
	rectangle(sf::RectangleShape(sf::Vector2f(15.0f, 100.0f))),
	upKey(ctrlKeyUp),
	downKey(ctrlKeyDown),
	speed(2.0f)
{
	rectangle.setPosition(position);
}

void Paddle::Update(sf::Time deltaTime)
{
	if (sf::Keyboard::isKeyPressed(upKey))
		rectangle.setPosition(rectangle.getPosition() + sf::Vector2f(0, -1) * speed * (float)deltaTime.asMilliseconds());

	if (sf::Keyboard::isKeyPressed(downKey))
		rectangle.setPosition(rectangle.getPosition() + sf::Vector2f(0, 1) * speed * (float)deltaTime.asMilliseconds());
}

void Paddle::Draw()
{
	window->draw(rectangle);
}
