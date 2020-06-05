#pragma once
#include "../Tower.h"
class DarkTower : virtual public Tower
{
private:
	// Private variables

	// Initialization
	void initVariables();
	void initTextures();
	void initSprites();
public:
	// Constructor / Destructor
	DarkTower();
	virtual ~DarkTower();

	// Public Variables
	int towerCost;
	// Accessors

	// Public Functions

};

