#include "StructureInventory.h"

// Initialization

void StructureInventory::initVariables()
{
	this->towerFollowing = false;
	this->towerIsPlacable = true;

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
}

void StructureInventory::initSprites()
{
	this->tower.setSize(sf::Vector2f(80, 80));
	this->tower.setOrigin(this->tower.getSize().x / 2, this->tower.getSize().y / 2);
}

void StructureInventory::initFont()
{
}

void StructureInventory::initText()
{
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
	this->tower.setTexture(&towerTexture);
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

void StructureInventory::DeselectTowers()
{
	fireTower.DeselectTower();
	waterTower.DeselectTower();
	windTower.DeselectTower();
	iceTower.DeselectTower();
	earthTower.DeselectTower();
	energyTower.DeselectTower();
	lightTower.DeselectTower();
	darkTower.DeselectTower();
	elementalAmplifier.DeselectTower();
	elementalOverclocker.DeselectTower();
	manaAmplifier.DeselectTower();
	observatory.DeselectTower();
	regenTower.DeselectTower();
	voidTower.DeselectTower();
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
			// Create fire tower here, give parameters of tower tile position etc.
			fireTower.CreateTower(position);
			towerPlacementPositions.push_back(position);
			structurePrice = fireTower.towerCost;
			std::cout << "Fire Tower Created! : PosX: " << position.x << " ,PosY: " << position.y << std::endl;
		}
		else if (towerIsFollowing() == waterString) {
			waterTower.CreateTower(position);
			towerPlacementPositions.push_back(position);
			structurePrice = waterTower.towerCost;
			std::cout << "Water Tower Created! : PosX: " << position.x << " ,PosY: " << position.y << std::endl;
		}
		else if (towerIsFollowing() == windString) {
			windTower.CreateTower(position);
			towerPlacementPositions.push_back(position);
			structurePrice = windTower.towerCost;
			std::cout << "Wind Tower Created! : PosX: " << position.x << " ,PosY: " << position.y << std::endl;
		}
		else if (towerIsFollowing() == iceString) {
			iceTower.CreateTower(position);
			towerPlacementPositions.push_back(position);
			structurePrice = iceTower.towerCost;
			std::cout << "Ice Tower Created! : PosX: " << position.x << " ,PosY: " << position.y << std::endl;
		}
		else if (towerIsFollowing() == earthString) {
			earthTower.CreateTower(position);
			towerPlacementPositions.push_back(position);
			structurePrice = earthTower.towerCost;
			std::cout << "Earth Tower Created! : PosX: " << position.x << " ,PosY: " << position.y << std::endl;
		}
		else if (towerIsFollowing() == energyString) {
			energyTower.CreateTower(position);
			towerPlacementPositions.push_back(position);
			structurePrice = energyTower.towerCost;
			std::cout << "Energy Tower Created! : PosX: " << position.x << " ,PosY: " << position.y << std::endl;
		}
		else if (towerIsFollowing() == lightString) {
			lightTower.CreateTower(position);
			towerPlacementPositions.push_back(position);
			structurePrice = lightTower.towerCost;
			std::cout << "Light Tower Created! : PosX: " << position.x << " ,PosY: " << position.y << std::endl;
		}
		else if (towerIsFollowing() == darkString) {
			darkTower.CreateTower(position);
			towerPlacementPositions.push_back(position);
			structurePrice = darkTower.towerCost;
			std::cout << "Dark Tower Created! : PosX: " << position.x << " ,PosY: " << position.y << std::endl;
		}
		else if (towerIsFollowing() == elementAmpString) {
			elementalAmplifier.CreateTower(position);
			towerPlacementPositions.push_back(position);
			structurePrice = elementalAmplifier.towerCost;
			std::cout << "Elemental Amplifier Tower Created! : PosX: " << position.x << " ,PosY: " << position.y << std::endl;
		}
		else if (towerIsFollowing() == elementOverString) {
			elementalOverclocker.CreateTower(position);
			towerPlacementPositions.push_back(position);
			structurePrice = elementalOverclocker.towerCost;
			std::cout << "Elemental Overclocker Created! : PosX: " << position.x << " ,PosY: " << position.y << std::endl;
		}
		else if (towerIsFollowing() == manaAmpString) {
			manaAmplifier.CreateTower(position);
			towerPlacementPositions.push_back(position);
			structurePrice = manaAmplifier.towerCost;
			std::cout << "Mana Amplifier Tower Created! : PosX: " << position.x << " ,PosY: " << position.y << std::endl;
		}
		else if (towerIsFollowing() == observString) {
			observatory.CreateTower(position);
			towerPlacementPositions.push_back(position);
			structurePrice = observatory.towerCost;
			std::cout << "Observatory Tower Created! : PosX: " << position.x << " ,PosY: " << position.y << std::endl;
		}
		else if (towerIsFollowing() == regenString) {
			regenTower.CreateTower(position);
			towerPlacementPositions.push_back(position);
			structurePrice = regenTower.towerCost;
			std::cout << "Regen Tower Created! : PosX: " << position.x << " ,PosY: " << position.y << std::endl;
		}
		else if (towerIsFollowing() == voidString) {
			voidTower.CreateTower(position);
			towerPlacementPositions.push_back(position);
			structurePrice = voidTower.towerCost;
			std::cout << "Void Tower Created! : PosX: " << position.x << " ,PosY: " << position.y << std::endl;
		}
	}

	return structurePrice;
}

void StructureInventory::towerClicked(sf::Vector2i position)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		this->DeselectTowers();
		fireTower.towerClicked(position);
		waterTower.towerClicked(position);
		windTower.towerClicked(position);
		iceTower.towerClicked(position);
		earthTower.towerClicked(position);
		energyTower.towerClicked(position);
		lightTower.towerClicked(position);
		darkTower.towerClicked(position);
		elementalAmplifier.towerClicked(position);
		elementalOverclocker.towerClicked(position);
		manaAmplifier.towerClicked(position);
		regenTower.towerClicked(position);
		observatory.towerClicked(position);
		voidTower.towerClicked(position);
	}
}

void StructureInventory::deleteAllTowers()
{
	fireTower.deleteTowers();
	waterTower.deleteTowers();
	windTower.deleteTowers();
	iceTower.deleteTowers();
	earthTower.deleteTowers();
	energyTower.deleteTowers();
	lightTower.deleteTowers();
	darkTower.deleteTowers();
	elementalAmplifier.deleteTowers();
	elementalOverclocker.deleteTowers();
	manaAmplifier.deleteTowers();
	regenTower.deleteTowers();
	observatory.deleteTowers();
	voidTower.deleteTowers();

	for (int i = 0; i < towerPlacementPositions.size(); i++) {
		towerPlacementPositions.erase(towerPlacementPositions.begin() + i);
	}
}

void StructureInventory::updateFiring()
{
	// This works - Now need to get the towers to fire at these enemies
	if (wave.fireEnemy.enemies.size() > 0) {
		for (int i = 0; i < wave.fireEnemy.enemies.size(); i++) {
			this->updateTowerFiring(sf::Vector2i(wave.fireEnemy.enemies[i].getPosition().x, wave.fireEnemy.enemies[i].getPosition().y));
		}
	}
	if (wave.waterEnemy.enemies.size() > 0) {
		for (int i = 0; i < wave.waterEnemy.enemies.size(); i++) {
			this->updateTowerFiring(sf::Vector2i(wave.waterEnemy.enemies[i].getPosition().x, wave.waterEnemy.enemies[i].getPosition().y));
		}
	}
	if (wave.windEnemy.enemies.size() > 0) {
		for (int i = 0; i < wave.windEnemy.enemies.size(); i++) {
			this->updateTowerFiring(sf::Vector2i(wave.windEnemy.enemies[i].getPosition().x, wave.windEnemy.enemies[i].getPosition().y));
		}
	}
	if (wave.iceEnemy.enemies.size() > 0) {
		for (int i = 0; i < wave.iceEnemy.enemies.size(); i++) {
			this->updateTowerFiring(sf::Vector2i(wave.iceEnemy.enemies[i].getPosition().x, wave.iceEnemy.enemies[i].getPosition().y));
		}
	}
	if (wave.earthEnemy.enemies.size() > 0) {
		for (int i = 0; i < wave.earthEnemy.enemies.size(); i++) {
			this->updateTowerFiring(sf::Vector2i(wave.earthEnemy.enemies[i].getPosition().x, wave.earthEnemy.enemies[i].getPosition().y));
		}
	}
	if (wave.energyEnemy.enemies.size() > 0) {
		for (int i = 0; i < wave.energyEnemy.enemies.size(); i++) {
			this->updateTowerFiring(sf::Vector2i(wave.energyEnemy.enemies[i].getPosition().x, wave.energyEnemy.enemies[i].getPosition().y));
		}
	}
	if (wave.lightEnemy.enemies.size() > 0) {
		for (int i = 0; i < wave.lightEnemy.enemies.size(); i++) {
			this->updateTowerFiring(sf::Vector2i(wave.lightEnemy.enemies[i].getPosition().x, wave.lightEnemy.enemies[i].getPosition().y));
		}
	}
	if (wave.darkEnemy.enemies.size() > 0) {
		for (int i = 0; i < wave.darkEnemy.enemies.size(); i++) {
			this->updateTowerFiring(sf::Vector2i(wave.darkEnemy.enemies[i].getPosition().x, wave.darkEnemy.enemies[i].getPosition().y));
		}
	}
	if (wave.voidEnemy.enemies.size() > 0) {
		for (int i = 0; i < wave.voidEnemy.enemies.size(); i++) {
			this->updateTowerFiring(sf::Vector2i(wave.voidEnemy.enemies[i].getPosition().x, wave.voidEnemy.enemies[i].getPosition().y));
		}
	}


}

void StructureInventory::updateMousePosition(sf::Vector2i &windowPos, sf::Vector2f &viewPos, sf::Vector2i &gridPos)
{
	fireTower.updateMousePosition(windowPos, viewPos, gridPos);
	waterTower.updateMousePosition(windowPos, viewPos, gridPos);
	windTower.updateMousePosition(windowPos, viewPos, gridPos);
	iceTower.updateMousePosition(windowPos, viewPos, gridPos);
	earthTower.updateMousePosition(windowPos, viewPos, gridPos);
	energyTower.updateMousePosition(windowPos, viewPos, gridPos);
	lightTower.updateMousePosition(windowPos, viewPos, gridPos);
	darkTower.updateMousePosition(windowPos, viewPos, gridPos);
	voidTower.updateMousePosition(windowPos, viewPos, gridPos);
}

void StructureInventory::updateTowers(sf::Time deltaTime)
{
	// Attack Towers
	fireTower.update(deltaTime);
	waterTower.update(deltaTime);
	windTower.update(deltaTime);
	iceTower.update(deltaTime);
	earthTower.update(deltaTime);
	energyTower.update(deltaTime);
	lightTower.update(deltaTime);
	darkTower.update(deltaTime);
	// Support Towers
	elementalAmplifier.update(deltaTime);
	elementalOverclocker.update(deltaTime);
	manaAmplifier.update(deltaTime);
	observatory.update(deltaTime);
	regenTower.update(deltaTime);
	voidTower.update(deltaTime);
}

void StructureInventory::updateTowerFiring(sf::Vector2i &enemyPos)
{
	if (fireTower.getTowerAmount() > 0) {
		fireTower.FireBullets(sf::Vector2i(enemyPos.x, enemyPos.y));
	}
	if (waterTower.getTowerAmount() > 0) {
		waterTower.FireBullets(sf::Vector2i(enemyPos.x, enemyPos.y));
	}
	if (windTower.getTowerAmount() > 0) {
		windTower.FireBullets(sf::Vector2i(enemyPos.x, enemyPos.y));
	}
	if (iceTower.getTowerAmount() > 0) {
		iceTower.FireBullets(sf::Vector2i(enemyPos.x, enemyPos.y));
	}
	if (earthTower.getTowerAmount() > 0) {
		earthTower.FireBullets(sf::Vector2i(enemyPos.x, enemyPos.y));
	}
	if (energyTower.getTowerAmount() > 0) {
		energyTower.FireBullets(sf::Vector2i(enemyPos.x, enemyPos.y));
	}
	if (lightTower.getTowerAmount() > 0) {
		lightTower.FireBullets(sf::Vector2i(enemyPos.x, enemyPos.y));
	}
	if (darkTower.getTowerAmount() > 0) {
		darkTower.FireBullets(sf::Vector2i(enemyPos.x, enemyPos.y));
	}
	if (voidTower.getTowerAmount() > 0) {
		voidTower.FireBullets(sf::Vector2i(enemyPos.x, enemyPos.y));
	}
	//std::cout << "Enemy Pos X: " << enemyPos.x << ", Y: " << enemyPos.y << std::endl;
}

void StructureInventory::update(sf::Time deltaTime)
{
	this->updateFiring();
	this->updateTowers(deltaTime);
}

void StructureInventory::mouseHandler(sf::Vector2i windowPos)
{
	if (this->towerFollowing == true) {
		this->tower.setPosition(windowPos.x, windowPos.y);
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
		this->towerFollowing = false;
		this->DeselectTowers();
	}
}

void StructureInventory::render(sf::RenderTarget & target)
{
	if (towerFollowing == true) {
		target.draw(tower);
	}
}

void StructureInventory::renderTowers(sf::RenderTarget & target)
{
	// Attack Towers
	fireTower.render(target);
	waterTower.render(target);
	windTower.render(target);
	iceTower.render(target);
	earthTower.render(target);
	energyTower.render(target);
	lightTower.render(target);
	darkTower.render(target);
	// Support Towers
	elementalAmplifier.render(target);
	elementalOverclocker.render(target);
	manaAmplifier.render(target);
	observatory.render(target);
	regenTower.render(target);
	voidTower.render(target);
}
