#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
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
- Make it so that the tower cost is within each tower class for the price
- When you place a tower, subtract the tower cost from the HUD mana, if you have enough mana
- If not enough mana, use a cross out texture for the tower image on the HUD
- Make the towers within this class public variables so they can be called by the GUI to access the tower cost.
- Make it so that the towers are placed on tiles, find the tiles where a structure is placed, if another structure is placed there, make it unable to place a tower on that tile. (use red cross to show that you aren't able to do that)
- For each tile on the map, give a boolean value for if the tile is water or a coastal tile. Coastal tiles can't place any tile. Bodies of water can only have water and ice towers.
- Create a Magma tile, an ice tile etc. When an ice tile is placed on a water tile, the water tile must turn to ice.
- Only fire towers should be placable on a magma tile.
*/
class StructureInventory
{
private:
	// Private Variables
	sf::RectangleShape tower;
	sf::Texture towerTexture;
	bool towerFollowing;
	bool towerIsPlacable;
	sf::Vector2i mousePosWindow;
	std::string towerToFollow;
	std::string fireString, waterString, windString, iceString, earthString, energyString, lightString, darkString, voidString, regenString, observString, manaAmpString, elementOverString, elementAmpString;
	int structurePrice;
	std::vector<sf::Vector2i> towerPlacementPositions;
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

	 // Public Functions

	void towerFollow(std::string &towerString);
	// Needs Tile Position & tower being placed
	int towerPlace(sf::Vector2i position);
	bool towerPlacable(sf::Vector2i position);
	void updateFollowing();
	void update();
	
	void mouseHandler(sf::Vector2i windowPos);
	void render(sf::RenderTarget &target);
	void renderTowers(sf::RenderTarget &target);
};

