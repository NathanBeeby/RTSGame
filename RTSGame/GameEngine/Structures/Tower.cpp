#include "Tower.h"

// Initialization
void Tower::initVariables()
{
	// Integer Variables
	this->towerSize.x = 200;
	this->towerSize.y = 200;

	this->towerNum = 0;
	this->towerPos.x = -1;
	this->towerPos.y = -1;
	this->textureInt = 0;
	// Float Variables

	// Boolean Variables
	this->towers.resize(towerNum);
	this->towerIsClicked = false;
	this->towerSelected = false;
}

void Tower::initTextures()
{
	//this->towerTextures.resize(4);

	//if (!this->towerTextures[0].loadFromFile("../Assets/Image_Assets/Towers/FireTower.png")) {
	//	std::cout << "Error loading wind tower texture 0" << std::endl;
	//}
	//else if (!this->towerTextures[1].loadFromFile("../Assets/Image_Assets/Towers/FireTower.png")) {
	//	std::cout << "Error loading wind tower texture 1" << std::endl;
	//}
	//else if (!this->towerTextures[2].loadFromFile("../Assets/Image_Assets/Towers/FireTower.png")) {
	//	std::cout << "Error loading wind tower texture 2" << std::endl;
	//}
	//else if (!this->towerTextures[3].loadFromFile("../Assets/Image_Assets/Towers/FireTower.png")) {
	//	std::cout << "Error loading wind tower texture 3" << std::endl;
	//}
}

void Tower::initSprites()
{
	for (int i = 0; i < towers.size(); i++) {
		this->towers[i].setSize(sf::Vector2f(towerSize.x, towerSize.y));
		this->towers[i].setTexture(&towerTextures[0]);
	}
	this->radiusCircle.setFillColor(sf::Color(125, 125, 125, 15));
	this->radiusCircle.setOutlineThickness(2);
	this->radiusCircle.setOutlineColor(sf::Color(155, 155, 155));
	this->radiusCircle.setRadius(this->radius);
}

Tower::Tower()
{
	this->initVariables();
	this->initTextures();
	this->initSprites();
}

Tower::~Tower()
{
}

const int Tower::getTowerRange() const
{
	return this->towerRange;
}

const int Tower::getTowerSpeed() const
{
	return this->towerSpeed;
}

const int Tower::getTowerDamage() const
{
	return this->towerDamage;
}

sf::Vector2f Tower::towerClicked(sf::Vector2i clickPos)
{
	this->towerPos = sf::Vector2f(-1, -1);

	for (int i = 0; i < this->towers.size(); i++) {
		if (clickPos.x >= this->towers[i].getGlobalBounds().left && clickPos.x <= (this->towers[i].getGlobalBounds().left + this->towers[i].getGlobalBounds().width)) {
			if (clickPos.y >= this->towers[i].getGlobalBounds().top && clickPos.y <= (this->towers[i].getGlobalBounds().top + this->towers[i].getGlobalBounds().height)) {
				this->towerPos.x = this->towers[i].getPosition().x + (this->towers[i].getSize().x / 2);
				this->towerPos.y = this->towers[i].getPosition().y + (this->towers[i].getSize().y / 2);
				this->towerIsClicked = true;
				this->SelectTower(i, towerPos);
			}
		}
	}

	return this->towerPos;
}

void Tower::CreateTower(sf::Vector2i towerPos)
{
	this->towerNum++;
	this->towers.resize(towerNum);
	this->tower.setSize(sf::Vector2f(this->towerSize.x, this->towerSize.y));
	this->tower.setPosition(sf::Vector2f(towerPos.x, towerPos.y));

	this->tower.setTexture(&towerTextures[0]);

	this->towers.push_back(this->tower);
}

void Tower::SelectTower(int towerID, sf::Vector2f towerCenter)
{
	this->towerSelected = true;
	this->radiusCircle.setRadius(this->radius);
	this->radiusCircle.setPosition(sf::Vector2f(towerCenter.x - (radiusCircle.getRadius()), towerCenter.y - (radiusCircle.getRadius())));
}

void Tower::DeselectTower()
{
	this->towerSelected = false;
}

void Tower::DeleteTower(int towerId)
{
	this->towers.erase(towers.begin() + towerId);
}

void Tower::deleteTowers()
{
	for (int i = 0; i < this->towers.size(); i++) {
		this->towers.erase(towers.begin() + i);
	}
}

void Tower::updateTowerSelected()
{
	if (towerSelected == true) {

	}
}

void Tower::update()
{
	if (towerIsClicked == true) {
		this->updateTowerSelected();
	}
}

void Tower::render(sf::RenderTarget & target)
{
	for (int i = 0; i < this->towers.size(); i++) {
		target.draw(this->towers[i]);
	}
	if (towerSelected == true) {
		target.draw(this->radiusCircle);
	}
}
