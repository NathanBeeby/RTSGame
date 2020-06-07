#pragma once
#include "../Enemy.h"
class VoidEnemy : virtual public Enemy
{
private:
	// Private Variables

	// Initialization
	void initVariables();
	void initTextures();
	void initSprites();
public:
	// Constructor / Destructor
	VoidEnemy();
	virtual ~VoidEnemy();

	// Public Variables

	// Accessors

	// Public Functions

};

