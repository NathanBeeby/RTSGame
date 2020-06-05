#pragma once
#include "../Tower.h"
class ElementalAmplifierTower : virtual public Tower
{
private:
	// Private variables


	// Initialization
	void initVariables();
	void initTextures();
	void initSprites();
public:
	// Constructor / Destructor
	ElementalAmplifierTower();
	virtual ~ElementalAmplifierTower();

	// Public Variables
	int towerCost;
	// Accessors

	// Public Functions

};

