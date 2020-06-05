#pragma once
#include "../Tower.h"
class EarthTower : virtual public Tower
{
private:
	// Private variables


	// Initialization
	void initVariables();
	void initTextures();
	void initSprites();
public:
	// Constructor / Destructor
	EarthTower();
	virtual ~EarthTower();

	// Public Variables
	int towerCost;
	// Accessors

	// Public Functions

};

