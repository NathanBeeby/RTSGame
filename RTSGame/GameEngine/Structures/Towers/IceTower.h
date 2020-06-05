#pragma once
#include "../Tower.h"
class IceTower : virtual public Tower
{
private:
	// Private variables

	// Initialization
	void initVariables();
	void initTextures();
	void initSprites();
public:
	// Constructor / Destructor
	IceTower();
	virtual ~IceTower();

	// Public Variables
	int towerCost;
	// Accessors

	// Public Functions

};

