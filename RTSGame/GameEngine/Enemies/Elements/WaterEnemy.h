#pragma once
#include "../Enemy.h"
class WaterEnemy : virtual public Enemy
{
private:
	// Private Variables

	// Initialization
	void initVariables();
	void initTextures();
	void initSprites();
public:
	// Constructor / Destructor
	WaterEnemy();
	virtual ~WaterEnemy();

	// Public Variables

	// Accessors

	// Public Functions

};

