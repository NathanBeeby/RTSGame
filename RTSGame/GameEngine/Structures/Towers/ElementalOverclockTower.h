#pragma once
#include "../Tower.h"
class ElementalOverclockTower : virtual public Tower
{
private:
	// Private variables


	// Initialization
	void initVariables();
	void initTextures();
	void initSprites();
public:
	// Constructor / Destructor
	ElementalOverclockTower();
	virtual ~ElementalOverclockTower();

	// Public Variables
	int towerCost;
	// Accessors

	// Public Functions

};

