#include "ElementalOverclockTower.h"

void ElementalOverclockTower::initVariables()
{
	this->towerSize.x = 200;
	this->towerSize.y = 200;
	this->towerNum = 0;
	this->eOverclockTower.resize(towerNum);
	this->towerCost = 300;
	this->elemOverClicked = false;
	this->towerPos.x = -1;
	this->towerPos.y = -1;
}

void ElementalOverclockTower::initTextures()
{
	this->eOverclockTowerTexture.resize(4);

	if (!this->eOverclockTowerTexture[0].loadFromFile("../Assets/Image_Assets/Towers/ElementalOverclocker.png")) {
		std::cout << "Error loading wind tower texture 0" << std::endl;
	}
	else if (!this->eOverclockTowerTexture[1].loadFromFile("../Assets/Image_Assets/Towers/ElementalOverclocker.png")) {
		std::cout << "Error loading wind tower texture 1" << std::endl;
	}
	else if (!this->eOverclockTowerTexture[2].loadFromFile("../Assets/Image_Assets/Towers/ElementalOverclocker.png")) {
		std::cout << "Error loading wind tower texture 2" << std::endl;
	}
	else if (!this->eOverclockTowerTexture[3].loadFromFile("../Assets/Image_Assets/Towers/ElementalOverclocker.png")) {
		std::cout << "Error loading wind tower texture 3" << std::endl;
	}
}

void ElementalOverclockTower::initSprites()
{
	for (int i = 0; i < eOverclockTower.size(); i++) {
		this->eOverclockTower[i].setSize(sf::Vector2f(towerSize.x, towerSize.y));
		this->eOverclockTower[i].setTexture(&eOverclockTowerTexture[0]);
	}
}

ElementalOverclockTower::ElementalOverclockTower()
{
	this->initVariables();
	this->initTextures();
	this->initSprites();
}


ElementalOverclockTower::~ElementalOverclockTower()
{
}

sf::Vector2f ElementalOverclockTower::towerClicked(sf::Vector2i clickPos)
{
	this->towerPos = sf::Vector2f(-1, -1);
	for (int i = 0; i < this->eOverclockTower.size(); i++) {
		if (clickPos.x >= this->eOverclockTower[i].getGlobalBounds().left && clickPos.x <= (this->eOverclockTower[i].getGlobalBounds().left + this->eOverclockTower[i].getGlobalBounds().width)) {
			if (clickPos.y >= this->eOverclockTower[i].getGlobalBounds().top && clickPos.y <= (this->eOverclockTower[i].getGlobalBounds().top + this->eOverclockTower[i].getGlobalBounds().height)) {
				this->towerPos = this->eOverclockTower[i].getPosition();
				this->elemOverClicked = true;
			}
		}
	}

	return this->towerPos;
}

void ElementalOverclockTower::CreateTower(sf::Vector2i towerPos)
{
	this->towerNum++;
	this->eOverclockTower.resize(towerNum);
	this->eOverclock.setSize(sf::Vector2f(200, 200));
	this->eOverclock.setPosition(sf::Vector2f(towerPos.x, towerPos.y));

	this->eOverclock.setTexture(&eOverclockTowerTexture[0]);

	this->eOverclockTower.push_back(this->eOverclock);
	std::cout << "Elemental Overclocker Tower Created: " << std::endl;

}

void ElementalOverclockTower::SetTowerTexture(int towerId, std::string & towerTexture)
{
}

void ElementalOverclockTower::DeleteTower(int towerId)
{
}

void ElementalOverclockTower::deleteTowers()
{
}

void ElementalOverclockTower::update()
{
}

void ElementalOverclockTower::render(sf::RenderTarget & target)
{
	for (int i = 0; i < eOverclockTower.size(); i++) {
		target.draw(eOverclockTower[i]);
	}
}
