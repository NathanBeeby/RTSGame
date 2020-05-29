#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
class EarthTower
{
private:
	// Private variables
	sf::RectangleShape earth;
	sf::Texture texture;
	std::vector <sf::RectangleShape> earthTower;
	std::vector<sf::Texture> earthTowerTexture;
	sf::Vector2f towerSize;
	int towerNum;
	// Private Functions

	// Initialization
	void initVariables();
	void initTextures();
	void initSprites();
public:
	// Constructor / Destructor
	EarthTower();
	~EarthTower();

	// Public Variables
	int towerCost;
	// Accessors

	// Public Functions
	void CreateTower(sf::Vector2i towerPos);
	void SetTowerTexture(int towerId, std::string &towerTexture);
	void DeleteTower(int towerId);
	void update();
	void render(sf::RenderTarget &target);

	//void CreateTower();
	//void SetTowerTexture(int towerId, std::string &towerTexture);
	//void DeleteTower(int towerId);
};

