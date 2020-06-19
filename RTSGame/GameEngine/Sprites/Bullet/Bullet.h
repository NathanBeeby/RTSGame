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
		: currVelocity(0.f, 0.f), maxSpeed(this->maxSpeed), element(this->element)
	{

		this->initTextures();
		this->sprite.setSize(sf::Vector2f(width, height));

	}

	void update();
};

