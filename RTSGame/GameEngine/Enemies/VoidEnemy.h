#pragma once
#include "Enemy.h"
class VoidEnemy : public Enemy
{
private:
	// Private Variables
	sf::RectangleShape voidEnem;
	sf::Texture texture;
	std::vector<sf::RectangleShape> voidEnemy;
	std::vector<sf::Texture> voidEnemyTextures;
	sf::Vector2i enemySize;
	int enemyNum;
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
	void CreateEnemy(sf::Vector2i enemyPos);
	void DeleteEnemy(int enemyId);
	void DeleteAllEnemies();
	void update();
	void render(sf::RenderTarget &target);
};

