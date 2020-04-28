#include "Game.h"
#include <sstream>
void Game::initVariables()
{

}

void Game::initTextures()
{
	//this->spriteTexture.resize(8);

	//if (!this->spriteTexture[0].loadFromFile("../Assets/Image_Assets/Dirt1.png")) {
	//	std::cout << "Dirt 1 Failed to load" << std::endl;
	//}
	//if (!this->spriteTexture[1].loadFromFile("../Assets/Image_Assets/Dirt2.png")) {
	//	std::cout << "Dirt 1 Failed to load" << std::endl;
	//}
	//if (!this->spriteTexture[2].loadFromFile("../Assets/Image_Assets/Grass1.png")) {
	//	std::cout << "Dirt 1 Failed to load" << std::endl;
	//}
	//if (!this->spriteTexture[3].loadFromFile("../Assets/Image_Assets/Grass2.png")) {
	//	std::cout << "Dirt 1 Failed to load" << std::endl;
	//}
	//if (!this->spriteTexture[4].loadFromFile("../Assets/Image_Assets/Grass3.png")) {
	//	std::cout << "Dirt 1 Failed to load" << std::endl;
	//}
	//if (!this->spriteTexture[5].loadFromFile("../Assets/Image_Assets/Sand1.png")) {
	//	std::cout << "Dirt 1 Failed to load" << std::endl;
	//}
	//if (!this->spriteTexture[6].loadFromFile("../Assets/Image_Assets/Sand2.png")) {
	//	std::cout << "Dirt 1 Failed to load" << std::endl;
	//}
	//if (!this->spriteTexture[7].loadFromFile("../Assets/Image_Assets/Water.png")) {
	//	std::cout << "Dirt 1 Failed to load" << std::endl;
	//}
}

void Game::initSprites()
{
	this->tileSelector.setSize(sf::Vector2f(gridSizeF, gridSizeF));
	this->tileSelector.setFillColor(sf::Color::Transparent);
	this->tileSelector.setOutlineThickness(2.f);
	this->tileSelector.setOutlineColor(sf::Color::Yellow);
}

Game::Game()
{
	this->initVariables();
	this->initTextures();
	this->initSprites();
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
	mousePosWindow = sf::Mouse::getPosition(window);
	mousePosView = window.mapPixelToCoords(mousePosWindow);
	mousePosGrid.x = (mousePosView.x / gridSizeU);
	mousePosGrid.y = (mousePosView.y / gridSizeU);
	std::stringstream ss;

	ss << "Mouse Pos Window:  X - " << mousePosWindow.x << ", Y - " << mousePosWindow.y << "\n" <<
		"Mouse Pos View:  X - " << mousePosView.x << ", Y - " << mousePosView.y << "\n" <<
		"Mouse Pos Grid:  X - " << mousePosGrid.x << ", Y - " << mousePosGrid.y << "\n";
	std::cout << ss.str() << std::endl;
}

void Game::updateTileView(sf::View &view)
{
	// Rendering Tiles via mouse position
	//tile.fromX = mousePosGrid.x - 25;
	//tile.toX = mousePosGrid.x + 25;
	//tile.fromY = mousePosGrid.y - 15;
	//tile.toY = mousePosGrid.y + 15;
	// Rendering tiles via view position
	tile.fromX = view.getCenter().x / gridSizeF - 15;
	tile.toX = view.getCenter().x / gridSizeF + 15;
	tile.fromY = view.getCenter().y / gridSizeF - 7;
	tile.toY = view.getCenter().y / gridSizeF + 7;
}


void Game::update(sf::Time deltaTime)
{
	
	this->tile.update();
	this->gui.update(deltaTime);
}

void Game::render(sf::RenderWindow &window, sf::View &view)
{
	mousePosWindow = sf::Mouse::getPosition(window);
	mousePosView = window.mapPixelToCoords(mousePosWindow);
	mousePosGrid.x = (mousePosView.x / gridSizeU);
	mousePosGrid.y = (mousePosView.y / gridSizeU);
	this->tileSelector.setPosition(mousePosGrid.x * gridSizeF, mousePosGrid.y * gridSizeF);
	tile.render(window);
	window.draw(tileSelector);
	gui.render(window, view);
	this->updateTileView(view);

}