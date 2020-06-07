#pragma once
#include "UI.h"
#include "../GameAssets/AssetManager.h"
#include "StructureInventory.h"
#include "../Wave/Wave.h"
class GUI : public UI
{
private:
	// Private Variables
	AssetManager manager;
	Wave wave;
	StructureInventory structInv;

	// Clock
	sf::Clock guiClock;

	// Boolean Variables
	bool mouseHeld;

	// Integer Variables
	int levelValue, scoreValue, invMaxX, invMaxY, invMax, health, mana, waveAmt, guiTime, guiTimeMinute, day, minute;

	// Unsigned Variables
	unsigned gridSizeU = static_cast<unsigned>(gridSizeF);

	// Float Variables
	float gridSizeF;

	// Shape Variables
	sf::RectangleShape resourceBar, pauseButton, settingsButton, miniMapBox, chatBox, chatScrollBar, tileSelector;
	
	// Texture Variables
	sf::Texture resourceBarTexture, waveTexture, pauseTexture, settingsTexture, chatBoxTexture, emptyBoxTexture, inventoryTexture, miniMapTexture, healthTexture, manaTexture, fireNoTexture, waterNoTexture, windNoTexture, iceNoTexture, earthNoTexture, energyNoTexture,
		lightNoTexture, darkNoTexture, elemAmpNoTexture, elemOverNoTexture, manaAmpNoTexture, observNoTexture, regenNoTexture, voidNoTexture, fireTexture, waterTexture, windTexture, iceTexture, earthTexture, energyTexture,
		lightTexture, darkTexture, elemAmpTexture, elemOverTexture, manaAmpTexture, observTexture, regenTexture, voidTexture;
	
	// String Variables
	std::string fireTower, waterTower, windTower, iceTower, earthTower, energyTower, lightTower, darkTower, voidTower, regenTower, 
		observTower, manaAmpTower, elementOverTower, elementAmpTower, levelString, scoreString, waveString, healthString, manaString;

	// Text Variables
	sf::Text levelText, scoreText, waveText, timerText, dayText, healthText, manaText;

	// Vector Variables
	std::vector<sf::RectangleShape> guiBox;
	std::vector<sf::RectangleShape> inventoryBox;
	std::vector<sf::Texture> guiBoxTextures;
	std::vector<sf::Texture> inventoryBoxTexture;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;
	sf::Vector2f screenSize;
	sf::Vector2u mousePosGrid;

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

	void updateLives();
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

