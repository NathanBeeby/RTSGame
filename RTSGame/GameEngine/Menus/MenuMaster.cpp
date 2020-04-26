#include "MenuMaster.h"


void MenuMaster::initVariables()
{
	// Integer Variables
	this->selectedItemIndex = 0;
	this->height = 1080;
	this->width = 1920;
}

void MenuMaster::initBackground()
{
}

void MenuMaster::initFont()
{
	if (!this->font.loadFromFile("../Assets/Font_Assets/Freshman.ttf"))
	{
		// error...
		std::cout << "Error loading font file Freshman" << std::endl;
		system("pause");
	}
}

// Constructor / Destructor
MenuMaster::MenuMaster()
{
	this->initVariables();
	this->initFont();
}


MenuMaster::~MenuMaster()
{

}

