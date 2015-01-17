#ifndef _CLONG_BALL_H_
#define _CLONG_BALL_H_

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Ball
{
	//Private

	//Self-explained.
	sf::CircleShape theBall;

	sf::Vector2f velocity;

	float getVelMagnitude();

public:

	Ball();

	//Sets a random color for the ball.
	void colorize();

	//Make the ball start its movement. It may be used to reset the ball.
	void start();

	sf::Color getRandomColor();

	sf::CircleShape& getBall();

};

#endif //_CLONG_BALL_H_
