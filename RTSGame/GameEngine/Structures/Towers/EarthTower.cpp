#include "EarthTower.h"


void EarthTower::initVariables()
{
	this->towerSize.x = 200;
	this->towerSize.y = 200;
	this->towerNum = 0;
	this->earthTower.resize(towerNum);
	this->towerCost = 300;
	this->earthClicked = false;
	this->towerPos.x = -1;
	this->towerPos.y = -1;
}

void EarthTower::initTextures()
{
	this->earthTowerTexture.resize(4);

	if (!this->earthTowerTexture[0].loadFromFile("../Assets/Image_Assets/Towers/EarthTower.png")) {
		std::cout << "Error loading wind tower texture 0" << std::endl;
	}
	else if (!this->earthTowerTexture[1].loadFromFile("../Assets/Image_Assets/Towers/EarthTower.png")) {
		std::cout << "Error loading wind tower texture 1" << std::endl;
	}
	else if (!this->earthTowerTexture[2].loadFromFile("../Assets/Image_Assets/Towers/EarthTower.png")) {
		std::cout << "Error loading wind tower texture 2" << std::endl;
	}
	else if (!this->earthTowerTexture[3].loadFromFile("../Assets/Image_Assets/Towers/EarthTower.png")) {
		std::cout << "Error loading wind tower texture 3" << std::endl;
	}
}

void EarthTower::initSprites()
{
	for (int i = 0; i < earthTower.size(); i++) {
		this->earthTower[i].setSize(sf::Vector2f(towerSize.x, towerSize.y));
		this->earthTower[i].setTexture(&earthTowerTexture[0]);
	}
}

EarthTower::EarthTower()
{
	this->initVariables();
	this->initTextures();
	this->initSprites();
}


EarthTower::~EarthTower()
{
}

sf::Vector2f EarthTower::towerClicked(sf::Vector2i clickPos)
{
	this->towerPos = sf::Vector2f(-1, -1);
	for (int i = 0; i < this->earthTower.size(); i++) {
		if (clickPos.x >= this->earthTower[i].getGlobalBounds().left && clickPos.x <= (this->earthTower[i].getGlobalBounds().left + this->earthTower[i].getGlobalBounds().width)) {
			if (clickPos.y >= this->earthTower[i].getGlobalBounds().top && clickPos.y <= (this->earthTower[i].getGlobalBounds().top + this->earthTower[i].getGlobalBounds().height)) {
				this->towerPos = this->earthTower[i].getPosition();
				this->earthClicked = true;
			}
		}
	}

	return this->towerPos;
}

void EarthTower::CreateTower(sf::Vector2i towerPos)
{
	this->towerNum++;
	this->earthTower.resize(towerNum);
	this->earth.setSize(sf::Vector2f(200, 200));
	this->earth.setPosition(sf::Vector2f(towerPos.x, towerPos.y));

	this->earth.setTexture(&earthTowerTexture[0]);

	this->earthTower.push_back(this->earth);
	std::cout << "Earth Tower Created: " << std::endl;

}

void EarthTower::SetTowerTexture(int towerId, std::string & towerTexture)
{
}

void EarthTower::DeleteTower(int towerId)
{
}

void EarthTower::deleteTowers()
{
}

void EarthTower::update()
{
}

void EarthTower::render(sf::RenderTarget & target)
{
	for (int i = 0; i < earthTower.size(); i++) {
		target.draw(earthTower[i]);
	}
}
