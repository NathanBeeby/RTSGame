#include "FireTower.h"

void FireTower::initVariables()
{
	this->towerSize.x = 200;
	this->towerSize.y = 200;
	this->towerNum = 0;
	this->fireTower.resize(towerNum);
	this->towerCost = 300;
}

void FireTower::initTextures()
{
	this->fireTowerTexture.resize(4);

	if (!this->fireTowerTexture[0].loadFromFile("../Assets/Image_Assets/Towers/FireTower.png")) {
		std::cout << "Error loading wind tower texture 0" << std::endl;
	}
	else if (!this->fireTowerTexture[1].loadFromFile("../Assets/Image_Assets/Towers/FireTower.png")) {
		std::cout << "Error loading wind tower texture 1" << std::endl;
	}
	else if (!this->fireTowerTexture[2].loadFromFile("../Assets/Image_Assets/Towers/FireTower.png")) {
		std::cout << "Error loading wind tower texture 2" << std::endl;
	}
	else if (!this->fireTowerTexture[3].loadFromFile("../Assets/Image_Assets/Towers/FireTower.png")) {
		std::cout << "Error loading wind tower texture 3" << std::endl;
	}
}

void FireTower::initSprites()
{
	for (int i = 0; i < fireTower.size(); i++) {
		this->fireTower[i].setSize(sf::Vector2f(towerSize.x, towerSize.y));
		this->fireTower[i].setTexture(&fireTowerTexture[0]);
	}
}

FireTower::FireTower()
{
	this->initVariables();
	this->initTextures();
	this->initSprites();
}


FireTower::~FireTower()
{
}

void FireTower::CreateTower(sf::Vector2i towerPos)
{
	this->towerNum++;
	this->fireTower.resize(towerNum);
	this->fire.setSize(sf::Vector2f(200, 200));
	this->fire.setPosition(sf::Vector2f(towerPos.x, towerPos.y));

	this->fire.setTexture(&fireTowerTexture[0]);

	this->fireTower.push_back(this->fire);
	std::cout << "Fire Tower Created: " << std::endl;

}

void FireTower::SetTowerTexture(int towerId, std::string & towerTexture)
{
}

void FireTower::DeleteTower(int towerId)
{
	this->fireTower.erase(fireTower.begin() + towerId);
}

void FireTower::deleteTowers()
{
	for (int i = 0; i < this->fireTower.size(); i++) {
		this->fireTower.erase(fireTower.begin() + i);
	}
}

void FireTower::update()
{

}

void FireTower::render(sf::RenderTarget & target)
{
	for (int i = 0; i < this->fireTower.size(); i++) {
		target.draw(this->fireTower[i]);
	}
}
