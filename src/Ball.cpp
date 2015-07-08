#include "Ball.hpp"
#include "Defs.hpp"
#include "Util.hpp"

#include <random>

Ball::Ball()
{
	timer.restart();
	colorize();

	theBall.setRadius( BALL_RAD );
	theBall.setOutlineThickness( 4.f );

	start();

}

void Ball::colorize()
{
	if (timer.getElapsedTime().asSeconds() > 1)
	{
		theBall.setFillColor(getRandomColor());
		theBall.setOutlineColor(getRandomColor());

		timer.restart();
	}
}

sf::CircleShape& Ball::getBall()
{
	return theBall;
}

void Ball::start()
{
	theBall.setPosition( ( SCREEN_W - BALL_RAD ) / 2, ( SCREEN_H - BALL_RAD ) / 2 );
}