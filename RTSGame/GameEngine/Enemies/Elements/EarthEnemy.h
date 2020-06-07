#pragma once
#include "../Enemy.h"
class EarthEnemy : public Enemy
{
private:
	// Private Variables

	// Initialization
	void initVariables();
	void initTextures();
	void initSprites();
public:
	// Constructor / Destructor
	EarthEnemy();
	virtual ~EarthEnemy();

	// Public Variables

	// Accessors

	// Public Functions

};

