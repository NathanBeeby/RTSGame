#include "Tower.h"

void Tower::initVariables()
{
	this->delayTime = sf::seconds(10).asSeconds();
	this->elapsed = 0;
	// Boolean Variables
	this->towerIsClicked = false;
	this->towerSelected = false;

	// Vector variables
	this->aimDir = sf::Vector2f(-1, -1);
	this->aimDirNorm = sf::Vector2f(-1, -1);
	this->bullet.element = element;
	this->bullet.baseDamage = towerDamage;
	this->bullet.maxSpeed = bulletSpeed;

}

void Tower::initTextures()
{
	if (!this->fireTexture.loadFromFile("../Assets/Image_Assets/Towers/FireTower.png")) {
		std::cout << "Error loading fire tower texture" << std::endl;
	}
	if (!this->waterTexture.loadFromFile("../Assets/Image_Assets/Towers/WaterTower.png")) {
		std::cout << "Error loading water tower texture" << std::endl;
	}
	if (!this->windTexture.loadFromFile("../Assets/Image_Assets/Towers/WindTower.png")) {
		std::cout << "Error loading wind tower texture" << std::endl;
	}
	if (!this->iceTexture.loadFromFile("../Assets/Image_Assets/Towers/IceTower.png")) {
		std::cout << "Error loading wind tower texture 0" << std::endl;
	}
	if (!this->earthTexture.loadFromFile("../Assets/Image_Assets/Towers/EarthTower.png")) {
		std::cout << "Error loading earth tower texture" << std::endl;
	}
	if (!this->energyTexture.loadFromFile("../Assets/Image_Assets/Towers/EnergyTower.png")) {
		std::cout << "Error loading energy tower texture" << std::endl;
	}
	if (!this->lightTexture.loadFromFile("../Assets/Image_Assets/Towers/LightTower.png")) {
		std::cout << "Error loading light tower texture" << std::endl;
	}
	if (!this->darkTexture.loadFromFile("../Assets/Image_Assets/Towers/DarkTower.png")) {
		std::cout << "Error loading dark tower texture" << std::endl;
	}
	if (!this->voidTexture.loadFromFile("../Assets/Image_Assets/Towers/VoidTower.png")) {
		std::cout << "Error loading void tower texture" << std::endl;
	}
	if (!this->elemAmpTexture.loadFromFile("../Assets/Image_Assets/Towers/ElementalAmplifier.png")) {
		std::cout << "Error loading elemental amplifier tower texture" << std::endl;
	}
	if (!this->elemOverTexture.loadFromFile("../Assets/Image_Assets/Towers/ElementalOverclocker.png")) {
		std::cout << "Error loading elemental overclocker tower texture" << std::endl;
	}
	if (!this->manaAmpTexture.loadFromFile("../Assets/Image_Assets/Towers/ManaAmplifier.png")) {
		std::cout << "Error loading mana amplifier tower texture" << std::endl;
	}
	if (!this->observTexture.loadFromFile("../Assets/Image_Assets/Towers/Observatory.png")) {
		std::cout << "Error loading observatory tower texture" << std::endl;
	}
	if (!this->regenTexture.loadFromFile("../Assets/Image_Assets/Towers/Regenerator.png")) {
		std::cout << "Error loading regen tower texture" << std::endl;
	}
}

sf::Vector2f Tower::towerClicked(sf::Vector2i clickPos)
{
	this->towerPos = sf::Vector2f(-1, -1);



		if (clickPos.x >= this->sprite.getGlobalBounds().left && clickPos.x <= (this->sprite.getGlobalBounds().left + this->sprite.getGlobalBounds().width)) {
			if (clickPos.y >= this->sprite.getGlobalBounds().top && clickPos.y <= (this->sprite.getGlobalBounds().top + this->sprite.getGlobalBounds().height)) {
				this->towerPos.x = this->sprite.getPosition().x + (this->sprite.getSize().x / 2);
				this->towerPos.y = this->sprite.getPosition().y + (this->sprite.getSize().y / 2);
				this->towerIsClicked = true;
				this->SelectTower(towerPos);
			}
		}
	

	return this->towerPos;
}

void Tower::FireBullet(sf::Vector2f &enemyPos)
{
	elapsed += bulletTimer.restart().asSeconds();

	if (enemyPos.x > 0 || enemyPos.y > 0) {

			this->aimDir = enemyPos - towerCenter;
			this->aimDirNorm = this->aimDir / sqrt(pow(aimDir.x, 2) + (aimDir.y, 2));
		
			if (elapsed >= delayTime) {
				this->CreateBullet();
				bulletTimer.restart();
				this->elapsed = 0;
			}
	}
}

void Tower::CreateBullet()
{
	bullet.maxSpeed = bulletSpeed;
	bullet.element = this->element;
	bullet.sprite.setPosition(sf::Vector2f(sprite.getPosition().x + (sprite.getSize().x / 2), sprite.getPosition().y + (sprite.getSize().y / 2)));
	bullet.origin = sf::Vector2f(sprite.getPosition().x + (sprite.getSize().x / 2), sprite.getPosition().y + (sprite.getSize().y / 2));
	bullet.currVelocity = aimDirNorm * bullet.maxSpeed;
	bullets.push_back(Bullet(bullet));
}

void Tower::SelectTower(sf::Vector2f towerCenter)
{
	this->towerSelected = true;
	this->radiusCircle.setRadius(this->towerRange);
	this->radiusCircle.setPosition(sf::Vector2f(towerCenter.x - (radiusCircle.getRadius()), towerCenter.y - (radiusCircle.getRadius())));
}

void Tower::DeselectTower()
{
	this->towerSelected = false;
}

void Tower::render(sf::RenderTarget & target)
{
	renderBullets(target);

	target.draw(this->sprite);
	
	if (towerSelected == true) {
		target.draw(this->radiusCircle);
	}
}

void Tower::renderBullets(sf::RenderTarget &target)
{
	for (size_t i = 0; i < bullets.size(); i++) {
		target.draw(bullets[i].sprite);
	}
}



void Tower::update()
{
	bullet.update();

	this->towerCenter = sf::Vector2f(this->sprite.getPosition().x + (this->sprite.getSize().x / 2), this->sprite.getPosition().y + (this->sprite.getSize().y / 2));

	for (size_t i = 0; i < bullets.size(); i++)
	{
		bullets[i].sprite.move(bullets[i].currVelocity);
		if (bullets[i].sprite.getPosition().x <= bullets[i].origin.x - towerRange || bullets[i].sprite.getPosition().x >= bullets[i].origin.x + towerRange ||
			bullets[i].sprite.getPosition().y <= bullets[i].origin.y - towerRange || bullets[i].sprite.getPosition().y >= bullets[i].origin.y + towerRange) {
			bullets.erase(bullets.begin() + i);
		}
	}
	
	if (this->element == 0) {
		this->sprite.setTexture(&fireTexture);
		this->towerCost = 300;
		this->towerDamage = 100.f; // 0-4
		this->towerRange = 600.f;
		this->towerAttackSpeed = 9.5f;
		this->bulletSpeed = 50.f;
	}
	else if (this->element == 1) {
		this->sprite.setTexture(&waterTexture);
		this->towerCost = 280;
		this->towerDamage = 100.f; // 0-4
		this->towerRange = 700.f;
		this->towerAttackSpeed = 5.f;
		this->bulletSpeed = 25.f;
	}
	else if (this->element == 2) {
		this->sprite.setTexture(&windTexture);
		this->towerCost = 255;
		this->towerDamage = 100.f; // 0-4
		this->towerRange = 600.f;
		this->towerAttackSpeed = 4.f;
		this->bulletSpeed = 15.f;

	}
	else if (this->element == 3) {
		this->sprite.setTexture(&iceTexture);
		this->towerCost = 210;
		this->towerDamage = 100.f; // 0-4
		this->towerRange = 350.f;
		this->towerAttackSpeed = 5.f;
		this->bulletSpeed = 10.f;

	}
	else if (this->element == 4) {
		this->sprite.setTexture(&earthTexture);
		this->towerCost = 400;
		this->towerDamage = 100.f; // 0-4
		this->towerRange = 350.f;
		this->towerAttackSpeed = 2.f;
		this->bulletSpeed = 5.f;

	}
	else if (this->element == 5) {
		this->sprite.setTexture(&energyTexture);
		this->towerCost = 350;
		this->towerDamage = 100.f; // 0-4
		this->towerRange = 600.f;
		this->towerAttackSpeed = 5.f;
		this->bulletSpeed = 50.f;
	}
	else if (this->element == 6) {
		this->sprite.setTexture(&lightTexture);
		this->towerCost = 230;
		this->towerDamage = 100.f; // 0-4
		this->towerRange = 350.f;
		this->towerAttackSpeed = 5.f;
		this->bulletSpeed = 25.f;

	}
	else if (this->element == 7) {
		this->sprite.setTexture(&darkTexture);
		this->towerCost = 366;
		this->towerDamage = 100.f; // 0-4
		this->towerRange = 400.f;
		this->towerAttackSpeed = 3.f;
		this->bulletSpeed = 10.f;

	}
	else if (this->element == 8) {
		this->sprite.setTexture(&elemAmpTexture);
		this->towerCost = 600;
		this->towerDamage = 0.f; // 0-4
		this->towerRange = 100.f;
		this->towerAttackSpeed = 0.0f;
		this->bulletSpeed = 0.f;
	}
	else if (this->element == 9) {
		this->sprite.setTexture(&elemOverTexture);
		this->towerCost = 600;
		this->towerDamage = 0.f; // 0-4
		this->towerRange = 100.f;
		this->towerAttackSpeed = 0.0f;
		this->bulletSpeed = 0.f;
	}
	else if (this->element == 8) {
		this->sprite.setTexture(&manaAmpTexture);
		this->towerCost = 600;
		this->towerDamage = 0.f; // 0-4
		this->towerRange = 100.f;
		this->towerAttackSpeed = 0.0f;
		this->bulletSpeed = 0.f;
	}
	else if (this->element == 8) {
		this->sprite.setTexture(&observTexture);
		this->towerCost = 600;
		this->towerDamage = 0.f; // 0-4
		this->towerRange = 100.f;
		this->towerAttackSpeed = 0.0f;
		this->bulletSpeed = 0.f;
	}
	else if (this->element == 8) {
		this->sprite.setTexture(&regenTexture);
		this->towerCost = 600;
		this->towerDamage = 0.f; // 0-4
		this->towerRange = 100.f;
		this->towerAttackSpeed = 0.0f;
		this->bulletSpeed = 0.f;
	}
	else if (this->element == 8) {
		this->sprite.setTexture(&voidTexture);
		this->towerCost = 755;
		this->towerDamage = 100.f; // 0-4
		this->towerRange = 1000.f;
		this->towerAttackSpeed = 9.5f;
		this->bulletSpeed = 15.f;
	}
}


