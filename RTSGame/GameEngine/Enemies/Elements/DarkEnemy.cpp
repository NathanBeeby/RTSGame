#include "DarkEnemy.h"

// Private Variables / Initialization
void DarkEnemy::initVariables()
{

}

void DarkEnemy::initTextures()
{
	this->enemyTextures.resize(4);

	if (!this->enemyTextures[0].loadFromFile("../Assets/Image_Assets/Enemies/Vampire.png")) {
		std::cout << "Error loading wind tower texture 0" << std::endl;
	}
	else if (!this->enemyTextures[1].loadFromFile("../Assets/Image_Assets/Enemies/Werewolf.png")) {
		std::cout << "Error loading wind tower texture 1" << std::endl;
	}
	else if (!this->enemyTextures[2].loadFromFile("../Assets/Image_Assets/Enemies/Vampire.png")) {
		std::cout << "Error loading wind tower texture 2" << std::endl;
	}
	else if (!this->enemyTextures[3].loadFromFile("../Assets/Image_Assets/Enemies/Werewolf.png")) {
		std::cout << "Error loading wind tower texture 3" << std::endl;
	}
}

void DarkEnemy::initSprites()
{
	
}

// Constructor / Destructor
DarkEnemy::DarkEnemy()
{
	this->initVariables();
	this->initTextures();
	this->initSprites();
}


DarkEnemy::~DarkEnemy()
{
}
