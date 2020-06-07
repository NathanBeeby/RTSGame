#include "IceEnemy.h"


// Private Variables / Initialization
void IceEnemy::initVariables()
{

}

void IceEnemy::initTextures()
{
	this->enemyTextures.resize(4);

	if (!this->enemyTextures[0].loadFromFile("../Assets/Image_Assets/Enemies/Yeti.png")) {
		std::cout << "Error loading wind tower texture 0" << std::endl;
	}
	else if (!this->enemyTextures[1].loadFromFile("../Assets/Image_Assets/Enemies/IceWraith.png")) {
		std::cout << "Error loading wind tower texture 1" << std::endl;
	}
	else if (!this->enemyTextures[2].loadFromFile("../Assets/Image_Assets/Enemies/Yeti.png")) {
		std::cout << "Error loading wind tower texture 2" << std::endl;
	}
	else if (!this->enemyTextures[3].loadFromFile("../Assets/Image_Assets/Enemies/IceWraith.png")) {
		std::cout << "Error loading wind tower texture 3" << std::endl;
	}
}

void IceEnemy::initSprites()
{
	
}

// Constructor / Destructor
IceEnemy::IceEnemy()
{
	this->initVariables();
	this->initTextures();
	this->initSprites();
}


IceEnemy::~IceEnemy()
{
}
