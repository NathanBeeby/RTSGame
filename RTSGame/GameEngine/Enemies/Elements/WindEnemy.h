#pragma once
#include "../Enemy.h"
class WindEnemy : virtual public Enemy
{
private:
	// Private Variables

	// Initialization
	void initVariables();
	void initTextures();
	void initSprites();
public:
	// Constructor / Destructor
	WindEnemy();
	virtual ~WindEnemy();

	// Public Variables

	// Accessors

	// Public Functions

};

