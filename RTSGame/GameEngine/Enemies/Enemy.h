#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "../Map/PathWaypoints.h"
/*
	- Split up functions into sub-functions which serve one purpose each
	- Create Parent Class for enemy movement (AI class)

*/
class Enemy
{
private:
	// Private Variables
	sf::Texture enemytexture;
	
	std::vector<sf::RectangleShape> enemies;
	std::vector <sf::RectangleShape> enemyHealthBar;
	std::vector <sf::RectangleShape> enemyMaxHealthBar;
	sf::RectangleShape enemy;
	sf::RectangleShape healthBar;
	sf::RectangleShape maxHealthBar;

	//Waypoints code
	std::vector<int> currentPoint;
	std::vector<int> maxPoint;
	std::vector<int> enemyHealth;
	std::vector<int> enemyMaxHealth;
	int enemiesPassed;
	int enemiesKill;

	std::vector<sf::Vector2i> goalWaypoint;
	sf::Vector2i enemySize;

	PathWaypoints waypoint;

	int enemyNum;
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
	void setIsPaused(bool paused);
	void DeleteEnemy(int enemyId);
	void EnemyPassedGoal(int enemyId);
	void EnemyKilled(int enemyId);
	void DeleteAllEnemies();
	void updateEnemyWaypoint();
	void updateEnemyMovement(int i);
	void update();
	void render(sf::RenderTarget &target);
};

