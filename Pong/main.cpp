#include <SFML\Graphics.hpp>

#include "Paddle.h"
#include "Ball.h"
#include "Scoreboard.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Pong");
	window.setVerticalSyncEnabled(true);

	Paddle leftPaddle(&window, sf::Vector2f(50.0f, 250.0f), sf::Keyboard::W, sf::Keyboard::S);
	Paddle rightPaddle(&window, sf::Vector2f(735.0f, 250.0f), sf::Keyboard::I, sf::Keyboard::K);
	Ball ball(&window);
	Scoreboard scoreboard(&window);

	sf::Clock clock;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		sf::Time deltaTime = clock.restart();

		leftPaddle.Update(deltaTime);
		rightPaddle.Update(deltaTime);
		ball.Update(deltaTime, leftPaddle, rightPaddle, scoreboard);
		scoreboard.Update();

		window.clear(sf::Color(0, 77, 153, 255));

		scoreboard.Draw();
		leftPaddle.Draw();
		rightPaddle.Draw();
		ball.Draw();

		window.display();
	}

	return 0;
}