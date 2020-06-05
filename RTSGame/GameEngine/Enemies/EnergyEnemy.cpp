#include "EnergyEnemy.h"


// Private Variables / Initialization
void EnergyEnemy::initVariables()
{
	this->enemySize.x = 150;
	this->enemySize.y = 150;
	this->enemyNum = 0;
	this->energyEnemy.resize(enemyNum);
}

void EnergyEnemy::initTextures()
{
	this->energyEnemyTextures.resize(4);

	if (!this->energyEnemyTextures[0].loadFromFile("../Assets/Image_Assets/Enemies/Demon.png")) {
		std::cout << "Error loading wind tower texture 0" << std::endl;
	}
	else if (!this->energyEnemyTextures[1].loadFromFile("../Assets/Image_Assets/Enemies/Dragon.png")) {
		std::cout << "Error loading wind tower texture 1" << std::endl;
	}
	else if (!this->energyEnemyTextures[2].loadFromFile("../Assets/Image_Assets/Enemies/Demon.png")) {
		std::cout << "Error loading wind tower texture 2" << std::endl;
	}
	else if (!this->energyEnemyTextures[3].loadFromFile("../Assets/Image_Assets/Enemies/Dragon.png")) {
		std::cout << "Error loading wind tower texture 3" << std::endl;
	}
}

void EnergyEnemy::initSprites()
{
	for (int i = 0; i < energyEnemy.size(); i++) {
		this->energyEnemy[i].setSize(sf::Vector2f(enemySize.x, enemySize.y));
		this->energyEnemy[i].setTexture(&energyEnemyTextures[0]);
	}
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

void EnergyEnemy::CreateEnemy(sf::Vector2i enemyPos)
{
	this->enemyNum++;
	this->energyEnemy.resize(enemyNum);
	this->energy.setSize(sf::Vector2f(enemySize.x, enemySize.y));
	this->energy.setPosition(sf::Vector2f(enemyPos.x, enemyPos.y));

	this->energy.setTexture(&energyEnemyTextures[0]);

	this->energyEnemy.push_back(this->energy);

}

void EnergyEnemy::DeleteEnemy(int enemyId)
{
	this->energyEnemy.erase(energyEnemy.begin() + enemyId);
}

void EnergyEnemy::DeleteAllEnemies()
{
	for (int i = 0; i < energyEnemy.size(); i++) {
		this->energyEnemy.erase(energyEnemy.begin() + i);
	}
}

void EnergyEnemy::update()
{
	for (int i = 0; i < this->energyEnemy.size(); i++) {
		this->energyEnemy[i].move(1, 0);
	}
}

void EnergyEnemy::render(sf::RenderTarget & target)
{
	for (int i = 0; i < this->energyEnemy.size(); i++) {
		target.draw(this->energyEnemy[i]);
	}
}
