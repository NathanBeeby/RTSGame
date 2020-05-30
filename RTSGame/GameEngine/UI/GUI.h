#pragma once
#include "UI.h"
#include "../GameAssets/AssetManager.h"
#include "StructureInventory.h"
class GUI : public UI
{
private:
	// Private Variables
	AssetManager manager;
	StructureInventory structInv;
	int levelValue, scoreValue;
	int invMaxX, invMaxY, invMax, health, mana, wave;
	int guiTime, guiTimeMinute, day, minute;
	sf::RectangleShape resourceBar, pauseButton, settingsButton, miniMapBox, chatBox, chatScrollBar;
	sf::Texture resourceBarTexture, waveTexture, pauseTexture, settingsTexture, chatBoxTexture, emptyBoxTexture, inventoryTexture, miniMapTexture, healthTexture, manaTexture;
	sf::Clock guiClock;
	bool mouseHeld;
	sf::Texture fireNoTexture, waterNoTexture, windNoTexture, iceNoTexture, earthNoTexture, energyNoTexture,
		lightNoTexture, darkNoTexture, elemAmpNoTexture, elemOverNoTexture, manaAmpNoTexture, observNoTexture, regenNoTexture, voidNoTexture;
	sf::Texture fireTexture, waterTexture, windTexture, iceTexture, earthTexture, energyTexture,
		lightTexture, darkTexture, elemAmpTexture, elemOverTexture, manaAmpTexture, observTexture, regenTexture, voidTexture;
	std::string fireTower, waterTower, windTower, iceTower, earthTower, energyTower, lightTower, darkTower, voidTower, regenTower, observTower, manaAmpTower, elementOverTower, elementAmpTower;

	std::vector<sf::RectangleShape> guiBox;
	std::vector<sf::RectangleShape> inventoryBox;

	std::vector<sf::Texture> guiBoxTextures;
	std::vector<sf::Texture> inventoryBoxTexture;

	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;
	sf::Vector2u mousePosGrid;
	float gridSizeF = 200.f;
	unsigned gridSizeU = static_cast<unsigned>(gridSizeF);
	sf::Vector2f screenSize;
	sf::Text levelText, scoreText, waveText, timerText, dayText, healthText, manaText;
	std::string levelString, scoreString, waveString, healthString, manaString;

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
	void updateTowerTextures();
	void keyHandler(sf::Keyboard::Key key);
	//void mouseHandler(sf::RenderWindow &window);
	void mouseHandler(sf::Vector2i &windowPos, sf::Vector2u &gridPos);
	void renderResources(sf::RenderTarget &target, sf::View &view);
	void render(sf::RenderTarget &target, sf::View &view);
	void renderTowers(sf::RenderTarget &target);
};

