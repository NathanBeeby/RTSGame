#include "WaterTower.h"



void WaterTower::initVariables()
{
	this->towerCost = 280;
}

void WaterTower::initTextures()
{
	this->towerTextures.resize(4);

	if (!this->towerTextures[0].loadFromFile("../Assets/Image_Assets/Towers/WaterTower.png")) {
		std::cout << "Error loading wind tower texture 0" << std::endl;
	}
	else if (!this->towerTextures[1].loadFromFile("../Assets/Image_Assets/Towers/WaterTower.png")) {
		std::cout << "Error loading wind tower texture 1" << std::endl;
	}
	else if (!this->towerTextures[2].loadFromFile("../Assets/Image_Assets/Towers/WaterTower.png")) {
		std::cout << "Error loading wind tower texture 2" << std::endl;
	}
	else if (!this->towerTextures[3].loadFromFile("../Assets/Image_Assets/Towers/WaterTower.png")) {
		std::cout << "Error loading wind tower texture 3" << std::endl;
	}
}

void WaterTower::initSprites()
{
}

WaterTower::WaterTower()
{
	this->initVariables();
	this->initTextures();
	this->initSprites();
}


WaterTower::~WaterTower()
{
}
