#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <vector>
class Bullet
{
private:
	// Private Variables
	sf::Texture fireTexture, waterTexture, windTexture, iceTexture, earthTexture, energyTexture, lightTexture, darkTexture, voidTexture;


	void initTextures();

public:
	sf::RectangleShape sprite;
	sf::Vector2f currVelocity;
	sf::Vector2f origin;
	float maxSpeed;
	int element;
	float baseDamage;


	Bullet(float width = 30.f, float height = 60.f)
		: currVelocity(0.f, 0.f), maxSpeed(15.f), element(0)
	{
		this->initTextures();
		this->sprite.setSize(sf::Vector2f(width, height));

	}

	void update();
	//// Constructors / Destructor
	//Bullet();
	////Bullet(int ElementNo, int LevelNo, sf::Vector2i startPos, sf::Vector2i goalPos);
	//virtual ~Bullet();

	//// Public Variables
	//std::vector<sf::RectangleShape> bulletSprites;
	//std::vector<sf::Texture> bulletTextures;

	//// Accessors

	//// Modifiers
	//void CreateBullet(sf::Vector2i startPos, sf::Vector2i &goalPos, int elementNo, int levelNo, float damage, float speed);
	//void DestroyBullet();

	//// Public Functions
	//void updateBulletMovement(sf::Time deltaTime, float range);
	//void updateBulletRotation();
	//void update(sf::Time deltaTime, float range);
	//void render(sf::RenderTarget &target);
};

