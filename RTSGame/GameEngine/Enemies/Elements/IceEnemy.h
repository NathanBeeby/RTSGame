#pragma once
#include "../Enemy.h"
class IceEnemy : public Enemy
{
private:
	// Private Variables

	// Initialization
	void initVariables();
	void initTextures();
	void initSprites();
public:
	// Constructor / Destructor
	IceEnemy();
	virtual ~IceEnemy();

	// Public Variables

	// Accessors

	// Public Functions
};

