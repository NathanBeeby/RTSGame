#pragma once
#include "../Tower.h"
class VoidTower : virtual public Tower
{
private:
	// Private variables


	// Initialization
	void initVariables();
	void initTextures();
	void initSprites();
public:
	// Constructor / Destructor
	VoidTower();
	virtual ~VoidTower();

	// Public Variables
	int towerCost;
	// Accessors

	// Public Functions

};

