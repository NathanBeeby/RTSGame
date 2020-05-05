#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Character
{
private:
	// Private Variables
	int playerLevel;

	// Initialization
	void initVariables();
public:
	// Constructor / Destructor
	Character();
	virtual ~Character();

	// Public Variables
	std::vector<sf::RectangleShape> sprites;
	std::vector<sf::Texture> spritesTextures;

	// Accessors

	// Public Functions


};

