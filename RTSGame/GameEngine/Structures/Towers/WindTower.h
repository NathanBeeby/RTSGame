#pragma once
#include "../Tower.h"
class WindTower : virtual public Tower
{
private:
	// Private variables

	// Initialization
	void initVariables();
	void initTextures();
	void initSprites();
public:
	// Constructor / Destructor
	WindTower();
	virtual ~WindTower();

	// Public Variables
	int towerCost;

	// Accessors

	// Public Functions

};

