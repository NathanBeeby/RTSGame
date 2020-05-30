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
	return towerIsPlacable;
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

void StructureInventory::updateFollowing()
{
}

void StructureInventory::update()
{
	this->updateFollowing();
}

void StructureInventory::mouseHandler(sf::Vector2i windowPos)
{
	//mousePosWindow = sf::Mouse::getPosition(window);

	if (this->towerFollowing == true) {
		this->tower.setPosition(windowPos.x, windowPos.y);
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
		this->towerFollowing = false;
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
