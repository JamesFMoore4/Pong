#include <SFML\Graphics.hpp>

int main()
{

	sf::RenderWindow window(sf::VideoMode(800, 600), "Pong");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color(0, 77, 153, 255));

		window.display();
	}

	return 0;
}