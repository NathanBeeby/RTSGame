#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include "TileProperties.h"

struct Tile
{
	// Private variables
	sf::Texture tileText;
	sf::Sprite tile, miniMapTile;
	sf::Vector2i map[35][30];

	sf::Vector2i tileMax;
	std::vector<bool> isWater;
	int miniMapOffsetX, miniMapOffsetY;
	TileProperties tileProp;

	//// Initialization
	void initVariables();
	void initTextures();
	void initSprite();
public:
	// Constructor / Destructor
	Tile();
	virtual ~Tile();
	// Public Variables
	int fromX, fromY, toX, toY;
	int miniMapFromX, miniMapToX, miniMapFromY, miniMapToY;
	// Public Functions
	void updateTileView();
	void updateMiniMapView();
	void update();
	void renderMiniMap(sf::RenderTarget &target, sf::View &view);
	void render(sf::RenderTarget &target);
	//// Modifiers
	//void setPosition(sf::Vector2f pos);
	//const sf::Vector2f getPosition() const;

	//void setSize(sf::Vector2f size);
	//const sf::Vector2f getSize() const;

	//void setScale(sf::Vector2f scale);
	//const sf::Vector2f getScale() const;

	//void setRotation(float rot);
	//const float getRotation() const;

	//void setTexture(sf::Texture *texture);
	//const sf::Texture getTexture() const;
};

