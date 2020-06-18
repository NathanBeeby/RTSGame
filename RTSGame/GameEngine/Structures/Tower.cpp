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
	this->towerCenters.resize(towerNum);
	this->towerIsClicked = false;
	this->towerSelected = false;

	// Vector variables
	this->aimDir = sf::Vector2f(-1, -1);
	this->aimDirNorm = sf::Vector2f(-1, -1);
	this->aimDirs.resize(towerNum);
	this->aimDirNorms.resize(towerNum);
}

void Tower::initTextures()
{

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
	this->radiusCircle.setRadius(this->towerRange);
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

const float Tower::getTowerRange() const
{
	return this->towerRange;
}

const float Tower::getTowerSpeed() const
{
	return this->towerAttackSpeed;
}

const float Tower::getTowerDamage() const
{
	return this->towerDamage;
}

const bool Tower::isTowerSelected() const
{
	return this->towerSelected;
}

const bool Tower::isEnemyInRadius() const
{
	bool enemyInRange = false;

	return enemyInRange;
}

const int Tower::getTowerAmount() const
{
	return towers.size();
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

void Tower::FireBullets(sf::Vector2i &enemyPos)
{
	for (int i = 0; i < towers.size(); i++) { // NEED TO GET THE ENEMY POSITION IN VIEW SPACE & ONLY FIRE A BULLET FROM A SPECIFIC TOWER WHEN ENEMY IS IN RANGE (MADE E.G> FUNCTION BELOW)
		// ALSO NEED TO ADD TIME DELAY HERE
		if (enemyPos.x > 0 || enemyPos.y > 0) {
			//std::cout << "Tower Center pos: X - " << tower.getPosition().x + (tower.getSize().x / 2) << ", Y - " << tower.getPosition().y + (tower.getSize().y / 2) << std::endl;
			if (enemyPos.x >= towers[i].getPosition().x + (towers[i].getSize().x / 2) + towerRange || enemyPos.x <= towers[i].getPosition().x + (towers[i].getSize().x / 2) - towerRange) {
				if (enemyPos.y >= towers[i].getPosition().y + (towers[i].getSize().y / 2) + towerRange || enemyPos.y <= towers[i].getPosition().y + (towers[i].getSize().y / 2) - towerRange) {
					//bullet.CreateBullet(sf::Vector2i(this->towers[towerNum].getPosition().x + (this->towers[towerNum].getSize().x / 2), this->towers[towerNum].getPosition().y + (this->towers[towerNum].getSize().y / 2)), sf::Vector2i(enemyPos.x, enemyPos.y), this->elementId, 0, towerDamage, towerAttackSpeed);
					std::cout << "Enemy in range" << std::endl;
					bullets.push_back(bullet);
				}
			}
		}
	}
}

void Tower::FireBullet(sf::Vector2i &enemyPos)
{
	if (enemyPos.x > 0 || enemyPos.y > 0) {
		//std::cout << "Tower Center pos: X - " << tower.getPosition().x + (tower.getSize().x / 2) << ", Y - " << tower.getPosition().y + (tower.getSize().y / 2) << std::endl;
		if (enemyPos.x >= tower.getPosition().x + (tower.getSize().x / 2) + towerRange || enemyPos.x <= tower.getPosition().x + (tower.getSize().x / 2) - towerRange) {
			if (enemyPos.y >= tower.getPosition().y + (tower.getSize().y / 2) + towerRange || enemyPos.y <= tower.getPosition().y + (tower.getSize().y / 2) - towerRange) {
				//bullet.CreateBullet(sf::Vector2i(this->towers[towerNum].getPosition().x + (this->towers[towerNum].getSize().x / 2), this->towers[towerNum].getPosition().y + (this->towers[towerNum].getSize().y / 2)), sf::Vector2i(enemyPos.x, enemyPos.y), this->elementId, 0, towerDamage, towerAttackSpeed);
				bullets.push_back(bullet);
			}
		}
	}
}


void Tower::CreateTower(sf::Vector2i towerPos)
{
	this->towerNum++;
	this->towers.resize(towerNum);
	this->aimDirs.resize(towerNum);
	this->aimDirNorms.resize(towerNum);
	this->towerCenters.resize(towerNum);
	this->tower.setSize(sf::Vector2f(this->towerSize.x, this->towerSize.y));
	this->tower.setPosition(sf::Vector2f(towerPos.x, towerPos.y));

	this->tower.setTexture(&towerTextures[0]);

	this->towers.push_back(this->tower);
	this->towerCenters.push_back(sf::Vector2f(this->tower.getPosition().x + (this->tower.getSize().x / 2), this->tower.getPosition().y + (this->tower.getSize().y / 2)));
	this->aimDirs.push_back(this->aimDir);
	this->aimDirNorms.push_back(this->aimDirNorm);
}

void Tower::SelectTower(int towerID, sf::Vector2f towerCenter)
{
	this->towerSelected = true;
	this->radiusCircle.setRadius(this->towerRange);
	this->radiusCircle.setPosition(sf::Vector2f(towerCenter.x - (radiusCircle.getRadius()), towerCenter.y - (radiusCircle.getRadius())));
	// TOWER SELECTED HERE

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

void Tower::updateMousePosition(sf::Vector2i &windowPos, sf::Vector2f &viewPos, sf::Vector2i &gridPos)
{
	mousePosWindow = sf::Vector2f(windowPos);
	mousePosView = sf::Vector2f(viewPos);
	mousePosGrid = sf::Vector2f(gridPos);

	// Setting the Aim Direction from the first tower

	if (towerCenters.size() >= 1) {
		for (int i = 0; i < aimDirs.size(); i++) {
			this->aimDirs[i] = mousePosView - towerCenters[i];
			this->aimDirNorms[i] = this->aimDirs[i] / sqrt(pow(aimDirs[i].x, 2) + (aimDirs[i].y, 2));

			//std::cout << "Aim Direction:" << i << " X - " << aimDirs[i].x << ", Y - " << aimDirs[i].y << std::endl;
			//std::cout << "Aim Direction Normal: " << i << " X - " << aimDirNorms[i].x << ", Y - " << aimDirNorms[i].y << std::endl;
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			for (int i = 0; i < towers.size(); i++)
			{
				bullet.maxSpeed = bulletSpeed;
				bullet.element = this->elementId;
				bullet.sprite.setPosition(sf::Vector2f(towers[i].getPosition().x + (towers[i].getSize().x / 2), towers[i].getPosition().y + (towers[i].getSize().y / 2)));
				bullet.currVelocity = aimDirNorms[i] * bullet.maxSpeed;
				bullet.positionOfDestruction = aimDirNorms[i] * towerRange;
				bullets.push_back(Bullet(bullet));
			}
		}


		for (size_t i = 0; i < bullets.size(); i++)
		{
			bullets[i].sprite.move(bullets[i].currVelocity);
			if (bullets[i].sprite.getPosition().x >= bullets[i].positionOfDestruction.x) {
				if (bullets[i].sprite.getPosition().y >= bullets[i].positionOfDestruction.y) {
					bullets.erase(bullets.begin() + i);
				}
			}
			std::cout << "Time Until Destruction: " << bullets[i].timeUntilDestruction << std::endl;
			if (bullets[i].timeUntilDestruction <= 0) {
				bullets.erase(bullets.begin() + i);
			}
		}

	}
}

void Tower::update(sf::Time deltaTime)
{
	//bullet.update(deltaTime, towerRange);

	//if (towers.size() >= 1) {
	//	this->FireBullets();
	//}
	bullet.update();
	for (int i = 0; i < towerCenters.size(); i++) {
		this->towerCenters[i] = sf::Vector2f(this->towers[i].getPosition().x + (this->towers[i].getSize().x / 2), this->towers[i].getPosition().y + (this->towers[i].getSize().y / 2));
	}
}

void Tower::render(sf::RenderTarget & target)
{
	//bullet.render(target);
	renderBullets(target);
	for (int i = 0; i < this->towers.size(); i++) {
		target.draw(this->towers[i]);
	}
	if (towerSelected == true) {
		target.draw(this->radiusCircle);
	}
}

void Tower::renderBullets(sf::RenderTarget &target)
{
	for (size_t i = 0; i < bullets.size(); i++) {
		target.draw(bullets[i].sprite);
	}
}
