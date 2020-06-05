#include "Wave.h"



void Wave::initVariables()
{
	this->enemyPerWave = 20;
	this->waveNum = 0;
	this->waveDifficulty = 1;
	this->enemyAmount = 0;
	this->enemyInRound = 0;
	this->enemyStartPos = sf::Vector2i(0, 2000);
	this->second = sf::seconds(1);
	this->waveBegan = false;
	this->element = 0; // element begins at fire
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

void Wave::beginWave()
{
	if (enemyAmount == 0 && waveBegan == false) {
		std::cout << "Element: " << this->element << std::endl;
		this->waveBegan = true;
		this->element = (rand() % 8 + 1);
		this->waveNum++;
		this->enemyAmount = (waveNum + waveDifficulty) * enemyPerWave;
	}
}


void Wave::updateEnemyInWave()
{
	if (waveBegan == true) {
		for (int i = 0; i < enemyAmount; i++) {
			if (this->waveClock.getElapsedTime().asSeconds() >= second.asSeconds()) {
				if (this->element == 0) {
					fireEnemy.CreateEnemy(enemyStartPos);
				}
				else if (this->element == 1) {
					waterEnemy.CreateEnemy(enemyStartPos);
				}
				else if (this->element == 2) {
					windEnemy.CreateEnemy(enemyStartPos);
				}
				else if (this->element == 3) {
					iceEnemy.CreateEnemy(enemyStartPos);
				}
				else if (this->element == 4) {
					earthEnemy.CreateEnemy(enemyStartPos);
				}
				else if (this->element == 5) {
					energyEnemy.CreateEnemy(enemyStartPos);
				}
				else if (this->element == 6) {
					lightEnemy.CreateEnemy(enemyStartPos);
				}
				else if (this->element == 7) {
					darkEnemy.CreateEnemy(enemyStartPos);
				}
				else {
					voidEnemy.CreateEnemy(enemyStartPos);
				}

				this->waveClock.restart();
				this->enemyAmount--;
			}
		}
		if (enemyAmount <= 0) {
			waveBegan = false;
		}
	}
}

void Wave::updateEnemies()
{
		fireEnemy.update();
		waterEnemy.update();
		windEnemy.update();
		iceEnemy.update();
		earthEnemy.update();
		energyEnemy.update();
		lightEnemy.update();
		darkEnemy.update();
		voidEnemy.update();
}


void Wave::update()
{
	this->updateEnemyInWave();
	this->updateEnemies();
}

void Wave::renderEnemies(sf::RenderTarget & target)
{
		fireEnemy.render(target);
		waterEnemy.render(target);
		windEnemy.render(target);
		iceEnemy.render(target);
		earthEnemy.render(target);
		energyEnemy.render(target);
		lightEnemy.render(target);
		darkEnemy.render(target);
		voidEnemy.render(target);
}

void Wave::render(sf::RenderTarget & target)
{
	this->renderEnemies(target);
}
