#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
class Tower {
private:
	// Private Variables
	int towerDamage, towerRange, towerSpeed;
	sf::RectangleShape tower;
	sf::Texture towerTexture;
	std::vector <sf::RectangleShape> towers;
	sf::Vector2f towerSize, towerPos;
	sf::CircleShape radiusCircle;
	int textureInt;
	int towerNum;
	bool towerIsClicked;
	bool towerSelected;
	// Private Functions

	// Initialization
	void initVariables();
	void initTextures();
	void initSprites();
public:
	// Constructor / Destructor
	Tower();
	virtual ~Tower();
	// Public Variables
	int towerCost;
	float radius;
	std::vector<sf::Texture> towerTextures;

struct Type
{
	int level; // 0-4
	int typeId; // 0-8 - Fire, Water, Wind, Ice, Earth, Energy, Light, Dark, Void
	std::string type; // Fire, Water, Wind, Ice, Earth, Energy, Light, Dark, Void

};

	// Accessors
const int getTowerRange() const;
const int getTowerSpeed() const;
const int getTowerDamage() const;
const bool isTowerSelected() const;


	// Public Functions
sf::Vector2f towerClicked(sf::Vector2i clickPos);

void CreateTower(sf::Vector2i towerPos);
void SelectTower(int towerID, sf::Vector2f towerCenter);
void DeselectTower();
void DeleteTower(int towerId);
void deleteTowers();
void updateTowerSelected();
void update();
void render(sf::RenderTarget &target);
};



