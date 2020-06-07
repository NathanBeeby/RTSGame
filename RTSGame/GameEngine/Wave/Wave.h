#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <SFML/Graphics.hpp>
#include "../Enemies/Elements/FireEnemy.h"
#include "../Enemies/Elements/WaterEnemy.h"
#include "../Enemies/Elements/WindEnemy.h"
#include "../Enemies/Elements/IceEnemy.h"
#include "../Enemies/Elements/EarthEnemy.h"
#include "../Enemies/Elements/EnergyEnemy.h"
#include "../Enemies/Elements/LightEnemy.h"
#include "../Enemies/Elements/DarkEnemy.h"
#include "../Enemies/Elements/VoidEnemy.h"

class Wave
{
private:
	//Private Variables
	int waveNum;
	int waveDifficulty;
	int enemyPerWave;
	int enemyAmount;
	int enemyInRound;

	sf::Clock waveClock;
	sf::Vector2i enemyStartPos;
	sf::Time second;
	bool waveBegan;
	int element;

	FireEnemy fireEnemy;
	WaterEnemy waterEnemy;
	WindEnemy windEnemy;
	IceEnemy iceEnemy;
	EarthEnemy earthEnemy;
	EnergyEnemy energyEnemy;
	LightEnemy lightEnemy;
	DarkEnemy darkEnemy;
	VoidEnemy voidEnemy;

	// Initialization
	void initVariables();

public:
	// Constructor / Destructor
	Wave();
	virtual ~Wave();

	// Public Variables

	// Accessors
	const int getWaveNumber() const;
	const int getWaveDifficulty() const;

	// Public Functions
	void beginWave();

	void updateEnemyInWave();
	void updateEnemies();
	void update();
	void renderEnemies(sf::RenderTarget &target);
	void render(sf::RenderTarget &target);

};

