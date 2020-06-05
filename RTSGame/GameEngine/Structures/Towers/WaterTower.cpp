#include "WaterTower.h"



void WaterTower::initVariables()
{
	this->towerSize.x = 200;
	this->towerSize.y = 200;
	this->towerNum = 0;
	this->waterTower.resize(towerNum);
	this->towerCost = 300;
	this->waterClicked = false;
	this->towerPos.x = -1;
	this->towerPos.y = -1;
}

void WaterTower::initTextures()
{
	this->waterTowerTexture.resize(4);

	if (!this->waterTowerTexture[0].loadFromFile("../Assets/Image_Assets/Towers/WaterTower.png")) {
		std::cout << "Error loading wind tower texture 0" << std::endl;
	}
	else if (!this->waterTowerTexture[1].loadFromFile("../Assets/Image_Assets/Towers/WaterTower.png")) {
		std::cout << "Error loading wind tower texture 1" << std::endl;
	}
	else if (!this->waterTowerTexture[2].loadFromFile("../Assets/Image_Assets/Towers/WaterTower.png")) {
		std::cout << "Error loading wind tower texture 2" << std::endl;
	}
	else if (!this->waterTowerTexture[3].loadFromFile("../Assets/Image_Assets/Towers/WaterTower.png")) {
		std::cout << "Error loading wind tower texture 3" << std::endl;
	}
}

void WaterTower::initSprites()
{
	for (int i = 0; i < waterTower.size(); i++) {
		this->waterTower[i].setSize(sf::Vector2f(towerSize.x, towerSize.y));
		this->waterTower[i].setTexture(&waterTowerTexture[0]);
	}
}

WaterTower::WaterTower()
{
	this->initVariables();
	this->initTextures();
	this->initSprites();
}


WaterTower::~WaterTower()
{
}

sf::Vector2f WaterTower::towerClicked(sf::Vector2i clickPos)
{
	this->towerPos = sf::Vector2f(-1, -1);
	for (int i = 0; i < this->waterTower.size(); i++) {
		if (clickPos.x >= this->waterTower[i].getGlobalBounds().left && clickPos.x <= (this->waterTower[i].getGlobalBounds().left + this->waterTower[i].getGlobalBounds().width)) {
			if (clickPos.y >= this->waterTower[i].getGlobalBounds().top && clickPos.y <= (this->waterTower[i].getGlobalBounds().top + this->waterTower[i].getGlobalBounds().height)) {
				this->towerPos = this->waterTower[i].getPosition();
				this->waterClicked = true;
			}
		}
	}

	return this->towerPos;
}

void WaterTower::CreateTower(sf::Vector2i towerPos)
{
	this->towerNum++;
	this->waterTower.resize(towerNum);
	this->water.setSize(sf::Vector2f(200, 200));
	this->water.setPosition(sf::Vector2f(towerPos.x, towerPos.y));

	this->water.setTexture(&waterTowerTexture[0]);

	this->waterTower.push_back(this->water);
	std::cout << "Water Tower Created: " << std::endl;

}

void WaterTower::SetTowerTexture(int towerId, std::string & towerTexture)
{
}

void WaterTower::DeleteTower(int towerId)
{
}

void WaterTower::deleteTowers()
{
}

void WaterTower::update()
{
}

void WaterTower::render(sf::RenderTarget & target)
{
	for (int i = 0; i < waterTower.size(); i++) {
		target.draw(waterTower[i]);
	}
}
