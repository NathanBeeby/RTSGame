#include "WaterEnemy.h"


// Private Variables / Initialization
void WaterEnemy::initVariables()
{
	this->enemySize.x = 150;
	this->enemySize.y = 150;
	this->enemyNum = 0;
	this->waterEnemy.resize(enemyNum);
}

void WaterEnemy::initTextures()
{
	this->waterEnemyTextures.resize(4);

	if (!this->waterEnemyTextures[0].loadFromFile("../Assets/Image_Assets/Enemies/Hydra.png")) {
		std::cout << "Error loading wind tower texture 0" << std::endl;
	}
	else if (!this->waterEnemyTextures[1].loadFromFile("../Assets/Image_Assets/Enemies/Mermaid.png")) {
		std::cout << "Error loading wind tower texture 1" << std::endl;
	}
	else if (!this->waterEnemyTextures[2].loadFromFile("../Assets/Image_Assets/Enemies/Hydra.png")) {
		std::cout << "Error loading wind tower texture 2" << std::endl;
	}
	else if (!this->waterEnemyTextures[3].loadFromFile("../Assets/Image_Assets/Enemies/Mermaid.png")) {
		std::cout << "Error loading wind tower texture 3" << std::endl;
	}
}

void WaterEnemy::initSprites()
{
	for (int i = 0; i < waterEnemy.size(); i++) {
		this->waterEnemy[i].setSize(sf::Vector2f(enemySize.x, enemySize.y));
		this->waterEnemy[i].setTexture(&waterEnemyTextures[0]);
	}
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

void WaterEnemy::CreateEnemy(sf::Vector2i enemyPos)
{
	this->enemyNum++;
	this->waterEnemy.resize(enemyNum);
	this->water.setSize(sf::Vector2f(enemySize.x, enemySize.y));
	this->water.setPosition(sf::Vector2f(enemyPos.x, enemyPos.y));

	this->water.setTexture(&waterEnemyTextures[0]);

	this->waterEnemy.push_back(this->water);
}

void WaterEnemy::DeleteEnemy(int enemyId)
{
	this->waterEnemy.erase(waterEnemy.begin() + enemyId);
}

void WaterEnemy::DeleteAllEnemies()
{
	for (int i = 0; i < waterEnemy.size(); i++) {
		this->waterEnemy.erase(waterEnemy.begin() + i);
	}
}

void WaterEnemy::update()
{
	for (int i = 0; i < this->waterEnemy.size(); i++) {
		this->waterEnemy[i].move(1, 0);
	}
}

void WaterEnemy::render(sf::RenderTarget & target)
{
	for (int i = 0; i < this->waterEnemy.size(); i++) {
		target.draw(this->waterEnemy[i]);
	}
}
