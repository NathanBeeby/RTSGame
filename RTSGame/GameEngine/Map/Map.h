#pragma once
#include "Tile.h"
#include <iostream>

class Map
{
private:
	// Private variables
	float gridSizeF;
	unsigned gridSizeU;
	sf::RectangleShape shape;
	int maxTiles;
	Tile tiles;
	//std::vector<Tile> tiles;

	// Initialization
	void initVariables();
	void initTextures();
	void initSprites();
public:
	Map();
	virtual ~Map();

	void update();
	void render(sf::RenderTarget &target);
};

