#pragma once
#include "Enemy.h"
class DarkEnemy : public Enemy
{
private:
	// Private Variables
	sf::RectangleShape dark;
	sf::Texture texture;
	std::vector<sf::RectangleShape> darkEnemy;
	std::vector<sf::Texture> darkEnemyTextures;
	sf::Vector2i enemySize;
	int enemyNum;
	// Initialization
	void initVariables();
	void initTextures();
	void initSprites();
public:
	// Constructor / Destructor
	DarkEnemy();
	virtual ~DarkEnemy();

	// Public Variables

	// Accessors

	// Public Functions
	void CreateEnemy(sf::Vector2i enemyPos);
	void DeleteEnemy(int enemyId);
	void DeleteAllEnemies();
	void update();
	void render(sf::RenderTarget &target);
};

