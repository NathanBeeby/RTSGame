#include "EarthEnemy.h"

// Private Variables / Initialization
void EarthEnemy::initVariables()
{
	this->enemySize.x = 150;
	this->enemySize.y = 150;
	this->enemyNum = 0;
	this->earthEnemy.resize(enemyNum);
}

void EarthEnemy::initTextures()
{
	this->earthEnemyTextures.resize(4);

	if (!this->earthEnemyTextures[0].loadFromFile("../Assets/Image_Assets/Enemies/Orc.png")) {
		std::cout << "Error loading wind tower texture 0" << std::endl;
	}
	else if (!this->earthEnemyTextures[1].loadFromFile("../Assets/Image_Assets/Enemies/Elf.png")) {
		std::cout << "Error loading wind tower texture 1" << std::endl;
	}
	else if (!this->earthEnemyTextures[2].loadFromFile("../Assets/Image_Assets/Enemies/Orc.png")) {
		std::cout << "Error loading wind tower texture 2" << std::endl;
	}
	else if (!this->earthEnemyTextures[3].loadFromFile("../Assets/Image_Assets/Enemies/Elf.png")) {
		std::cout << "Error loading wind tower texture 3" << std::endl;
	}
}

void EarthEnemy::initSprites()
{
	for (int i = 0; i < earthEnemy.size(); i++) {
		this->earthEnemy[i].setSize(sf::Vector2f(enemySize.x, enemySize.y));
		this->earthEnemy[i].setTexture(&earthEnemyTextures[0]);
	}
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

void EarthEnemy::CreateEnemy(sf::Vector2i enemyPos)
{
	this->enemyNum++;
	this->earthEnemy.resize(enemyNum);
	this->earth.setSize(sf::Vector2f(enemySize.x, enemySize.y));
	this->earth.setPosition(sf::Vector2f(enemyPos.x, enemyPos.y));

	this->earth.setTexture(&earthEnemyTextures[0]);

	this->earthEnemy.push_back(this->earth);
}

void EarthEnemy::DeleteEnemy(int enemyId)
{
	this->earthEnemy.erase(earthEnemy.begin() + enemyId);
}

void EarthEnemy::DeleteAllEnemies()
{
	for (int i = 0; i < earthEnemy.size(); i++) {
		this->earthEnemy.erase(earthEnemy.begin() + i);
	}
}

void EarthEnemy::update()
{
	for (int i = 0; i < this->earthEnemy.size(); i++) {
		this->earthEnemy[i].move(1, 0);
	}
}

void EarthEnemy::render(sf::RenderTarget & target)
{
	for (int i = 0; i < this->earthEnemy.size(); i++) {
		target.draw(this->earthEnemy[i]);
	}
}
