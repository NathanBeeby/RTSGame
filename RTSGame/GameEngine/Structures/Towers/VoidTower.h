#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
class VoidTower
{
private:
	// Private variables
	sf::RectangleShape voidT;
	sf::Texture texture;
	std::vector <sf::RectangleShape> voidTower;
	std::vector<sf::Texture> voidTowerTexture;
	sf::Vector2f towerSize, towerPos;
	int towerNum;
	bool voidClicked;
	// Private Functions

	// Initialization
	void initVariables();
	void initTextures();
	void initSprites();
public:
	// Constructor / Destructor
	VoidTower();
	~VoidTower();

	// Public Variables
	int towerCost;
	// Accessors

	// Public Functions
	sf::Vector2f towerClicked(sf::Vector2i clickPos);
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

