#include "DarkTower.h"

void DarkTower::initVariables()
{
	this->towerSize.x = 200;
	this->towerSize.y = 200;
	this->towerNum = 0;
	this->darkTower.resize(towerNum);
	this->towerCost = 300;
}

void DarkTower::initTextures()
{
	this->darkTowerTexture.resize(4);

	if (!this->darkTowerTexture[0].loadFromFile("../Assets/Image_Assets/Towers/DarkTower.png")) {
		std::cout << "Error loading wind tower texture 0" << std::endl;
	}
	else if (!this->darkTowerTexture[1].loadFromFile("../Assets/Image_Assets/Towers/DarkTower.png")) {
		std::cout << "Error loading wind tower texture 1" << std::endl;
	}
	else if (!this->darkTowerTexture[2].loadFromFile("../Assets/Image_Assets/Towers/DarkTower.png")) {
		std::cout << "Error loading wind tower texture 2" << std::endl;
	}
	else if (!this->darkTowerTexture[3].loadFromFile("../Assets/Image_Assets/Towers/DarkTower.png")) {
		std::cout << "Error loading wind tower texture 3" << std::endl;
	}
}

void DarkTower::initSprites()
{
	for (int i = 0; i < darkTower.size(); i++) {
		this->darkTower[i].setSize(sf::Vector2f(towerSize.x, towerSize.y));
		this->darkTower[i].setTexture(&darkTowerTexture[0]);
	}
}

DarkTower::DarkTower()
{
	this->initVariables();
	this->initTextures();
	this->initSprites();
}


DarkTower::~DarkTower()
{
}

void DarkTower::CreateTower(sf::Vector2i towerPos)
{
	this->towerNum++;
	this->darkTower.resize(towerNum);
	this->dark.setSize(sf::Vector2f(200, 200));
	this->dark.setPosition(sf::Vector2f(towerPos.x, towerPos.y));

	this->dark.setTexture(&darkTowerTexture[0]);

	this->darkTower.push_back(this->dark);
	std::cout << "Dark Tower Created: " << std::endl;

}

void DarkTower::SetTowerTexture(int towerId, std::string & towerTexture)
{
}

void DarkTower::DeleteTower(int towerId)
{
}

void DarkTower::update()
{
}

void DarkTower::render(sf::RenderTarget & target)
{
	for (int i = 0; i < darkTower.size(); i++) {
		target.draw(darkTower[i]);
	}
}
