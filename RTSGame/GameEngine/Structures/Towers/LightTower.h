#pragma once
#include "../Tower.h"
class LightTower: virtual public Tower
{
private:
	// Private variables

	// Initialization
	void initVariables();
	void initTextures();
	void initSprites();
public:
	// Constructor / Destructor
	LightTower();
	~LightTower();

	// Public Variables
	int towerCost;
	// Accessors

	// Public Functions

};

