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
	int miniMapOffsetX, miniMapOffsetY, mapNo, mapMax, tileSize;
	sf::Texture tileText;
	sf::Sprite tile, miniMapTile;
	sf::Vector2i map[35][30];
	sf::Vector2i tileMax;
	std::vector<sf::Vector2i> waterTiles;
	std::vector<std::string> mapFile;
	TileProperties tileProp;
	//StructureInventory structInv;
	//// Initialization
	void initVariables();
	void initTextures();
	void initWaypoints(int mapNum);
	void initSprite(int mapNum);
public:
	// Constructor / Destructor
	Tile();
	virtual ~Tile();

	// Public Variables
	std::vector<sf::Vector2i> unplacableTiles;
	int fromX, fromY, toX, toY, miniMapFromX, miniMapToX, miniMapFromY, miniMapToY;

	// Accessors
	const int getMapNo() const;
	const int getMapMax() const;


	// Public Functions
	void updateTileView();
	void updateMiniMapView();
	void updateMap(int mapNum);
	void nextMap();
	void previousMap();
	void update();
	void renderMiniMap(sf::RenderTarget &target, sf::View &view);
	void render(sf::RenderTarget &target);

};

