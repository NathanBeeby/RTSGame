#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


class MenuMaster
{
private:
	// Private Variables

	// Initialization
	void initVariables();
	void initBackground();
	void initFont();
public:
	// Constructor / Destructor
	MenuMaster();
	virtual ~MenuMaster();

	// Public Variables
	int selectedItemIndex;
	int height, width;
	sf::Font font;
	sf::RectangleShape background;
	sf::Texture backgroundTexture;


	//Public functions
	int GetPressedItem() { return selectedItemIndex; }

};

