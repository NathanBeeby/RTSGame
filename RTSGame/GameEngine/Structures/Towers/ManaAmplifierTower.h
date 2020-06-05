#pragma once
#include "../Tower.h"
class ManaAmplifierTower : virtual public Tower
{
private:
	// Private variables

	// Initialization
	void initVariables();
	void initTextures();
	void initSprites();
public:
	// Constructor / Destructor
	ManaAmplifierTower();
	virtual ~ManaAmplifierTower();

	// Public Variables
	int towerCost;
	// Accessors

	// Public Functions

};

