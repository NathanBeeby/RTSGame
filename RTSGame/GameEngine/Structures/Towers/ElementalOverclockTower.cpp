#include "ElementalOverclockTower.h"

void ElementalOverclockTower::initVariables()
{
	this->towerCost = 700;
	this->radius = 500.f;
}

void ElementalOverclockTower::initTextures()
{
	this->towerTextures.resize(4);

	if (!this->towerTextures[0].loadFromFile("../Assets/Image_Assets/Towers/ElementalOverclocker.png")) {
		std::cout << "Error loading wind tower texture 0" << std::endl;
	}
	else if (!this->towerTextures[1].loadFromFile("../Assets/Image_Assets/Towers/ElementalOverclocker.png")) {
		std::cout << "Error loading wind tower texture 1" << std::endl;
	}
	else if (!this->towerTextures[2].loadFromFile("../Assets/Image_Assets/Towers/ElementalOverclocker.png")) {
		std::cout << "Error loading wind tower texture 2" << std::endl;
	}
	else if (!this->towerTextures[3].loadFromFile("../Assets/Image_Assets/Towers/ElementalOverclocker.png")) {
		std::cout << "Error loading wind tower texture 3" << std::endl;
	}
}

void ElementalOverclockTower::initSprites()
{

}

ElementalOverclockTower::ElementalOverclockTower()
{
	this->initVariables();
	this->initTextures();
	this->initSprites();
}


ElementalOverclockTower::~ElementalOverclockTower()
{
}
