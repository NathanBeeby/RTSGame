#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
class EnergyTower
{
private:
	// Private variables
	sf::RectangleShape energy;
	sf::Texture texture;
	std::vector <sf::RectangleShape> energyTower;
	std::vector<sf::Texture> energyTowerTexture;
	sf::Vector2f towerSize;
	int towerNum;
	// Private Functions

	// Initialization
	void initVariables();
	void initTextures();
	void initSprites();
public:
	// Constructor / Destructor
	EnergyTower();
	~EnergyTower();

	// Public Variables
	int towerCost;
	// Accessors

	// Public Functions
	void CreateTower(sf::Vector2i towerPos);
	void SetTowerTexture(int towerId, std::string &towerTexture);
	void DeleteTower(int towerId);
	void deleteTowers();
	void update();
	void render(sf::RenderTarget &target);

	//void CreateTower();
	//void SetTowerTexture(int towerId, std::string &towerTexture);
	//void DeleteTower(int towerId);
};

