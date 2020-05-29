#pragma once
#include <iostream>
#include "Towers\FireTower.h"
#include "Towers\WaterTower.h"
#include "Towers\WindTower.h"
#include "Towers\IceTower.h"
#include "Towers\EarthTower.h"
#include "Towers\EnergyTower.h"
#include "Towers\LightTower.h"
#include "Towers\DarkTower.h"

class Tower {
private:
	// Private Variables
	FireTower fireTower;
	WaterTower waterTower;
	WindTower windTower;
	IceTower iceTower;
	EarthTower earthTower;
	EnergyTower energyTower;
	LightTower lightTower;
	DarkTower darkTower;
	// Private Functions

	// Initialization

public:
	// Constructor / Destructor
	Tower();
	virtual ~Tower();
	// Public Variables
struct Type
{
	int level; // 0-4
	int typeId; // 0-8 - Fire, Water, Wind, Ice, Earth, Energy, Light, Dark, Void
	std::string type; // Fire, Water, Wind, Ice, Earth, Energy, Light, Dark, Void

};

	// Accessors

	// Public Functions
	
};



