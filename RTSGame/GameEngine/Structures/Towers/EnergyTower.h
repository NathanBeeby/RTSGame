#pragma once
#include "../Tower.h"
class EnergyTower : virtual public Tower
{
private:
	// Private variables

	// Initialization
	void initVariables();
	void initTextures();
	void initSprites();
public:
	// Constructor / Destructor
	EnergyTower();
	virtual ~EnergyTower();

	// Public Variables
	int towerCost;
	// Accessors

	// Public Functions
	
};

