#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
class BasicAnimations
{
private:
	// Private Variables
	int bloodTextureSize;
	sf::RectangleShape bloodSplat;
	std::vector<sf::Texture> bloodTextures;

	// Initialization
	void initVariables();
	void initTextures();
	void initSprites();
	void initText();
public:
	// Constructor / Destructor
	BasicAnimations();
	virtual ~BasicAnimations();

	// Public Variables

	// Accessors

	// Public Functions
	void Shake(sf::RectangleShape &shape); // For Menu Items - Possible for company into - Move rectangle side to side and rotate it left and right slightly
	void Jump(sf::RectangleShape &shape); // For Menu items - Possibly for company intro - Moves rectangle up then back town to its original position
	void StrobeButtonEffect(sf::RectangleShape &sprite); // On Menu Buttons - instead of having a different color text for buttons when using keyboard,
	// Strobe effect will be an outline which will change color
	void BloodSplat(sf::RectangleShape &shape); // For enemies - Once enemy is killed, on the position of the enemy, a blood splay effect should appear
	void BloodTrailEffect(sf::RectangleShape &shape); // For enemies - Blood path follows enemies and erases once enemy is 2 tiles away
	void FadeToNothing(sf::RectangleShape &shape); // For Enemies - enemy expands whilst also increasing translucence until enemy disappears and enemy will then be erased
	void GameOverText(sf::Vector2f centerPos);
	void ManaToIcon(sf::RectangleShape &shape, sf::Vector2f centerPos, sf::Vector2f iconPos); // Once round is over, mana rectangle shapes will move from the center of the screen to the mana icon, and then erase
	void HealthToIcon(sf::RectangleShape &shape, sf::Vector2f centerPos, sf::Vector2f iconPos); // Once round is over, heart rectangle shapes will move from the center of the screen to the health icon, and then erase
	void GameSuccessText(sf::Vector2f centerPos);

	void update();
	void render(sf::RenderTarget &target);
};

