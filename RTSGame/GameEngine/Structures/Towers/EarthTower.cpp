#include "EarthTower.h"


void EarthTower::initVariables()
{
	this->towerCost = 400;
	this->element = "Earth";
	this->elementId = 4;
	this->towerDamage = 100.f; // 0-4
	this->towerRange = 350.f;
	this->towerAttackSpeed = 2.f;
	this->bulletSpeed = 5.f;
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
