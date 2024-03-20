#include "Scoreboard.h"

Scoreboard::Scoreboard(sf::RenderWindow* gameWindow) : window(gameWindow), leftScore(0), rightScore(0)
{
	if (font.loadFromFile("Assets/bit5x3.ttf"))
	{
		text.setFont(font);
		text.setString(std::to_string(leftScore) + "    " + std::to_string(rightScore));
		text.setCharacterSize(64);
		text.setStyle(sf::Text::Bold);
		text.setPosition(window->getSize().x / 2.0f - text.getGlobalBounds().width / 2.0f, 15.0f);
	}
	else
	{
		std::cout << "Error loading font" << '\n';
		window->close();
	}
}

void Scoreboard::Update()
{
}

void Scoreboard::Draw()
{
	window->draw(text);
}
