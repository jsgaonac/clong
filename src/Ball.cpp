#include "Ball.hpp"
#include "mt19937ar.h"
#include "Defs.hpp"

#include <ctime>
#include <cstdint>

Ball::Ball()
{
	//Seeds the PRNG
	init_genrand( time(NULL) );

	colorize();

	theBall.setRadius( BALL_RAD );
	theBall.setOutlineThickness( 4.f );

	start();

}

void Ball::colorize()
{
	theBall.setFillColor( getRandomColor() );
	theBall.setOutlineColor( getRandomColor() );
}

sf::Color Ball::getRandomColor()
{
	uint32_t R = genrand_int32() % 256;
	uint32_t G = genrand_int32() % 256;
	uint32_t B = genrand_int32() % 256;

	return sf::Color( R, G, B );
}

sf::CircleShape& Ball::getBall()
{
	return theBall;
}

void Ball::start()
{
	theBall.setPosition( ( SCREEN_W - BALL_RAD ) / 2, ( SCREEN_H - BALL_RAD ) / 2 );
}