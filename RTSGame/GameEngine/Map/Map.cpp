#include "Map.h"



void Map::initVariables()
{
	//this->maxTiles = 10;
	this->gridSizeF = 100.f;
	this->gridSizeU = static_cast<unsigned>(gridSizeF);
	shape.setSize(sf::Vector2f(gridSizeF, gridSizeF));
	if (!this->tiles.tileTexture.loadFromFile("")) {

	}
	this->tiles.tile.setPosition(sf::Vector2f(0.f,0.f));
	this->tiles.tile.setSize(sf::Vector2f(200.f,200.f));
	this->tiles.tile.setTexture(&this->tiles.tileTexture);
}

void Map::initTextures()
{
}

void Map::initSprites()
{
	for (int i = 0; i < maxTiles; i++)
	{
		//this->tiles.push_back(sandTile);
		//this->sandTile.setPosition(sf::Vector2f(i * 32, 0));
	}
}

Map::Map()
{
	this->initVariables();
	this->initSprites();
}


Map::~Map()
{
}

void Map::update()
{
}

void Map::render(sf::RenderTarget &target)
{
	//for (int i = 0; i < maxTiles; i++) {
	//	target.draw(tiles[i]);
	//}
}
