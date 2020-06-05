#pragma once
#include "Enemy.h"
class IceEnemy : public Enemy
{
private:
	// Private Variables
	sf::RectangleShape ice;
	sf::Texture texture;
	std::vector<sf::RectangleShape> iceEnemy;
	std::vector<sf::Texture> iceEnemyTextures;
	sf::Vector2i enemySize;
	int enemyNum;
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
	void CreateEnemy(sf::Vector2i enemyPos);
	void DeleteEnemy(int enemyId);
	void DeleteAllEnemies();
	void update();
	void render(sf::RenderTarget &target);
};

