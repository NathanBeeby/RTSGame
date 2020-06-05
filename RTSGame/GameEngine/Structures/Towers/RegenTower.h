#pragma once
#include "../Tower.h"
class RegenTower : virtual public Tower
{
private:
	// Private variables

	// Initialization
	void initVariables();
	void initTextures();
	void initSprites();
public:
	// Constructor / Destructor
	RegenTower();
	virtual ~RegenTower();

	// Public Variables
	int towerCost;
	// Accessors

	// Public Functions

};

