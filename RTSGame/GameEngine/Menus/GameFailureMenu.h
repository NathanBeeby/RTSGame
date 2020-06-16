#pragma once
#include "MenuMaster.h"

class GameFailureMenu : public MenuMaster
{
private:
	// Private Variables


	// Initialization
	void initVariables();
	void initSprites();
	void initText();
	void initTextures();
public:
	// Constructor / Destructor
	GameFailureMenu();
	 virtual ~GameFailureMenu();

	 // Public Functions
	 void Up();
	 void Down();
	 void keyHandler(sf::Keyboard::Key key);
	 void mouseHandler(sf::RenderWindow &window);
	 void update();
	 void render(sf::RenderTarget &target);
};

