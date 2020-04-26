#pragma once
#include "MenuMaster.h"
#define item_Number 4
class StartMenu : public MenuMaster
{
private:
	// Private Variables
	sf::Texture backgroundTexture;
	sf::Text MenuText[item_Number];

	// Initialization
	void initVariables();
	void initSprites();
	void initTextures();
	void initText();

public:
	// Constructor / Destructor
	StartMenu();
	virtual ~StartMenu();

	// Public Variables
	bool newGamePressed, loadGamePressed, optionsPressed, quitPressed;

	// Public Functions
	void Up();
	void Down();
	void keyHandler(sf::Keyboard::Key key);
	void mouseHandler(sf::RenderWindow &window);
	void update();
	void render(sf::RenderTarget &target);


};

