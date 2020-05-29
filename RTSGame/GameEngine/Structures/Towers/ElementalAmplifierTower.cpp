#include "ElementalAmplifierTower.h"

void ElementalAmplifierTower::initVariables()
{
	this->towerSize.x = 200;
	this->towerSize.y = 200;
	this->towerNum = 0;
	this->eAmplifierTower.resize(towerNum);
	this->towerCost = 300;
}

void ElementalAmplifierTower::initTextures()
{
	this->eAmplifierTowerTexture.resize(4);

	if (!this->eAmplifierTowerTexture[0].loadFromFile("../Assets/Image_Assets/Towers/ElementalAmplifier.png")) {
		std::cout << "Error loading wind tower texture 0" << std::endl;
	}
	else if (!this->eAmplifierTowerTexture[1].loadFromFile("../Assets/Image_Assets/Towers/ElementalAmplifier.png")) {
		std::cout << "Error loading wind tower texture 1" << std::endl;
	}
	else if (!this->eAmplifierTowerTexture[2].loadFromFile("../Assets/Image_Assets/Towers/ElementalAmplifier.png")) {
		std::cout << "Error loading wind tower texture 2" << std::endl;
	}
	else if (!this->eAmplifierTowerTexture[3].loadFromFile("../Assets/Image_Assets/Towers/ElementalAmplifier.png")) {
		std::cout << "Error loading wind tower texture 3" << std::endl;
	}
}

void ElementalAmplifierTower::initSprites()
{
	for (int i = 0; i < eAmplifierTower.size(); i++) {
		this->eAmplifierTower[i].setSize(sf::Vector2f(towerSize.x, towerSize.y));
		this->eAmplifierTower[i].setTexture(&eAmplifierTowerTexture[0]);
	}
}

ElementalAmplifierTower::ElementalAmplifierTower()
{
	this->initVariables();
	this->initTextures();
	this->initSprites();
}


ElementalAmplifierTower::~ElementalAmplifierTower()
{
}

void ElementalAmplifierTower::CreateTower(sf::Vector2i towerPos)
{
	this->towerNum++;
	this->eAmplifierTower.resize(towerNum);
	this->eAmplifier.setSize(sf::Vector2f(200, 200));
	this->eAmplifier.setPosition(sf::Vector2f(towerPos.x, towerPos.y));

	this->eAmplifier.setTexture(&eAmplifierTowerTexture[0]);

	this->eAmplifierTower.push_back(this->eAmplifier);
	std::cout << "Elemental Overclocker Tower Created: " << std::endl;

}

void ElementalAmplifierTower::SetTowerTexture(int towerId, std::string & towerTexture)
{
}

void ElementalAmplifierTower::DeleteTower(int towerId)
{
}

void ElementalAmplifierTower::update()
{
}

void ElementalAmplifierTower::render(sf::RenderTarget & target)
{
	for (int i = 0; i < eAmplifierTower.size(); i++) {
		target.draw(eAmplifierTower[i]);
	}
}
