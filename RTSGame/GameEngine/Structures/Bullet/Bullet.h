#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <vector>
class Bullet
{
private:
	// Private Variables
	int bulletSize;
	sf::RectangleShape bulletSprite;
	std::vector<std::string> fireTextureStrings, waterTextureStrings, windTextureStrings, iceTextureStrings, earthTextureStrings, energyTextureStrings, lightTextureStrings, darkTextureStrings, voidTextureStrings;
	std::vector<int> damages, attackSpeeds;
	std::vector<sf::Vector2i> startPosition, goalPosition;
	std::vector<sf::Texture> fireTextures, waterTextures, windTextures, iceTextures, earthTextures, energyTextures, lightTextures, darkTextures, voidTextures;

	// Initialization
	void initVariables();
	void initStrings();
	void resizeStrings();
	void initTextures();
	void initSprites();
public:
	// Constructors / Destructor
	Bullet();
	//Bullet(int ElementNo, int LevelNo, sf::Vector2i startPos, sf::Vector2i goalPos);
	virtual ~Bullet();

	// Public Variables
	std::vector<sf::RectangleShape> bulletSprites;
	std::vector<sf::Texture> bulletTextures;

	// Accessors

	// Modifiers
	void CreateBullet(sf::Vector2i startPos, sf::Vector2i &goalPos, int elementNo, int levelNo, float damage, float speed);
	void DestroyBullet();

	// Public Functions
	void updateBulletMovement(sf::Time deltaTime, float range);
	void updateBulletRotation();
	void update(sf::Time deltaTime, float range);
	void render(sf::RenderTarget &target);
};

