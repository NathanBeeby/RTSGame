#pragma once
#include <SFML/Graphics.hpp>
#include <random>
#include <ctime>
class TileProperties
{
private:
	// Private Variables
	int tileNumber;
	sf::Vector2f tileMax;

	// Initialization
	void initVariables();
public:
	// Constructor / Destructor 
	TileProperties();
	virtual ~TileProperties();

	// Public Variables
	bool isWater;
	int xPos, yPos;

	// Accessors
	const int& tileNum(int maxTexture) const;

	// Public Functions
	void update();
};

