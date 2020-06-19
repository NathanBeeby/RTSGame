#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "../../Map/PathWaypoints.h"

class Enemy
{
private:
	sf::Texture fireTexture, waterTexture, windTexture, iceTexture, earthTexture, energyTexture, lightTexture, darkTexture, voidTexture;
	
	void initTextures();
	void initWaypoints();
public:
	sf::RectangleShape sprite, maxHealthBar, healthBar;
	sf::Vector2f currVelocity;
	float movementSpeed;
	int health, element, currentPoint, maxPoint;

	sf::Vector2i goalWayPoint;
	PathWaypoints waypoint;
	bool passedGoal, killed;
	float spawnDelay;

	Enemy(float width = 150.f, float height = 150.f)
		: currVelocity(0.f, 0.f), movementSpeed(this->movementSpeed), element(this->element), health(100), spawnDelay(this->spawnDelay)
	{
		std::cout << "Enemy Element ID: " << this->element << std::endl;
		this->initTextures();
		this->initWaypoints();

		this->passedGoal = false;

		this->currentPoint = 0;
		this->maxPoint = this->waypoint.waypoints.size();
		this->goalWayPoint = sf::Vector2i(this->waypoint.waypoints[1].x, this->waypoint.waypoints[1].y);

		this->sprite.setSize(sf::Vector2f(width, height));
		
		this->maxHealthBar.setPosition(sprite.getPosition().x, sprite.getPosition().y - 10);
		this->maxHealthBar.setSize(sf::Vector2f(150.f, 20.f));
		this->maxHealthBar.setFillColor(sf::Color::Red);
		this->maxHealthBar.setOutlineColor(sf::Color::Black);
		this->maxHealthBar.setOutlineThickness(2);

		this->healthBar.setPosition(sprite.getPosition().x, sprite.getPosition().y - 10);
		this->healthBar.setSize(sf::Vector2f(this->health, 20.f));
		this->healthBar.setFillColor(sf::Color::Green);
	}

	void updateHealthPosition();
	void updateEnemyWaypoint();
	void updateEnemyMovement();
	void update();
};

