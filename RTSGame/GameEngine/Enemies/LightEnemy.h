#pragma once
#include "Enemy.h"
class LightEnemy : public Enemy
{
private:
	// Private Variables
	sf::RectangleShape light;
	sf::Texture texture;
	std::vector<sf::RectangleShape> lightEnemy;
	std::vector<sf::Texture> lightEnemyTextures;
	sf::Vector2i enemySize;
	int enemyNum;
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
	void CreateEnemy(sf::Vector2i enemyPos);
	void DeleteEnemy(int enemyId);
	void DeleteAllEnemies();
	void update();
	void render(sf::RenderTarget &target);
};

