#include "Tile.h"

void Tile::initVariables()
{
	this->tileMax.x = 100;
	this->tileMax.y = 100;
}

void Tile::initTextures()
{
	this->tileTexture.resize(8);

	if (!this->tileTexture[0].loadFromFile("../Assets/Image_Assets/Dirt1.png")) {
		std::cout << "Dirt 1 Failed to load" << std::endl;
	}
	if (!this->tileTexture[1].loadFromFile("../Assets/Image_Assets/Dirt2.png")) {
		std::cout << "Dirt 1 Failed to load" << std::endl;
	}
	if (!this->tileTexture[2].loadFromFile("../Assets/Image_Assets/Grass1.png")) {
		std::cout << "Dirt 1 Failed to load" << std::endl;
	}
	if (!this->tileTexture[3].loadFromFile("../Assets/Image_Assets/Grass2.png")) {
		std::cout << "Dirt 1 Failed to load" << std::endl;
	}
	if (!this->tileTexture[4].loadFromFile("../Assets/Image_Assets/Grass3.png")) {
		std::cout << "Dirt 1 Failed to load" << std::endl;
	}
	if (!this->tileTexture[5].loadFromFile("../Assets/Image_Assets/Sand1.png")) {
		std::cout << "Dirt 1 Failed to load" << std::endl;
	}
	if (!this->tileTexture[6].loadFromFile("../Assets/Image_Assets/Sand2.png")) {
		std::cout << "Dirt 1 Failed to load" << std::endl;
	}
	if (!this->tileTexture[7].loadFromFile("../Assets/Image_Assets/Water.png")) {
		std::cout << "Dirt 1 Failed to load" << std::endl;
	}
}

void Tile::initSprite()
{
	this->tiles.resize((this->tileMax.x * this->tileMax.y), std::vector<sf::RectangleShape>());
	for (int x = 0; x < tileMax.x; x++) {
		this->tiles[x].resize((this->tileMax.x * this->tileMax.y), sf::RectangleShape());
		for (int y = 0; y < tileMax.y; y++) {
			tiles[x][y].setSize(sf::Vector2f(200, 200));
			tiles[x][y].setOutlineThickness(1);
			tiles[x][y].setOutlineColor(sf::Color::Black);
			tiles[x][y].setPosition(sf::Vector2f(tiles[x][y].getSize().x * x, tiles[x][y].getSize().y * y));
			tiles[x][y].setTexture(&this->tileTexture[rand() % 8]);
		}
	}

	this->fromX = 0;
	this->toX = 0;
	this->fromY = 0;
	this->toY = 0;
}

Tile::Tile()
{
	this->initVariables();
	this->initTextures();
	this->initSprite();
}

Tile::~Tile()
{
}

void Tile::updateTileView()
{
	if (fromX < 0) {
		fromX = 0;
	}
	else if (fromX >= tileMax.x) {
		fromX = tileMax.x - 1;
	}
	if (toX < 0) {
		toX = 0;
	}
	else if (toX >= tileMax.x) {
		toX = tileMax.x - 1;
	}


	if (fromY < 0) {
		fromY = 0;
	}
	else if (fromY >= tileMax.y) {
		fromY = tileMax.y - 1;
	}
	if (toY < 0) {
		toY = 0;
	}
	else if (toY >= tileMax.y) {
		toY = tileMax.y - 1;
	}
}

void Tile::update()
{
	this->updateTileView();
}

void Tile::render(sf::RenderTarget &target)
{
	std::cout << "Rendering FromX: " << this->fromX << ", FromY: " << this->fromY << std::endl;
	std::cout << "Rendering toX: " << this->toX << ", toY: " << this->toY << std::endl;
	for (int x = fromX; x < toX; x++) {
		for (int y = fromY; y < toY; y++) {

			target.draw(tiles[x][y]);
		}
	}
}
