#include "WindTower.h"

void WindTower::initVariables()
{
	this->towerSize.x = 200;
	this->towerSize.y = 200;
	this->towerNum = 0;
	this->windTower.resize(towerNum);
	this->towerCost = 300;
	this->windClicked = false;
	this->towerPos.x = -1;
	this->towerPos.y = -1;
}

void WindTower::initTextures()
{
	this->windTowerTexture.resize(4);

	if (!this->windTowerTexture[0].loadFromFile("../Assets/Image_Assets/Towers/WindTower.png")) {
		std::cout << "Error loading wind tower texture 0" << std::endl;
	} 
	else if (!this->windTowerTexture[1].loadFromFile("../Assets/Image_Assets/Towers/WindTower.png")) {
		std::cout << "Error loading wind tower texture 1" << std::endl;
	}
	else if (!this->windTowerTexture[2].loadFromFile("../Assets/Image_Assets/Towers/WindTower.png")) {
		std::cout << "Error loading wind tower texture 2" << std::endl;
	}
	else if (!this->windTowerTexture[3].loadFromFile("../Assets/Image_Assets/Towers/WindTower.png")) {
		std::cout << "Error loading wind tower texture 3" << std::endl;
	}
}

void WindTower::initSprites()
{
	for (int i = 0; i < windTower.size(); i++) {
		this->windTower[i].setSize(sf::Vector2f(towerSize.x, towerSize.y));
		this->windTower[i].setTexture(&windTowerTexture[0]);
	}
}

WindTower::WindTower()
{
	this->initVariables();
	this->initTextures();
	this->initSprites();
}


WindTower::~WindTower()
{
}

sf::Vector2f WindTower::towerClicked(sf::Vector2i clickPos)
{
	this->towerPos = sf::Vector2f(-1, -1);
	for (int i = 0; i < this->windTower.size(); i++) {
		if (clickPos.x >= this->windTower[i].getGlobalBounds().left && clickPos.x <= (this->windTower[i].getGlobalBounds().left + this->windTower[i].getGlobalBounds().width)) {
			if (clickPos.y >= this->windTower[i].getGlobalBounds().top && clickPos.y <= (this->windTower[i].getGlobalBounds().top + this->windTower[i].getGlobalBounds().height)) {
				this->towerPos = this->windTower[i].getPosition();
				this->windClicked = true;
			}
		}
	}

	return this->towerPos;
}

void WindTower::CreateTower(sf::Vector2i towerPos)
{
	this->towerNum++;
	this->windTower.resize(towerNum);
	this->wind.setSize(sf::Vector2f(200, 200));
	this->wind.setPosition(sf::Vector2f(towerPos.x, towerPos.y));

	this->wind.setTexture(&windTowerTexture[0]);

	this->windTower.push_back(this->wind);
	std::cout << "Wind Tower Created: " << std::endl;

}

void WindTower::SetTowerTexture(int towerId, std::string & towerTexture)
{
}

void WindTower::DeleteTower(int towerId)
{
}

void WindTower::deleteTowers()
{
}

void WindTower::update()
{
}

void WindTower::render(sf::RenderTarget & target)
{
	for (int i = 0; i < windTower.size(); i++) {
		target.draw(windTower[i]);
	}
}
