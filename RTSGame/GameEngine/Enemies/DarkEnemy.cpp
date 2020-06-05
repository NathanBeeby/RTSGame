#include "DarkEnemy.h"

// Private Variables / Initialization
void DarkEnemy::initVariables()
{
	this->enemySize.x = 150;
	this->enemySize.y = 150;
	this->enemyNum = 0;
	this->darkEnemy.resize(enemyNum);
}

void DarkEnemy::initTextures()
{
	this->darkEnemyTextures.resize(4);

	if (!this->darkEnemyTextures[0].loadFromFile("../Assets/Image_Assets/Enemies/Vampire.png")) {
		std::cout << "Error loading wind tower texture 0" << std::endl;
	}
	else if (!this->darkEnemyTextures[1].loadFromFile("../Assets/Image_Assets/Enemies/Werewolf.png")) {
		std::cout << "Error loading wind tower texture 1" << std::endl;
	}
	else if (!this->darkEnemyTextures[2].loadFromFile("../Assets/Image_Assets/Enemies/Vampire.png")) {
		std::cout << "Error loading wind tower texture 2" << std::endl;
	}
	else if (!this->darkEnemyTextures[3].loadFromFile("../Assets/Image_Assets/Enemies/Werewolf.png")) {
		std::cout << "Error loading wind tower texture 3" << std::endl;
	}
}

void DarkEnemy::initSprites()
{
	for (int i = 0; i < darkEnemy.size(); i++) {
		this->darkEnemy[i].setSize(sf::Vector2f(enemySize.x, enemySize.y));
		this->darkEnemy[i].setTexture(&darkEnemyTextures[0]);
	}
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

void DarkEnemy::CreateEnemy(sf::Vector2i enemyPos)
{
	this->enemyNum++;
	this->darkEnemy.resize(enemyNum);
	this->dark.setSize(sf::Vector2f(enemySize.x, enemySize.y));
	this->dark.setPosition(sf::Vector2f(enemyPos.x, enemyPos.y));

	this->dark.setTexture(&darkEnemyTextures[0]);

	this->darkEnemy.push_back(this->dark);
}

void DarkEnemy::DeleteEnemy(int enemyId)
{
	this->darkEnemy.erase(darkEnemy.begin() + enemyId);
}

void DarkEnemy::DeleteAllEnemies()
{
	for (int i = 0; i < darkEnemy.size(); i++) {
		this->darkEnemy.erase(darkEnemy.begin() + i);
	}
}

void DarkEnemy::update()
{
	for (int i = 0; i < this->darkEnemy.size(); i++) {
		this->darkEnemy[i].move(1, 0);
	}
}

void DarkEnemy::render(sf::RenderTarget & target)
{
	for (int i = 0; i < this->darkEnemy.size(); i++) {
		target.draw(this->darkEnemy[i]);
	}
}
