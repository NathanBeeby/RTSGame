#include "Game.h"
#include <sstream>
void Game::initVariables()
{
	this->miniMap.setViewport(sf::FloatRect(0.0235f, 0.824f, 0.208f, 0.165f));
	this->miniMap.setCenter(sf::Vector2f(1700.f, 100.f));
	this->miniMap.setSize(sf::Vector2f(200.f, 200.f));
	this->viewSpeed = 10.f;
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


void Game::keyHandler(sf::Keyboard::Key key, sf::View &view)
{
	gui.keyHandler(key);
	deltaTime = clock.getElapsedTime().asSeconds();
	if (key == sf::Keyboard::Key::L) {
		tile.previousMap();
	}
	else if(key == sf::Keyboard::Key::O) {
		tile.nextMap();
	}
	if (key == sf::Keyboard::W || key == sf::Keyboard::Up)
	{
		if (view.getCenter().y > 1310) {
			view.move(0.f, -(viewSpeed * deltaTime));
		}
		else {
			view.setCenter(sf::Vector2f(view.getCenter().x, 1310));
		}
	}
	else if (key == sf::Keyboard::S || key == sf::Keyboard::Down)
	{
		if (view.getCenter().y + view.getCenter().y <= ((tile.tileMax.y + 2) * gridSizeF) + (view.getCenter().y / 2) + 100) {
			view.move(0.f, (viewSpeed * deltaTime));
		}
		else {
			//view.setCenter(sf::Vector2f(view.getCenter().x, 4500));
		}
	}
	else if (key == sf::Keyboard::A || key == sf::Keyboard::Left)
	{
		if (view.getCenter().x > 2620) {
			view.move(-(viewSpeed * deltaTime), 0.f);
		}
		else {
			view.setCenter(sf::Vector2f(2620, view.getCenter().y));
		}
	}
	else if (key == sf::Keyboard::D || key == sf::Keyboard::Right)
	{
		if (view.getCenter().x + view.getCenter().x <= ((tile.tileMax.x + 1) * gridSizeF) + (view.getCenter().x / 2) - 60) {
			view.move((viewSpeed * deltaTime), 0.f);
		}
		else {
			//view.setCenter(sf::Vector2f(4800, view.getCenter().y));
		}
	}
	//clock.restart();
}

void Game::mouseHandler(sf::RenderWindow & window, sf::View &view)
{
	mousePosWindow = sf::Mouse::getPosition(window);
	mousePosView = window.mapPixelToCoords(mousePosWindow);
	mousePosGrid.x = (mousePosView.x / gridSizeU);
	mousePosGrid.y = (mousePosView.y / gridSizeU);
	gui.mouseHandler(mousePosWindow, mousePosGrid);

	//std::cout << "Mouse Pos Window: X - " << mousePosWindow.x << ", Y - " << mousePosWindow.y << std::endl;
	//std::cout << "Mouse Pos View: X - " << mousePosView.x << ", Y - " << mousePosView.y << std::endl;
	//std::cout << "Mouse Pos Grid: X - " << mousePosGrid.x << ", Y - " << mousePosGrid.y << std::endl;
}

void Game::updateTileView(sf::View &view)
{
	//if (view.getCenter().y <= 1310) {
	//	view.setCenter(sf::Vector2f(view.getCenter().x, 1310));
	//}
	//if (view.getCenter().y + view.getCenter().y >= 4500) {
	//	view.setCenter(sf::Vector2f(view.getCenter().x, 4500));
	//}
	//if (view.getCenter().x <= 2620) {
	//	view.setCenter(sf::Vector2f(2620, view.getCenter().y));
	//}
	//if (view.getCenter().x + view.getCenter().x >= 4800) {
	//	view.setCenter(sf::Vector2f(4800, view.getCenter().y));
	//}

	// Rendering tiles via view position
	tile.fromX = view.getCenter().x / gridSizeF - 15;
	tile.toX = view.getCenter().x / gridSizeF + 15;
	tile.fromY = view.getCenter().y / gridSizeF - 8;
	tile.toY = view.getCenter().y / gridSizeF + 8;

	tile.miniMapFromX = view.getCenter().x / gridSizeF - 15;
	tile.miniMapToX = view.getCenter().x / gridSizeF + 36;
	tile.miniMapFromY = view.getCenter().y / gridSizeF - 7;
	tile.miniMapToY = view.getCenter().y / gridSizeF + 16;
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

	mouseHandler(window, view);

	this->tileSelector.setPosition(mousePosGrid.x * gridSizeF, mousePosGrid.y * gridSizeF);
	tile.render(window);
	gui.renderTowers(window);
	window.draw(tileSelector);
	gui.renderTowerSelector(window, sf::Vector2i(mousePosGrid.x * gridSizeF, mousePosGrid.y * gridSizeF));
	gui.render(window, view);
	tile.renderMiniMap(window, view);
	this->updateTileView(view);
	window.setView(miniMap);

	// Need to draw 1/4 of the map within the mini map view, if the main view is on one of the 4 quaters
	// Display that quater on the minimap view
	// TILE MINIMAP BELOW NEEDS FIXING - vector out of range when drawing
	//tile.renderMiniMap(window);
	window.setView(window.getDefaultView());

}