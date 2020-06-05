#pragma once
#include "../Tower.h"
class WaterTower : virtual public Tower
{
private:
	// Private variables

	// Initialization
	void initVariables();
	void initTextures();
	void initSprites();
public:
	// Constructor / Destructor
	WaterTower();
	virtual ~WaterTower();

	// Public Variables
	int towerCost;
	// Accessors

	// Public Functions

};

