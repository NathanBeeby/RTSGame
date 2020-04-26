#pragma once
#include "MenuMaster.h"
#define item_Number 5

class InstructionsMenu : public MenuMaster
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
	InstructionsMenu();
	virtual ~InstructionsMenu();

	// Public Variables
	bool ins1, ins2, ins3, ins4, backPressed;

	// Public Functions
	void backButtonPressed();
	void Up();
	void Down();

	void keyHandler(sf::Keyboard::Key key);
	void mouseHandler(sf::RenderWindow &window);
	void update();
	void render(sf::RenderTarget &target);
};

