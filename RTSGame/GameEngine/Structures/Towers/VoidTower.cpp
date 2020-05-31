#include "VoidTower.h"


void VoidTower::initVariables()
{
	this->towerSize.x = 200;
	this->towerSize.y = 200;
	this->towerNum = 0;
	this->voidTower.resize(towerNum);
	this->towerCost = 300;
}

void VoidTower::initTextures()
{
	this->voidTowerTexture.resize(4);

	if (!this->voidTowerTexture[0].loadFromFile("../Assets/Image_Assets/Towers/VoidTower.png")) {
		std::cout << "Error loading wind tower texture 0" << std::endl;
	}
	else if (!this->voidTowerTexture[1].loadFromFile("../Assets/Image_Assets/Towers/VoidTower.png")) {
		std::cout << "Error loading wind tower texture 1" << std::endl;
	}
	else if (!this->voidTowerTexture[2].loadFromFile("../Assets/Image_Assets/Towers/VoidTower.png")) {
		std::cout << "Error loading wind tower texture 2" << std::endl;
	}
	else if (!this->voidTowerTexture[3].loadFromFile("../Assets/Image_Assets/Towers/VoidTower.png")) {
		std::cout << "Error loading wind tower texture 3" << std::endl;
	}
}

void VoidTower::initSprites()
{
	for (int i = 0; i < voidTower.size(); i++) {
		this->voidTower[i].setSize(sf::Vector2f(towerSize.x, towerSize.y));
		this->voidTower[i].setTexture(&voidTowerTexture[0]);
	}
}

VoidTower::VoidTower()
{
	this->initVariables();
	this->initTextures();
	this->initSprites();
}


VoidTower::~VoidTower()
{
}

void VoidTower::CreateTower(sf::Vector2i towerPos)
{
	this->towerNum++;
	this->voidTower.resize(towerNum);
	this->voidT.setSize(sf::Vector2f(200, 200));
	this->voidT.setPosition(sf::Vector2f(towerPos.x, towerPos.y));

	this->voidT.setTexture(&voidTowerTexture[0]);

	this->voidTower.push_back(this->voidT);
	std::cout << "Void Tower Created: " << std::endl;

}

void VoidTower::SetTowerTexture(int towerId, std::string & towerTexture)
{
}

void VoidTower::DeleteTower(int towerId)
{
}

void VoidTower::deleteTowers()
{
}

void VoidTower::update()
{
}

void VoidTower::render(sf::RenderTarget & target)
{
	for (int i = 0; i < voidTower.size(); i++) {
		target.draw(voidTower[i]);
	}
}
