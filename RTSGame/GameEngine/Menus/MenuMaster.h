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

	virtual void Up() = 0;
	virtual void Down() = 0;


	//Public functions
	int GetPressedItem() { return selectedItemIndex; }

};

