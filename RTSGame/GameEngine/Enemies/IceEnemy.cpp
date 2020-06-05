#include "IceEnemy.h"


// Private Variables / Initialization
void IceEnemy::initVariables()
{
	this->enemySize.x = 150;
	this->enemySize.y = 150;
	this->enemyNum = 0;
	this->iceEnemy.resize(enemyNum);
}

void IceEnemy::initTextures()
{
	this->iceEnemyTextures.resize(4);

	if (!this->iceEnemyTextures[0].loadFromFile("../Assets/Image_Assets/Enemies/Yeti.png")) {
		std::cout << "Error loading wind tower texture 0" << std::endl;
	}
	else if (!this->iceEnemyTextures[1].loadFromFile("../Assets/Image_Assets/Enemies/IceWraith.png")) {
		std::cout << "Error loading wind tower texture 1" << std::endl;
	}
	else if (!this->iceEnemyTextures[2].loadFromFile("../Assets/Image_Assets/Enemies/Yeti.png")) {
		std::cout << "Error loading wind tower texture 2" << std::endl;
	}
	else if (!this->iceEnemyTextures[3].loadFromFile("../Assets/Image_Assets/Enemies/IceWraith.png")) {
		std::cout << "Error loading wind tower texture 3" << std::endl;
	}
}

void IceEnemy::initSprites()
{
	for (int i = 0; i < iceEnemy.size(); i++) {
		this->iceEnemy[i].setSize(sf::Vector2f(enemySize.x, enemySize.y));
		this->iceEnemy[i].setTexture(&iceEnemyTextures[0]);
	}
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

void IceEnemy::CreateEnemy(sf::Vector2i enemyPos)
{
	this->enemyNum++;
	this->iceEnemy.resize(enemyNum);
	this->ice.setSize(sf::Vector2f(enemySize.x, enemySize.y));
	this->ice.setPosition(sf::Vector2f(enemyPos.x, enemyPos.y));

	this->ice.setTexture(&iceEnemyTextures[0]);

	this->iceEnemy.push_back(this->ice);
}

void IceEnemy::DeleteEnemy(int enemyId)
{
	this->iceEnemy.erase(iceEnemy.begin() + enemyId);
}

void IceEnemy::DeleteAllEnemies()
{
	for (int i = 0; i < iceEnemy.size(); i++) {
		this->iceEnemy.erase(iceEnemy.begin() + i);
	}
}

void IceEnemy::update()
{
	for (int i = 0; i < this->iceEnemy.size(); i++) {
		this->iceEnemy[i].move(1, 0);
	}
}

void IceEnemy::render(sf::RenderTarget & target)
{
	for (int i = 0; i < this->iceEnemy.size(); i++) {
		target.draw(this->iceEnemy[i]);
	}
}
