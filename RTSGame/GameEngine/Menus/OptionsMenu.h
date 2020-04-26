#pragma once
#include "MenuMaster.h"
#define item_Number 5

class OptionsMenu : public MenuMaster
{
private:
	// Private Variables
	sf::Text MenuText[item_Number];
	sf::RectangleShape emptyMusic, emptySound, emptyMaster, MasterBar, MusicBar, SoundBar;


	// Initialization
	void initVariables();
	void initSprites();
	void initTextures();
	void initText();
public:
	// Constructor / Destructor
	OptionsMenu();
	virtual ~OptionsMenu();

	// Public Variables
	bool instructionsPressed, backPressed;
	float Music, Sound, Master;

	// Public Functions
	void instructionsButtonPressed();
	void backButtonPressed();
	void Up();
	void Down();

	void keyHandler(sf::Keyboard::Key key);
	void mouseHandler(sf::RenderWindow &window);
	void update();
	void render(sf::RenderTarget &target);
};

