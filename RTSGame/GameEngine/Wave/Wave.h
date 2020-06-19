#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <SFML/Graphics.hpp>
#include "../Sprites/Enemy/Enemy.h"

class Wave
{
private:
	//Private Variables
	int waveNum;
	int waveDifficulty;
	int enemyPerWave;
	int enemyAmount;
	int enemyInRound;
	int manaReturn;

	sf::Clock waveClock;
	float delayTime;
	float elapsed;
	std::vector<float> delayTimes;
	sf::Vector2i enemyStartPos;
	bool waveBegan, wavePaused;
	int element;

	// Initialization
	void initVariables();

public:
	// Constructor / Destructor
	Wave();
	virtual ~Wave();

	// Public Variables
	int mana, enemiesAreKilled, enemiesArePassed;
	std::vector<Enemy> enemies;
	Enemy enemy;

	//FireEnemy fireEnemy;
	//WaterEnemy waterEnemy;
	//WindEnemy windEnemy;
	//IceEnemy iceEnemy;
	//EarthEnemy earthEnemy;
	//EnergyEnemy energyEnemy;
	//LightEnemy lightEnemy;
	//DarkEnemy darkEnemy;
	//VoidEnemy voidEnemy;

	// Accessors
	const int getWaveNumber() const;
	const int getWaveDifficulty() const;
	const int enemiesPassedGoal() const;
	const int enemiesKilled() const;
	const int returnedMana() const;
	// Public Functions
	void beginWave();

	void pauseWave(bool pause);
	void updateEnemyInWave();
	void updateEnemies();
	void update();
	void renderEnemies(sf::RenderTarget &target);
	void render(sf::RenderTarget &target);

};

