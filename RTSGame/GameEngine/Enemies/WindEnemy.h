#pragma once
#include "Enemy.h"
class WindEnemy : public Enemy
{
private:
	// Private Variables
	sf::RectangleShape wind;
	sf::Texture texture;
	std::vector<sf::RectangleShape> windEnemy;
	std::vector<sf::Texture> windEnemyTextures;
	sf::Vector2i enemySize;
	int enemyNum;

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
	void CreateEnemy(sf::Vector2i enemyPos);
	void DeleteEnemy(int enemyId);
	void DeleteAllEnemies();
	void update();
	void render(sf::RenderTarget &target);
};

