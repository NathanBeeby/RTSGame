#pragma once
#include "Character.h"
class Player : public Character
{
private:
	// Private Variables
	sf::RectangleShape sprite;
	sf::Texture spriteTexture;
	float movementSpeed;
	sf::Vector2f spritePosition;

	// Initialization
	void initVariables();
	void initTextures();
	void initSprites();
public:
	// Constructor / Destructor
	Player();
	virtual ~Player();

	// Public Variables

	// Accessors
	const sf::Vector2f& getPosition() const;

	// Public Functions
	void movePlayer(sf::Vector2f movePosition);
	void update();
	void render(sf::RenderTarget &target);
};

