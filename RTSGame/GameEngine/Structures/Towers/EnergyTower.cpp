#include "EnergyTower.h"


void EnergyTower::initVariables()
{
	this->towerSize.x = 200;
	this->towerSize.y = 200;
	this->towerNum = 0;
	this->energyTower.resize(towerNum);
	this->towerCost = 300;
}

void EnergyTower::initTextures()
{
	this->energyTowerTexture.resize(4);

	if (!this->energyTowerTexture[0].loadFromFile("../Assets/Image_Assets/Towers/EnergyTower.png")) {
		std::cout << "Error loading wind tower texture 0" << std::endl;
	}
	else if (!this->energyTowerTexture[1].loadFromFile("../Assets/Image_Assets/Towers/EnergyTower.png")) {
		std::cout << "Error loading wind tower texture 1" << std::endl;
	}
	else if (!this->energyTowerTexture[2].loadFromFile("../Assets/Image_Assets/Towers/EnergyTower.png")) {
		std::cout << "Error loading wind tower texture 2" << std::endl;
	}
	else if (!this->energyTowerTexture[3].loadFromFile("../Assets/Image_Assets/Towers/EnergyTower.png")) {
		std::cout << "Error loading wind tower texture 3" << std::endl;
	}
}

void EnergyTower::initSprites()
{
	for (int i = 0; i < energyTower.size(); i++) {
		this->energyTower[i].setSize(sf::Vector2f(towerSize.x, towerSize.y));
		this->energyTower[i].setTexture(&energyTowerTexture[0]);
	}
}

EnergyTower::EnergyTower()
{
	this->initVariables();
	this->initTextures();
	this->initSprites();
}


EnergyTower::~EnergyTower()
{
}

void EnergyTower::CreateTower(sf::Vector2i towerPos)
{
	this->towerNum++;
	this->energyTower.resize(towerNum);
	this->energy.setSize(sf::Vector2f(200, 200));
	this->energy.setPosition(sf::Vector2f(towerPos.x, towerPos.y));

	this->energy.setTexture(&energyTowerTexture[0]);

	this->energyTower.push_back(this->energy);
	std::cout << "Energy Tower Created: " << std::endl;

}

void EnergyTower::SetTowerTexture(int towerId, std::string & towerTexture)
{
}

void EnergyTower::DeleteTower(int towerId)
{
}

void EnergyTower::update()
{
}

void EnergyTower::render(sf::RenderTarget & target)
{
	for (int i = 0; i < energyTower.size(); i++) {
		target.draw(energyTower[i]);
	}
}
