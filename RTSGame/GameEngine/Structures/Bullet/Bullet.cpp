#include "Bullet.h"

//
//// Initialization
//void Bullet::initVariables()
//{
//	// Integer Variables
//	this->bulletSize = 0;
//
//	// Vector Sizes
//	this->bulletSprites.resize(bulletSize);
//	this->goalPosition.resize(bulletSize);
//	this->startPosition.resize(bulletSize);
//	this->damages.resize(bulletSize);
//	this->attackSpeeds.resize(bulletSize);
//
//	this->fireTextures.resize(1);
//	this->waterTextures.resize(1);
//	this->windTextures.resize(1);
//	this->iceTextures.resize(1);
//	this->earthTextures.resize(1);
//	this->energyTextures.resize(1);
//	this->lightTextures.resize(1);
//	this->darkTextures.resize(1);
//	this->voidTextures.resize(1);
//
//}
//
//void Bullet::initStrings()
//{
//	this->fireTextureStrings[0] = "../Assets/Image_Assets/Towers/Bullets/Fire/FireBullet0.png";
//	this->waterTextureStrings[0] = "../Assets/Image_Assets/Towers/Bullets/Water/WaterBullet0.png";
//	this->windTextureStrings[0] = "../Assets/Image_Assets/Towers/Bullets/Wind/WindBullet0.png";
//	this->iceTextureStrings[0] = "../Assets/Image_Assets/Towers/Bullets/Ice/IceBullet0.png";
//	this->earthTextureStrings[0] = "../Assets/Image_Assets/Towers/Bullets/Earth/EarthBullet0.png";
//	this->energyTextureStrings[0] = "../Assets/Image_Assets/Towers/Bullets/Energy/EnergyBullet0.png";
//	this->lightTextureStrings[0] = "../Assets/Image_Assets/Towers/Bullets/Light/LightBullet0.png";
//	this->darkTextureStrings[0] = "../Assets/Image_Assets/Towers/Bullets/Dark/DarkBullet0.png";
//	this->voidTextureStrings[0] = "../Assets/Image_Assets/Towers/Bullets/Void/VoidBullet0.png";
//}
//
//void Bullet::initTextures()
//{
//
//	if (!fireTextures[0].loadFromFile(fireTextureStrings[0])) {
//		std::cout << "Fire Textures not loaded" << std::endl;
//	}
//	if (!waterTextures[0].loadFromFile(waterTextureStrings[0])) {
//		std::cout << "Water Textures not loaded" << std::endl;
//	}
//	if (!windTextures[0].loadFromFile(windTextureStrings[0])) {
//		std::cout << "Wind Textures not loaded" << std::endl;
//	}
//	if (!iceTextures[0].loadFromFile(iceTextureStrings[0])) {
//		std::cout << "Ice Textures not loaded" << std::endl;
//	}
//	if (!earthTextures[0].loadFromFile(earthTextureStrings[0])) {
//		std::cout << "Earth Textures not loaded" << std::endl;
//	}
//	if (!energyTextures[0].loadFromFile(energyTextureStrings[0])) {
//		std::cout << "Energy Textures not loaded" << std::endl;
//	}
//	if (!lightTextures[0].loadFromFile(lightTextureStrings[0])) {
//		std::cout << "Light Textures not loaded" << std::endl;
//	}
//	if (!darkTextures[0].loadFromFile(darkTextureStrings[0])) {
//		std::cout << "Dark Textures not loaded" << std::endl;
//	}
//	if (!voidTextures[0].loadFromFile(voidTextureStrings[0])) {
//		std::cout << "Void Textures not loaded" << std::endl;
//	}
//}
//
//void Bullet::initSprites()
//{
//	for (int i = 0; i < bulletSprites.size(); i++) {
//		this->bulletSprites[i].setSize(sf::Vector2f(30, 60));
//		this->bulletSprites[i].setPosition(sf::Vector2f(-200, -200));
//		this->bulletSprites[i].setTexture(&this->voidTextures[0]);
//	}
//}
//
//// Constructor / Destructor
//Bullet::Bullet()
//{
//	this->initVariables();
//	this->resizeStrings();
//	this->initStrings();
//	this->initTextures();
//	this->initSprites();
//}
//
//Bullet::~Bullet()
//{
//}
//
//// Public Functions
//void Bullet::resizeStrings()
//{
//	// Initializing String vector size
//	this->fireTextureStrings.resize(1);
//	this->waterTextureStrings.resize(1);
//	this->windTextureStrings.resize(1);
//	this->iceTextureStrings.resize(1);
//	this->earthTextureStrings.resize(1);
//	this->energyTextureStrings.resize(1);
//	this->lightTextureStrings.resize(1);
//	this->darkTextureStrings.resize(1);
//	this->voidTextureStrings.resize(1);
//}
//
//void Bullet::CreateBullet(sf::Vector2i startPos, sf::Vector2i &goalPos, int elementNo, int levelNo, float damage, float speed)
//{
//	this->bulletSprite.setSize(sf::Vector2f(30, 60));
//	this->bulletSprite.setPosition(sf::Vector2f(startPos.x, startPos.y));
//	if (elementNo == 0) {
//		this->bulletSprite.setTexture(&this->fireTextures[0]);
//	}
//	else if (elementNo == 1) {
//		this->bulletSprite.setTexture(&this->waterTextures[0]);
//	}
//	else if (elementNo == 2) {
//		this->bulletSprite.setTexture(&this->windTextures[0]);
//	}
//	else if (elementNo == 3) {
//		this->bulletSprite.setTexture(&this->iceTextures[0]);
//	}
//	else if (elementNo == 4) {
//		this->bulletSprite.setTexture(&this->earthTextures[0]);
//	}
//	else if (elementNo == 5) {
//		this->bulletSprite.setTexture(&this->energyTextures[0]);
//	}
//	else if (elementNo == 6) {
//		this->bulletSprite.setTexture(&this->lightTextures[0]);
//	}
//	else if (elementNo == 7) {
//		this->bulletSprite.setTexture(&this->darkTextures[0]);
//	}
//	else if (elementNo == 8) {
//		this->bulletSprite.setTexture(&this->voidTextures[0]);
//	}
//
//	this->bulletSprites.push_back(bulletSprite);
//	this->goalPosition.push_back(goalPos);
//	this->startPosition.push_back(startPos);
//	this->damages.push_back(damage);
//	this->attackSpeeds.push_back(speed);
//}
//
//void Bullet::DestroyBullet()
//{
//	for (int i = 0; i < bulletSprites.size(); i++) {
//		if (bulletSprites[i].getPosition().x == goalPosition[i].x && bulletSprites[i].getPosition().y == goalPosition[i].y) {
//			this->bulletSprites.erase(bulletSprites.begin() + i);
//		}
//	}
//}
//
//void Bullet::updateBulletMovement(sf::Time deltaTime, float range)
//{
//	int moveX = 0;
//	int moveY = 0;
//
//	for (int i = 0; i < bulletSprites.size(); i++) {
//		if (bulletSprites[i].getPosition().x > goalPosition[i].x) {
//			moveX = -attackSpeeds[i];
//		}
//		else if (bulletSprites[i].getPosition().x < goalPosition[i].x) {
//			moveX = attackSpeeds[i];
//		}
//		else {
//			moveX = 0;
//		}
//
//		if (bulletSprites[i].getPosition().y > goalPosition[i].y) {
//			moveY = -attackSpeeds[i];
//		}
//		else if (bulletSprites[i].getPosition().y < goalPosition[i].y) {
//			moveY = attackSpeeds[i];
//		}
//		else {
//			moveY = 0;
//		}
//		if (moveX != 0 || moveY != 0) {
//			this->bulletSprites[i].move(moveX, moveY);
//		}
//	}
//}
//
//void Bullet::updateBulletRotation()
//{
//	for (int i = 0; i < bulletSprites.size(); i++) {
//		if (this->bulletSprites[i].getPosition().x > this->goalPosition[i].x && this->bulletSprites[i].getPosition().y == this->goalPosition[i].y) {
//			this->bulletSprite.setRotation(-90.f);
//		}
//		else if (this->bulletSprites[i].getPosition().x < this->goalPosition[i].x && this->bulletSprites[i].getPosition().y == this->goalPosition[i].y) {
//			this->bulletSprites[i].setRotation(90.f);
//		}
//		else if (this->bulletSprites[i].getPosition().x == this->goalPosition[i].x && this->bulletSprites[i].getPosition().y > this->goalPosition[i].y) {
//			this->bulletSprites[i].setRotation(0.f);
//		}
//		else if (this->bulletSprites[i].getPosition().x == this->goalPosition[i].x && this->bulletSprites[i].getPosition().y < this->goalPosition[i].y) {
//			this->bulletSprites[i].setRotation(180.f);
//		}
//
//		else if (this->bulletSprites[i].getPosition().x > this->goalPosition[i].x && this->bulletSprites[i].getPosition().y > this->goalPosition[i].y) {
//			this->bulletSprites[i].setRotation(-45.f);
//		}
//		else if (this->bulletSprites[i].getPosition().x < this->goalPosition[i].x && this->bulletSprites[i].getPosition().y < this->goalPosition[i].y) {
//			this->bulletSprites[i].setRotation(135.f);
//		}
//		else if (this->bulletSprites[i].getPosition().x < this->goalPosition[i].x && this->bulletSprites[i].getPosition().y > this->goalPosition[i].y) {
//			this->bulletSprites[i].setRotation(45.f);
//		}
//		else if (this->bulletSprites[i].getPosition().x > this->goalPosition[i].x && this->bulletSprites[i].getPosition().y < this->goalPosition[i].y) {
//			this->bulletSprites[i].setRotation(-135.f);
//		}
//	}
//}
//
//
//void Bullet::update(sf::Time deltaTime, float range)
//{
//	this->updateBulletMovement(deltaTime, range);
//	this->updateBulletRotation();
//	this->DestroyBullet();
//}
//
//void Bullet::render(sf::RenderTarget & target)
//{
//	for (int i = 0; i < bulletSprites.size(); i++) {
//		target.draw(bulletSprites[i]);
//	}
//}

void Bullet::initTextures()
{
	if (!this->fireTexture.loadFromFile("../Assets/Image_Assets/Towers/Bullets/Fire/FireBullet0.png")) {
		std::cout << "Failed to load fire bullet texture" << std::endl;
	}
	if (!this->waterTexture.loadFromFile("../Assets/Image_Assets/Towers/Bullets/Water/WaterBullet0.png")) {
		std::cout << "Failed to load water bullet texture" << std::endl;
	}
	if (!this->windTexture.loadFromFile("../Assets/Image_Assets/Towers/Bullets/Wind/WindBullet0.png")) {
		std::cout << "Failed to load wind bullet texture" << std::endl;
	}
	if (!this->iceTexture.loadFromFile("../Assets/Image_Assets/Towers/Bullets/Ice/IceBullet0.png")) {
		std::cout << "Failed to load ice bullet texture" << std::endl;
	}
	if (!this->earthTexture.loadFromFile("../Assets/Image_Assets/Towers/Bullets/Earth/EarthBullet0.png")) {
		std::cout << "Failed to load earth bullet texture" << std::endl;
	}
	if (!this->energyTexture.loadFromFile("../Assets/Image_Assets/Towers/Bullets/Energy/EnergyBullet0.png")) {
		std::cout << "Failed to load energy bullet texture" << std::endl;
	}
	if (!this->lightTexture.loadFromFile("../Assets/Image_Assets/Towers/Bullets/Light/LightBullet0.png")) {
		std::cout << "Failed to load light bullet texture" << std::endl;
	}
	if (!this->darkTexture.loadFromFile("../Assets/Image_Assets/Towers/Bullets/Dark/DarkBullet0.png")) {
		std::cout << "Failed to load dark bullet texture" << std::endl;
	}
	if (!this->voidTexture.loadFromFile("../Assets/Image_Assets/Towers/Bullets/Void/VoidBullet0.png")) {
		std::cout << "Failed to load void bullet texture" << std::endl;
	}
}

void Bullet::update()
{
	if (this->element == 0) {
		this->sprite.setTexture(&fireTexture);
		this->baseDamage = 5.f;
	}
	else if (this->element == 1) {
		this->sprite.setTexture(&waterTexture);
		this->baseDamage = 0.5f;
	}
	else if (this->element == 2) {
		this->sprite.setTexture(&windTexture);
		this->baseDamage = 2.5f;
	}
	else if (this->element == 3) {
		this->sprite.setTexture(&iceTexture);
		this->baseDamage = 3.f;
	}
	else if (this->element == 4) {
		this->sprite.setTexture(&earthTexture);
		this->baseDamage = 5.f;
	}
	else if (this->element == 5) {
		this->sprite.setTexture(&energyTexture);
		this->baseDamage = 7.f;
	}
	else if (this->element == 6) {
		this->sprite.setTexture(&lightTexture);
		this->baseDamage = 2.f;
	}
	else if (this->element == 7) {
		this->sprite.setTexture(&darkTexture);
		this->baseDamage = 3.f;
	}
	else if (this->element == 8) {
		this->sprite.setTexture(&voidTexture);
		this->baseDamage = 10.f;
	}
}
