#include "WindEnemy.h"


// Private Variables / Initialization
void WindEnemy::initVariables()
{
	this->enemySize.x = 150;
	this->enemySize.y = 150;
	this->enemyNum = 0;
	this->windEnemy.resize(enemyNum);
}

void WindEnemy::initTextures()
{
	this->windEnemyTextures.resize(4);

	if (!this->windEnemyTextures[0].loadFromFile("../Assets/Image_Assets/Enemies/Demon.png")) {
		std::cout << "Error loading wind tower texture 0" << std::endl;
	}
	else if (!this->windEnemyTextures[1].loadFromFile("../Assets/Image_Assets/Enemies/Dragon.png")) {
		std::cout << "Error loading wind tower texture 1" << std::endl;
	}
	else if (!this->windEnemyTextures[2].loadFromFile("../Assets/Image_Assets/Enemies/Demon.png")) {
		std::cout << "Error loading wind tower texture 2" << std::endl;
	}
	else if (!this->windEnemyTextures[3].loadFromFile("../Assets/Image_Assets/Enemies/Dragon.png")) {
		std::cout << "Error loading wind tower texture 3" << std::endl;
	}
}

void WindEnemy::initSprites()
{
	for (int i = 0; i < windEnemy.size(); i++) {
		this->windEnemy[i].setSize(sf::Vector2f(enemySize.x, enemySize.y));
		this->windEnemy[i].setTexture(&windEnemyTextures[0]);
	}
}

// Constructor / Destructor
WindEnemy::WindEnemy()
{
	this->initVariables();
	this->initTextures();
	this->initSprites();
}


WindEnemy::~WindEnemy()
{
}

void WindEnemy::CreateEnemy(sf::Vector2i enemyPos)
{
	this->enemyNum++;
	this->windEnemy.resize(enemyNum);
	this->wind.setSize(sf::Vector2f(enemySize.x, enemySize.y));
	this->wind.setPosition(sf::Vector2f(enemyPos.x, enemyPos.y));

	this->wind.setTexture(&windEnemyTextures[0]);

	this->windEnemy.push_back(this->wind);

}

void WindEnemy::DeleteEnemy(int enemyId)
{
	this->windEnemy.erase(windEnemy.begin() + enemyId);
}

void WindEnemy::DeleteAllEnemies()
{
	for (int i = 0; i < windEnemy.size(); i++) {
		this->windEnemy.erase(windEnemy.begin() + i);
	}
}

void WindEnemy::update()
{
	for (int i = 0; i < this->windEnemy.size(); i++) {
		this->windEnemy[i].move(1, 0);
	}
}

void WindEnemy::render(sf::RenderTarget & target)
{
	for (int i = 0; i < this->windEnemy.size(); i++) {
		target.draw(this->windEnemy[i]);
	}
}
