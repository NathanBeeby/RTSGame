#include "Player.h"
#include <iostream>


void Player::initVariables()
{
	this->movementSpeed = 10.f;
	this->spritePosition = sf::Vector2f(10, 10);
}

void Player::initTextures()
{
	if (!this->spriteTexture.loadFromFile("../Assets/Image_Assets/Sprites/basicSprite.png")) {
		std::cout << "Sprite didn't load" << std::endl;
	}
}

void Player::initSprites()
{
	sprite.setPosition(sf::Vector2f(spritePosition.x, spritePosition.y));
	sprite.setSize(sf::Vector2f(50, 50));
	sprite.setTexture(&this->spriteTexture);
}

Player::Player()
{
	this->initVariables();
	this->initTextures();
	this->initSprites();
}


Player::~Player()
{
}

const sf::Vector2f & Player::getPosition() const
{
	return this->spritePosition;
}

void Player::movePlayer(sf::Vector2f movePosition)
{
	if (movePosition.x > sprite.getPosition().x) {
		this->spritePosition.x = 1;
	}
	else if (movePosition.x < sprite.getPosition().x) {
		this->spritePosition.x = -1;
	}
	if (movePosition.y > sprite.getPosition().y) {
		this->spritePosition.y = 1;
	}
	else if (movePosition.y < sprite.getPosition().y) {
		this->spritePosition.y = -1;
	}

	this->sprite.move(spritePosition.x, spritePosition.y);
}

void Player::update()
{
}

void Player::render(sf::RenderTarget & target)
{
	target.draw(sprite);
}
