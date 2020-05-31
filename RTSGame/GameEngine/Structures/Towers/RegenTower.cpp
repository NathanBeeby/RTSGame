#include "RegenTower.h"


void RegenTower::initVariables()
{
	this->towerSize.x = 200;
	this->towerSize.y = 200;
	this->towerNum = 0;
	this->regenTower.resize(towerNum);
	this->towerCost = 300;
}

void RegenTower::initTextures()
{
	this->regenTowerTexture.resize(4);

	if (!this->regenTowerTexture[0].loadFromFile("../Assets/Image_Assets/Towers/Regenerator.png")) {
		std::cout << "Error loading wind tower texture 0" << std::endl;
	}
	else if (!this->regenTowerTexture[1].loadFromFile("../Assets/Image_Assets/Towers/Regenerator.png")) {
		std::cout << "Error loading wind tower texture 1" << std::endl;
	}
	else if (!this->regenTowerTexture[2].loadFromFile("../Assets/Image_Assets/Towers/Regenerator.png")) {
		std::cout << "Error loading wind tower texture 2" << std::endl;
	}
	else if (!this->regenTowerTexture[3].loadFromFile("../Assets/Image_Assets/Towers/Regenerator.png")) {
		std::cout << "Error loading wind tower texture 3" << std::endl;
	}
}

void RegenTower::initSprites()
{
	for (int i = 0; i < regenTower.size(); i++) {
		this->regenTower[i].setSize(sf::Vector2f(towerSize.x, towerSize.y));
		this->regenTower[i].setTexture(&regenTowerTexture[0]);
	}
}

RegenTower::RegenTower()
{
	this->initVariables();
	this->initTextures();
	this->initSprites();
}


RegenTower::~RegenTower()
{
}

void RegenTower::CreateTower(sf::Vector2i towerPos)
{
	this->towerNum++;
	this->regenTower.resize(towerNum);
	this->regen.setSize(sf::Vector2f(200, 200));
	this->regen.setPosition(sf::Vector2f(towerPos.x, towerPos.y));

	this->regen.setTexture(&regenTowerTexture[0]);

	this->regenTower.push_back(this->regen);
	std::cout << "Regen Tower Created: " << std::endl;

}

void RegenTower::SetTowerTexture(int towerId, std::string & towerTexture)
{
}

void RegenTower::DeleteTower(int towerId)
{
}

void RegenTower::deleteTowers()
{
}

void RegenTower::update()
{
}

void RegenTower::render(sf::RenderTarget & target)
{
	for (int i = 0; i < regenTower.size(); i++) {
		target.draw(regenTower[i]);
	}
}
