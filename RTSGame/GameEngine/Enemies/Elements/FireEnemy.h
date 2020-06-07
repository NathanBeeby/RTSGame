#pragma once
#include "../Enemy.h"
class FireEnemy : virtual public Enemy
{
private:
	// Private Variables

	// Initialization
	void initVariables();
	void initTextures();
	void initSprites();
public:
	// Constructor / Destructor
	FireEnemy();
	virtual ~FireEnemy();

	// Public Variables

	// Accessors

	// Public Functions
};

