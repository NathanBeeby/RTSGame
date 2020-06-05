#pragma once
#include "Enemy.h"
class EnergyEnemy : public Enemy
{
	// Private Variables
	sf::RectangleShape energy;
	sf::Texture texture;
	std::vector<sf::RectangleShape>energyEnemy;
	std::vector<sf::Texture> energyEnemyTextures;
	sf::Vector2i enemySize;
	int enemyNum;
	// Initialization
	void initVariables();
	void initTextures();
	void initSprites();
public:
	// Constructor / Destructor
	EnergyEnemy();
	virtual ~EnergyEnemy();

	// Public Variables

	// Accessors

	// Public Functions
	void CreateEnemy(sf::Vector2i enemyPos);
	void DeleteEnemy(int enemyId);
	void DeleteAllEnemies();
	void update();
	void render(sf::RenderTarget &target);
};

