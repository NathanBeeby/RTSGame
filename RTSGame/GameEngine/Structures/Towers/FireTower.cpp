#include "FireTower.h"

void FireTower::initVariables()
{
	this->towerSize.x = 200;
	this->towerSize.y = 200;
	this->towerNum = 0;
	this->fireTower.resize(towerNum);
	this->towerCost = 300;
	this->fireClicked = false;
	this->towerPos.x = -1;
	this->towerPos.y = -1;
	this->radius = 500.f;
	this->towerSelected = false;
}

void FireTower::initTextures()
{
	this->fireTowerTexture.resize(4);

	if (!this->fireTowerTexture[0].loadFromFile("../Assets/Image_Assets/Towers/FireTower.png")) {
		std::cout << "Error loading wind tower texture 0" << std::endl;
	}
	else if (!this->fireTowerTexture[1].loadFromFile("../Assets/Image_Assets/Towers/FireTower.png")) {
		std::cout << "Error loading wind tower texture 1" << std::endl;
	}
	else if (!this->fireTowerTexture[2].loadFromFile("../Assets/Image_Assets/Towers/FireTower.png")) {
		std::cout << "Error loading wind tower texture 2" << std::endl;
	}
	else if (!this->fireTowerTexture[3].loadFromFile("../Assets/Image_Assets/Towers/FireTower.png")) {
		std::cout << "Error loading wind tower texture 3" << std::endl;
	}
}

void FireTower::initSprites()
{
	for (int i = 0; i < fireTower.size(); i++) {
		this->fireTower[i].setSize(sf::Vector2f(towerSize.x, towerSize.y));
		this->fireTower[i].setTexture(&fireTowerTexture[0]);
	}
	this->radiusCircle.setFillColor(sf::Color(125, 125, 125, 15));
	this->radiusCircle.setOutlineThickness(2);
	this->radiusCircle.setOutlineColor(sf::Color(155, 155, 155));
	this->radiusCircle.setRadius(this->radius);
}

FireTower::FireTower()
{
	this->initVariables();
	this->initTextures();
	this->initSprites();
}


FireTower::~FireTower()
{
}

sf::Vector2f FireTower::towerClicked(sf::Vector2i clickPos)
{
	this->towerPos = sf::Vector2f(-1, -1);
	for (int i = 0; i < this->fireTower.size(); i++) {
		if (clickPos.x >= this->fireTower[i].getGlobalBounds().left && clickPos.x <= (this->fireTower[i].getGlobalBounds().left + this->fireTower[i].getGlobalBounds().width)) {
			if (clickPos.y >= this->fireTower[i].getGlobalBounds().top && clickPos.y <= (this->fireTower[i].getGlobalBounds().top + this->fireTower[i].getGlobalBounds().height)) {
				this->towerPos.x = this->fireTower[i].getPosition().x + (this->fireTower[i].getSize().x / 2);
				this->towerPos.y = this->fireTower[i].getPosition().y + (this->fireTower[i].getSize().y / 2);
				this->fireClicked = true;
				this->SelectTower(i, towerPos);
				std::cout << "Fire Clicked" << std::endl;
			}
		}
	}

	return this->towerPos;
}

void FireTower::CreateTower(sf::Vector2i towerPos)
{
	this->towerNum++;
	this->fireTower.resize(towerNum);
	this->fire.setSize(sf::Vector2f(200, 200));
	this->fire.setPosition(sf::Vector2f(towerPos.x, towerPos.y));

	this->fire.setTexture(&fireTowerTexture[0]);

	this->fireTower.push_back(this->fire);
	//std::cout << "Fire Tower Created: " << std::endl;

}

void FireTower::SetTowerTexture(int towerId, std::string & towerTexture)
{
}

void FireTower::SelectTower(int towerID, sf::Vector2f towerCenter)
{
	this->towerSelected = true;
	this->radiusCircle.setRadius(this->radius);
	this->radiusCircle.setPosition(sf::Vector2f(towerCenter.x - (radiusCircle.getRadius()), towerCenter.y - (radiusCircle.getRadius())));

	//Tower ID is tower in lise, incase we want to make a delete button and delete selected tower

}

void FireTower::DeselectTower()
{
	std::cout << "Tower Deselected" << std::endl;
	this->towerSelected = false;
}

void FireTower::DeleteTower(int towerId)
{
	this->fireTower.erase(fireTower.begin() + towerId);
}

void FireTower::deleteTowers()
{
	for (int i = 0; i < this->fireTower.size(); i++) {
		this->fireTower.erase(fireTower.begin() + i);
	}
}

void FireTower::updateTowerSelected()
{
	if (towerSelected == true) {

	}
}

void FireTower::update()
{
	if (fireClicked == true) {
		this->updateTowerSelected();
	}
}

void FireTower::render(sf::RenderTarget & target)
{
	for (int i = 0; i < this->fireTower.size(); i++) {
		target.draw(this->fireTower[i]);
	}
	if (towerSelected == true) {
		target.draw(this->radiusCircle);
	}
}
