#include "Game.hpp"
#include "Defs.hpp"

#ifdef DEBUG
#include <iostream>
#endif

Game::Game(unsigned int width, unsigned int height, unsigned int bpp, std::string windowTitle) :
	gameWindow(new sf::RenderWindow( sf::VideoMode( width, height, bpp ), windowTitle )),
	backgroundTexture(new sf::Texture())
{
	errors = ERR_NONE;

	if( gameWindow == nullptr )
	{
		errors = ERR_CANT_INIT_WIND0W;
		#ifdef DEBUG
		std::cout << "[Couldn't open a window.]" << std::endl;
		#endif
	}

}

bool Game::loadResources()
{
	bool success = true;
	
	if( !backgroundTexture->loadFromFile( "../resources/Background.png" ) )
	{
		#ifdef DEBUG
		std::cout << ":-->[Couldn't load background texture.]" << std::endl;
		#endif
		
		success = false;
	} 
	
	backgroundSprite.setTexture( *backgroundTexture );

	paddleOne.setSize( sf::Vector2f( PADDLE_W, PADDLE_H ) );
	paddleTwo.setSize( sf::Vector2f( PADDLE_W, PADDLE_H ) );

	paddleOne.setFillColor( sf::Color( 255, 102, 51) );
	paddleTwo.setFillColor( sf::Color( 245, 184, 0 ) );

	paddleOne.setPosition( PADDING, ( SCREEN_H  -  PADDLE_H )/ 2 );
	paddleTwo.setPosition( SCREEN_W - PADDLE_W - PADDING, ( SCREEN_H  -  PADDLE_H )/ 2 );

	return success;
}

int Game::run()
{
	// Checks at start that a window was constructed.
	if (errors == ERR_CANT_INIT_WIND0W)
	{
		return -1;
	}

	if (!loadResources())
	{
		return -2;
	}
	
	timeHandler.restart();
	sf::Event event;
	
	//Game loop
	while( gameWindow->isOpen() )
    {    	
        while( gameWindow->pollEvent(event) )
        {
			if(event.type == sf::Event::Closed) gameWindow->close();
        }

        ball.colorize();

        //Checks if the players want their paddles to move.
		handleInput();

        timeHandler.restart();

        if( sf::Keyboard::isKeyPressed( sf::Keyboard::C ) ) ball.colorize();

        //Checks if paddles and ball are within boundaries.
        checkBounds();

        // Clear the window with black
        gameWindow->clear( sf::Color::Black );

        drawAll();
        
        //Show the stuff blitted into the screen
        gameWindow->display();
    }
    
    return 0;    
}

void Game::drawAll()
{
	gameWindow->draw( backgroundSprite );
	gameWindow->draw( paddleOne );
	gameWindow->draw( paddleTwo );
	gameWindow->draw( ball.getBall() );
}

void Game::handleInput()
{
	float elapsedTime = timeHandler.getElapsedTime().asSeconds();

	if( sf::Keyboard::isKeyPressed( sf::Keyboard::W ) )
	{
		paddleOne.setPosition( paddleOne.getPosition().x,
			paddleOne.getPosition().y + -1.f * PADDLE_MOV * elapsedTime );
	}
	if( sf::Keyboard::isKeyPressed( sf::Keyboard::S ) )
	{
		paddleOne.setPosition( paddleOne.getPosition().x, 
			paddleOne.getPosition().y + PADDLE_MOV * elapsedTime );
	}

	if( sf::Keyboard::isKeyPressed( sf::Keyboard::Up ) )
	{
		paddleTwo.setPosition( paddleTwo.getPosition().x,
			paddleTwo.getPosition().y + -1.f * PADDLE_MOV * elapsedTime );
	}
	if( sf::Keyboard::isKeyPressed( sf::Keyboard::Down ) )
	{
		paddleTwo.setPosition( paddleTwo.getPosition().x, 
			paddleTwo.getPosition().y + PADDLE_MOV * elapsedTime );
	}

}

void Game::checkBounds()
{
	if( paddleOne.getPosition().y < PADDING )
	{
		paddleOne.setPosition( paddleOne.getPosition().x, PADDING );
	}
	else if( paddleOne.getPosition().y + paddleOne.getSize().y > SCREEN_H - PADDING )
	{
		paddleOne.setPosition( paddleOne.getPosition().x, SCREEN_H - PADDING - paddleOne.getSize().y );
	}

	if( paddleTwo.getPosition().y < PADDING )
	{
		paddleTwo.setPosition( paddleTwo.getPosition().x, PADDING );
	}
	else if( paddleTwo.getPosition().y + paddleTwo.getSize().y > SCREEN_H - PADDING )
	{
		paddleTwo.setPosition( paddleTwo.getPosition().x, SCREEN_H - PADDING - paddleTwo.getSize().y );
	}
}

Game::~Game()
{

}