#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <vector>
class Bullet
{
private:
	// Private Variables
	std::vector<std::string> fireTextureStrings;
	std::vector<std::string> waterTextureStrings;
	std::vector<std::string> windTextureStrings;
	std::vector<std::string> iceTextureStrings;
	std::vector<std::string> earthTextureStrings;
	std::vector<std::string> energyTextureStrings;
	std::vector<std::string> lightTextureStrings;
	std::vector<std::string> darkTextureStrings;
	std::vector<std::string> voidTextureStrings;
	sf::RectangleShape bulletSprite;
	std::vector<sf::Vector2i> startPosition, goalPosition;
	std::vector<int> damages, attackSpeeds;

	std::vector<sf::Texture> fireTextures, waterTextures, windTextures, iceTextures, earthTextures, energyTextures, lightTextures, darkTextures, voidTextures;

	int bulletSize;

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
	void CreateBullet(sf::Vector2i startPos, sf::Vector2i goalPos, int elementNo, int levelNo, int damage, int speed);
	void DestroyBullet();


	// Public Functions
	void updateBulletMovement(sf::Time deltaTime);
	void update(sf::Time deltaTime);
	void render(sf::RenderTarget &target);
};

