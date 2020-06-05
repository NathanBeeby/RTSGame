#pragma once
#include "Enemy.h"
class WaterEnemy : public Enemy
{
private:
	// Private Variables
	sf::RectangleShape water;
	sf::Texture texture;
	std::vector<sf::RectangleShape> waterEnemy;
	std::vector<sf::Texture> waterEnemyTextures;
	sf::Vector2i enemySize;
	int enemyNum;
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
	void CreateEnemy(sf::Vector2i enemyPos);
	void DeleteEnemy(int enemyId);
	void DeleteAllEnemies();
	void update();
	void render(sf::RenderTarget &target);
};

