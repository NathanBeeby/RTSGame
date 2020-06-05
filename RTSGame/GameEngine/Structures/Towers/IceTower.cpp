#include "IceTower.h"

void IceTower::initVariables()
{
	this->towerSize.x = 200;
	this->towerSize.y = 200;
	this->towerNum = 0;
	this->iceTower.resize(towerNum);
	this->towerCost = 300;
	this->iceClicked = false;
	this->towerPos.x = -1;
	this->towerPos.y = -1;
}

void IceTower::initTextures()
{
	this->iceTowerTexture.resize(4);

	if (!this->iceTowerTexture[0].loadFromFile("../Assets/Image_Assets/Towers/IceTower.png")) {
		std::cout << "Error loading wind tower texture 0" << std::endl;
	}
	else if (!this->iceTowerTexture[1].loadFromFile("../Assets/Image_Assets/Towers/IceTower.png")) {
		std::cout << "Error loading wind tower texture 1" << std::endl;
	}
	else if (!this->iceTowerTexture[2].loadFromFile("../Assets/Image_Assets/Towers/IceTower.png")) {
		std::cout << "Error loading wind tower texture 2" << std::endl;
	}
	else if (!this->iceTowerTexture[3].loadFromFile("../Assets/Image_Assets/Towers/IceTower.png")) {
		std::cout << "Error loading wind tower texture 3" << std::endl;
	}
}

void IceTower::initSprites()
{
	for (int i = 0; i < iceTower.size(); i++) {
		this->iceTower[i].setSize(sf::Vector2f(towerSize.x, towerSize.y));
		this->iceTower[i].setTexture(&iceTowerTexture[0]);
	}
}

IceTower::IceTower()
{
	this->initVariables();
	this->initTextures();
	this->initSprites();
}


IceTower::~IceTower()
{
}

sf::Vector2f IceTower::towerClicked(sf::Vector2i clickPos)
{
	this->towerPos = sf::Vector2f(-1, -1);
	for (int i = 0; i < this->iceTower.size(); i++) {
		if (clickPos.x >= this->iceTower[i].getGlobalBounds().left && clickPos.x <= (this->iceTower[i].getGlobalBounds().left + this->iceTower[i].getGlobalBounds().width)) {
			if (clickPos.y >= this->iceTower[i].getGlobalBounds().top && clickPos.y <= (this->iceTower[i].getGlobalBounds().top + this->iceTower[i].getGlobalBounds().height)) {
				this->towerPos = this->iceTower[i].getPosition();
				this->iceClicked = true;
			}
		}
	}

	return this->towerPos;
}

void IceTower::CreateTower(sf::Vector2i towerPos)
{
	this->towerNum++;
	this->iceTower.resize(towerNum);
	this->ice.setSize(sf::Vector2f(200, 200));
	this->ice.setPosition(sf::Vector2f(towerPos.x, towerPos.y));

	this->ice.setTexture(&iceTowerTexture[0]);

	this->iceTower.push_back(this->ice);
	std::cout << "Ice Tower Created: " << std::endl;

}

void IceTower::SetTowerTexture(int towerId, std::string & towerTexture)
{
}

void IceTower::DeleteTower(int towerId)
{
}

void IceTower::deleteTowers()
{
}

void IceTower::update()
{
}

void IceTower::render(sf::RenderTarget & target)
{
	for (int i = 0; i < iceTower.size(); i++) {
		target.draw(iceTower[i]);
	}
}
