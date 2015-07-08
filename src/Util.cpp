#include "Util.hpp"

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> dis(0, 255);

sf::Color getRandomColor()
{
	int R = dis(gen);
	int G = dis(gen);
	int B = dis(gen);

	return sf::Color( R, G, B );
}

