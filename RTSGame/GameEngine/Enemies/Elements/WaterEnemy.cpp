#include "WaterEnemy.h"


// Private Variables / Initialization
void WaterEnemy::initVariables()
{

}

void WaterEnemy::initTextures()
{
	this->enemyTextures.resize(4);

	if (!this->enemyTextures[0].loadFromFile("../Assets/Image_Assets/Enemies/Hydra.png")) {
		std::cout << "Error loading wind tower texture 0" << std::endl;
	}
	else if (!this->enemyTextures[1].loadFromFile("../Assets/Image_Assets/Enemies/Mermaid.png")) {
		std::cout << "Error loading wind tower texture 1" << std::endl;
	}
	else if (!this->enemyTextures[2].loadFromFile("../Assets/Image_Assets/Enemies/Hydra.png")) {
		std::cout << "Error loading wind tower texture 2" << std::endl;
	}
	else if (!this->enemyTextures[3].loadFromFile("../Assets/Image_Assets/Enemies/Mermaid.png")) {
		std::cout << "Error loading wind tower texture 3" << std::endl;
	}
}

void WaterEnemy::initSprites()
{

}

// Constructor / Destructor
WaterEnemy::WaterEnemy()
{
	this->initVariables();
	this->initTextures();
	this->initSprites();
}


WaterEnemy::~WaterEnemy()
{
}
