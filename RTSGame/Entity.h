#pragma once
#include <SFML/Graphics.hpp>
class Entity
{
private:
	void setVelocity(sf::Vector2f velocity);
	void setVelocity(float vx, float vy);
	sf::Vector2f getVelocity() const;
public:
	sf::Vector2f mVelocity;
};

