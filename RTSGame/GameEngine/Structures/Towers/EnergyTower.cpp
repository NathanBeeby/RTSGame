#include "EnergyTower.h"


void EnergyTower::initVariables()
{
	this->towerCost = 350;
}

void EnergyTower::initTextures()
{
	this->towerTextures.resize(4);

	if (!this->towerTextures[0].loadFromFile("../Assets/Image_Assets/Towers/EnergyTower.png")) {
		std::cout << "Error loading wind tower texture 0" << std::endl;
	}
	else if (!this->towerTextures[1].loadFromFile("../Assets/Image_Assets/Towers/EnergyTower.png")) {
		std::cout << "Error loading wind tower texture 1" << std::endl;
	}
	else if (!this->towerTextures[2].loadFromFile("../Assets/Image_Assets/Towers/EnergyTower.png")) {
		std::cout << "Error loading wind tower texture 2" << std::endl;
	}
	else if (!this->towerTextures[3].loadFromFile("../Assets/Image_Assets/Towers/EnergyTower.png")) {
		std::cout << "Error loading wind tower texture 3" << std::endl;
	}
}

void EnergyTower::initSprites()
{

}

EnergyTower::EnergyTower()
{
	this->initVariables();
	this->initTextures();
	this->initSprites();
}


EnergyTower::~EnergyTower()
{
}
