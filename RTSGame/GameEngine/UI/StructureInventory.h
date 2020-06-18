#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>

#include "../Wave/Wave.h"

#include "../Structures/Towers/FireTower.h"
#include "../Structures/Towers/WaterTower.h"
#include "../Structures/Towers/WindTower.h"
#include "../Structures/Towers/IceTower.h"
#include "../Structures/Towers/EarthTower.h"
#include "../Structures/Towers/EnergyTower.h"
#include "../Structures/Towers/LightTower.h"
#include "../Structures/Towers/DarkTower.h"

#include "../Structures/Towers/ElementalAmplifierTower.h"
#include "../Structures/Towers/ElementalOverclockTower.h"
#include "../Structures/Towers/ManaAmplifierTower.h"
#include "../Structures/Towers/ObservatoryTower.h"
#include "../Structures/Towers/RegenTower.h"
#include "../Structures/Towers/VoidTower.h"
/*
TODO: URGENT:
- For each tile on the map, give a boolean value for if the tile is water or a coastal tile. Coastal tiles can't place any tile. Bodies of water can only have water and ice towers.
- Create a Magma tile, an ice tile etc. When an ice tile is placed on a water tile, the water tile must turn to ice.
- Only fire towers should be placable on a magma tile.



-------------MAIN------------------
- Tower placement is broken, look into why and fix this
*/
class StructureInventory
{
private:
	// Private Variables
	bool towerFollowing, towerIsPlacable;
	int structurePrice;
	sf::RectangleShape tower;
	sf::Texture towerTexture;
	sf::Vector2i mousePosWindow;
	sf::Vector2i unplacablePos;
	std::string towerToFollow, fireString, waterString, windString, iceString, earthString, energyString, lightString, darkString, voidString, regenString, observString, manaAmpString, elementOverString, elementAmpString;
	std::vector<sf::Vector2i> towerPlacementPositions;
	std::vector<sf::Vector2i> unplacablePositions;
	std::vector<sf::Vector2i> waterTiles;
	// Initialization
	void initVariables();
	void initSprites();
	void initFont();
	void initText();
public:
	// Constructor / Destructor
	StructureInventory();
	virtual ~StructureInventory();

	// Public Variables
	Wave wave;
	FireTower fireTower;
	WaterTower waterTower;
	WindTower windTower;
	IceTower iceTower;
	EarthTower earthTower;
	EnergyTower energyTower;
	LightTower lightTower;
	DarkTower darkTower;
	ElementalAmplifierTower elementalAmplifier;
	ElementalOverclockTower elementalOverclocker;
	ManaAmplifierTower manaAmplifier;
	ObservatoryTower observatory;
	RegenTower regenTower;
	VoidTower voidTower;

	// Accessors
	void setFollowing(bool follow);
	const bool isFollowing() const;
	const std::string towerIsFollowing() const;
	const int getTowerCost() const;
	sf::Vector2i returnUnplacablePosition(sf::Vector2i position);

	 // Public Functions
	void towerFollow(std::string &towerString);
	int towerPlace(sf::Vector2i position);
	void towerClicked(sf::Vector2i position);
	bool towerPlacable(sf::Vector2i position);
	void unplacablePosition(sf::Vector2i position);
	void waterTilePositions(sf::Vector2i position);
	void DeselectTowers();
	void deleteAllTowers();
	void updateFiring();
	void updateMousePosition(sf::Vector2i &windowPos, sf::Vector2f &viewPos, sf::Vector2i &gridPos);
	void updateTowers(sf::Time deltaTime);
	void updateTowerFiring(sf::Vector2i &enemyPos);
	void update(sf::Time deltaTime);
	void mouseHandler(sf::Vector2i windowPos);
	void render(sf::RenderTarget &target);
	void renderTowers(sf::RenderTarget &target);
};

