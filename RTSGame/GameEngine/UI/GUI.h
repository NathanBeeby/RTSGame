#pragma once
#include "UI.h"
#include "../GameAssets/AssetManager.h"
#include "StructureInventory.h"
#include "../Wave/Wave.h"
class GUI : virtual public UI
{
private:
	// Private Variables
	AssetManager manager;
	Wave wave;
	StructureInventory structInv;

	// Boolean Variables
	bool mouseHeld, isLevelWon, isLevelLost;

	// Integer Variables
	int levelValue, invMaxX, invMaxY, invMax, waveAmt, guiTime, guiTimeMinute, day, minute;

	// Shape Variables
	sf::RectangleShape resourceBar, pauseButton, settingsButton, miniMapBox, chatBox, chatScrollBar, tileSelector;
	
	// Texture Variables
	sf::Texture resourceBarTexture, waveTexture, pauseTexture, settingsTexture, chatBoxTexture, emptyBoxTexture, inventoryTexture, miniMapTexture, healthTexture, manaTexture;
	
	// String Variables
	std::string levelString, scoreString, waveString, healthString, manaString;

	// Text Variables
	sf::Text levelText, scoreText, waveText, timerText, dayText, healthText, manaText;

	//// Unsigned Variables
	//unsigned gridSizeU = static_cast<unsigned>(gridSizeF);

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
	const bool LevelWon() const;
	const bool LevelLost() const;



	void updateResources();
	void updateClock();
	void update(sf::Time deltaTime);
	void updateTowerTextures();
	void keyHandler(sf::Keyboard::Key key);
	void mouseHandler(sf::Vector2i &windowPos, sf::Vector2u &gridPos);
	void renderResources(sf::RenderTarget &target, sf::View &view);
	void render(sf::RenderTarget &target, sf::View &view);
	void renderTowerSelector(sf::RenderTarget &target, sf::Vector2i pos);
	void renderTowers(sf::RenderTarget &target);
	void renderWave(sf::RenderTarget &target);
};

