#include "Enemy.h"


// Initialization
void Enemy::initVariables()
{
	this->enemySize.x = 150;
	this->enemySize.y = 150;
	this->enemyNum = 0;
	this->enemies.resize(enemyNum);

	// Waypoints
	this->currentPoint.resize(enemyNum);
	this->maxPoint.resize(enemyNum);

	this->currentWaypoint.resize(enemyNum);
	this->goalWaypoint.resize(enemyNum);
}

void Enemy::initTextures()
{
}

void Enemy::initSprites()
{
	waypoint.AddWayPoint(sf::Vector2i(0, (200 * 14) + 20));
	waypoint.AddWayPoint(sf::Vector2i((200 * 6) + 20, (200 * 14) + 20));
	waypoint.AddWayPoint(sf::Vector2i((200 * 6) + 20, (200 * 5) + 20));
	waypoint.AddWayPoint(sf::Vector2i((200 * 11) + 20, (200 * 5) + 20));
	waypoint.AddWayPoint(sf::Vector2i((200 * 11) + 20, (200 * 22) + 20));
	waypoint.AddWayPoint(sf::Vector2i((200 * 22) + 20, (200 * 22) + 20));
	waypoint.AddWayPoint(sf::Vector2i((200 * 22) + 20, (200 * 15) + 20));
	waypoint.AddWayPoint(sf::Vector2i((200 * 33) + 20, (200 * 15) + 20));
	for (int i = 0; i < enemies.size(); i++) {
		this->enemies[i].setSize(sf::Vector2f(enemySize.x, enemySize.y));
		this->enemies[i].setTexture(&enemyTextures[0]);
		this->enemies[i].setPosition(sf::Vector2f(this->waypoint.waypoints[currentPoint[i]].x, this->waypoint.waypoints[currentPoint[i]].y));
	}
}

// Constructor / Destructor
Enemy::Enemy()
{
	this->initVariables();
	this->initTextures();
	this->initSprites();
}


Enemy::~Enemy()
{
}

void Enemy::CreateEnemy(sf::Vector2i enemyPos)
{
	// ENEMY CODE
	this->enemyNum++;
	this->enemies.resize(enemyNum);
	this->currentPoint.resize(enemyNum);
	this->maxPoint.resize(enemyNum);

	this->currentWaypoint.resize(enemyNum);
	this->goalWaypoint.resize(enemyNum);
	this->enemy.setSize(sf::Vector2f(enemySize.x, enemySize.y));
	this->enemy.setPosition(sf::Vector2f(enemyPos.x, enemyPos.y));
	this->enemy.setTexture(&enemyTextures[0]);
	this->enemies.push_back(this->enemy);
	// WAYPOINTS CODE
	this->currentPoint.push_back(0);
	this->maxPoint.push_back(this->waypoint.waypoints.size());
	this->currentWaypoint.push_back(sf::Vector2i(this->waypoint.waypoints[0].x, this->waypoint.waypoints[0].y));
	this->goalWaypoint.push_back(sf::Vector2i(this->waypoint.waypoints[1].x, this->waypoint.waypoints[1].y));

}

void Enemy::DeleteEnemy(int enemyId)
{
	this->enemies.erase(enemies.begin() + enemyId);
}

void Enemy::DeleteAllEnemies()
{
	for (int i = 0; i < enemies.size(); i++) {
		this->enemies.erase(enemies.begin() + i);
	}
}

void Enemy::updateEnemyWaypointAndMovement()
{
	// Movement Variables (enemies X and Y)
	float enemyMoveX = 0.f;
	float enemyMoveY = 0.f;

	for (int i = 0; i < enemies.size(); i++) {
		if (this->currentPoint[i] <= this->maxPoint[i]) { // if the current waypoint isn't the last waypoint, run code below
			// If the enemy gets to the goal waypoint
			if (this->enemies[i].getPosition().x == this->goalWaypoint[i].x && this->enemies[i].getPosition().y == this->goalWaypoint[i].y) {
				this->currentPoint[i]++;
				if (this->currentPoint[i] < 7) {
					this->goalWaypoint[i] = sf::Vector2i(this->waypoint.waypoints[currentPoint[i] + 1].x, this->waypoint.waypoints[currentPoint[i] + 1].y);
				}
				else {
					this->DeleteEnemy(i);
				}
			}
			else {

				// If not at goal point, move the enemy until it gets there
				if (this->enemies[i].getPosition().x < this->goalWaypoint[i].x) {
					enemyMoveX = 10.f;
				}
				else if (this->enemies[i].getPosition().x > this->goalWaypoint[i].x) {
					enemyMoveX = -10.f;
				}
				if (this->enemies[i].getPosition().y < this->goalWaypoint[i].y) {
					enemyMoveY = 10.f;
				}
				else if (this->enemies[i].getPosition().y > this->goalWaypoint[i].y) {
					enemyMoveY = -10.f;
				}
				this->enemies[i].move(enemyMoveX, enemyMoveY);
			}
		}

		//if (maxPoint[i] == 8) {
		//	if (this->currentPoint[i] == 7) {
		//		this->DeleteEnemy(i);
		//	}
		//}
		//else {
		//	// Remove enemy here and Remove lives from hud here
		//	this->enemies.erase(this->enemies.begin() + i);
		//	this->currentPoint.erase(this->currentPoint.begin() + i);
		//	this->maxPoint.erase(this->maxPoint.begin() + i);
		//	// TODO: REMOVE LIVES FROM HUD HERE

		//}
	}
}


void Enemy::update()
{
	this->updateEnemyWaypointAndMovement();

}

void Enemy::render(sf::RenderTarget & target)
{
	for (int i = 0; i < this->enemies.size(); i++) {
		target.draw(this->enemies[i]);
	}
}
