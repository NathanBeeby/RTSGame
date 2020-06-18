#include "RegenTower.h"


void RegenTower::initVariables()
{
	this->towerCost = 550;
	this->element = "Void";
	this->elementId = 8;
	this->towerDamage = 100.f; // 0-4
	this->towerRange = 240.f;
	this->towerAttackSpeed = 1.f;
	this->bulletSpeed = 1.f;
}

void RegenTower::initTextures()
{
	this->towerTextures.resize(4);

	if (!this->towerTextures[0].loadFromFile("../Assets/Image_Assets/Towers/Regenerator.png")) {
		std::cout << "Error loading wind tower texture 0" << std::endl;
	}
	else if (!this->towerTextures[1].loadFromFile("../Assets/Image_Assets/Towers/Regenerator.png")) {
		std::cout << "Error loading wind tower texture 1" << std::endl;
	}
	else if (!this->towerTextures[2].loadFromFile("../Assets/Image_Assets/Towers/Regenerator.png")) {
		std::cout << "Error loading wind tower texture 2" << std::endl;
	}
	else if (!this->towerTextures[3].loadFromFile("../Assets/Image_Assets/Towers/Regenerator.png")) {
		std::cout << "Error loading wind tower texture 3" << std::endl;
	}
}

void RegenTower::initSprites()
{

}

RegenTower::RegenTower()
{
	this->initVariables();
	this->initTextures();
	this->initSprites();
}


RegenTower::~RegenTower()
{
}
