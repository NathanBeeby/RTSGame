#include "Enemy.h"


// Initialization
void Enemy::initVariables()
{
	// Integer Variables
	this->enemySize.x = 150;
	this->enemySize.y = 150;
	this->enemyNum = 0;
	this->enemiesPassed = 0;
	this->enemiesKill = 0;

	// Enemies array size initialization
	this->enemies.resize(enemyNum);
	this->enemyMaxHealth.resize(enemyNum);
	this->enemyMaxHealthBar.resize(enemyNum);
	this->enemyHealth.resize(enemyNum);
	this->enemyHealthBar.resize(enemyNum);

	// Waypoints initialization
	this->currentPoint.resize(enemyNum);
	this->maxPoint.resize(enemyNum);
	this->goalWaypoint.resize(enemyNum);
}

void Enemy::initTextures()
{
}

void Enemy::initWaypoints()
{
	waypoint.AddWayPoint(sf::Vector2i(0, (200 * 14) + 20));
	waypoint.AddWayPoint(sf::Vector2i((200 * 6) + 20, (200 * 14) + 20));
	waypoint.AddWayPoint(sf::Vector2i((200 * 6) + 20, (200 * 5) + 20));
	waypoint.AddWayPoint(sf::Vector2i((200 * 11) + 20, (200 * 5) + 20));
	waypoint.AddWayPoint(sf::Vector2i((200 * 11) + 20, (200 * 22) + 20));
	waypoint.AddWayPoint(sf::Vector2i((200 * 22) + 20, (200 * 22) + 20));
	waypoint.AddWayPoint(sf::Vector2i((200 * 22) + 20, (200 * 15) + 20));
	waypoint.AddWayPoint(sf::Vector2i((200 * 33) + 20, (200 * 15) + 20));
}

void Enemy::initSprites()
{
	// Randomly generate enemy health / generate health by level and element

	for (int i = 0; i < enemies.size(); i++) {
		this->enemies[i].setSize(sf::Vector2f(enemySize.x, enemySize.y));
		this->enemies[i].setTexture(&enemyTextures[0]);
		this->enemies[i].setPosition(sf::Vector2f(this->waypoint.waypoints[currentPoint[i]].x, this->waypoint.waypoints[currentPoint[i]].y));

		this->enemyMaxHealthBar[i].setSize(sf::Vector2f(this->enemyMaxHealth[i], 8.f));
		this->enemyMaxHealthBar[i].setFillColor(sf::Color::Red);
		this->enemyMaxHealthBar[i].setPosition(this->enemies[i].getPosition().x, this->enemies[i].getPosition().y - 10);
		this->enemyMaxHealthBar[i].setOutlineColor(sf::Color::Black);
		this->enemyMaxHealthBar[i].setOutlineThickness(2);

		this->enemyHealthBar[i].setSize(sf::Vector2f(this->enemyHealth[i], 8.f));
		this->enemyHealthBar[i].setFillColor(sf::Color::Green);
		this->enemyHealthBar[i].setPosition(this->enemies[i].getPosition().x, this->enemies[i].getPosition().y - 10);
		this->enemyHealthBar[i].setOutlineColor(sf::Color::Black);
		this->enemyHealthBar[i].setOutlineThickness(2);

	}
}

// Constructor / Destructor
Enemy::Enemy()
{
	this->initVariables();
	this->initTextures();
	this->initWaypoints();
	this->initSprites();
}


Enemy::~Enemy()
{
}

const int Enemy::enemiesPassedGoal() const
{
	return this->enemiesPassed;
}

const int Enemy::enemiesKilled() const
{
	return this->enemiesKill;
}

void Enemy::ResizeArrays()
{
	// Enemies array size initialization
	this->enemies.resize(enemyNum);
	this->enemyMaxHealth.resize(enemyNum);
	this->enemyMaxHealthBar.resize(enemyNum);
	this->enemyHealth.resize(enemyNum);
	this->enemyHealthBar.resize(enemyNum);

	// Waypoints initialization
	this->currentPoint.resize(enemyNum);
	this->maxPoint.resize(enemyNum);
	this->goalWaypoint.resize(enemyNum);
}

void Enemy::pushBackEnemy(sf::Vector2i enemyPos)
{
	this->enemy.setSize(sf::Vector2f(enemySize.x, enemySize.y));
	this->enemy.setPosition(sf::Vector2f(enemyPos.x, enemyPos.y));
	this->enemy.setTexture(&enemyTextures[0]);

	this->maxHealthBar.setSize(sf::Vector2f(150.f, 8.f));
	this->maxHealthBar.setPosition(sf::Vector2f(enemyPos.x, enemyPos.y - 10));
	this->maxHealthBar.setFillColor(sf::Color::Red);
	this->maxHealthBar.setOutlineColor(sf::Color::Black);
	this->maxHealthBar.setOutlineThickness(2);

	this->healthBar.setSize(sf::Vector2f(50.f, 8.f));
	this->healthBar.setPosition(sf::Vector2f(enemyPos.x, enemyPos.y - 10));
	this->healthBar.setFillColor(sf::Color::Green);
	this->healthBar.setOutlineColor(sf::Color::Black);
	this->healthBar.setOutlineThickness(2);

	this->enemies.push_back(this->enemy);
	this->enemyMaxHealthBar.push_back(this->maxHealthBar);
	this->enemyHealthBar.push_back(this->healthBar);
	this->currentPoint.push_back(0);
	this->maxPoint.push_back(this->waypoint.waypoints.size());
	this->goalWaypoint.push_back(sf::Vector2i(this->waypoint.waypoints[1].x, this->waypoint.waypoints[1].y));

	this->enemyMaxHealth.push_back(5.f);
	this->enemyHealth.push_back(150.f);
}

void Enemy::CreateEnemy(sf::Vector2i enemyPos)
{
	// ENEMY CODE
	this->enemyNum++; // Incrementing the enemy number which will be used to resize the arrays
	this->ResizeArrays(); // resizing the arrays 
	this->pushBackEnemy(enemyPos); // Creating the enemy
}

void Enemy::DeleteEnemy(int enemyId)
{
	this->enemyMaxHealth.erase(enemyMaxHealth.begin() + enemyId);
	this->enemyMaxHealthBar.erase(enemyMaxHealthBar.begin() + enemyId); // didnt erase from vector until second loop
	this->enemyHealth.erase(enemyHealth.begin() + enemyId);
	this->enemyHealthBar.erase(enemyHealthBar.begin() + enemyId); // didn't erase from vector until second loop
	this->enemies.erase(enemies.begin() + enemyId); // didn't erase from vector until second loop


	this->goalWaypoint.erase(goalWaypoint.begin() + enemyId);// didn't erase from vector until second loop
	this->currentPoint.erase(currentPoint.begin() + enemyId);// didn't erase from vector until second loop
	this->maxPoint.erase(maxPoint.begin() + enemyId);// didn't erase from vector until second loop
	//this->gui.RemoveHealth(1);
}

void Enemy::EnemyPassedGoal(int enemyId)
{
	this->DeleteEnemy(enemyId);
	this->enemiesPassed++;
}

void Enemy::EnemyKilled(int enemyId)
{
	this->DeleteEnemy(enemyId);
	this->enemiesKill++;
}

void Enemy::DeleteAllEnemies()
{
	for (int i = 0; i < enemies.size(); i++) {
		this->enemyMaxHealth.erase(enemyMaxHealth.begin() + i); // Issue Deleting
		this->enemyMaxHealthBar.erase(enemyMaxHealthBar.begin() + i); // didn't erase from array
		this->enemyHealth.erase(enemyHealth.begin() + i);
		this->enemyHealthBar.erase(enemyHealthBar.begin() + i);
		this->enemies.erase(enemies.begin() + i);

		this->goalWaypoint.erase(goalWaypoint.begin() + i);
		this->currentPoint.erase(currentPoint.begin() + i);
		this->maxPoint.erase(maxPoint.begin() + i);

	}
}

void Enemy::updateEnemyWaypoint()
{
	for (int i = 0; i < enemies.size(); i++) {
		if (this->currentPoint[i] <= this->maxPoint[i]) { // if the current waypoint isn't the last waypoint, run code below
			// If the enemy gets to the goal waypoint
			if (this->enemies[i].getPosition().x == this->goalWaypoint[i].x && this->enemies[i].getPosition().y == this->goalWaypoint[i].y) {
				this->currentPoint[i]++;
				if (this->currentPoint[i] < 7) {
					this->goalWaypoint[i] = sf::Vector2i(this->waypoint.waypoints[currentPoint[i] + 1].x, this->waypoint.waypoints[currentPoint[i] + 1].y);
				}
				else {
					this->EnemyPassedGoal(i);
				}
			}
			else {
				this->updateEnemyMovement(i);
			}
		}
	}
}


void Enemy::updateEnemyMovement(int i)
{
	// Movement Variables (enemies X and Y)
	float enemyMoveX = 0.f;
	float enemyMoveY = 0.f;

	// If not at goal point, move the enemy until it gets there
	if (this->enemies[i].getPosition().x < this->goalWaypoint[i].x) {
		enemyMoveX = 10.f;
	}
	else if (this->enemies[i].getPosition().x > this->goalWaypoint[i].x) {
		enemyMoveX = -10.f;
	}
	else {
		enemyMoveX = 0.f;
	}
	if (this->enemies[i].getPosition().y < this->goalWaypoint[i].y) {
		enemyMoveY = 10.f;
	}
	else if (this->enemies[i].getPosition().y > this->goalWaypoint[i].y) {
		enemyMoveY = -10.f;
	}
	else {
		enemyMoveY = 0.f;
	}
	this->enemies[i].move(enemyMoveX, enemyMoveY);
	this->enemyMaxHealthBar[i].move(enemyMoveX, enemyMoveY);
	this->enemyHealthBar[i].move(enemyMoveX, enemyMoveY);
}

void Enemy::update()
{
	this->updateEnemyWaypoint();

}

void Enemy::render(sf::RenderTarget & target)
{
	for (int i = 0; i < this->enemies.size(); i++) {
		target.draw(this->enemies[i]);
		target.draw(this->enemyMaxHealthBar[i]);
		target.draw(this->enemyHealthBar[i]);
	}
}
