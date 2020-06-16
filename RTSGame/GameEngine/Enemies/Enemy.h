#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "../Map/PathWaypoints.h"

class Enemy
{
private:
	// Private Variables
	int enemiesPassed, enemiesKill, enemyNum;
	sf::Texture enemytexture;
	sf::RectangleShape enemy, healthBar, maxHealthBar;
	std::vector<sf::RectangleShape> enemies, enemyHealthBar, enemyMaxHealthBar;
	//Waypoints code
	std::vector<int> currentPoint, maxPoint, enemyHealth, enemyMaxHealth;
	std::vector<sf::Vector2i> goalWaypoint;
	sf::Vector2i enemySize;
	PathWaypoints waypoint;

	// Initialization
	void initVariables();
	void initTextures();
	void initWaypoints();
	void initSprites();
public:
	// Constructor / Destructor
	Enemy();
	virtual ~Enemy();

	// Public Variables 
	std::vector<sf::Texture> enemyTextures;

	// Accessors
	const int enemiesPassedGoal() const;
	const int enemiesKilled() const;

	// Public Functions
	void ResizeArrays();
	void pushBackEnemy(sf::Vector2i enemyPos);

	void CreateEnemy(sf::Vector2i enemyPos);
	void DeleteEnemy(int enemyId);
	void EnemyPassedGoal(int enemyId);
	void EnemyKilled(int enemyId);
	void DeleteAllEnemies();
	void updateEnemyWaypoint();
	void updateEnemyMovement(int i);
	void update();
	void render(sf::RenderTarget &target);
};

