#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <vector>
#include "Bullet\Bullet.h"
class Tower {
private:
	// Private Variables
	bool towerIsClicked, towerSelected;
	int textureInt, towerNum;
	sf::CircleShape radiusCircle;
	sf::RectangleShape tower;
	sf::Texture towerTexture;
	sf::Vector2f towerSize, towerPos, aimDir, aimDirNorm;
	sf::Vector2f mousePosWindow;
	sf::Vector2f mousePosView;
	sf::Vector2f mousePosGrid;
	std::vector<sf::Vector2f> aimDirs, aimDirNorms, towerCenters;
	std::vector <sf::RectangleShape> towers;

	std::vector<Bullet> bullets;
	// Initialization
	void initVariables();
	void initTextures();
	void initSprites();
public:
	// Constructor / Destructor
	Tower();
	virtual ~Tower();

	// Public Variables
	Bullet bullet;
	int towerCost, elementId; // 0-8 - Fire, Water, Wind, Ice, Earth, Energy, Light, Dark, Void
	float towerDamage, towerRange, towerAttackSpeed;
	float bulletSpeed;
	std::string element; // Fire, Water, Wind, Ice, Earth, Energy, Light, Dark, Void
	std::vector<sf::Texture> towerTextures;

	// Accessors
	const float getTowerRange() const;
	const float getTowerSpeed() const;
	const float getTowerDamage() const;
	const bool isTowerSelected() const;
	const bool isEnemyInRadius() const;
	const int getTowerAmount() const;
	// Public Functions
	sf::Vector2f towerClicked(sf::Vector2i clickPos);

	void FireBullets(sf::Vector2i & enemyPos);
	void FireBullet(sf::Vector2i &enemyPos);
	void CreateTower(sf::Vector2i towerPos);
	void SelectTower(int towerID, sf::Vector2f towerCenter);
	void DeselectTower();
	void DeleteTower(int towerId);
	void deleteTowers();
	void updateMousePosition(sf::Vector2i &windowPos, sf::Vector2f &viewPos, sf::Vector2i &gridPos);
	void update(sf::Time deltaTime);
	void render(sf::RenderTarget &target);
	void renderBullets(sf::RenderTarget &target);
};



