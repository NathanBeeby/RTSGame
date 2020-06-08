#include "ObservatoryTower.h"

void ObservatoryTower::initVariables()
{
	this->towerCost = 600;
	this->radius = 750.f;
}

void ObservatoryTower::initTextures()
{
	this->towerTextures.resize(4);

	if (!this->towerTextures[0].loadFromFile("../Assets/Image_Assets/Towers/Observatory.png")) {
		std::cout << "Error loading wind tower texture 0" << std::endl;
	}
	else if (!this->towerTextures[1].loadFromFile("../Assets/Image_Assets/Towers/Observatory.png")) {
		std::cout << "Error loading wind tower texture 1" << std::endl;
	}
	else if (!this->towerTextures[2].loadFromFile("../Assets/Image_Assets/Towers/Observatory.png")) {
		std::cout << "Error loading wind tower texture 2" << std::endl;
	}
	else if (!this->towerTextures[3].loadFromFile("../Assets/Image_Assets/Towers/Observatory.png")) {
		std::cout << "Error loading wind tower texture 3" << std::endl;
	}
}

void ObservatoryTower::initSprites()
{

}

ObservatoryTower::ObservatoryTower()
{
	this->initVariables();
	this->initTextures();
	this->initSprites();
}


ObservatoryTower::~ObservatoryTower()
{
}
