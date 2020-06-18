#include "VoidTower.h"


void VoidTower::initVariables()
{
	this->towerCost = 755;
	this->element = "Void";
	this->elementId = 8;
	this->towerDamage = 100.f; // 0-4
	this->towerRange = 1000.f;
	this->towerAttackSpeed = 9.5f;
	this->bulletSpeed = 15.f;
}

void VoidTower::initTextures()
{
	this->towerTextures.resize(4);

	if (!this->towerTextures[0].loadFromFile("../Assets/Image_Assets/Towers/VoidTower.png")) {
		std::cout << "Error loading wind tower texture 0" << std::endl;
	}
	else if (!this->towerTextures[1].loadFromFile("../Assets/Image_Assets/Towers/VoidTower.png")) {
		std::cout << "Error loading wind tower texture 1" << std::endl;
	}
	else if (!this->towerTextures[2].loadFromFile("../Assets/Image_Assets/Towers/VoidTower.png")) {
		std::cout << "Error loading wind tower texture 2" << std::endl;
	}
	else if (!this->towerTextures[3].loadFromFile("../Assets/Image_Assets/Towers/VoidTower.png")) {
		std::cout << "Error loading wind tower texture 3" << std::endl;
	}
}

void VoidTower::initSprites()
{

}

VoidTower::VoidTower()
{
	this->initVariables();
	this->initTextures();
	this->initSprites();
}


VoidTower::~VoidTower()
{
}
