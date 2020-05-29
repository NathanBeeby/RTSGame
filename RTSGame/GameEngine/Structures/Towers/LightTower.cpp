#include "LightTower.h"

void LightTower::initVariables()
{
	this->towerSize.x = 200;
	this->towerSize.y = 200;
	this->towerNum = 0;
	this->lightTower.resize(towerNum);
	this->towerCost = 300;
}

void LightTower::initTextures()
{
	this->lightTowerTexture.resize(4);

	if (!this->lightTowerTexture[0].loadFromFile("../Assets/Image_Assets/Towers/LightTower.png")) {
		std::cout << "Error loading wind tower texture 0" << std::endl;
	}
	else if (!this->lightTowerTexture[1].loadFromFile("../Assets/Image_Assets/Towers/LightTower.png")) {
		std::cout << "Error loading wind tower texture 1" << std::endl;
	}
	else if (!this->lightTowerTexture[2].loadFromFile("../Assets/Image_Assets/Towers/LightTower.png")) {
		std::cout << "Error loading wind tower texture 2" << std::endl;
	}
	else if (!this->lightTowerTexture[3].loadFromFile("../Assets/Image_Assets/Towers/LightTower.png")) {
		std::cout << "Error loading wind tower texture 3" << std::endl;
	}
}

void LightTower::initSprites()
{
	for (int i = 0; i < lightTower.size(); i++) {
		this->lightTower[i].setSize(sf::Vector2f(towerSize.x, towerSize.y));
		this->lightTower[i].setTexture(&lightTowerTexture[0]);
	}
}

LightTower::LightTower()
{
	this->initVariables();
	this->initTextures();
	this->initSprites();
}


LightTower::~LightTower()
{
}

void LightTower::CreateTower(sf::Vector2i towerPos)
{
	this->towerNum++;
	this->lightTower.resize(towerNum);
	this->light.setSize(sf::Vector2f(200, 200));
	this->light.setPosition(sf::Vector2f(towerPos.x, towerPos.y));

	this->light.setTexture(&lightTowerTexture[0]);

	this->lightTower.push_back(this->light);
	std::cout << "Wind Tower Created: " << std::endl;

}

void LightTower::SetTowerTexture(int towerId, std::string & towerTexture)
{
}

void LightTower::DeleteTower(int towerId)
{
}

void LightTower::update()
{
}

void LightTower::render(sf::RenderTarget & target)
{
	for (int i = 0; i < lightTower.size(); i++) {
		target.draw(lightTower[i]);
	}
}
