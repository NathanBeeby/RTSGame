#include "ManaAmplifierTower.h"

void ManaAmplifierTower::initVariables()
{
	this->towerCost = 600;
}

void ManaAmplifierTower::initTextures()
{
	this->towerTextures.resize(4);

	if (!this->towerTextures[0].loadFromFile("../Assets/Image_Assets/Towers/ManaAmplifier.png")) {
		std::cout << "Error loading wind tower texture 0" << std::endl;
	}
	else if (!this->towerTextures[1].loadFromFile("../Assets/Image_Assets/Towers/ManaAmplifier.png")) {
		std::cout << "Error loading wind tower texture 1" << std::endl;
	}
	else if (!this->towerTextures[2].loadFromFile("../Assets/Image_Assets/Towers/ManaAmplifier.png")) {
		std::cout << "Error loading wind tower texture 2" << std::endl;
	}
	else if (!this->towerTextures[3].loadFromFile("../Assets/Image_Assets/Towers/ManaAmplifier.png")) {
		std::cout << "Error loading wind tower texture 3" << std::endl;
	}
}

void ManaAmplifierTower::initSprites()
{

}

ManaAmplifierTower::ManaAmplifierTower()
{
	this->initVariables();
	this->initTextures();
	this->initSprites();
}


ManaAmplifierTower::~ManaAmplifierTower()
{
}