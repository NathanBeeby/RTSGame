#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>

#include "../Wave/Wave.h"
#include "../Sprites/Tower/Tower.h"

/*
TODO: URGENT:
- For each tile on the map, give a boolean value for if the tile is water or a coastal tile. Coastal tiles can't place any tile. Bodies of water can only have water and ice towers.
- Create a Magma tile, an ice tile etc. When an ice tile is placed on a water tile, the water tile must turn to ice.
- Only fire towers should be placable on a magma tile.
*/
class StructureInventory
{
private:
	// Private Variables
	bool towerFollowing, towerIsPlacable;
	int structurePrice;
	int enemyKillMana;
	sf::RectangleShape towerImage;
	sf::Texture towerTexture;
	sf::Vector2i mousePosWindow;
	sf::Vector2i unplacablePos;
	std::string towerToFollow, fireString, waterString, windString, iceString, earthString, energyString, lightString, darkString, voidString, regenString, observString, manaAmpString, elementOverString, elementAmpString;
	sf::Texture fireTexture, waterTexture, windTexture, iceTexture, earthTexture, energyTexture, lightTexture, darkTexture, voidTexture, elemAmpTexture, elemOverTexture, regenTexture, observTexture, manaAmpTexture;
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
	std::vector<Tower> towers;
	Tower tower;

	int firePrice, waterPrice, windPrice, icePrice, earthPrice, energyPrice, lightPrice, darkPrice, elemAmpPrice, elemOverPrice, manaAmpPrice, observPrice, regenPrice, voidPrice;

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
	void deleteAllTowers();
	void updateFiring();
	void updateTowers(sf::Time deltaTime);
	void updateEnemiesKilled();
	void updateTowerFiring(sf::Vector2i &enemyPos);
	void update(sf::Time deltaTime);
	void mouseHandler(sf::Vector2i windowPos);
	void render(sf::RenderTarget &target);
	void renderTowers(sf::RenderTarget &target);
};

