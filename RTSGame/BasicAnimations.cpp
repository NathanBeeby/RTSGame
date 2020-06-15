#include "BasicAnimations.h"


// Initialization 
void BasicAnimations::initVariables()
{
	this->bloodTextureSize = 5;
}

void BasicAnimations::initTextures()
{
	if (!this->bloodTextures[0].loadFromFile("")) {
		std::cout << "Failed to load blood texture 0" << std::endl;
	}
	if (!this->bloodTextures[1].loadFromFile("")) {
		std::cout << "Failed to load blood texture 1" << std::endl;
	}
	if (!this->bloodTextures[2].loadFromFile("")) {
		std::cout << "Failed to load blood texture 2" << std::endl;
	}
	if (!this->bloodTextures[3].loadFromFile("")) {
		std::cout << "Failed to load blood texture 3" << std::endl;
	}
	if (!this->bloodTextures[4].loadFromFile("")) {
		std::cout << "Failed to load blood texture 4" << std::endl;
	}
}

void BasicAnimations::initSprites()
{
}

void BasicAnimations::initText()
{
}

// Constructor / Destructor
BasicAnimations::BasicAnimations()
{
}


BasicAnimations::~BasicAnimations()
{
}

// Public Functions
void BasicAnimations::Shake(sf::RectangleShape &shape)
{
	int shakeAmt = 4;
	for (int i = 0; i < shakeAmt; i++) {
		shape.move(10.f, 0.f);
		shape.rotate(4.f);
		shape.move(-10.f, 0.f);
		shape.rotate(-4.f);
	}
}

void BasicAnimations::Jump(sf::RectangleShape &shape)
{

}

void BasicAnimations::StrobeButtonEffect(sf::RectangleShape &sprite)
{
	sprite.setOutlineThickness(2);
	sprite.setOutlineColor(sf::Color::Yellow);
	// Find way to make strobe effect color
}

void BasicAnimations::BloodSplat(sf::RectangleShape &shape)
{
	bloodSplat.setSize(sf::Vector2f(shape.getSize().x, shape.getSize().y));
	bloodSplat.setPosition(sf::Vector2f(shape.getPosition().x, shape.getPosition().y));
	for(int i = 0; i < bloodTextures.size(); i++){
	bloodSplat.setTexture(&bloodTextures[i]);
	}
}

void BasicAnimations::BloodTrailEffect(sf::RectangleShape &shape)
{
}

void BasicAnimations::FadeToNothing(sf::RectangleShape &shape)
{
}

void BasicAnimations::GameOverText(sf::Vector2f centerPos)
{
}

void BasicAnimations::ManaToIcon(sf::RectangleShape &shape, sf::Vector2f centerPos, sf::Vector2f iconPos)
{
}

void BasicAnimations::HealthToIcon(sf::RectangleShape &shape, sf::Vector2f centerPos, sf::Vector2f iconPos)
{
}

void BasicAnimations::GameSuccessText(sf::Vector2f centerPos)
{
}

void BasicAnimations::render(sf::RenderTarget & target)
{
	target.draw(this->bloodSplat);
}
