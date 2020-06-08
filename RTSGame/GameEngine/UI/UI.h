#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include "../Wave/Wave.h"
#include "StructureInventory.h"
class UI
{
private:
	// Private Variables
	int towerSize, uiButtonSize, uiButtonTextureSize, towerUpgradeSize;

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
	Wave wave;
	StructureInventory structInv;

	// Boolean Variables
	bool mouseHeld, isLevelWon, isLevelLost, towerMenuOpen, towerUpgradeMenuOpen, gamePaused;

	// Font Variables
	sf::Font font;

	// Clock Variables
	sf::Clock uiClock;

	// Integer Variables
	int health, scoreValue, levelValue, waveAmt, actualHealth, uiTime, uiTimeMinute, day, minute;

	// Float Variables
	float gridSizeF;

	// SFML Vector Variables
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;
	sf::Vector2u mousePosGrid;
	sf::Vector2f screenSize;

	// Shape Variables
	std::vector<sf::RectangleShape> uiButtons;  // settings button, pause button, start round button, fast forward button etc.
	std::vector<sf::RectangleShape> guiBox;
	std::vector<sf::RectangleShape> inventoryBox;
	std::vector<sf::RectangleShape> towerUpgradeBox;
	sf::RectangleShape towerMenuToggle, towerUpgradeMenuToggle;

	// String Vector Variables
	std::vector<std::string> towerStrings;
	std::vector<std::string> towerNoStrings;

	// String Variables
	std::string levelString, scoreString, waveString, healthString, manaString, towerCloseString, towerOpenString, towerUpgradeCloseString, towerUpgradeOpenString;

	// Texture Vector Variables
	std::vector<sf::Texture> uiButtonTextures;
	std::vector<sf::Texture> towerTextures;
	std::vector<sf::Texture> towerNoTextures;
	std::vector<sf::Texture> guiBoxTextures;
	std::vector<sf::Texture> inventoryBoxTexture;
	std::vector<sf::Texture> towerUpgradeBoxTexture;
	sf::Texture towerToggleTexture, towerUpgradeToggleTexture;

	// Text Variables
	sf::Text levelText, scoreText, waveText, timerText, dayText, healthText, manaText;

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

	void uiButtonsMouseHandler(sf::Vector2i & windowPos);
	void towerMenuMouseHandler(sf::Vector2i &windowPos);
	void towerUIMouseHandler(sf::Vector2i &windowPos);
	void towerUpgradeUIMouseHandler(sf::Vector2i &windowPos);

	void updateUIText();
	void updateGameState();
	void updateClock();
	void updateUITime();

};

