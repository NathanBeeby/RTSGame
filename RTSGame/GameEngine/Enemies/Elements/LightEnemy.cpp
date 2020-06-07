#include "LightEnemy.h"


// Private Variables / Initialization
void LightEnemy::initVariables()
{

}

void LightEnemy::initTextures()
{
	this->enemyTextures.resize(4);

	if (!this->enemyTextures[0].loadFromFile("../Assets/Image_Assets/Enemies/Kitsune.png")) {
		std::cout << "Error loading wind tower texture 0" << std::endl;
	}
	else if (!this->enemyTextures[1].loadFromFile("../Assets/Image_Assets/Enemies/Kitsune.png")) {
		std::cout << "Error loading wind tower texture 1" << std::endl;
	}
	else if (!this->enemyTextures[2].loadFromFile("../Assets/Image_Assets/Enemies/Kitsune.png")) {
		std::cout << "Error loading wind tower texture 2" << std::endl;
	}
	else if (!this->enemyTextures[3].loadFromFile("../Assets/Image_Assets/Enemies/Kitsune.png")) {
		std::cout << "Error loading wind tower texture 3" << std::endl;
	}
}

void LightEnemy::initSprites()
{
	
}

// Constructor / Destructor
LightEnemy::LightEnemy()
{
	this->initVariables();
	this->initTextures();
	this->initSprites();
}


LightEnemy::~LightEnemy()
{
}
