#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <vector>
#include "../Bullet/Bullet.h"
class Tower {
private:
	sf::Texture fireTexture, waterTexture, windTexture, iceTexture, earthTexture, energyTexture, lightTexture, darkTexture, voidTexture, elemAmpTexture, elemOverTexture, manaAmpTexture, observTexture, regenTexture;
	sf::Clock bulletTimer;
	float delayTime, elapsed;

	//// Initialization
	void initVariables();
	void initTextures();
public:
	//// Constructor / Destructor
	Tower(float width = 200.f, float height = 200.f) :
		towerDamage(), towerRange(), towerAttackSpeed(), bulletSpeed(),
		element()
	{
		this->initTextures();

		this->sprite.setSize(sf::Vector2f(width, height));
		this->towerCenter = sf::Vector2f(this->sprite.getPosition().x + (this->sprite.getSize().x / 2), this->sprite.getPosition().y + (this->sprite.getSize().y / 2));
		this->delayTime -= this->towerAttackSpeed;

		this->radiusCircle.setFillColor(sf::Color(125, 125, 125, 15));
		this->radiusCircle.setOutlineThickness(2);
		this->radiusCircle.setOutlineColor(sf::Color(155, 155, 155));
		this->radiusCircle.setRadius(this->towerRange);

	}
	//// Public Variables
	sf::Vector2f towerSize, towerPos, aimDir, aimDirNorm, towerCenter;
	sf::CircleShape radiusCircle;
	sf::RectangleShape sprite;
	std::vector<Bullet> bullets;
	Bullet bullet;
	int towerCost, element; 
	float towerDamage, towerRange, towerAttackSpeed, bulletSpeed;
	bool towerIsClicked, towerSelected;

	//// Public Functions
	sf::Vector2f towerClicked(sf::Vector2i clickPos);

	void FireBullet(sf::Vector2f & enemyPos);
	void CreateBullet();
	void SelectTower(sf::Vector2f towerCenter);
	void DeselectTower();
	void update();
	void renderBullets(sf::RenderTarget & target);
	void render(sf::RenderTarget & target);
};



