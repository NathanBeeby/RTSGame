#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
class UI
{
private:
	// Private Variables
	int towerSize;



	// Initialization
	void initVariables();
	void initTextures();
	void initText();
	void initSprites();
public:
	// Constructor / Destructor
	UI();
	virtual ~UI();

	// Public Variables
	sf::Font font;

	// Clock Variables
	sf::Clock uiClock;

	// Integer Variables
	int health, mana, scoreValue;

	// Float Variables
	float gridSizeF;

	// SFML Vector Variables
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;
	sf::Vector2u mousePosGrid;
	sf::Vector2f screenSize;

	

	// Shapre Variables
	std::vector<sf::RectangleShape> uiButtons;  // settings button, pause button, start round button, fast forward button etc.
	std::vector<sf::RectangleShape> guiBox;
	std::vector<sf::RectangleShape> inventoryBox;

	// String Vector Variables
	std::vector<std::string> towerStrings;
	std::vector<std::string> towerNoStrings;

	// Texture Vector Variables
	std::vector<sf::Texture> uiButtonTextures;
	std::vector<sf::Texture> towerTextures;
	std::vector<sf::Texture> towerNoTextures;
	std::vector<sf::Texture> guiBoxTextures;
	std::vector<sf::Texture> inventoryBoxTexture;

	// Accessors
	const int getScoreValue() const;
	const int getHealthValue() const;
	const int getManaValue() const;

	// Public Functions
	void RemoveHealth(int hp);
	void AddHealth(int hp);
	void RemoveMana(int mp);
	void AddMana(int mp);
	void RemoveScore(int sr);
	void AddScore(int sr);


};

