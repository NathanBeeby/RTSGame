#include "FireTower.h"

void FireTower::initVariables()
{
	this->towerCost = 300;
	this->element = "Fire";
	this->elementId = 0;
	this->towerDamage = 100.f; // 0-4
	this->towerRange = 600.f;
	this->towerAttackSpeed = 20.f;
}

void FireTower::initTextures()
{
	this->towerTextures.resize(4);

	if (!this->towerTextures[0].loadFromFile("../Assets/Image_Assets/Towers/FireTower.png")) {
		std::cout << "Error loading wind tower texture 0" << std::endl;
	}
	else if (!this->towerTextures[1].loadFromFile("../Assets/Image_Assets/Towers/FireTower.png")) {
		std::cout << "Error loading wind tower texture 1" << std::endl;
	}
	else if (!this->towerTextures[2].loadFromFile("../Assets/Image_Assets/Towers/FireTower.png")) {
		std::cout << "Error loading wind tower texture 2" << std::endl;
	}
	else if (!this->towerTextures[3].loadFromFile("../Assets/Image_Assets/Towers/FireTower.png")) {
		std::cout << "Error loading wind tower texture 3" << std::endl;
	}
}

void FireTower::initSprites()
{

}

FireTower::FireTower()
{
	this->initVariables();
	this->initTextures();
	this->initSprites();
}


FireTower::~FireTower()
{
}

