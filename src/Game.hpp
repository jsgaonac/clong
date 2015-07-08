#ifndef _CLONG_GAME_H_
#define _CLONG_GAME_H_

#include <SFML/Graphics.hpp>

#include <string>
#include <vector>
#include <memory>

#include "Ball.hpp"

class Game
{
	//Private
	
	// Errors
	int errors;

	std::unique_ptr<sf::RenderWindow> gameWindow;

	//Used to Framerate-indepent rendering.
	sf::Clock timeHandler;
	
	/* Game Resources  */
		
	//Background texture
	std::unique_ptr<sf::Texture> backgroundTexture;
	
	//Background sprite
	sf::Sprite backgroundSprite;
	
	//The paddles for players one and two, respectively.
	//I used a rectangle shape instead of a sprite and a texture because it's simpler, in my opinion.
	//In case of needing 'fancy graphics', one could set a texture to this shape.
	sf::RectangleShape paddleOne;
	sf::RectangleShape paddleTwo;

	Ball ball;

	unsigned int scorePlayer1;
	unsigned int scorePlayer2;
	
	//The maximum score. When a player reaches this score the game ends.
	unsigned int scoreLimit;
	
	// Loads the textures of the game.
	bool loadResources();

	//Draw all the things that are meant to be displayed.
	void drawAll();

	//Handle user-input and move paddles.
	void handleInput();

	//Check all the objects are within bounds.
	void checkBounds();

	public:
	
	Game(unsigned int width, unsigned int height, unsigned int bpp, std::string windowTitle);
	
	int run();
	
		
	virtual ~Game();
};
	

#endif // _CLONG_GAME_H_
