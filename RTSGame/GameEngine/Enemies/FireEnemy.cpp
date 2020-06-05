#include "FireEnemy.h"


// Private Variables / Initialization
void FireEnemy::initVariables()
{
	this->enemySize.x = 150;
	this->enemySize.y = 150;
	this->enemyNum = 0;
	this->fireEnemy.resize(enemyNum);
}

void FireEnemy::initTextures()
{
	this->fireEnemyTextures.resize(4);

	if (!this->fireEnemyTextures[0].loadFromFile("../Assets/Image_Assets/Enemies/Demon.png")) {
		std::cout << "Error loading wind tower texture 0" << std::endl;
	}
	else if (!this->fireEnemyTextures[1].loadFromFile("../Assets/Image_Assets/Enemies/Dragon.png")) {
		std::cout << "Error loading wind tower texture 1" << std::endl;
	}
	else if (!this->fireEnemyTextures[2].loadFromFile("../Assets/Image_Assets/Enemies/Demon.png")) {
		std::cout << "Error loading wind tower texture 2" << std::endl;
	}
	else if (!this->fireEnemyTextures[3].loadFromFile("../Assets/Image_Assets/Enemies/Dragon.png")) {
		std::cout << "Error loading wind tower texture 3" << std::endl;
	}
}

void FireEnemy::initSprites()
{
	for (int i = 0; i < fireEnemy.size(); i++) {
		this->fireEnemy[i].setSize(sf::Vector2f(enemySize.x, enemySize.y));
		this->fireEnemy[i].setTexture(&fireEnemyTextures[0]);
	}
}

// Constructor / Destructor
FireEnemy::FireEnemy()
{
	this->initVariables();
	this->initTextures();
	this->initSprites();
}


FireEnemy::~FireEnemy()
{
}

void FireEnemy::CreateEnemy(sf::Vector2i enemyPos)
{
	this->enemyNum++;
	this->fireEnemy.resize(enemyNum);
	this->fire.setSize(sf::Vector2f(enemySize.x, enemySize.y));
	this->fire.setPosition(sf::Vector2f(enemyPos.x, enemyPos.y));

	this->fire.setTexture(&fireEnemyTextures[0]);

	this->fireEnemy.push_back(this->fire);

}

void FireEnemy::DeleteEnemy(int enemyId)
{
	this->fireEnemy.erase(fireEnemy.begin() + enemyId);
}

void FireEnemy::DeleteAllEnemies()
{
	for (int i = 0; i < fireEnemy.size(); i++) {
		this->fireEnemy.erase(fireEnemy.begin() + i);
	}
}

void FireEnemy::update()
{
	for (int i = 0; i < this->fireEnemy.size(); i++) {
		this->fireEnemy[i].move(1, 0);
	}
}

void FireEnemy::render(sf::RenderTarget & target)
{
	for (int i = 0; i < this->fireEnemy.size(); i++) {
		target.draw(this->fireEnemy[i]);
	}
}
