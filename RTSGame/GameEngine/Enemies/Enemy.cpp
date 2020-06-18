#include "Enemy.h"

/*

//	else if (!this->enemyTextures[2].loadFromFile("../Assets/Image_Assets/Enemies/Vampire.png")) {

//	else if (!this->enemyTextures[3].loadFromFile("../Assets/Image_Assets/Enemies/Werewolf.png")) {

//	if (!this->enemyTextures[0].loadFromFile("../Assets/Image_Assets/Enemies/Orc.png")) {

//	else if (!this->enemyTextures[1].loadFromFile("../Assets/Image_Assets/Enemies/Elf.png")) {
//	if (!this->enemyTextures[0].loadFromFile("../Assets/Image_Assets/Enemies/Demon.png")) {

//	else if (!this->enemyTextures[1].loadFromFile("../Assets/Image_Assets/Enemies/Dragon.png")) {
//	if (!this->enemyTextures[0].loadFromFile("../Assets/Image_Assets/Enemies/Yeti.png")) {

//	else if (!this->enemyTextures[1].loadFromFile("../Assets/Image_Assets/Enemies/IceWraith.png")) {
//	if (!this->enemyTextures[0].loadFromFile("../Assets/Image_Assets/Enemies/Kitsune.png")) {

//	if (!this->enemyTextures[0].loadFromFile("../Assets/Image_Assets/Enemies/Hydra.png")) {

//	else if (!this->enemyTextures[1].loadFromFile("../Assets/Image_Assets/Enemies/Mermaid.png")) {
*/

void Enemy::initTextures()
{
	if (!fireTexture.loadFromFile("../Assets/Image_Assets/Enemies/Demon.png")) {
		std::cout << "Error loading fire tower texture" << std::endl;
	}
	if (!waterTexture.loadFromFile("../Assets/Image_Assets/Enemies/Hydra.png")) {
		std::cout << "Error loading water tower texture" << std::endl;
	}
	if (!windTexture.loadFromFile("../Assets/Image_Assets/Enemies/Demon.png")) {
		std::cout << "Error loading wind tower texture" << std::endl;
	}
	if (!iceTexture.loadFromFile("../Assets/Image_Assets/Enemies/Yeti.png")) {
		std::cout << "Error loading ice tower texture" << std::endl;
	}
	if (!earthTexture.loadFromFile("../Assets/Image_Assets/Enemies/Orc.png")) {
		std::cout << "Error loading earth tower texture" << std::endl;
	}
	if (!energyTexture.loadFromFile("../Assets/Image_Assets/Enemies/Demon.png")) {
		std::cout << "Error loading energy tower texture" << std::endl;
	}
	if (!lightTexture.loadFromFile("../Assets/Image_Assets/Enemies/Kitsune.png")) {
		std::cout << "Error loading light tower texture" << std::endl;
	}
	if (!darkTexture.loadFromFile("../Assets/Image_Assets/Enemies/Vampire.png")) {
		std::cout << "Error loading dark tower texture" << std::endl;
	}
	if (!voidTexture.loadFromFile("../Assets/Image_Assets/Enemies/Demon.png")) {
		std::cout << "Error loading void tower texture" << std::endl;
	}
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
void Enemy::updateHealthPosition()
{
	this->maxHealthBar.setPosition(sprite.getPosition().x, sprite.getPosition().y - 10);
	this->healthBar.setPosition(sprite.getPosition().x, sprite.getPosition().y - 10);
}

void Enemy::updateEnemyWaypoint()
{
		if (this->currentPoint <= this->maxPoint) { // if the current waypoint isn't the last waypoint, run code below
			// If the enemy gets to the goal waypoint
			if (this->sprite.getPosition().x == this->goalWayPoint.x && this->sprite.getPosition().y == this->goalWayPoint.y) {
				this->currentPoint++;
				if (this->currentPoint < 7) {
					this->goalWayPoint = sf::Vector2i(this->waypoint.waypoints[currentPoint + 1].x, this->waypoint.waypoints[currentPoint + 1].y);
				}
				else {
					this->passedGoal = true;
				}
			}
			else {
				this->updateEnemyMovement();
			}
		}
	
}


void Enemy::updateEnemyMovement()
{
	// Movement Variables (enemies X and Y)
	float enemyMoveX = 0.f;
	float enemyMoveY = 0.f;

	// If not at goal point, move the enemy until it gets there
	if (this->sprite.getPosition().x < this->goalWayPoint.x) {
		enemyMoveX = this->movementSpeed;
	}
	else if (this->sprite.getPosition().x > this->goalWayPoint.x) {
		enemyMoveX = -this->movementSpeed;
	}
	else {
		enemyMoveX = 0.f;
	}
	if (this->sprite.getPosition().y < this->goalWayPoint.y) {
		enemyMoveY = this->movementSpeed;
	}
	else if (this->sprite.getPosition().y > this->goalWayPoint.y) {
		enemyMoveY = -this->movementSpeed;
	}
	else {
		enemyMoveY = 0.f;
	}
	this->sprite.move(enemyMoveX, enemyMoveY);
	this->maxHealthBar.move(enemyMoveX, enemyMoveY);
	this->healthBar.move(enemyMoveX, enemyMoveY);
}


void Enemy::update()
{
	if (this->element == 0) {
		this->sprite.setTexture(&fireTexture);
		this->movementSpeed = 5.f;
	}
	else if (this->element == 1) {
		this->sprite.setTexture(&waterTexture);
		this->movementSpeed = 0.5f;
	}
	else if (this->element == 2) {
		this->sprite.setTexture(&windTexture);
		this->movementSpeed = 2.5f;
	}
	else if (this->element == 3) {
		this->sprite.setTexture(&iceTexture);
		this->movementSpeed = 3.f;
	}
	else if (this->element == 4) {
		this->sprite.setTexture(&earthTexture);
		this->movementSpeed = 5.f;
	}
	else if (this->element == 5) {
		this->sprite.setTexture(&energyTexture);
		this->movementSpeed = 7.f;
	}
	else if (this->element == 6) {
		this->sprite.setTexture(&lightTexture);
		this->movementSpeed = 2.f;
	}
	else if (this->element == 7) {
		this->sprite.setTexture(&darkTexture);
		this->movementSpeed = 3.f;
	}
	else if (this->element == 8) {
		this->sprite.setTexture(&voidTexture);
		this->movementSpeed = 10.f;
	}
}
