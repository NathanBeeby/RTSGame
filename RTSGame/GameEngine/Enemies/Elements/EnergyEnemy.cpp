#include "EnergyEnemy.h"


// Private Variables / Initialization
void EnergyEnemy::initVariables()
{

}

void EnergyEnemy::initTextures()
{
	this->enemyTextures.resize(4);

	if (!this->enemyTextures[0].loadFromFile("../Assets/Image_Assets/Enemies/Demon.png")) {
		std::cout << "Error loading wind tower texture 0" << std::endl;
	}
	else if (!this->enemyTextures[1].loadFromFile("../Assets/Image_Assets/Enemies/Dragon.png")) {
		std::cout << "Error loading wind tower texture 1" << std::endl;
	}
	else if (!this->enemyTextures[2].loadFromFile("../Assets/Image_Assets/Enemies/Demon.png")) {
		std::cout << "Error loading wind tower texture 2" << std::endl;
	}
	else if (!this->enemyTextures[3].loadFromFile("../Assets/Image_Assets/Enemies/Dragon.png")) {
		std::cout << "Error loading wind tower texture 3" << std::endl;
	}
}

void EnergyEnemy::initSprites()
{
	
}

// Constructor / Destructor
EnergyEnemy::EnergyEnemy()
{
	this->initVariables();
	this->initTextures();
	this->initSprites();
}


EnergyEnemy::~EnergyEnemy()
{
}

