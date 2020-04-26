#pragma once
#include "MenuMaster.h"
#define item_Number 4
class InitGameMenu : public MenuMaster
{
private:
	// Private Variables
	sf::Text MenuText[item_Number];


	// Initialization
	void initVariables();
	void initSprites();
	void initTextures();
	void initText();
public:
	// Constructor / Destructor
	InitGameMenu();
	virtual ~InitGameMenu();

	// Public Variables
	bool backPressed, playPressed;

	// Public Functions
	void Up();
	void Down();
	void backButtonPressed();
	void playButtonPressed();

	void keyHandler(sf::Keyboard::Key key);
	void mouseHandler(sf::RenderWindow &window);
	void update();
	void render(sf::RenderTarget &target);
};

