#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "../Map/PathWaypoints.h"
//#include "../UI/GUI.h"
/*
	- Split up functions into sub-functions which serve one purpose each
	- Create Parent Class for enemy movement (AI class)

*/
class Enemy
{
private:
	// Private Variables
	sf::RectangleShape enemy;
	sf::Texture enemytexture;
	std::vector<sf::RectangleShape> enemies;
	sf::Vector2i enemySize;
	int enemiesPassed;
	int enemiesKill;

	//GUI gui;

	//Waypoints code
	std::vector<int> currentPoint;
	std::vector<int> maxPoint;

	std::vector<sf::Vector2i> goalWaypoint;
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
	void pushBackWaypoints();

	void CreateEnemy(sf::Vector2i enemyPos);
	void DeleteEnemy(int enemyId);
	void EnemyPassedGoal(int enemyId);
	void EnemyKilled(int enemyId);
	void DeleteAllEnemies();
	void updateEnemyWaypointAndMovement();
	void update();
	void render(sf::RenderTarget &target);
};

