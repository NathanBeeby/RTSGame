#include "EarthEnemy.h"

// Private Variables / Initialization
void EarthEnemy::initVariables()
{
}

void EarthEnemy::initTextures()
{
	this->enemyTextures.resize(4);

	if (!this->enemyTextures[0].loadFromFile("../Assets/Image_Assets/Enemies/Orc.png")) {
		std::cout << "Error loading wind tower texture 0" << std::endl;
	}
	else if (!this->enemyTextures[1].loadFromFile("../Assets/Image_Assets/Enemies/Elf.png")) {
		std::cout << "Error loading wind tower texture 1" << std::endl;
	}
	else if (!this->enemyTextures[2].loadFromFile("../Assets/Image_Assets/Enemies/Orc.png")) {
		std::cout << "Error loading wind tower texture 2" << std::endl;
	}
	else if (!this->enemyTextures[3].loadFromFile("../Assets/Image_Assets/Enemies/Elf.png")) {
		std::cout << "Error loading wind tower texture 3" << std::endl;
	}
}

void EarthEnemy::initSprites()
{

}

// Constructor / Destructor
EarthEnemy::EarthEnemy()
{
	this->initVariables();
	this->initTextures();
	this->initSprites();
}


EarthEnemy::~EarthEnemy()
{
}

