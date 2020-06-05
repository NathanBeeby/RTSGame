#pragma once
#include "../Tower.h"
class ObservatoryTower : virtual public Tower
{
private:
	// Private variables


	// Initialization
	void initVariables();
	void initTextures();
	void initSprites();
public:
	// Constructor / Destructor
	ObservatoryTower();
	virtual ~ObservatoryTower();

	// Public Variables
	int towerCost;
	// Accessors

	// Public Functions

};

