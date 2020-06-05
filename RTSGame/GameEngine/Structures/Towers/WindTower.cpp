#include "WindTower.h"

void WindTower::initVariables()
{
	this->towerCost = 155;
}

void WindTower::initTextures()
{
	this->towerTextures.resize(4);

	if (!this->towerTextures[0].loadFromFile("../Assets/Image_Assets/Towers/WindTower.png")) {
		std::cout << "Error loading wind tower texture 0" << std::endl;
	} 
	else if (!this->towerTextures[1].loadFromFile("../Assets/Image_Assets/Towers/WindTower.png")) {
		std::cout << "Error loading wind tower texture 1" << std::endl;
	}
	else if (!this->towerTextures[2].loadFromFile("../Assets/Image_Assets/Towers/WindTower.png")) {
		std::cout << "Error loading wind tower texture 2" << std::endl;
	}
	else if (!this->towerTextures[3].loadFromFile("../Assets/Image_Assets/Towers/WindTower.png")) {
		std::cout << "Error loading wind tower texture 3" << std::endl;
	}
}

void WindTower::initSprites()
{

}

WindTower::WindTower()
{
	this->initVariables();
	this->initTextures();
	this->initSprites();
}


WindTower::~WindTower()
{
}