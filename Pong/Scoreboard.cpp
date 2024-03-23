#include "Scoreboard.h"

Scoreboard::Scoreboard(sf::RenderWindow* gameWindow) : 
	window(gameWindow), 
	leftScore(0), 
	rightScore(0), 
	lastCollision(none),
	isRunning(true),
	isOver(false)
{
	if (font.loadFromFile("Assets/bit5x3.ttf"))
	{
		scoreText.setFont(font);
		scoreText.setString(std::to_string(leftScore) + "    " + std::to_string(rightScore));
		scoreText.setCharacterSize(64);
		scoreText.setStyle(sf::Text::Bold);
		//Set score position to top of screen
		scoreText.setPosition(window->getSize().x / 2.0f - scoreText.getGlobalBounds().width / 2.0f, 15.0f);

		pauseText.setFont(font);
		pauseText.setString("PAUSED");
		pauseText.setCharacterSize(64);
		pauseText.setStyle(sf::Text::Bold);
		//Pause text position is center of screen
		pauseText.setPosition(window->getSize().x / 2.0f - scoreText.getGlobalBounds().width / 2.0f, 
			window->getSize().y / 2.0f - scoreText.getGlobalBounds().height);

		endText.setFont(font);
		endText.setCharacterSize(64);
		endText.setStyle(sf::Text::Bold);
		endText.setString("PLAYER X WINS!"); //Placeholder text used so that text can be properly centered
		endText.setPosition(window->getSize().x / 2.0f - endText.getGlobalBounds().width / 2.0f,
			window->getSize().y / 2.0f - endText.getGlobalBounds().height);
	}
	else
	{
		std::cout << "Error loading font" << '\n';
		window->close();
	}
}

void Scoreboard::IncrementRightScore()
{
	rightScore++;
}

void Scoreboard::IncrementLeftScore()
{
	leftScore++;
}

void Scoreboard::Update()
{
	scoreText.setString(std::to_string(leftScore) + "    " + std::to_string(rightScore));
	if (leftScore == 13)
	{
		isOver = true;
		endText.setString("PLAYER 1 WINS!");
	}
	else if (rightScore == 13)
	{
		isOver = true;
		endText.setString("PLAYER 2 WINS!");
	}
}

void Scoreboard::Draw()
{
	window->draw(scoreText);
	if (!isRunning) window->draw(pauseText);
	if (isOver) window->draw(endText);
}

Collision Scoreboard::getLastCollision()
{
	return lastCollision;
}

void Scoreboard::GetLastCollision(Collision collision)
{
	lastCollision = collision;
}

bool Scoreboard::IsRunning()
{
	return isRunning;
}

void Scoreboard::SetRunning(bool isRunning)
{
	this->isRunning = isRunning;
}

bool Scoreboard::IsOver()
{
	return isOver;
}


