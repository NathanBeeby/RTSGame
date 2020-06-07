#include "UI.h"

// Initialization
void UI::initVariables()
{
	// Boolean Variables
	this->mouseHeld = false;

	// Integer Variables
	this->towerSize = 14;
	this->uiButtonSize = 3;
	this->uiTime = 0;
	this->uiTimeMinute = 0;
	this->day = 0;
	this->minute = 60;
	// Vector size
	this->towerTextures.resize(this->towerSize);
	this->towerNoTextures.resize(this->towerSize);
	this->towerStrings.resize(this->towerSize);
	this->towerNoStrings.resize(this->towerSize);

	// UI Buttons
	this->uiButtons.resize(uiButtonSize);
	this->uiButtonTextures.resize(uiButtonSize);

}

void UI::initTextures()
{
	// Tower Textures
	this->towerTextures[0].loadFromFile(this->towerStrings[0]);
	this->towerTextures[1].loadFromFile(this->towerStrings[1]);
	this->towerTextures[2].loadFromFile(this->towerStrings[2]);
	this->towerTextures[3].loadFromFile(this->towerStrings[3]);
	this->towerTextures[4].loadFromFile(this->towerStrings[4]);
	this->towerTextures[5].loadFromFile(this->towerStrings[5]);
	this->towerTextures[6].loadFromFile(this->towerStrings[6]);
	this->towerTextures[7].loadFromFile(this->towerStrings[7]);
	this->towerTextures[8].loadFromFile(this->towerStrings[8]);
	this->towerTextures[9].loadFromFile(this->towerStrings[9]);
	this->towerTextures[10].loadFromFile(this->towerStrings[10]);
	this->towerTextures[11].loadFromFile(this->towerStrings[11]);
	this->towerTextures[12].loadFromFile(this->towerStrings[12]);
	this->towerTextures[13].loadFromFile(this->towerStrings[13]);

	// No Texture
	this->towerNoTextures[0].loadFromFile(this->towerNoStrings[0]);
	this->towerNoTextures[1].loadFromFile(this->towerNoStrings[1]);
	this->towerNoTextures[2].loadFromFile(this->towerNoStrings[2]);
	this->towerNoTextures[3].loadFromFile(this->towerNoStrings[3]);
	this->towerNoTextures[4].loadFromFile(this->towerNoStrings[4]);
	this->towerNoTextures[5].loadFromFile(this->towerNoStrings[5]);
	this->towerNoTextures[6].loadFromFile(this->towerNoStrings[6]);
	this->towerNoTextures[7].loadFromFile(this->towerNoStrings[7]);
	this->towerNoTextures[8].loadFromFile(this->towerNoStrings[8]);
	this->towerNoTextures[9].loadFromFile(this->towerNoStrings[9]);
	this->towerNoTextures[10].loadFromFile(this->towerNoStrings[10]);
	this->towerNoTextures[11].loadFromFile(this->towerNoStrings[11]);
	this->towerNoTextures[12].loadFromFile(this->towerNoStrings[12]);
	this->towerNoTextures[13].loadFromFile(this->towerNoStrings[13]);

	if (!this->uiButtonTextures[0].loadFromFile("../Assets/Image_Assets/GUI/GUIButtons/Start.png")) {
		std::cout << "Failed to Load Start Texture" << std::endl;
	}
	if (!this->uiButtonTextures[1].loadFromFile("../Assets/Image_Assets/GUI/GUIButtons/PauseButton.png")) {
		std::cout << "Failed to Load pause Texture" << std::endl;
	}
	if (!this->uiButtonTextures[2].loadFromFile("../Assets/Image_Assets/GUI/GUIButtons/SettingsButton.png")) {
		std::cout << "Failed to Load setting Texture" << std::endl;
	}
}

void UI::initText()
{
	this->towerStrings[0] = "../Assets/Image_Assets/Towers/FireTower.png";
	this->towerStrings[1] = "../Assets/Image_Assets/Towers/WaterTower.png";
	this->towerStrings[2] = "../Assets/Image_Assets/Towers/WindTower.png";
	this->towerStrings[3] = "../Assets/Image_Assets/Towers/IceTower.png";
	this->towerStrings[4] = "../Assets/Image_Assets/Towers/EarthTower.png";
	this->towerStrings[5] = "../Assets/Image_Assets/Towers/EnergyTower.png";
	this->towerStrings[6] = "../Assets/Image_Assets/Towers/LightTower.png";
	this->towerStrings[7] = "../Assets/Image_Assets/Towers/DarkTower.png";
	this->towerStrings[8] = "../Assets/Image_Assets/Towers/ElementalAmplifier.png";
	this->towerStrings[9] = "../Assets/Image_Assets/Towers/ElementalOverclocker.png";
	this->towerStrings[10] = "../Assets/Image_Assets/Towers/ManaAmplifier.png";
	this->towerStrings[11] = "../Assets/Image_Assets/Towers/Observatory.png";
	this->towerStrings[12] = "../Assets/Image_Assets/Towers/Regenerator.png";
	this->towerStrings[13] = "../Assets/Image_Assets/Towers/VoidTower.png";

	this->towerNoStrings[0] = "../Assets/Image_Assets/Towers/NoTexture/FireTower.png";
	this->towerNoStrings[1] = "../Assets/Image_Assets/Towers/NoTexture/WaterTower.png";
	this->towerNoStrings[2] = "../Assets/Image_Assets/Towers/NoTexture/WindTower.png";
	this->towerNoStrings[3] = "../Assets/Image_Assets/Towers/NoTexture/IceTower.png";
	this->towerNoStrings[4] = "../Assets/Image_Assets/Towers/NoTexture/EarthTower.png";
	this->towerNoStrings[5] = "../Assets/Image_Assets/Towers/NoTexture/EnergyTower.png";
	this->towerNoStrings[6] = "../Assets/Image_Assets/Towers/NoTexture/LightTower.png";
	this->towerNoStrings[7] = "../Assets/Image_Assets/Towers/NoTexture/DarkTower.png";
	this->towerNoStrings[8] = "../Assets/Image_Assets/Towers/NoTexture/ElementalAmplifier.png";
	this->towerNoStrings[9] = "../Assets/Image_Assets/Towers/NoTexture/ElementalOverclocker.png";
	this->towerNoStrings[10] = "../Assets/Image_Assets/Towers/NoTexture/ManaAmplifier.png";
	this->towerNoStrings[11] = "../Assets/Image_Assets/Towers/NoTexture/Observatory.png";
	this->towerNoStrings[12] = "../Assets/Image_Assets/Towers/NoTexture/Regenerator.png";
	this->towerNoStrings[13] = "../Assets/Image_Assets/Towers/NoTexture/VoidTower.png";
}

void UI::initSprites()
{
	for (int i = 0; i < uiButtons.size(); i++) {
		this->uiButtons[i].setSize(sf::Vector2f(40.f, 40.f));
		this->uiButtons[i].setTexture(&this->uiButtonTextures[i]);
		this->uiButtons[i].setOutlineColor(sf::Color::Yellow);
		this->uiButtons[i].setOutlineThickness(2);
		this->uiButtons[i].setPosition(sf::Vector2f(1770.f + ((uiButtons[i].getSize().x + 10) * i), 10.f));
	}
}

// Constructor / Destructor
UI::UI()
{
	this->initVariables();
	this->initText();
	this->initTextures();
	this->initSprites();
}


UI::~UI()
{
}

// Accessors

const int UI::getScoreValue() const
{
	return this->scoreValue;
}

const int UI::getHealthValue() const
{
	return this->health;
}

const int UI::getManaValue() const
{
	return this->wave.mana;
}

// Public Functions

void UI::RemoveHealth(int hp)
{
	this->health -= hp;
}

void UI::AddHealth(int hp)
{
	this->health += hp;
}

void UI::RemoveMana(int mp)
{
	this->wave.mana -= mp;
}

void UI::AddMana(int mp)
{
	this->wave.mana += mp;
}

void UI::RemoveScore(int sr)
{
	this->scoreValue -= sr;
}

void UI::AddScore(int sr)
{
	this->scoreValue += sr;
}

void UI::uiButtonsMouseHandler(sf::Vector2i & windowPos)
{
	if (windowPos.y >= uiButtons[0].getPosition().y && windowPos.y <= uiButtons[0].getPosition().y + uiButtons[0].getSize().y) {
		if (windowPos.x >= uiButtons[0].getPosition().x && windowPos.x <= uiButtons[0].getPosition().x + uiButtons[0].getSize().x) {
			// Start Round Button
			std::cout << "Wave Began" << std::endl;
			wave.beginWave();
			// Change Texture to double spped
			// if clicked again make tripple speed
			// if round over set back to start button
		}
		if (windowPos.x >= uiButtons[1].getPosition().x && windowPos.x <= uiButtons[1].getPosition().x + uiButtons[1].getSize().x) {
			std::cout << "Wave Paused" << std::endl;
		}
		if (windowPos.x >= uiButtons[2].getPosition().x && windowPos.x <= uiButtons[2].getPosition().x + uiButtons[2].getSize().x) {
			std::cout << "Settings Clicked" << std::endl;
		}
	}
}

void UI::towerMenuMouseHandler(sf::Vector2i & windowPos)
{
	if (windowPos.x >= inventoryBox[0].getPosition().x && windowPos.x <= inventoryBox[0].getPosition().x + inventoryBox[0].getSize().x) {

		if (windowPos.y >= inventoryBox[0].getPosition().y && windowPos.y <= inventoryBox[0].getPosition().y + inventoryBox[0].getSize().y) {
			if (wave.mana >= structInv.fireTower.towerCost) {
				std::cout << "Clicking Fire Tower" << std::endl;
				this->structInv.towerFollow(this->towerStrings[0]);
				this->mouseHeld = true;
			}
			else {
				// set fire tower texture to crossed out tower texture
			}
		}
		if (windowPos.y >= inventoryBox[1].getPosition().y && windowPos.y <= inventoryBox[1].getPosition().y + inventoryBox[1].getSize().y) {
			if (wave.mana >= structInv.windTower.towerCost) {
				std::cout << "Clicking Wind Tower" << std::endl;
				this->structInv.towerFollow(this->towerStrings[2]);
				this->mouseHeld = true;
			}
		}
		if (windowPos.y >= inventoryBox[2].getPosition().y && windowPos.y <= inventoryBox[2].getPosition().y + inventoryBox[2].getSize().y) {
			if (wave.mana >= structInv.earthTower.towerCost) {
				std::cout << "Clicking Earth Tower" << std::endl;
				this->structInv.towerFollow(this->towerStrings[4]);
				this->mouseHeld = true;
			}
		}
		if (windowPos.y >= inventoryBox[3].getPosition().y && windowPos.y <= inventoryBox[3].getPosition().y + inventoryBox[3].getSize().y) {
			if (wave.mana >= structInv.lightTower.towerCost) {
				std::cout << "Clicking Light Tower" << std::endl;
				this->structInv.towerFollow(this->towerStrings[6]);
				this->mouseHeld = true;
			}
		}
		if (windowPos.y >= inventoryBox[4].getPosition().y && windowPos.y <= inventoryBox[4].getPosition().y + inventoryBox[4].getSize().y) {
			if (wave.mana >= structInv.elementalAmplifier.towerCost) {
				std::cout << "Clicking Elemental Amplifier Tower" << std::endl;
				this->structInv.towerFollow(this->towerStrings[8]);
				this->mouseHeld = true;
			}
		}
		if (windowPos.y >= inventoryBox[5].getPosition().y && windowPos.y <= inventoryBox[5].getPosition().y + inventoryBox[5].getSize().y) {
			if (wave.mana >= structInv.elementalOverclocker.towerCost) {
				std::cout << "Clicking Elemental Overclocker tower" << std::endl;
				this->structInv.towerFollow(this->towerStrings[9]);
				this->mouseHeld = true;
			}
		}
		if (windowPos.y >= inventoryBox[6].getPosition().y && windowPos.y <= inventoryBox[6].getPosition().y + inventoryBox[6].getSize().y) {
			if (wave.mana >= structInv.manaAmplifier.towerCost) {
				std::cout << "Clicking Mana Amplifier" << std::endl;
				this->structInv.towerFollow(this->towerStrings[10]);
				this->mouseHeld = true;
			}
		}
	}
	else if (windowPos.x >= inventoryBox[7].getPosition().x && windowPos.x <= inventoryBox[7].getPosition().x + inventoryBox[7].getSize().x) {
		if (windowPos.y >= inventoryBox[7].getPosition().y && windowPos.y <= inventoryBox[7].getPosition().y + inventoryBox[7].getSize().y) {
			if (wave.mana >= structInv.waterTower.towerCost) {
				std::cout << "Clicking Water Tower" << std::endl;
				this->structInv.towerFollow(this->towerStrings[1]);
				this->mouseHeld = true;
			}
		}
		if (windowPos.y >= inventoryBox[8].getPosition().y && windowPos.y <= inventoryBox[8].getPosition().y + inventoryBox[8].getSize().y) {
			if (wave.mana >= structInv.iceTower.towerCost) {
				std::cout << "Clicking Ice Tower" << std::endl;
				this->structInv.towerFollow(this->towerStrings[3]);
				this->mouseHeld = true;
			}
		}
		if (windowPos.y >= inventoryBox[9].getPosition().y && windowPos.y <= inventoryBox[9].getPosition().y + inventoryBox[9].getSize().y) {
			if (wave.mana >= structInv.energyTower.towerCost) {
				std::cout << "Clicking Energy Tower" << std::endl;
				this->structInv.towerFollow(this->towerStrings[5]);
				this->mouseHeld = true;
			}
		}
		if (windowPos.y >= inventoryBox[10].getPosition().y && windowPos.y <= inventoryBox[10].getPosition().y + inventoryBox[10].getSize().y) {
			if (wave.mana >= structInv.darkTower.towerCost) {
				std::cout << "Clicking Dark Tower" << std::endl;
				this->structInv.towerFollow(this->towerStrings[7]);
				this->mouseHeld = true;
			}
		}
		if (windowPos.y >= inventoryBox[11].getPosition().y && windowPos.y <= inventoryBox[11].getPosition().y + inventoryBox[11].getSize().y) {
			if (wave.mana >= structInv.observatory.towerCost) {
				std::cout << "Clicking Observatory tower" << std::endl;
				this->structInv.towerFollow(this->towerStrings[11]);
				this->mouseHeld = true;
			}
		}
		if (windowPos.y >= inventoryBox[12].getPosition().y && windowPos.y <= inventoryBox[12].getPosition().y + inventoryBox[12].getSize().y) {
			if (wave.mana >= structInv.regenTower.towerCost) {
				std::cout << "Clicking regenerator tower" << std::endl;
				this->structInv.towerFollow(this->towerStrings[12]);
				this->mouseHeld = true;
			}
		}
		if (windowPos.y >= inventoryBox[13].getPosition().y && windowPos.y <= inventoryBox[13].getPosition().y + inventoryBox[13].getSize().y) {
			if (wave.mana >= structInv.voidTower.towerCost) {
				std::cout << "Clicking void tower" << std::endl;
				this->structInv.towerFollow(this->towerStrings[13]);
				this->mouseHeld = true;
			}
		}
	}
}

void UI::updateUIText()
{
	this->levelString = std::to_string(this->levelValue); // converting the int to string, so player knows the stats
	this->scoreString = std::to_string(this->scoreValue);
	this->healthString = std::to_string(this->actualHealth);
	this->manaString = std::to_string(this->wave.mana);
	this->waveString = std::to_string(wave.getWaveNumber());

	this->levelText.setString("Level: " + levelString);
	this->scoreText.setString("Score: " + scoreString);
	this->healthText.setString(healthString);
	this->manaText.setString(manaString);
	this->waveText.setString(waveString);
}

void UI::updateGameState()
{
	this->actualHealth = this->health - this->wave.enemiesPassedGoal();

	if (actualHealth <= 0) {
		this->isLevelLost = true;
	}
	if (this->waveAmt >= 30) {
		this->isLevelWon = true;
	}
}

void UI::updateClock()
{
	sf::Time TimeElapsed = uiClock.getElapsedTime(); // setting the time to the hud clock, so it can count seconds
	sf::Time seconds = sf::seconds(1); // this is to compare to the time elapsed to get 1 second

	if (TimeElapsed >= seconds) { // if the time elapsed is a second, increment the HUDTime and restart the HUDClock 
		uiTime++;
		uiClock.restart();
		//std::cout << "Minutes: " << HUDTimeMinute << ", Seconds: " << HUDTime << std::endl;
	}

	if (uiTime >= minute) { // if the HUDTime is more or equal to 60, do this
		uiTimeMinute++; // increment the hud time minute
		uiTime = 0; // change the hud time back to 0
		if (uiTimeMinute >= 24) {// if the hudtime minute is more than 24(like a 24 hour clock)
			day++;
			uiTimeMinute = 0; // set hudtime back to 0
		}
	}

	this->updateUITime();
}

void UI::updateUITime()
{
	std::string MinutesString = std::to_string(uiTimeMinute);
	std::string SecondsString = std::to_string(uiTime);
	std::string dayString = std::to_string(day);

	dayText.setString("Day : " + dayString);
	if (uiTimeMinute <= 9 && uiTime <= 9) { // if both HUDTime and HUDTimeMinute is less than 9, put a 0 before both 
		timerText.setString("0" + MinutesString + " : 0" + SecondsString);
	}
	else if (uiTime <= 9) { // if the HUDTime seconds is less than 9, have a 0 before the number, so it's digital time
		timerText.setString(MinutesString + " : 0" + SecondsString);
	}
	else if (uiTimeMinute <= 9) { // ig HUDTimeMinute is less than 9, but a 0 before the minutes
		timerText.setString("0" + MinutesString + " : " + SecondsString);
	}
	else {
		timerText.setString(MinutesString + " : " + SecondsString);
	}
}


