#include "DarkTower.h"

void DarkTower::initVariables()
{
	this->towerCost = 366;
	this->radius = 400.f;
}

void DarkTower::initTextures()
{
	this->towerTextures.resize(4);

	if (!this->towerTextures[0].loadFromFile("../Assets/Image_Assets/Towers/DarkTower.png")) {
		std::cout << "Error loading wind tower texture 0" << std::endl;
	}
	else if (!this->towerTextures[1].loadFromFile("../Assets/Image_Assets/Towers/DarkTower.png")) {
		std::cout << "Error loading wind tower texture 1" << std::endl;
	}
	else if (!this->towerTextures[2].loadFromFile("../Assets/Image_Assets/Towers/DarkTower.png")) {
		std::cout << "Error loading wind tower texture 2" << std::endl;
	}
	else if (!this->towerTextures[3].loadFromFile("../Assets/Image_Assets/Towers/DarkTower.png")) {
		std::cout << "Error loading wind tower texture 3" << std::endl;
	}
}

void DarkTower::initSprites()
{

}

DarkTower::DarkTower()
{
	this->initVariables();
	this->initTextures();
	this->initSprites();
}


DarkTower::~DarkTower()
{
}
