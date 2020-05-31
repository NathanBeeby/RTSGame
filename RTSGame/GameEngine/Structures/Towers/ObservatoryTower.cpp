#include "ObservatoryTower.h"

void ObservatoryTower::initVariables()
{
	this->towerSize.x = 200;
	this->towerSize.y = 200;
	this->towerNum = 0;
	this->observatoryTower.resize(towerNum);
	this->towerCost = 300;
}

void ObservatoryTower::initTextures()
{
	this->observatoryTowerTexture.resize(4);

	if (!this->observatoryTowerTexture[0].loadFromFile("../Assets/Image_Assets/Towers/Observatory.png")) {
		std::cout << "Error loading wind tower texture 0" << std::endl;
	}
	else if (!this->observatoryTowerTexture[1].loadFromFile("../Assets/Image_Assets/Towers/Observatory.png")) {
		std::cout << "Error loading wind tower texture 1" << std::endl;
	}
	else if (!this->observatoryTowerTexture[2].loadFromFile("../Assets/Image_Assets/Towers/Observatory.png")) {
		std::cout << "Error loading wind tower texture 2" << std::endl;
	}
	else if (!this->observatoryTowerTexture[3].loadFromFile("../Assets/Image_Assets/Towers/Observatory.png")) {
		std::cout << "Error loading wind tower texture 3" << std::endl;
	}
}

void ObservatoryTower::initSprites()
{
	for (int i = 0; i < observatoryTower.size(); i++) {
		this->observatoryTower[i].setSize(sf::Vector2f(towerSize.x, towerSize.y));
		this->observatoryTower[i].setTexture(&observatoryTowerTexture[0]);
	}
}

ObservatoryTower::ObservatoryTower()
{
	this->initVariables();
	this->initTextures();
	this->initSprites();
}


ObservatoryTower::~ObservatoryTower()
{
}

void ObservatoryTower::CreateTower(sf::Vector2i towerPos)
{
	this->towerNum++;
	this->observatoryTower.resize(towerNum);
	this->observatory.setSize(sf::Vector2f(200, 200));
	this->observatory.setPosition(sf::Vector2f(towerPos.x, towerPos.y));

	this->observatory.setTexture(&observatoryTowerTexture[0]);

	this->observatoryTower.push_back(this->observatory);
	std::cout << "Observatory Tower Created: " << std::endl;

}

void ObservatoryTower::SetTowerTexture(int towerId, std::string & towerTexture)
{
}

void ObservatoryTower::DeleteTower(int towerId)
{
}

void ObservatoryTower::deleteTowers()
{
}

void ObservatoryTower::update()
{
}

void ObservatoryTower::render(sf::RenderTarget & target)
{
	for (int i = 0; i < observatoryTower.size(); i++) {
		target.draw(observatoryTower[i]);
	}
}
