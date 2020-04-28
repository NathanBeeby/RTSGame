#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
struct Tile
{
	// Private variables
	sf::Vector2i tileMax;
	std::vector<std::vector<sf::RectangleShape>> tiles;
	std::vector<sf::Texture> tileTexture;
	//float posX, posY;
	//int sizeX, sizeY;

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
	// Public Functions
	void updateTileView();
	void update();
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

