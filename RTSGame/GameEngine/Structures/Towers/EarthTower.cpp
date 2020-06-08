#include "EarthTower.h"


void EarthTower::initVariables()
{
	this->towerCost = 400;
	this->radius = 350.f;
}

void EarthTower::initTextures()
{
	this->towerTextures.resize(4);

	if (!this->towerTextures[0].loadFromFile("../Assets/Image_Assets/Towers/EarthTower.png")) {
		std::cout << "Error loading wind tower texture 0" << std::endl;
	}
	else if (!this->towerTextures[1].loadFromFile("../Assets/Image_Assets/Towers/EarthTower.png")) {
		std::cout << "Error loading wind tower texture 1" << std::endl;
	}
	else if (!this->towerTextures[2].loadFromFile("../Assets/Image_Assets/Towers/EarthTower.png")) {
		std::cout << "Error loading wind tower texture 2" << std::endl;
	}
	else if (!this->towerTextures[3].loadFromFile("../Assets/Image_Assets/Towers/EarthTower.png")) {
		std::cout << "Error loading wind tower texture 3" << std::endl;
	}
}

void EarthTower::initSprites()
{

}

EarthTower::EarthTower()
{
	this->initVariables();
	this->initTextures();
	this->initSprites();
}


EarthTower::~EarthTower()
{
}
