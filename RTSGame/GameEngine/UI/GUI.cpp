#include "GUI.h"


// Initialization
void GUI::initVariables()
{
	this->levelValue = 0;
	this->scoreValue = 0;
	this->invMax = 0;
	this->guiTime = 0;
	this->guiTimeMinute = 0;
	this->day = 0;
	this->minute = 60;
	this->health = 100;
	this->mana = 500;
	this->fireTower = "../Assets/Image_Assets/Towers/FireTower.png";
	this->waterTower = "../Assets/Image_Assets/Towers/WaterTower.png";
	this->windTower = "../Assets/Image_Assets/Towers/WindTower.png";
	this->iceTower = "../Assets/Image_Assets/Towers/IceTower.png";
	this->earthTower = "../Assets/Image_Assets/Towers/EarthTower.png";
	this->energyTower = "../Assets/Image_Assets/Towers/EnergyTower.png";
	this->lightTower = "../Assets/Image_Assets/Towers/LightTower.png";
	this->darkTower = "../Assets/Image_Assets/Towers/DarkTower.png";
	this->elementAmpTower = "../Assets/Image_Assets/Towers/ElementalAmplifier.png";
	this->elementOverTower = "../Assets/Image_Assets/Towers/ElementalOverclocker.png";
	this->manaAmpTower = "../Assets/Image_Assets/Towers/ManaAmplifier.png";
	this->observTower = "../Assets/Image_Assets/Towers/Observatory.png";
	this->regenTower = "../Assets/Image_Assets/Towers/Regenerator.png";
	this->voidTower = "../Assets/Image_Assets/Towers/VoidTower.png";
	this->mouseHeld = false;
}

void GUI::initTextures()
{
	this->inventoryBoxTexture.resize(24);
	//manager.GetFont("../Assets/Font_Assets/Freshman.ttf");
	if (!this->font.loadFromFile("../Assets/Font_Assets/Freshman.ttf")) {
		std::cout << "Error: loading GUI Font" << std::endl;
	}

	if (!this->resourceBarTexture.loadFromFile("../Assets/Image_Assets/GUI/ResourceBar.png")) {
		std::cout << "Error: loading resourceBarTexture" << std::endl;
	}
	if (!this->pauseTexture.loadFromFile("../Assets/Image_Assets/GUI/PauseButton.png")) {
		std::cout << "Error: loading PauseButton" << std::endl;
	}
	if (!this->settingsTexture.loadFromFile("../Assets/Image_Assets/GUI/SettingsButton.png")) {
		std::cout << "Error: loading SettingsButton" << std::endl;
	}
	if (!this->chatBoxTexture.loadFromFile("../Assets/Image_Assets/GUI/ChatBox.png")) {
		std::cout << "Error: loading ChatBox" << std::endl;
	}
	if (!this->emptyBoxTexture.loadFromFile("../Assets/Image_Assets/GUI/EmptyBox.png")) {
		std::cout << "Error: loading EmptyBox" << std::endl;
	}
	if (!this->inventoryTexture.loadFromFile("../Assets/Image_Assets/GUI/InventoryBox.png")) {
		std::cout << "Error: loading InventoryBox" << std::endl;
	}
	if (!this->miniMapTexture.loadFromFile("../Assets/Image_Assets/GUI/MiniMapBox.png")) {
		std::cout << "Error: loading MiniMapBox" << std::endl;
	}
	if (!this->healthTexture.loadFromFile("../Assets/Image_Assets/GUI/Health.png")) {
		std::cout << "Error: loading health Texture" << std::endl;
	}
	if (!this->manaTexture.loadFromFile("../Assets/Image_Assets/GUI/Mana.png")) {
		std::cout << "Error: loading mana Texture" << std::endl;
	}
	if (!this->waveTexture.loadFromFile("../Assets/Image_Assets/GUI/Wave.png")) {
		std::cout << "Error: loading wave Texture" << std::endl;
	}
	// inventoryBoxTexture
	if (!this->inventoryBoxTexture[0].loadFromFile(this->fireTower)) {
		std::cout << "Error: loading fire tower" << std::endl;
	}
	if (!this->inventoryBoxTexture[1].loadFromFile(this->windTower)) {
		std::cout << "Error: loading wind tower" << std::endl;
	}
	if (!this->inventoryBoxTexture[2].loadFromFile(this->earthTower)) {
		std::cout << "Error: loading earth tower" << std::endl;
	}
	if (!this->inventoryBoxTexture[3].loadFromFile(this->lightTower)) {
		std::cout << "Error: loading light tower" << std::endl;
	}
	if (!this->inventoryBoxTexture[4].loadFromFile(this->elementAmpTower)) {
		std::cout << "Error: loading elemental amplifier tower" << std::endl;
	}
	if (!this->inventoryBoxTexture[5].loadFromFile(this->elementOverTower)) {
		std::cout << "Error: loading elemental overclocker tower" << std::endl;
	}
	if (!this->inventoryBoxTexture[6].loadFromFile(this->manaAmpTower)) {
		std::cout << "Error: loading mana amplifier tower" << std::endl;
	}
	if (!this->inventoryBoxTexture[7].loadFromFile(this->waterTower)) {
		std::cout << "Error: loading water tower" << std::endl;
	}
	if (!this->inventoryBoxTexture[8].loadFromFile(this->iceTower)) {
		std::cout << "Error: loading ice tower" << std::endl;
	}
	if (!this->inventoryBoxTexture[9].loadFromFile(this->energyTower)) {
		std::cout << "Error: loading energy tower" << std::endl;
	}
	if (!this->inventoryBoxTexture[10].loadFromFile(this->darkTower)) {
		std::cout << "Error: loading darkness tower" << std::endl;
	}
	if (!this->inventoryBoxTexture[11].loadFromFile(this->observTower)) {
		std::cout << "Error: loading observatory tower" << std::endl;
	}
	if (!this->inventoryBoxTexture[12].loadFromFile(this->regenTower)) {
		std::cout << "Error: loading regenerator tower" << std::endl;
	}
	if (!this->inventoryBoxTexture[13].loadFromFile(this->voidTower)) {
		std::cout << "Error: loading void tower" << std::endl;
	}

	if (!this->fireNoTexture.loadFromFile("../Assets/Image_Assets/Towers/NoTexture/FireTower.png")) {
		std::cout << "Error: loading no texture fire tower" << std::endl;
	}
	if (!this->waterNoTexture.loadFromFile("../Assets/Image_Assets/Towers/NoTexture/WaterTower.png")) {
		std::cout << "Error: loading no texture water tower" << std::endl;
	}
	if (!this->windNoTexture.loadFromFile("../Assets/Image_Assets/Towers/NoTexture/WindTower.png")) {
		std::cout << "Error: loading no texture wind tower" << std::endl;
	}
	if (!this->iceNoTexture.loadFromFile("../Assets/Image_Assets/Towers/NoTexture/IceTower.png")) {
		std::cout << "Error: loading no texture ice tower" << std::endl;
	}
	if (!this->earthNoTexture.loadFromFile("../Assets/Image_Assets/Towers/NoTexture/EarthTower.png")) {
		std::cout << "Error: loading no texture earth tower" << std::endl;
	}
	if (!this->energyNoTexture.loadFromFile("../Assets/Image_Assets/Towers/NoTexture/EnergyTower.png")) {
		std::cout << "Error: loading no texture energy tower" << std::endl;
	}
	if (!this->lightNoTexture.loadFromFile("../Assets/Image_Assets/Towers/NoTexture/LightTower.png")) {
		std::cout << "Error: loading no texture light tower" << std::endl;
	}
	if (!this->darkNoTexture.loadFromFile("../Assets/Image_Assets/Towers/NoTexture/DarkTower.png")) {
		std::cout << "Error: loading no texture dark tower" << std::endl;
	}
	if (!this->elemAmpNoTexture.loadFromFile("../Assets/Image_Assets/Towers/NoTexture/ElementalAmplifier.png")) {
		std::cout << "Error: loading no texture elemental amplifier tower" << std::endl;
	}
	if (!this->elemOverNoTexture.loadFromFile("../Assets/Image_Assets/Towers/NoTexture/ElementalOverclocker.png")) {
		std::cout << "Error: loading no texture elemental overclocker tower" << std::endl;
	}
	if (!this->manaAmpNoTexture.loadFromFile("../Assets/Image_Assets/Towers/NoTexture/ManaAmplifier.png")) {
		std::cout << "Error: loading no texture mana amplifier tower" << std::endl;
	}
	if (!this->observNoTexture.loadFromFile("../Assets/Image_Assets/Towers/NoTexture/Observatory.png")) {
		std::cout << "Error: loading no texture observatory tower" << std::endl;
	}
	if (!this->regenNoTexture.loadFromFile("../Assets/Image_Assets/Towers/NoTexture/Regenerator.png")) {
		std::cout << "Error: loading no texture regenerator tower" << std::endl;
	}
	if (!this->voidNoTexture.loadFromFile("../Assets/Image_Assets/Towers/NoTexture/VoidTower.png")) {
		std::cout << "Error: loading no texture void tower" << std::endl;
	}
	if (!this->fireTexture.loadFromFile("../Assets/Image_Assets/Towers/FireTower.png")) {
		std::cout << "Error: loading texture fire tower" << std::endl;
	}
	if (!this->waterTexture.loadFromFile("../Assets/Image_Assets/Towers/WaterTower.png")) {
		std::cout << "Error: loading texture water tower" << std::endl;
	}
	if (!this->windTexture.loadFromFile("../Assets/Image_Assets/Towers/WindTower.png")) {
		std::cout << "Error: loading texture wind tower" << std::endl;
	}
	if (!this->iceTexture.loadFromFile("../Assets/Image_Assets/Towers/IceTower.png")) {
		std::cout << "Error: loading texture ice tower" << std::endl;
	}
	if (!this->earthTexture.loadFromFile("../Assets/Image_Assets/Towers/EarthTower.png")) {
		std::cout << "Error: loading texture earth tower" << std::endl;
	}
	if (!this->energyTexture.loadFromFile("../Assets/Image_Assets/Towers/EnergyTower.png")) {
		std::cout << "Error: loading texture energy tower" << std::endl;
	}
	if (!this->lightTexture.loadFromFile("../Assets/Image_Assets/Towers/LightTower.png")) {
		std::cout << "Error: loading texture light tower" << std::endl;
	}
	if (!this->darkTexture.loadFromFile("../Assets/Image_Assets/Towers/DarkTower.png")) {
		std::cout << "Error: loading texture dark tower" << std::endl;
	}
	if (!this->elemAmpTexture.loadFromFile("../Assets/Image_Assets/Towers/ElementalAmplifier.png")) {
		std::cout << "Error: loading texture elemental amplifier tower" << std::endl;
	}
	if (!this->elemOverTexture.loadFromFile("../Assets/Image_Assets/Towers/ElementalOverclocker.png")) {
		std::cout << "Error: loading texture elemental overclocker tower" << std::endl;
	}
	if (!this->manaAmpTexture.loadFromFile("../Assets/Image_Assets/Towers/ManaAmplifier.png")) {
		std::cout << "Error: loading texture mana amplifier tower" << std::endl;
	}
	if (!this->observTexture.loadFromFile("../Assets/Image_Assets/Towers/Observatory.png")) {
		std::cout << "Error: loading texture observatory tower" << std::endl;
	}
	if (!this->regenTexture.loadFromFile("../Assets/Image_Assets/Towers/Regenerator.png")) {
		std::cout << "Error: loading texture regenerator tower" << std::endl;
	}
	if (!this->voidTexture.loadFromFile("../Assets/Image_Assets/Towers/VoidTower.png")) {
		std::cout << "Error: loading texture void tower" << std::endl;
	}
}

void GUI::initSprites()
{
	this->tileSelector.setSize(sf::Vector2f(gridSizeF, gridSizeF));
	this->tileSelector.setFillColor(sf::Color(255, 0, 0, 32));
	this->tileSelector.setOutlineThickness(2.f);
	this->tileSelector.setOutlineColor(sf::Color::Red);


	screenSize = sf::Vector2f(1920, 1080);
	this->invMaxX = 2;
	this->invMaxY = 7;

	// Set this to window width and height when we have it as a constant
	this->resourceBar.setSize(sf::Vector2f(screenSize.x, 60.f));
	this->resourceBar.setTexture(&this->resourceBarTexture);
	this->resourceBar.setOutlineColor(sf::Color::Yellow);
	this->resourceBar.setOutlineThickness(2);

	this->pauseButton.setSize(sf::Vector2f(40, 40));
	this->pauseButton.setTexture(&this->pauseTexture);
	this->pauseButton.setOutlineColor(sf::Color::Yellow);
	this->pauseButton.setOutlineThickness(2);

	this->settingsButton.setSize(sf::Vector2f(40, 40));
	this->settingsButton.setTexture(&this->settingsTexture);
	this->settingsButton.setOutlineColor(sf::Color::Yellow);
	this->settingsButton.setOutlineThickness(2);

	this->guiBox.resize(7);
	this->guiBox[0].setSize(sf::Vector2f(205.f, 175.f));
	this->guiBox[0].setTexture(&this->miniMapTexture);
	this->guiBox[0].setOutlineColor(sf::Color::Yellow);
	this->guiBox[0].setOutlineThickness(2);

	// Restart Box
	this->guiBox[1].setSize(sf::Vector2f(300.f, 87.5f));
	this->guiBox[1].setTexture(&this->emptyBoxTexture);
	this->guiBox[1].setOutlineColor(sf::Color::Yellow);
	this->guiBox[1].setOutlineThickness(2);

	// End Game Box
	this->guiBox[2].setSize(sf::Vector2f(300.f, 87.5f));
	this->guiBox[2].setTexture(&this->emptyBoxTexture);
	this->guiBox[2].setOutlineColor(sf::Color::Yellow);
	this->guiBox[2].setOutlineThickness(2);

	// Tower List 
	this->guiBox[3].setSize(sf::Vector2f(205.f, 843.f));
	this->guiBox[3].setTexture(&this->emptyBoxTexture);
	this->guiBox[3].setOutlineColor(sf::Color::Yellow);
	this->guiBox[3].setOutlineThickness(2);

	// health Box
	this->guiBox[4].setSize(sf::Vector2f(60.f, 60.f));
	this->guiBox[4].setTexture(&this->healthTexture);
	this->guiBox[4].setOutlineColor(sf::Color::Yellow);
	this->guiBox[4].setOutlineThickness(2);

	// Mana Box
	this->guiBox[5].setSize(sf::Vector2f(60.f, 60.f));
	this->guiBox[5].setTexture(&this->manaTexture);
	this->guiBox[5].setOutlineColor(sf::Color::Yellow);
	this->guiBox[5].setOutlineThickness(2);

	this->guiBox[6].setSize(sf::Vector2f(60.f, 60.f));
	this->guiBox[6].setTexture(&this->waveTexture);
	this->guiBox[6].setOutlineColor(sf::Color::Yellow);
	this->guiBox[6].setOutlineThickness(2);

	//this->miniMapBox.setSize(sf::Vector2f(200.f, 200.f));
	//this->miniMapBox.setFillColor(sf::Color::Black);
	//this->miniMapBox.setOutlineColor(sf::Color::Yellow);
	//this->miniMapBox.setOutlineThickness(2);

	//this->chatBox.setSize(sf::Vector2f(guiBox[3].getSize().x - 50, guiBox[0].getSize().y - 20));
	//this->chatBox.setFillColor(sf::Color::Black);
	//this->chatBox.setOutlineColor(sf::Color::Yellow);
	//this->chatBox.setOutlineThickness(2);

	//this->chatScrollBar.setSize(sf::Vector2f(20.f, guiBox[3].getSize().y - 20));
	//this->chatScrollBar.setFillColor(sf::Color::Black);
	//this->chatScrollBar.setOutlineColor(sf::Color::Yellow);
	//this->chatScrollBar.setOutlineThickness(2);

	this->inventoryBox.resize(invMaxX * invMaxY);

	for (int j = 0; j < invMaxY; j++) {
		for (int i = 0; i < invMaxX; i++) {
			this->inventoryBox[invMax].setSize(sf::Vector2f(80, 80));
			//this->inventoryBox[invMax].setFillColor(sf::Color::Black);
			this->inventoryBox[invMax].setOutlineColor(sf::Color::Yellow);
			this->inventoryBox[invMax].setOutlineThickness(2);
			this->inventoryBox[invMax].setPosition((this->guiBox[3].getPosition().x + 10) + (float)(i * inventoryBox[invMax].getSize().x), (this->guiBox[3].getPosition().y * (this->guiBox[3].getSize().y / 4) + 10) + (float)(j * inventoryBox[invMax].getSize().y));
			this->inventoryBox[invMax].setTexture(&this->inventoryBoxTexture[invMax]);
			this->invMax++;
		}
	}

}

void GUI::initText()
{
	this->levelText.setFont(font);
	this->levelText.setFillColor(sf::Color::Black);
	this->levelText.setCharacterSize(30);

	this->scoreText.setFont(font);
	this->scoreText.setFillColor(sf::Color::Black);
	this->scoreText.setCharacterSize(30);

	this->timerText.setFont(font);
	this->timerText.setFillColor(sf::Color(0, 0, 0));

	this->dayText.setFont(font);
	this->dayText.setFillColor(sf::Color(0, 0, 0));

	this->healthText.setFont(font);
	this->healthText.setFillColor(sf::Color::Black);
	this->healthText.setCharacterSize(30);

	this->manaText.setFont(font);
	this->manaText.setFillColor(sf::Color::Black);
	this->manaText.setCharacterSize(30);

	this->waveText.setFont(font);
	this->waveText.setFillColor(sf::Color::Black);
	this->waveText.setCharacterSize(30);
}

// Public Functions
GUI::GUI()
{
	this->initVariables();
	this->initTextures();
	this->initSprites();
	this->initText();
}


GUI::~GUI()
{
}

void GUI::updateResources()
{
	this->levelString = std::to_string(this->levelValue); // converting the int to string, so player knows the stats
	this->scoreString = std::to_string(this->scoreValue);

	this->healthString = std::to_string(this->health);
	this->manaString = std::to_string(this->mana);
	this->waveString = std::to_string(wave.getWaveNumber());

	this->levelText.setString("Level: " + levelString);

	this->scoreText.setString("Score: " + scoreString);

	this->healthText.setString(healthString);

	this->manaText.setString(manaString);

	this->waveText.setString(waveString);
}

void GUI::updateClock()
{
	sf::Time TimeElapsed = guiClock.getElapsedTime(); // setting the time to the hud clock, so it can count seconds
	sf::Time seconds = sf::seconds(1); // this is to compare to the time elapsed to get 1 second


	std::string MinutesString = std::to_string(guiTimeMinute);
	std::string SecondsString = std::to_string(guiTime);
	std::string dayString = std::to_string(day);

	if (TimeElapsed >= seconds) { // if the time elapsed is a second, increment the HUDTime and restart the HUDClock 
		guiTime++;
		guiClock.restart();
		//std::cout << "Minutes: " << HUDTimeMinute << ", Seconds: " << HUDTime << std::endl;
	}

	if (guiTime >= minute) { // if the HUDTime is more or equal to 60, do this
		guiTimeMinute++; // increment the hud time minute
		guiTime = 0; // change the hud time back to 0
		if (guiTimeMinute >= 24) {// if the hudtime minute is more than 24(like a 24 hour clock)
			day++;
			guiTimeMinute = 0; // set hudtime back to 0
		}
	}

	dayText.setString("Day : " + dayString);
	if (guiTimeMinute <= 9 && guiTime <= 9) { // if both HUDTime and HUDTimeMinute is less than 9, put a 0 before both 
		timerText.setString("0" + MinutesString + " : 0" + SecondsString);
	}
	else if (guiTime <= 9) { // if the HUDTime seconds is less than 9, have a 0 before the number, so it's digital time
		timerText.setString(MinutesString + " : 0" + SecondsString);
	}
	else if (guiTimeMinute <= 9) { // ig HUDTimeMinute is less than 9, but a 0 before the minutes
		timerText.setString("0" + MinutesString + " : " + SecondsString);
	}
	else {
		timerText.setString(MinutesString + " : " + SecondsString);

	}

}

void GUI::update(sf::Time deltaTime)
{
	this->structInv.update();
	this->wave.update();
	this->updateClock();
	this->updateResources();
	this->updateTowerTextures();
}

void GUI::updateTowerTextures()
{
	if (mana < structInv.fireTower.towerCost) {
		inventoryBox[0].setTexture(&fireNoTexture);
	}
	else {
		inventoryBox[0].setTexture(&fireTexture);
	}
	if (mana < structInv.waterTower.towerCost) {
		inventoryBox[7].setTexture(&waterNoTexture);
	}
	else {
		inventoryBox[7].setTexture(&waterTexture);
	}
	if (mana < structInv.windTower.towerCost) {
		inventoryBox[1].setTexture(&windNoTexture);
	}
	else {
		inventoryBox[1].setTexture(&windTexture);
	}
	if (mana < structInv.iceTower.towerCost) {
		inventoryBox[8].setTexture(&iceNoTexture);
	}
	else {
		inventoryBox[8].setTexture(&iceTexture);
	}
	if (mana < structInv.earthTower.towerCost) {
		inventoryBox[2].setTexture(&earthNoTexture);
	}
	else {
		inventoryBox[2].setTexture(&earthTexture);
	}
	if (mana < structInv.energyTower.towerCost) {
		inventoryBox[9].setTexture(&energyNoTexture);
	}
	else {
		inventoryBox[9].setTexture(&energyTexture);
	}
	if (mana < structInv.lightTower.towerCost) {
		inventoryBox[3].setTexture(&lightNoTexture);
	}
	else {
		inventoryBox[3].setTexture(&lightTexture);
	}
	if (mana < structInv.darkTower.towerCost) {
		inventoryBox[10].setTexture(&darkNoTexture);
	}
	else {
		inventoryBox[10].setTexture(&darkTexture);
	}
	if (mana < structInv.elementalAmplifier.towerCost) {
		inventoryBox[4].setTexture(&elemAmpNoTexture);
	}
	else {
		inventoryBox[4].setTexture(&elemAmpTexture);
	}
	if (mana < structInv.elementalOverclocker.towerCost) {
		inventoryBox[5].setTexture(&elemOverNoTexture);
	}
	else {
		inventoryBox[5].setTexture(&elemOverTexture);
	}
	if (mana < structInv.manaAmplifier.towerCost) {
		inventoryBox[6].setTexture(&manaAmpNoTexture);
	}
	else {
		inventoryBox[6].setTexture(&manaAmpTexture);
	}
	if (mana < structInv.regenTower.towerCost) {
		inventoryBox[12].setTexture(&regenNoTexture);
	}
	else {
		inventoryBox[12].setTexture(&regenTexture);
	}
	if (mana < structInv.observatory.towerCost) {
		inventoryBox[11].setTexture(&observNoTexture);
	}
	else {
		inventoryBox[11].setTexture(&observTexture);
	}
	if (mana < structInv.voidTower.towerCost) {
		inventoryBox[13].setTexture(&voidNoTexture);
	}
	else {
		inventoryBox[13].setTexture(&voidTexture);
	}
}

void GUI::keyHandler(sf::Keyboard::Key key)
{
	if (key == sf::Keyboard::Key::Q) {
		mana += 1000;
	}
	if (key == sf::Keyboard::Key::M) {
		std::cout << "Wave Began" << std::endl;
		wave.beginWave();
	}
}

void GUI::mouseHandler(sf::Vector2i &windowPos, sf::Vector2u &gridPos)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		if (structInv.isFollowing() == false) {
			if (windowPos.x >= inventoryBox[0].getPosition().x && windowPos.x <= inventoryBox[0].getPosition().x + inventoryBox[0].getSize().x) {

				if (windowPos.y >= inventoryBox[0].getPosition().y && windowPos.y <= inventoryBox[0].getPosition().y + inventoryBox[0].getSize().y) {
					if (mana >= structInv.fireTower.towerCost) {
						std::cout << "Clicking Fire Tower" << std::endl;
						this->structInv.towerFollow(this->fireTower);
						this->mouseHeld = true;
					}
					else {
						// set fire tower texture to crossed out tower texture
					}
				}
				if (windowPos.y >= inventoryBox[1].getPosition().y && windowPos.y <= inventoryBox[1].getPosition().y + inventoryBox[1].getSize().y) {
					if (mana >= structInv.windTower.towerCost) {
						std::cout << "Clicking Wind Tower" << std::endl;
						this->structInv.towerFollow(this->windTower);
						this->mouseHeld = true;
					}
				}
				if (windowPos.y >= inventoryBox[2].getPosition().y && windowPos.y <= inventoryBox[2].getPosition().y + inventoryBox[2].getSize().y) {
					if (mana >= structInv.earthTower.towerCost) {
						std::cout << "Clicking Earth Tower" << std::endl;
						this->structInv.towerFollow(this->earthTower);
						this->mouseHeld = true;
					}
				}
				if (windowPos.y >= inventoryBox[3].getPosition().y && windowPos.y <= inventoryBox[3].getPosition().y + inventoryBox[3].getSize().y) {
					if (mana >= structInv.lightTower.towerCost) {
						std::cout << "Clicking Light Tower" << std::endl;
						this->structInv.towerFollow(this->lightTower);
						this->mouseHeld = true;
					}
				}
				if (windowPos.y >= inventoryBox[4].getPosition().y && windowPos.y <= inventoryBox[4].getPosition().y + inventoryBox[4].getSize().y) {
					if (mana >= structInv.elementalAmplifier.towerCost) {
						std::cout << "Clicking Elemental Amplifier Tower" << std::endl;
						this->structInv.towerFollow(this->elementAmpTower);
						this->mouseHeld = true;
					}
				}
				if (windowPos.y >= inventoryBox[5].getPosition().y && windowPos.y <= inventoryBox[5].getPosition().y + inventoryBox[5].getSize().y) {
					if (mana >= structInv.elementalOverclocker.towerCost) {
						std::cout << "Clicking Elemental Overclocker tower" << std::endl;
						this->structInv.towerFollow(this->elementOverTower);
						this->mouseHeld = true;
					}
				}
				if (windowPos.y >= inventoryBox[6].getPosition().y && windowPos.y <= inventoryBox[6].getPosition().y + inventoryBox[6].getSize().y) {
					if (mana >= structInv.manaAmplifier.towerCost) {
						std::cout << "Clicking Mana Amplifier" << std::endl;
						this->structInv.towerFollow(this->manaAmpTower);
						this->mouseHeld = true;
					}
				}
			}
			else if (windowPos.x >= inventoryBox[7].getPosition().x && windowPos.x <= inventoryBox[7].getPosition().x + inventoryBox[7].getSize().x) {
				if (windowPos.y >= inventoryBox[7].getPosition().y && windowPos.y <= inventoryBox[7].getPosition().y + inventoryBox[7].getSize().y) {
					if (mana >= structInv.waterTower.towerCost) {
						std::cout << "Clicking Water Tower" << std::endl;
						this->structInv.towerFollow(this->waterTower);
						this->mouseHeld = true;
					}
				}
				if (windowPos.y >= inventoryBox[8].getPosition().y && windowPos.y <= inventoryBox[8].getPosition().y + inventoryBox[8].getSize().y) {
					if (mana >= structInv.iceTower.towerCost) {
						std::cout << "Clicking Ice Tower" << std::endl;
						this->structInv.towerFollow(this->iceTower);
						this->mouseHeld = true;
					}
				}
				if (windowPos.y >= inventoryBox[9].getPosition().y && windowPos.y <= inventoryBox[9].getPosition().y + inventoryBox[9].getSize().y) {
					if (mana >= structInv.energyTower.towerCost) {
						std::cout << "Clicking Energy Tower" << std::endl;
						this->structInv.towerFollow(this->energyTower);
						this->mouseHeld = true;
					}
				}
				if (windowPos.y >= inventoryBox[10].getPosition().y && windowPos.y <= inventoryBox[10].getPosition().y + inventoryBox[10].getSize().y) {
					if (mana >= structInv.darkTower.towerCost) {
						std::cout << "Clicking Dark Tower" << std::endl;
						this->structInv.towerFollow(this->darkTower);
						this->mouseHeld = true;
					}
				}
				if (windowPos.y >= inventoryBox[11].getPosition().y && windowPos.y <= inventoryBox[11].getPosition().y + inventoryBox[11].getSize().y) {
					if (mana >= structInv.observatory.towerCost) {
						std::cout << "Clicking Observatory tower" << std::endl;
						this->structInv.towerFollow(this->observTower);
						this->mouseHeld = true;
					}
				}
				if (windowPos.y >= inventoryBox[12].getPosition().y && windowPos.y <= inventoryBox[12].getPosition().y + inventoryBox[12].getSize().y) {
					if (mana >= structInv.regenTower.towerCost) {
						std::cout << "Clicking regenerator tower" << std::endl;
						this->structInv.towerFollow(this->regenTower);
						this->mouseHeld = true;
					}
				}
				if (windowPos.y >= inventoryBox[13].getPosition().y && windowPos.y <= inventoryBox[13].getPosition().y + inventoryBox[13].getSize().y) {
					if (mana >= structInv.voidTower.towerCost) {
						std::cout << "Clicking void tower" << std::endl;
						this->structInv.towerFollow(this->voidTower);
						this->mouseHeld = true;
					}
				}
			}
			// Add here
			structInv.towerClicked(sf::Vector2i(gridPos.x * gridSizeU, gridPos.y * gridSizeU));
		}
		else {
			if (this->mouseHeld == false && mana >= this->structInv.getTowerCost()) {
				if (this->structInv.towerPlacable(sf::Vector2i(gridPos.x * gridSizeU, gridPos.y * gridSizeU)) == true) {
					this->mana -= this->structInv.towerPlace(sf::Vector2i(gridPos.x * gridSizeU, gridPos.y * gridSizeU));
				}
				this->mouseHeld = true;
			}
		}
	}
	else {
		this->mouseHeld = false;
	}
	structInv.mouseHandler(windowPos);
}

void GUI::renderResources(sf::RenderTarget & target, sf::View & view)
{
	this->resourceBar.setPosition(0.f, -2.f);
	this->levelText.setPosition(50, 10);
	this->scoreText.setPosition(650, 10);

	target.setView(sf::View(sf::FloatRect(0, 0, 1920, 1080)));
	target.draw(resourceBar);
	target.draw(levelText);
	target.draw(scoreText);
}

void GUI::render(sf::RenderTarget & target, sf::View & view)
{
	this->pauseButton.setPosition(1810.f, 10.f);
	this->settingsButton.setPosition(1870.f, 10.f);
	this->guiBox[0].setPosition(1920 - guiBox[0].getSize().x, 1080 - guiBox[0].getSize().y);

	this->guiBox[1].setPosition(guiBox[0].getPosition().x - guiBox[1].getSize().x - 2, guiBox[0].getPosition().y);
	this->guiBox[2].setPosition(guiBox[0].getPosition().x - guiBox[2].getSize().x - 2, guiBox[1].getPosition().y + guiBox[2].getSize().y);
	this->guiBox[3].setPosition(guiBox[0].getPosition().x, guiBox[0].getPosition().y - guiBox[3].getSize().y - 2);
	this->guiBox[4].setPosition(guiBox[3].getPosition().x + 10, guiBox[3].getPosition().y + 10);
	this->guiBox[5].setPosition(guiBox[4].getPosition().x, guiBox[4].getPosition().y + guiBox[5].getSize().y + 10);
	this->guiBox[6].setPosition(guiBox[5].getPosition().x, guiBox[5].getPosition().y + guiBox[6].getSize().y + 10);

	this->healthText.setPosition(this->guiBox[4].getPosition().x + 80, this->guiBox[4].getPosition().y + 10);
	this->manaText.setPosition(this->guiBox[5].getPosition().x + 80, this->guiBox[5].getPosition().y + 10);
	this->waveText.setPosition(this->guiBox[6].getPosition().x + 80, this->guiBox[6].getPosition().y + 10);
	//this->miniMapBox.setPosition(this->guiBox[0].getPosition().x + 50, this->guiBox[0].getPosition().y +50);
	//this->chatBox.setPosition(this->guiBox[3].getPosition().x + 10, this->guiBox[3].getPosition().y + 10);
	//this->chatScrollBar.setPosition(this->chatBox.getPosition().x + this->chatBox.getSize().x + 10, this->guiBox[3].getPosition().y + 10);
	this->dayText.setPosition(1450, 10);
	this->timerText.setPosition(1610, 10);
	this->renderResources(target, view);

	int max = 0;
	for (int i = 0; i < invMaxX; i++) {
		for (int j = 0; j < invMaxY; j++) {
			this->inventoryBox[max].setPosition((this->guiBox[3].getPosition().x + 25) + (float)(i * inventoryBox[max].getSize().x), (this->guiBox[3].getPosition().y + 225) + (float)(j * inventoryBox[max].getSize().y));
			max++;
		}
	}

	target.draw(pauseButton);
	target.draw(settingsButton);
	for (int i = 0; i < guiBox.size(); i++) {
		target.draw(guiBox[i]);
	}
	//target.draw(miniMapBox);
	for (int i = 0; i < inventoryBox.size(); i++) {
		target.draw(inventoryBox[i]);
	}
	target.draw(timerText);
	target.draw(dayText);
	target.draw(healthText);
	target.draw(manaText);
	target.draw(waveText);
	this->renderWave(target);
	this->structInv.render(target);
	
}

void GUI::renderTowerSelector(sf::RenderTarget & target, sf::Vector2i pos)
{
	/*
	TODO: Make it so that pathway tiles are not placable tiles
	also make water tiles unplacable unless it's a water tower
	
	*/
	if (structInv.isFollowing()) {
		structInv.returnUnplacablePosition(pos);
		if (!structInv.towerPlacable(sf::Vector2i(pos.x, pos.y))) {
			this->tileSelector.setFillColor(sf::Color(255, 0, 0, 32));
			this->tileSelector.setOutlineColor(sf::Color::Red);
			this->tileSelector.setPosition(pos.x, pos.y);
			target.draw(tileSelector);
		}
		else {
			this->tileSelector.setFillColor(sf::Color(0, 255, 0, 32));
			this->tileSelector.setOutlineColor(sf::Color::Green);
			this->tileSelector.setPosition(pos.x, pos.y);
			target.draw(tileSelector);
		}
	}
	else {
		structInv.returnUnplacablePosition(pos);
		if (!structInv.towerPlacable(sf::Vector2i(pos.x, pos.y))) {
			this->tileSelector.setFillColor(sf::Color(0, 255, 0, 32));
			this->tileSelector.setOutlineColor(sf::Color::Green);
			this->tileSelector.setPosition(pos.x, pos.y);
			target.draw(tileSelector);
		}
	}
}

void GUI::renderTowers(sf::RenderTarget & target)
{
	this->structInv.renderTowers(target);
}

void GUI::renderWave(sf::RenderTarget & target)
{
	this->wave.render(target);
}
