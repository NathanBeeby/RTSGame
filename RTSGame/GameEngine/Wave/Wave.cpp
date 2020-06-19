#include "Wave.h"



void Wave::initVariables()
{
	this->enemiesArePassed = 0;
	this->enemiesAreKilled = 0;
	this->enemyPerWave = 5;
	this->waveNum = 0;
	this->waveDifficulty = 1;
	this->enemyAmount = 0;
	this->enemyInRound = 0;
	this->waveBegan = false;
	this->wavePaused = false;
	this->element = 0; // element begins at fire
	this->manaReturn = 0;
	// Where the enemies begin (Possibly need to make if statement for each given maps start position)
	this->enemyStartPos = sf::Vector2i(0, (200 * 14) + 20);
	this->delayTimes.resize(enemyAmount);
	this->enemy.element = element;
}

Wave::Wave()
{
	this->initVariables();
}


Wave::~Wave()
{
}

const int Wave::getWaveNumber() const
{
	return this->waveNum;
}

const int Wave::getWaveDifficulty() const
{
	return this->waveDifficulty;
}

const int Wave::enemiesPassedGoal() const
{
	return this->enemiesArePassed;
}

const int Wave::enemiesKilled() const
{
	return this->enemiesAreKilled;
}

const int Wave::returnedMana() const
{
	return this->manaReturn;
}

void Wave::beginWave()
{
	if (enemyAmount == 0 && waveBegan == false) {
		this->mana += 150;
		this->waveBegan = true;
		this->element = (rand() % 8 + 1);
		this->waveNum++;
		this->enemyAmount = (waveNum * waveDifficulty) * enemyPerWave;
		for (int i = 0; i < enemyAmount; i++) {
			this->delayTimes.push_back(enemy.spawnDelay);
		}
	}
}


void Wave::pauseWave(bool pause)
{
	this->wavePaused = pause;
}

void Wave::updateEnemyInWave()
{
	if (waveBegan == true) {
		elapsed += waveClock.restart().asSeconds();
		for (int i = 0; i < enemyAmount; i++) {

			if (elapsed >= delayTimes[i]) {
				std::cout << "Enemy Delay Time: " << delayTimes[i];
				enemy.sprite.setPosition(sf::Vector2f(enemyStartPos));
				enemy.element = element;
				enemies.push_back(Enemy(enemy));

				this->waveClock.restart();
				this->enemyAmount--;
				this->elapsed = 0;
			}
		}
		if (enemyAmount <= 0) {
			waveBegan = false;
		}
	}
}

void Wave::updateEnemies()
{
	if (this->wavePaused == false) {
		enemy.update();
		for (size_t i = 0; i < enemies.size(); i++) {
			enemies[i].updateHealthPosition();
			enemies[i].updateEnemyWaypoint();

			if (enemies[i].health <= 0) {
				enemies.erase(enemies.begin() + i);
				this->enemiesAreKilled++;
			}
			if (enemies.size() > 0) {
				if (enemies[i].currentPoint == enemies[i].maxPoint) {
					enemies.erase(enemies.begin() + i);
					this->enemiesArePassed++;
				}
			}
		}
		//fireEnemy.update();
		//waterEnemy.update();
		//windEnemy.update();
		//iceEnemy.update();
		//earthEnemy.update();
		//energyEnemy.update();
		//lightEnemy.update();
		//darkEnemy.update();
		//voidEnemy.update();
	}
}


void Wave::update()
{
	this->updateEnemyInWave();
	this->updateEnemies();
}

void Wave::renderEnemies(sf::RenderTarget & target)
{
	for (size_t i = 0; i < enemies.size(); i++) {
		target.draw(enemies[i].sprite);
		target.draw(enemies[i].maxHealthBar);
		target.draw(enemies[i].healthBar);
	}
	//fireEnemy.render(target);
	//waterEnemy.render(target);
	//windEnemy.render(target);
	//iceEnemy.render(target);
	//earthEnemy.render(target);
	//energyEnemy.render(target);
	//lightEnemy.render(target);
	//darkEnemy.render(target);
	//voidEnemy.render(target);
}

void Wave::render(sf::RenderTarget & target)
{
	this->renderEnemies(target);
}
