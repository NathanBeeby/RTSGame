#pragma once
#include "UI.h"
#include "../GameAssets/AssetManager.h"


class GUI : virtual public UI
{
private:
	// Private Variables
	AssetManager manager;

	// Integer Variables
	int invMaxX, invMaxY, invMax;

	// Shape Variables //pauseButton, settingsButton
	sf::RectangleShape resourceBar, miniMapBox, chatBox, chatScrollBar, tileSelector;
	
	// Texture Variables
	sf::Texture resourceBarTexture, waveTexture, chatBoxTexture, emptyBoxTexture, inventoryTexture, miniMapTexture, healthTexture, manaTexture;

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

	// Public Functions
	void AddUnplacablePosition(sf::Vector2i pos);
	void updateGUIPositions();
	void updateResources();
	void update(sf::Time deltaTime);
	void updateTowerTextures();
	void keyHandler(sf::Keyboard::Key key);
	void mouseHandler(sf::Vector2i &windowPos, sf::Vector2u &gridPos);
	void renderResources(sf::RenderTarget &target, sf::View &view);
	void renderGUI(sf::RenderTarget &target);
	void renderTowerMenu(sf::RenderTarget &target);
	void render(sf::RenderTarget &target, sf::View &view);
	void renderTowerSelector(sf::RenderTarget &target, sf::Vector2i pos);
	void renderTowers(sf::RenderTarget &target);
	void renderTowerUpgradeBox(sf::RenderTarget &target);
	void renderWave(sf::RenderTarget &target);
};

