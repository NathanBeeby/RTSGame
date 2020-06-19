#include "Bullet.h"



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

//void Bullet::update(sf::Time deltaTime, float range)
//{
//	this->updateBulletMovement(deltaTime, range);
//	this->updateBulletRotation();
//	this->DestroyBullet();
//}
//


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
