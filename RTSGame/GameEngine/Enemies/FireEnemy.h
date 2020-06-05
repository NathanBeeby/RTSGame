#pragma once
#include "Enemy.h"
class FireEnemy : public Enemy
{
private:
	// Private Variables
	sf::RectangleShape fire;
	sf::Texture texture;
	std::vector<sf::RectangleShape> fireEnemy;
	std::vector<sf::Texture> fireEnemyTextures;
	sf::Vector2i enemySize;
	int enemyNum;
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
	void CreateEnemy(sf::Vector2i enemyPos);
	void DeleteEnemy(int enemyId);
	void DeleteAllEnemies();
	void update();
	void render(sf::RenderTarget &target);
};

