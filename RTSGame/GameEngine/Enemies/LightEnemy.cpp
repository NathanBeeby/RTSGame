#include "LightEnemy.h"


// Private Variables / Initialization
void LightEnemy::initVariables()
{
	this->enemySize.x = 150;
	this->enemySize.y = 150;
	this->enemyNum = 0;
	this->lightEnemy.resize(enemyNum);
}

void LightEnemy::initTextures()
{
	this->lightEnemyTextures.resize(4);

	if (!this->lightEnemyTextures[0].loadFromFile("../Assets/Image_Assets/Enemies/Kitsune.png")) {
		std::cout << "Error loading wind tower texture 0" << std::endl;
	}
	else if (!this->lightEnemyTextures[1].loadFromFile("../Assets/Image_Assets/Enemies/Kitsune.png")) {
		std::cout << "Error loading wind tower texture 1" << std::endl;
	}
	else if (!this->lightEnemyTextures[2].loadFromFile("../Assets/Image_Assets/Enemies/Kitsune.png")) {
		std::cout << "Error loading wind tower texture 2" << std::endl;
	}
	else if (!this->lightEnemyTextures[3].loadFromFile("../Assets/Image_Assets/Enemies/Kitsune.png")) {
		std::cout << "Error loading wind tower texture 3" << std::endl;
	}
}

void LightEnemy::initSprites()
{
	for (int i = 0; i < lightEnemy.size(); i++) {
		this->lightEnemy[i].setSize(sf::Vector2f(enemySize.x, enemySize.y));
		this->lightEnemy[i].setTexture(&lightEnemyTextures[0]);
	}
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

void LightEnemy::CreateEnemy(sf::Vector2i enemyPos)
{
	this->enemyNum++;
	this->lightEnemy.resize(enemyNum);
	this->light.setSize(sf::Vector2f(enemySize.x, enemySize.y));
	this->light.setPosition(sf::Vector2f(enemyPos.x, enemyPos.y));

	this->light.setTexture(&lightEnemyTextures[0]);

	this->lightEnemy.push_back(this->light);
}

void LightEnemy::DeleteEnemy(int enemyId)
{
	this->lightEnemy.erase(lightEnemy.begin() + enemyId);
}

void LightEnemy::DeleteAllEnemies()
{
	for (int i = 0; i < lightEnemy.size(); i++) {
		this->lightEnemy.erase(lightEnemy.begin() + i);
	}
}

void LightEnemy::update()
{
	for (int i = 0; i < this->lightEnemy.size(); i++) {
		this->lightEnemy[i].move(1, 0);
	}
}

void LightEnemy::render(sf::RenderTarget & target)
{
	for (int i = 0; i < this->lightEnemy.size(); i++) {
		target.draw(this->lightEnemy[i]);
	}
}
