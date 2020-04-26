#include "Game.h"

Game::Game()
{
	//this->initVariables();
	//this->initFullscreenWindow(); //Init Default Window
	//this->initView();
}


Game::~Game()
{
	//delete this->window;

}


void Game::keyHandler(sf::Keyboard::Key key)
{
}

void Game::mouseHandler(sf::RenderWindow & window)
{
}

void Game::update(sf::Time deltaTime)
{
	////updating the sfml events
	//this->updateSFMLEvents();
	//this->updateView();
	this->gui.update(deltaTime);
}

void Game::render(sf::RenderTarget &target, sf::View &view)
{
	////clearing the window to black
	//window->clear(sf::Color::Black);
	gui.render(target, view);

	////Displaying the content to the window
	//window->display();
}