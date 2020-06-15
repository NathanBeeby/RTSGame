#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Bullet\Bullet.h"
class Tower {
private:
	// Private Variables
	sf::RectangleShape tower;
	sf::Texture towerTexture;
	std::vector <sf::RectangleShape> towers;
	sf::Vector2f towerSize, towerPos;
	sf::CircleShape radiusCircle;
	int textureInt;
	int towerNum;
	bool towerIsClicked;
	bool towerSelected;
	// Private Functions

	// Initialization
	void initVariables();
	void initTextures();
	void initSprites();
public:
	// Constructor / Destructor
	Tower();
	virtual ~Tower();
	// Public Variables
	float towerDamage; // 0-4
	float towerRange;
	float towerAttackSpeed;
	int elementId; // 0-8 - Fire, Water, Wind, Ice, Earth, Energy, Light, Dark, Void
	std::string element; // Fire, Water, Wind, Ice, Earth, Energy, Light, Dark, Void
	int towerCost;
	Bullet bullet;
	std::vector<sf::Texture> towerTextures;



	// Accessors
const float getTowerRange() const;
const float getTowerSpeed() const;
const float getTowerDamage() const;
const bool isTowerSelected() const;


	// Public Functions
sf::Vector2f towerClicked(sf::Vector2i clickPos);

//void FireBullets(sf::Time deltaTime);
void FireBullet(int towerNum, sf::Vector2i enemyPos);
void CreateTower(sf::Vector2i towerPos);
void SelectTower(int towerID, sf::Vector2f towerCenter);
void DeselectTower();
void DeleteTower(int towerId);
void deleteTowers();
void updateTowerSelected();
void update(sf::Time deltaTime);
void render(sf::RenderTarget &target);
};



