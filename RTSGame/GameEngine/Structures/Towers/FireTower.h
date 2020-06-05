#pragma once
#include "../Tower.h"
class FireTower : virtual public Tower
{
private: 
	// Private variables


	// Initialization
	void initVariables();
	void initTextures();
	void initSprites();
public:
	// Constructor / Destructor
	FireTower();
	virtual ~FireTower();

	// Public Variables
	int towerCost;
	// Accessors

	// Public Functions
};

