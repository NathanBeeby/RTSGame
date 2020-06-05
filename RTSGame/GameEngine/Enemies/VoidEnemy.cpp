#include "VoidEnemy.h"


// Private Variables / Initialization
void VoidEnemy::initVariables()
{
	this->enemySize.x = 150;
	this->enemySize.y = 150;
	this->enemyNum = 0;
	this->voidEnemy.resize(enemyNum);
}

void VoidEnemy::initTextures()
{
	this->voidEnemyTextures.resize(4);

	if (!this->voidEnemyTextures[0].loadFromFile("../Assets/Image_Assets/Enemies/Demon.png")) {
		std::cout << "Error loading wind tower texture 0" << std::endl;
	}
	else if (!this->voidEnemyTextures[1].loadFromFile("../Assets/Image_Assets/Enemies/Dragon.png")) {
		std::cout << "Error loading wind tower texture 1" << std::endl;
	}
	else if (!this->voidEnemyTextures[2].loadFromFile("../Assets/Image_Assets/Enemies/Demon.png")) {
		std::cout << "Error loading wind tower texture 2" << std::endl;
	}
	else if (!this->voidEnemyTextures[3].loadFromFile("../Assets/Image_Assets/Enemies/Dragon.png")) {
		std::cout << "Error loading wind tower texture 3" << std::endl;
	}
}

void VoidEnemy::initSprites()
{
	for (int i = 0; i < voidEnemy.size(); i++) {
		this->voidEnemy[i].setSize(sf::Vector2f(enemySize.x, enemySize.y));
		this->voidEnemy[i].setTexture(&voidEnemyTextures[0]);
	}
}

// Constructor / Destructor
VoidEnemy::VoidEnemy()
{
	this->initVariables();
	this->initTextures();
	this->initSprites();
}


VoidEnemy::~VoidEnemy()
{
}

void VoidEnemy::CreateEnemy(sf::Vector2i enemyPos)
{
	this->enemyNum++;
	this->voidEnemy.resize(enemyNum);
	this->voidEnem.setSize(sf::Vector2f(enemySize.x, enemySize.y));
	this->voidEnem.setPosition(sf::Vector2f(enemyPos.x, enemyPos.y));

	this->voidEnem.setTexture(&voidEnemyTextures[0]);

	this->voidEnemy.push_back(this->voidEnem);
}

void VoidEnemy::DeleteEnemy(int enemyId)
{
	this->voidEnemy.erase(voidEnemy.begin() + enemyId);
}

void VoidEnemy::DeleteAllEnemies()
{
	for (int i = 0; i < voidEnemy.size(); i++) {
		this->voidEnemy.erase(voidEnemy.begin() + i);
	}
}

void VoidEnemy::update()
{
	for (int i = 0; i < this->voidEnemy.size(); i++) {
		this->voidEnemy[i].move(1, 0);
	}
}

void VoidEnemy::render(sf::RenderTarget & target)
{
	for (int i = 0; i < this->voidEnemy.size(); i++) {
		target.draw(this->voidEnemy[i]);
	}
}
