#pragma once
#include <iostream>

class Tower {
private:
	// Private Variables
	int towerDamage, towerRange, towerSpeed;

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
const int getTowerRange() const;
const int getTowerSpeed() const;
const int getTowerDamage() const;


	// Public Functions
	
};



