#pragma once
#include "Enemy.h"
class EarthEnemy : public Enemy
{
private:
	// Private Variables
	sf::RectangleShape earth;
	sf::Texture texture;
	std::vector<sf::RectangleShape> earthEnemy;
	std::vector<sf::Texture> earthEnemyTextures;
	sf::Vector2i enemySize;
	int enemyNum;
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
	void CreateEnemy(sf::Vector2i enemyPos);
	void DeleteEnemy(int enemyId);
	void DeleteAllEnemies();
	void update();
	void render(sf::RenderTarget &target);
};

