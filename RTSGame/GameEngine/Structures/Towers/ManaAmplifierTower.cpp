#include "ManaAmplifierTower.h"

void ManaAmplifierTower::initVariables()
{
	this->towerSize.x = 200;
	this->towerSize.y = 200;
	this->towerNum = 0;
	this->mAmplifierTower.resize(towerNum);
	this->towerCost = 300;
}

void ManaAmplifierTower::initTextures()
{
	this->mAmplifierTowerTexture.resize(4);

	if (!this->mAmplifierTowerTexture[0].loadFromFile("../Assets/Image_Assets/Towers/ManaAmplifier.png")) {
		std::cout << "Error loading wind tower texture 0" << std::endl;
	}
	else if (!this->mAmplifierTowerTexture[1].loadFromFile("../Assets/Image_Assets/Towers/ManaAmplifier.png")) {
		std::cout << "Error loading wind tower texture 1" << std::endl;
	}
	else if (!this->mAmplifierTowerTexture[2].loadFromFile("../Assets/Image_Assets/Towers/ManaAmplifier.png")) {
		std::cout << "Error loading wind tower texture 2" << std::endl;
	}
	else if (!this->mAmplifierTowerTexture[3].loadFromFile("../Assets/Image_Assets/Towers/ManaAmplifier.png")) {
		std::cout << "Error loading wind tower texture 3" << std::endl;
	}
}

void ManaAmplifierTower::initSprites()
{
	for (int i = 0; i < mAmplifierTower.size(); i++) {
		this->mAmplifierTower[i].setSize(sf::Vector2f(towerSize.x, towerSize.y));
		this->mAmplifierTower[i].setTexture(&mAmplifierTowerTexture[0]);
	}
}

ManaAmplifierTower::ManaAmplifierTower()
{
	this->initVariables();
	this->initTextures();
	this->initSprites();
}


ManaAmplifierTower::~ManaAmplifierTower()
{
}

void ManaAmplifierTower::CreateTower(sf::Vector2i towerPos)
{
	this->towerNum++;
	this->mAmplifierTower.resize(towerNum);
	this->mAmplifier.setSize(sf::Vector2f(200, 200));
	this->mAmplifier.setPosition(sf::Vector2f(towerPos.x, towerPos.y));

	this->mAmplifier.setTexture(&mAmplifierTowerTexture[0]);

	this->mAmplifierTower.push_back(this->mAmplifier);
	std::cout << "Mana Amplifier Tower Created: " << std::endl;

}

void ManaAmplifierTower::SetTowerTexture(int towerId, std::string & towerTexture)
{
}

void ManaAmplifierTower::DeleteTower(int towerId)
{
}

void ManaAmplifierTower::update()
{
}

void ManaAmplifierTower::render(sf::RenderTarget & target)
{
	for (int i = 0; i < mAmplifierTower.size(); i++) {
		target.draw(mAmplifierTower[i]);
	}
}
