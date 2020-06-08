#include "LightTower.h"

void LightTower::initVariables()
{
	this->towerCost = 230;
	this->radius = 350.f;
}

void LightTower::initTextures()
{
	this->towerTextures.resize(4);

	if (!this->towerTextures[0].loadFromFile("../Assets/Image_Assets/Towers/LightTower.png")) {
		std::cout << "Error loading wind tower texture 0" << std::endl;
	}
	else if (!this->towerTextures[1].loadFromFile("../Assets/Image_Assets/Towers/LightTower.png")) {
		std::cout << "Error loading wind tower texture 1" << std::endl;
	}
	else if (!this->towerTextures[2].loadFromFile("../Assets/Image_Assets/Towers/LightTower.png")) {
		std::cout << "Error loading wind tower texture 2" << std::endl;
	}
	else if (!this->towerTextures[3].loadFromFile("../Assets/Image_Assets/Towers/LightTower.png")) {
		std::cout << "Error loading wind tower texture 3" << std::endl;
	}
}

void LightTower::initSprites()
{

}

LightTower::LightTower()
{
	this->initVariables();
	this->initTextures();
	this->initSprites();
}


LightTower::~LightTower()
{
}
