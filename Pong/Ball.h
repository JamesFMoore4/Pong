#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

#include "Direction.h"
#include "Math.h"
#include "Paddle.h"
#include "Scoreboard.h"

class Ball
{
private:

	sf::RenderWindow* window;
	sf::RectangleShape rectangle;
	sf::SoundBuffer wallImpactBuffer;
	sf::SoundBuffer paddleImpactBuffer;
	sf::Sound wallImpactSound;
	sf::Sound paddleImpactSound;
	
	float speed;
	float acceleration;
	const float maxSpeed = 1.0f;

	Direction direction;

public:

	Ball(sf::RenderWindow* gameWindow);
	void Update(sf::Time deltaTime, Paddle& leftPaddle, Paddle& rightPaddle, Scoreboard& scoreboard);
	void Draw();
};

