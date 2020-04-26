#pragma once
#include "UI.h"
class GUI : public UI
{
private:
	// Private Variables
	int woodValue, stoneValue, goldValue, coalValue;
	int invMaxX, invMaxY, invMax;
	int guiTime, guiTimeMinute, day, minute;
	sf::RectangleShape resourceBar, pauseButton, settingsButton, miniMapBox, chatBox, chatScrollBar;
	sf::Texture resourceBarTexture, pauseTexture, settingsTexture, chatBoxTexture, emptyBoxTexture, inventoryTexture, miniMapTexture;
	sf::Clock guiClock;

	std::vector<sf::RectangleShape> guiBox;
	std::vector<sf::RectangleShape> inventoryBox;

	std::vector<sf::Texture> guiBoxTextures;
	std::vector<sf::Texture> inventoryBoxTexture;

	sf::Vector2f screenSize;
	sf::Text woodText, stoneText, goldText, coalText, timerText, dayText;
	std::string woodString, stoneString, goldString, coalString;

	// Initialization
	void initVariables();
	void initTextures();
	void initSprites();
	void initText();
public:
	// Constructor / Destructor
	GUI();
	virtual ~GUI();

	// Public Variables

	// Accessors

	// Public Functions
	void updateResources();
	void updateClock();
	void update(sf::Time deltaTime);

	void renderResources(sf::RenderTarget &target, sf::View &view);
	void render(sf::RenderTarget &target, sf::View &view);
};

