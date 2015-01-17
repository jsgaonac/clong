#ifndef _CLONG_GAME_H_
#define _CLONG_GAME_H_

#include <SFML/Graphics.hpp>

#include <string>
#include <vector>

#include "Ball.hpp"

#include "Defs.hpp"

#ifdef DEBUG
#include <iostream>
#endif
			

class Game
{
	//Private
	sf::RenderWindow* gameWindow;

	//Used to Framerate-indepent rendering.
	sf::Clock timeHandler;
	
	/* Game Resources  */
		
	//Background texture
	sf::Texture* backgroundTexture;
	
	//Background sprite
	sf::Sprite backgroundSprite;
	
	//The paddles for player one an two, respectively.
	//I used a rectangle shape instead of a sprite and a texture because is simpler, in my opinion.
	//In case of needing 'fancy graphics', one could set a texture to this shape.
	sf::RectangleShape paddleOne;
	sf::RectangleShape paddleTwo;

	//Self-explained.
	Ball ball;

	unsigned int scorePlayer1;
	unsigned int scorePlayer2;
	
	//The maximum score. When a player reaches this score the game ends.
	unsigned int scoreLimit;
	
	
	//Returns true on success, false otherwise.
	bool initWindow( unsigned int width, unsigned int height, unsigned int bpp, 
		std::string windowTitle );
		
	//Loads al the resources and returns true if everything loaded well. False, otherwise.
	bool loadResources();
	
	//Frees the memory allocated by the resources.
	void cleanupResources();

	//Draw all the things that are meant to be displayed.
	void drawAll();

	//Handle user-input and move paddles.
	void handleInput();

	//Check all the objects are within bounds.
	void checkBounds();

	public:
	
	Game();
	
	int run();
	
		
	virtual ~Game();
	
};
	

#endif // _CLONG_GAME_H_
