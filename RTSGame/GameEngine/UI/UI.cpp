#include "UI.h"

// Initialization
void UI::initVariables()
{
	// Integer Variables
	this->towerSize = 14;

	// Vector size
	this->towerTextures.resize(this->towerSize);
	this->towerNoTextures.resize(this->towerSize);
	this->towerStrings.resize(this->towerSize);
	this->towerNoStrings.resize(this->towerSize);

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
	return this->mana;
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
	this->mana -= mp;
}

void UI::AddMana(int mp)
{
	this->mana += mp;
}

void UI::RemoveScore(int sr)
{
	this->scoreValue -= sr;
}

void UI::AddScore(int sr)
{
	this->scoreValue += sr;
}


