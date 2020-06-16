#pragma once
#include "MenuMaster.h"

class GameSuccessMenu : public MenuMaster
{
private:
	// Private Variables


	// Initialization
	void initVariables();
	void initSprites();
	void initText();
	void initTextures();
public:
	GameSuccessMenu();
	virtual ~GameSuccessMenu();

	// Public Functions
	void Up();
	void Down();
	void keyHandler(sf::Keyboard::Key key);
	void mouseHandler(sf::RenderWindow &window);
	void update();
	void render(sf::RenderTarget &target);
};

