#include "Ball.h"

Ball::Ball(sf::RenderWindow* gameWindow) : 
	window(gameWindow),
	rectangle(sf::RectangleShape(sf::Vector2f(15.0f, 15.0f))),
	speed(0.25f),
	acceleration(0.05f),
	direction(Direction(-1, -1))
{
	rectangle.setPosition(window->getSize().x / 2, 0);
}

void Ball::Update(sf::Time deltaTime, Paddle& leftPaddle, Paddle& rightPaddle, Scoreboard& scoreboard)
{
	rectangle.setPosition(rectangle.getPosition() + sf::Vector2f(direction.x, direction.y) 
		* speed * (float)deltaTime.asMilliseconds());

	//If ball hits top or bottom of screen, reverse y direction
	if (rectangle.getPosition().y <= 0 || rectangle.getPosition().y + rectangle.getSize().y >= window->getSize().y)
	{
		direction.y *= -1;
	}
	// If ball hits right wall, increment left score and reset ball
	else if (rectangle.getPosition().x + rectangle.getSize().x >= window->getSize().x)
	{
		scoreboard.IncrementLeftScore();
		scoreboard.GetLastCollision(none);
		rectangle.setPosition(window->getSize().x / 2, 0);
		direction.x = -1;
		direction.y = 1;
		speed = 0.25f;
	}
	//Increment right score and reset ball
	else if (rectangle.getPosition().x <= 0)
	{
		scoreboard.IncrementRightScore();
		scoreboard.GetLastCollision(none);
		rectangle.setPosition(window->getSize().x / 2, 0);
		direction.x = -1;
		direction.y = 1;
		speed = 0.25f;
	}
	//If ball hits right paddle, reverse x direction and increase speed
	else if (CheckRectCollision(rectangle.getGlobalBounds(), rightPaddle.GetGlobalBounds()))
	{
		//Fixes a bug in which the ball would collide multiple times with the paddle, causing it to rapidly increase speed
		if (scoreboard.getLastCollision() != right)
		{
			direction.x *= -1;
			if (speed < maxSpeed) speed += acceleration;
			scoreboard.GetLastCollision(right);

			//If ball hits middle of paddle, ball should move straight (top left of screen is origin)
			if (rectangle.getPosition().y > rightPaddle.getMiddleUpperBoundary()
				&& rectangle.getPosition().y < rightPaddle.getMiddleLowerBoundary())
				direction.y = 0;
			else if (rectangle.getPosition().y < rightPaddle.getMiddleUpperBoundary())
				direction.y = -1;
			else if (rectangle.getPosition().y > rightPaddle.getMiddleLowerBoundary())
				direction.y = 1;


		}
	}
	//Left paddle collision
	else if (CheckRectCollision(rectangle.getGlobalBounds(), leftPaddle.GetGlobalBounds()))
	{
		if (scoreboard.getLastCollision() != left)
		{
			direction.x *= -1;
			if (speed < maxSpeed) speed += acceleration;
			scoreboard.GetLastCollision(left);

			if (rectangle.getPosition().y > leftPaddle.getMiddleUpperBoundary()
				&& rectangle.getPosition().y < leftPaddle.getMiddleLowerBoundary())
				direction.y = 0;
			else if (rectangle.getPosition().y < leftPaddle.getMiddleUpperBoundary())
				direction.y = -1;
			else if (rectangle.getPosition().y > leftPaddle.getMiddleLowerBoundary())
				direction.y = 1;
		}
	}
	
}

void Ball::Draw()
{
	window->draw(rectangle);
}
