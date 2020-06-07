#pragma once
#include "../Enemy.h"
class LightEnemy : virtual public Enemy
{
private:
	// Private Variables
	
	// Initialization
	void initVariables();
	void initTextures();
	void initSprites();
public:
	// Constructor / Destructor
	LightEnemy();
	virtual ~LightEnemy();

	// Public Variables

	// Accessors

	// Public Functions

};

