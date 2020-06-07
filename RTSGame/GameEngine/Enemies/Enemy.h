#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "../Map/PathWaypoints.h"
class Enemy
{
private:
	// Private Variables
	sf::RectangleShape enemy;
	sf::Texture enemytexture;
	std::vector<sf::RectangleShape> enemies;
	sf::Vector2i enemySize;


	//Waypoints code
	std::vector<int> currentPoint;
	std::vector<int> maxPoint;


	std::vector<sf::Vector2i> currentWaypoint;
	std::vector<sf::Vector2i> goalWaypoint;
	PathWaypoints waypoint;




	int enemyNum;
	// Initialization
	void initVariables();
	void initTextures();
	void initSprites();
public:
	// Constructor / Destructor
	Enemy();
	virtual ~Enemy();

	// Public Variables 
	std::vector<sf::Texture> enemyTextures;

	// Accessors

	// Public Functions
	void CreateEnemy(sf::Vector2i enemyPos);
	void DeleteEnemy(int enemyId);
	void DeleteAllEnemies();
	void updateEnemyWaypointAndMovement();
	void update();
	void render(sf::RenderTarget &target);
};

