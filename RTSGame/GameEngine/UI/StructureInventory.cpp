#include "StructureInventory.h"

// Initialization

void StructureInventory::initVariables()
{
	this->towerFollowing = false;
	this->towerIsPlacable = true;

	this->firePrice = 300;
	this->waterPrice = 280;
	this->windPrice = 255;
	this->icePrice = 210;
	this->earthPrice = 400;
	this->energyPrice = 350;
	this->lightPrice = 230;
	this->darkPrice = 366;
	this->elemAmpPrice = 600;
	this->elemOverPrice = 600;
	this->manaAmpPrice = 600;
	this->observPrice = 600;
	this->regenPrice = 600;
	this->voidPrice = 755;


	this->towerToFollow = "";
	this->fireString = "../Assets/Image_Assets/Towers/FireTower.png";
	this->waterString = "../Assets/Image_Assets/Towers/WaterTower.png";
	this->windString = "../Assets/Image_Assets/Towers/WindTower.png";
	this->iceString = "../Assets/Image_Assets/Towers/IceTower.png";
	this->earthString = "../Assets/Image_Assets/Towers/EarthTower.png";
	this->energyString = "../Assets/Image_Assets/Towers/EnergyTower.png";
	this->lightString = "../Assets/Image_Assets/Towers/LightTower.png";
	this->darkString = "../Assets/Image_Assets/Towers/DarkTower.png";
	this->elementAmpString = "../Assets/Image_Assets/Towers/ElementalAmplifier.png";
	this->elementOverString = "../Assets/Image_Assets/Towers/ElementalOverclocker.png";
	this->manaAmpString = "../Assets/Image_Assets/Towers/ManaAmplifier.png";
	this->observString = "../Assets/Image_Assets/Towers/Observatory.png";
	this->regenString = "../Assets/Image_Assets/Towers/Regenerator.png";
	this->voidString = "../Assets/Image_Assets/Towers/VoidTower.png";

	this->unplacablePos.x = -200;
	this->unplacablePos.y = -200;
	this->enemyKillMana = 0;
}

void StructureInventory::initSprites()
{
	this->towerImage.setSize(sf::Vector2f(80, 80));
	this->towerImage.setOrigin(this->towerImage.getSize().x / 2, this->towerImage.getSize().y / 2);
}

void StructureInventory::initFont()
{
}

void StructureInventory::initText()
{
	if (!this->fireTexture.loadFromFile("../Assets/Image_Assets/Towers/FireTower.png")) {
		std::cout << "Failed to load fireTexture" << std::endl;
	}
	if (!this->waterTexture.loadFromFile("../Assets/Image_Assets/Towers/WaterTower.png")) {
		std::cout << "Failed to load waterTexture" << std::endl;
	}
	if (!this->windTexture.loadFromFile("../Assets/Image_Assets/Towers/WindTower.png")) {
		std::cout << "Failed to load windTexture" << std::endl;
	}
	if (!this->iceTexture.loadFromFile("../Assets/Image_Assets/Towers/IceTower.png")) {
		std::cout << "Failed to load iceTexture" << std::endl;
	}
	if (!this->earthTexture.loadFromFile("../Assets/Image_Assets/Towers/EarthTower.png")) {
		std::cout << "Failed to load earthTexture" << std::endl;
	}
	if (!this->energyTexture.loadFromFile("../Assets/Image_Assets/Towers/EnergyTower.png")) {
		std::cout << "Failed to load energyTexture" << std::endl;
	}
	if (!this->lightTexture.loadFromFile("../Assets/Image_Assets/Towers/LightTower.png")) {
		std::cout << "Failed to load lightTexture" << std::endl;
	}
	if (!this->darkTexture.loadFromFile("../Assets/Image_Assets/Towers/DarkTower.png")) {
		std::cout << "Failed to load darkTexture" << std::endl;
	}
	if (!this->elemAmpTexture.loadFromFile("../Assets/Image_Assets/Towers/ElementalAmplifier.png")) {
		std::cout << "Failed to load elemAmpTexture" << std::endl;
	}
	if (!this->elemOverTexture.loadFromFile("../Assets/Image_Assets/Towers/ElementalOverclocker.png")) {
		std::cout << "Failed to load elemOverTexture" << std::endl;
	}
	if (!this->manaAmpTexture.loadFromFile("../Assets/Image_Assets/Towers/ManaAmplifier.png")) {
		std::cout << "Failed to load manaAmpTexture" << std::endl;
	}
	if (!this->observTexture.loadFromFile("../Assets/Image_Assets/Towers/Observatory.png")) {
		std::cout << "Failed to load observTexture" << std::endl;
	}
	if (!this->regenTexture.loadFromFile("../Assets/Image_Assets/Towers/Regenerator.png")) {
		std::cout << "Failed to load regenTexture" << std::endl;
	}
	if (!this->voidTexture.loadFromFile("../Assets/Image_Assets/Towers/VoidTower.png")) {
		std::cout << "Failed to load voidTexture" << std::endl;
	}
}

// Constructor / Destructor
StructureInventory::StructureInventory()
{
	this->initVariables();
	this->initSprites();
	this->initFont();
	this->initText();
}


StructureInventory::~StructureInventory()
{
}

void StructureInventory::setFollowing(bool follow)
{
	this->towerFollowing = follow;
}

const bool StructureInventory::isFollowing() const
{
	return this->towerFollowing;
}

const std::string StructureInventory::towerIsFollowing() const
{
	return this->towerToFollow;
}

const int StructureInventory::getTowerCost() const
{
	return structurePrice;
}

// Public Functions
void StructureInventory::towerFollow(std::string &towerString)
{
	if (!this->towerTexture.loadFromFile(towerString)) {
		std::cout << "Couldn't load tower follow texture" << std::endl;
	}
	this->towerImage.setTexture(&towerTexture);
	setFollowing(true);
	this->towerToFollow = towerString;
}

bool StructureInventory::towerPlacable(sf::Vector2i position)
{
	this->towerIsPlacable = true;
	for (int i = 0; i < towerPlacementPositions.size(); i++) {
		if (position == towerPlacementPositions[i]) {
			this->towerIsPlacable = false;
		}
	}
	for (int i = 0; i < unplacablePositions.size(); i++) {
		if (position == unplacablePositions[i]) {
			this->towerIsPlacable = false;
		}
	}
	return towerIsPlacable;
}

void StructureInventory::unplacablePosition(sf::Vector2i position)
{
	towerPlacementPositions.push_back(position);
}

void StructureInventory::waterTilePositions(sf::Vector2i position)
{
	waterTiles.push_back(position);
}

sf::Vector2i StructureInventory::returnUnplacablePosition(sf::Vector2i position)
{
	for (int i = 0; i < towerPlacementPositions.size(); i++) {
		if (position == towerPlacementPositions[i]) {
			this->unplacablePos = position;
		}
	}
	for (int i = 0; i < unplacablePositions.size(); i++) {
		if (position == unplacablePositions[i]) {
			this->unplacablePos = position;
		}
	}
	return this->unplacablePos;
}


int StructureInventory::towerPlace(sf::Vector2i position)
{
	if (towerPlacable(position) == true) {
		if (towerIsFollowing() == fireString) {
			tower.sprite.setPosition(sf::Vector2f(position));
			tower.sprite.setTexture(&this->fireTexture);
			tower.element = 0;
			tower.towerDamage = 100.f;
			tower.towerCost = firePrice;
			tower.towerRange = 600.f;
			tower.towerAttackSpeed = 9.99f;
			tower.bulletSpeed = 50.f;
			towers.push_back(Tower(tower));
			towerPlacementPositions.push_back(position);
			structurePrice = tower.towerCost;
			std::cout << "Fire Tower Created! : PosX: " << position.x << " ,PosY: " << position.y << std::endl;
		}
		else if (towerIsFollowing() == waterString) {

			tower.sprite.setPosition(sf::Vector2f(position));
			tower.sprite.setTexture(&this->waterTexture);
			tower.element = 1;
			tower.towerDamage = 100.f;
			tower.towerCost = waterPrice;
			tower.towerRange = 700.f;
			tower.towerAttackSpeed = 8.01f;
			tower.bulletSpeed = 50.f;
			towers.push_back(Tower(tower));
			towerPlacementPositions.push_back(position);
			structurePrice = tower.towerCost;
			std::cout << "Water Tower Created! : PosX: " << position.x << " ,PosY: " << position.y << std::endl;
		}
		else if (towerIsFollowing() == windString) {

			tower.sprite.setPosition(sf::Vector2f(position));
			tower.sprite.setTexture(&this->windTexture);
			tower.element = 2;
			tower.towerDamage = 100.f;
			tower.towerCost = windPrice;
			tower.towerRange = 600.f;
			tower.towerAttackSpeed = 8.01f;
			tower.bulletSpeed = 50.f;
			towers.push_back(Tower(tower));
			towerPlacementPositions.push_back(position);
			structurePrice = tower.towerCost;
			std::cout << "Wind Tower Created! : PosX: " << position.x << " ,PosY: " << position.y << std::endl;
		}
		else if (towerIsFollowing() == iceString) {

			tower.sprite.setPosition(sf::Vector2f(position));
			tower.sprite.setTexture(&this->iceTexture);
			tower.element = 3;
			tower.towerDamage = 100.f;
			tower.towerCost = icePrice;
			tower.towerRange = 350.f;
			tower.towerAttackSpeed = 8.01f;
			tower.bulletSpeed = 50.f;
			towers.push_back(Tower(tower));
			towerPlacementPositions.push_back(position);
			structurePrice = tower.towerCost;
			std::cout << "Ice Tower Created! : PosX: " << position.x << " ,PosY: " << position.y << std::endl;
		}
		else if (towerIsFollowing() == earthString) {
			tower.sprite.setPosition(sf::Vector2f(position));
			tower.sprite.setTexture(&this->earthTexture);
			tower.element = 4;
			tower.towerDamage = 100.f;
			tower.towerCost = earthPrice;
			tower.towerRange = 350.f;
			tower.towerAttackSpeed = 8.01f;
			tower.bulletSpeed = 50.f;
			towers.push_back(Tower(tower));
			towerPlacementPositions.push_back(position);
			structurePrice = tower.towerCost;
			std::cout << "Earth Tower Created! : PosX: " << position.x << " ,PosY: " << position.y << std::endl;
		}
		else if (towerIsFollowing() == energyString) {

			tower.sprite.setPosition(sf::Vector2f(position));
			tower.sprite.setTexture(&this->energyTexture);
			tower.element = 5;
			tower.towerDamage = 100.f;
			tower.towerCost = energyPrice;
			tower.towerRange = 600.f;
			tower.towerAttackSpeed = 8.01f;
			tower.bulletSpeed = 50.f;
			towers.push_back(Tower(tower));
			towerPlacementPositions.push_back(position);
			structurePrice = tower.towerCost;
			std::cout << "Energy Tower Created! : PosX: " << position.x << " ,PosY: " << position.y << std::endl;
		}
		else if (towerIsFollowing() == lightString) {
			tower.sprite.setPosition(sf::Vector2f(position));
			tower.sprite.setTexture(&this->lightTexture);
			tower.element = 6;
			tower.towerDamage = 100.f;
			tower.towerCost = lightPrice;
			tower.towerRange = 350.f;
			tower.towerAttackSpeed = 8.01f;
			tower.bulletSpeed = 50.f;
			towers.push_back(Tower(tower));
			towerPlacementPositions.push_back(position);
			structurePrice = tower.towerCost;
			std::cout << "Light Tower Created! : PosX: " << position.x << " ,PosY: " << position.y << std::endl;
		}
		else if (towerIsFollowing() == darkString) {
			tower.sprite.setPosition(sf::Vector2f(position));
			tower.sprite.setTexture(&this->darkTexture);
			tower.element = 7;
			tower.towerDamage = 100.f;
			tower.towerCost = darkPrice;
			tower.towerRange = 350.f;
			tower.towerAttackSpeed = 8.01f;
			tower.bulletSpeed = 50.f;
			towers.push_back(Tower(tower));
			towerPlacementPositions.push_back(position);
			structurePrice = tower.towerCost;
			std::cout << "Dark Tower Created! : PosX: " << position.x << " ,PosY: " << position.y << std::endl;
		}
		else if (towerIsFollowing() == elementAmpString) {
			tower.sprite.setPosition(sf::Vector2f(position));
			tower.sprite.setTexture(&this->elemAmpTexture);
			tower.element = 8;
			tower.towerDamage = 100.f;
			tower.towerCost = elemAmpPrice;
			tower.towerRange = 1000.f;
			tower.towerAttackSpeed = 9.5f;
			tower.bulletSpeed = 50.f;
			towers.push_back(Tower(tower));
			towerPlacementPositions.push_back(position);
			structurePrice = tower.towerCost;
			std::cout << "Elemental Amplifier Tower Created! : PosX: " << position.x << " ,PosY: " << position.y << std::endl;
		}
		else if (towerIsFollowing() == elementOverString) {
			tower.sprite.setPosition(sf::Vector2f(position));
			tower.sprite.setTexture(&this->elemOverTexture);
			tower.element = 9;
			tower.towerDamage = 100.f;
			tower.towerCost = elemOverPrice;
			tower.towerRange = 1000.f;
			tower.towerAttackSpeed = 9.5f;
			tower.bulletSpeed = 50.f;
			towers.push_back(Tower(tower));
			towerPlacementPositions.push_back(position);
			structurePrice = tower.towerCost;
			std::cout << "Elemental Overclocker Created! : PosX: " << position.x << " ,PosY: " << position.y << std::endl;
		}
		else if (towerIsFollowing() == manaAmpString) {
			tower.sprite.setPosition(sf::Vector2f(position));
			tower.sprite.setTexture(&this->manaAmpTexture);
			tower.element = 10;
			tower.towerDamage = 100.f;
			tower.towerCost = manaAmpPrice;
			tower.towerRange = 1000.f;
			tower.towerAttackSpeed = 9.5f;
			tower.bulletSpeed = 50.f;
			towers.push_back(Tower(tower));
			towerPlacementPositions.push_back(position);
			structurePrice = tower.towerCost;
			std::cout << "Mana Amplifier Tower Created! : PosX: " << position.x << " ,PosY: " << position.y << std::endl;
		}
		else if (towerIsFollowing() == observString) {
			tower.sprite.setPosition(sf::Vector2f(position));
			tower.sprite.setTexture(&this->observTexture);
			tower.element = 11;
			tower.towerDamage = 100.f;
			tower.towerCost = observPrice;
			tower.towerRange = 1000.f;
			tower.towerAttackSpeed = 9.5f;
			tower.bulletSpeed = 50.f;
			towers.push_back(Tower(tower));
			towerPlacementPositions.push_back(position);
			structurePrice = tower.towerCost;
			std::cout << "Observatory Tower Created! : PosX: " << position.x << " ,PosY: " << position.y << std::endl;
		}
		else if (towerIsFollowing() == regenString) {
			tower.sprite.setPosition(sf::Vector2f(position));
			tower.sprite.setTexture(&this->regenTexture);
			tower.element = 12;
			tower.towerDamage = 100.f;
			tower.towerRange = 1000.f;
			tower.towerAttackSpeed = 9.5f;
			tower.bulletSpeed = 50.f;
			towers.push_back(Tower(tower));
			towerPlacementPositions.push_back(position);
			structurePrice = tower.towerCost;
			std::cout << "Regen Tower Created! : PosX: " << position.x << " ,PosY: " << position.y << std::endl;
		}
		else if (towerIsFollowing() == voidString) {
			tower.sprite.setPosition(sf::Vector2f(position));
			tower.sprite.setTexture(&this->voidTexture);
			tower.element = 13;
			tower.towerDamage = 100.f;
			tower.towerCost = voidPrice;
			tower.towerRange = 1000.f;
			tower.towerAttackSpeed = 9.5f;
			tower.bulletSpeed = 50.f;
			towers.push_back(Tower(tower));
			towerPlacementPositions.push_back(position);
			structurePrice = tower.towerCost;
			std::cout << "Void Tower Created! : PosX: " << position.x << " ,PosY: " << position.y << std::endl;
		}

	}

	return structurePrice;
}

void StructureInventory::towerClicked(sf::Vector2i position)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

		for (int i = 0; i < towers.size(); i++) {
			towers[i].DeselectTower();
			towers[i].towerClicked(position);
		}
	}
}

void StructureInventory::deleteAllTowers()
{
	for (int i = 0; i < towerPlacementPositions.size(); i++) {
		towerPlacementPositions.erase(towerPlacementPositions.begin() + i);
	}
}

void StructureInventory::updateFiring()
{
	// This works - Now need to get the towers to fire at these enemies
	if (wave.enemies.size() > 0) {
		//for (int i = 0; i < wave.enemies.size(); i++) {
		this->updateTowerFiring(sf::Vector2i(wave.enemies[0].sprite.getPosition().x, wave.enemies[0].sprite.getPosition().y));
	}
	//}
}

void StructureInventory::updateTowers(sf::Time deltaTime)
{
	// Attack Towers
	for (size_t i = 0; i < towers.size(); i++) {
		towers[i].update();
	}

}

void StructureInventory::updateEnemiesKilled()
{
	for (size_t k = 0; k < towers.size(); k++) {
		for (size_t j = 0; j < towers[k].bullets.size(); j++) {
			for (size_t i = 0; i < wave.enemies.size(); i++) {
				if (towers[k].bullets.size() > 0) {
					if (towers[k].bullets[j].sprite.getGlobalBounds().intersects(wave.enemies[i].sprite.getGlobalBounds())) {
						wave.enemies[i].health -= towers[k].bullets[j].baseDamage;
						towers[k].bullets.erase(towers[k].bullets.begin() + j);
						this->enemyKillMana += 5;
						std::cout << "fire tower hit enemy. Health = " << wave.enemies[i].health << std::endl;
					}
				}
			}
		}
	}

}

void StructureInventory::updateTowerFiring(sf::Vector2i &enemyPos)
{
	for (size_t i = 0; i < towers.size(); i++) {
		towers[i].FireBullet(sf::Vector2f(enemyPos.x, enemyPos.y));
	}


}

void StructureInventory::update(sf::Time deltaTime)
{
	this->updateFiring();
	this->updateEnemiesKilled();
	this->updateTowers(deltaTime);
}

void StructureInventory::mouseHandler(sf::Vector2i windowPos)
{
	if (this->towerFollowing == true) {
		this->towerImage.setPosition(windowPos.x, windowPos.y);
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
		this->towerFollowing = false;
		for (int i = 0; i < towers.size(); i++) {
			towers[i].DeselectTower();
		}
	}
}

void StructureInventory::render(sf::RenderTarget & target)
{
	if (towerFollowing == true) {
		target.draw(towerImage);
	}
}

void StructureInventory::renderTowers(sf::RenderTarget & target)
{

	for (size_t i = 0; i < towers.size(); i++) {
		towers[i].render(target);
	}
}
