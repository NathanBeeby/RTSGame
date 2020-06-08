#include "GUI.h"


// Initialization
void GUI::initVariables()
{
	// Integer Variables
	this->levelValue = 0;
	this->scoreValue = 0;
	this->invMax = 0;
	this->health = 100;
	this->wave.mana = 500;
	this->invMaxX = 2;
	this->invMaxY = 7;

	// Float Variables
	this->gridSizeF = 200.f;

	// Boolean Variables
	this->isLevelWon = false;
	this->isLevelLost = false;
	this->towerMenuOpen = true;

	// Vector2f Variables
	this->screenSize = sf::Vector2f(1920, 1080);
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
	if (!this->inventoryBoxTexture[0].loadFromFile(this->towerStrings[0])) {
		std::cout << "Error: loading fire tower" << std::endl;
	}
	if (!this->inventoryBoxTexture[1].loadFromFile(this->towerStrings[2])) {
		std::cout << "Error: loading wind tower" << std::endl;
	}
	if (!this->inventoryBoxTexture[2].loadFromFile(this->towerStrings[4])) {
		std::cout << "Error: loading earth tower" << std::endl;
	}
	if (!this->inventoryBoxTexture[3].loadFromFile(this->towerStrings[6])) {
		std::cout << "Error: loading light tower" << std::endl;
	}
	if (!this->inventoryBoxTexture[4].loadFromFile(this->towerStrings[8])) {
		std::cout << "Error: loading elemental amplifier tower" << std::endl;
	}
	if (!this->inventoryBoxTexture[5].loadFromFile(this->towerStrings[9])) {
		std::cout << "Error: loading elemental overclocker tower" << std::endl;
	}
	if (!this->inventoryBoxTexture[6].loadFromFile(this->towerStrings[10])) {
		std::cout << "Error: loading mana amplifier tower" << std::endl;
	}
	if (!this->inventoryBoxTexture[7].loadFromFile(this->towerStrings[1])) {
		std::cout << "Error: loading water tower" << std::endl;
	}
	if (!this->inventoryBoxTexture[8].loadFromFile(this->towerStrings[3])) {
		std::cout << "Error: loading ice tower" << std::endl;
	}
	if (!this->inventoryBoxTexture[9].loadFromFile(this->towerStrings[5])) {
		std::cout << "Error: loading energy tower" << std::endl;
	}
	if (!this->inventoryBoxTexture[10].loadFromFile(this->towerStrings[7])) {
		std::cout << "Error: loading darkness tower" << std::endl;
	}
	if (!this->inventoryBoxTexture[11].loadFromFile(this->towerStrings[11])) {
		std::cout << "Error: loading observatory tower" << std::endl;
	}
	if (!this->inventoryBoxTexture[12].loadFromFile(this->towerStrings[12])) {
		std::cout << "Error: loading regenerator tower" << std::endl;
	}
	if (!this->inventoryBoxTexture[13].loadFromFile(this->towerStrings[13])) {
		std::cout << "Error: loading void tower" << std::endl;
	}
	if (!this->towerToggleTexture.loadFromFile(this->towerCloseString)) {
		std::cout << "Error: loading tower toggle texture" << std::endl;
	}
}

void GUI::initSprites()
{
	// Initializing Tile Selector
	this->tileSelector.setSize(sf::Vector2f(gridSizeF, gridSizeF));
	this->tileSelector.setFillColor(sf::Color(255, 0, 0, 32));
	this->tileSelector.setOutlineThickness(2.f);
	this->tileSelector.setOutlineColor(sf::Color::Red);

	// Initializing the Resource Bar
	this->resourceBar.setSize(sf::Vector2f(screenSize.x, 60.f));
	this->resourceBar.setTexture(&this->resourceBarTexture);
	this->resourceBar.setOutlineColor(sf::Color::Yellow);
	this->resourceBar.setOutlineThickness(2);

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

	this->inventoryBox.resize(invMaxX * invMaxY);

	for (int j = 0; j < invMaxY; j++) {
		for (int i = 0; i < invMaxX; i++) {
			this->inventoryBox[invMax].setSize(sf::Vector2f(80, 80));
			this->inventoryBox[invMax].setOutlineColor(sf::Color::Yellow);
			this->inventoryBox[invMax].setOutlineThickness(2);
			this->inventoryBox[invMax].setPosition((this->guiBox[3].getPosition().x + 10) + (float)(i * inventoryBox[invMax].getSize().x), (this->guiBox[3].getPosition().y * (this->guiBox[3].getSize().y / 4) + 10) + (float)(j * inventoryBox[invMax].getSize().y));
			this->inventoryBox[invMax].setTexture(&this->inventoryBoxTexture[invMax]);
			this->invMax++;
		}
	}
	towerMenuToggle.setSize(sf::Vector2f(20.f, 80.f));
	towerMenuToggle.setTexture(&towerToggleTexture);
	towerMenuToggle.setPosition(sf::Vector2f((this->guiBox[3].getPosition().x - towerMenuToggle.getSize().x), this->guiBox[3].getPosition().y + (this->guiBox[3].getSize().y / 2)));
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
	this->timerText.setPosition(1610, 10);

	this->dayText.setFont(font);
	this->dayText.setFillColor(sf::Color(0, 0, 0));
	this->dayText.setPosition(1450, 10);

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

// Accessors
const bool GUI::LevelWon() const
{
	return isLevelWon;
}

const bool GUI::LevelLost() const
{
	return isLevelLost;
}

void GUI::AddUnplacablePosition(sf::Vector2i pos)
{
	structInv.unplacablePosition(pos);
}

void GUI::updateGUIPositions()
{
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
}

// Public Functions
void GUI::updateResources()
{
	this->updateGameState();
	this->updateUIText();
}

void GUI::update(sf::Time deltaTime)
{
	this->structInv.update();
	this->wave.update();
	this->updateClock();
	this->updateResources();
	this->updateTowerTextures();
	this->updateGUIPositions();
}

void GUI::updateTowerTextures()
{
	if (this->wave.mana < structInv.fireTower.towerCost) {
		inventoryBox[0].setTexture(&towerNoTextures[0]);
	}
	else {
		inventoryBox[0].setTexture(&this->towerTextures[0]);
	}
	if (this->wave.mana < structInv.waterTower.towerCost) {
		inventoryBox[7].setTexture(&towerNoTextures[1]);
	}
	else {
		inventoryBox[7].setTexture(&this->towerTextures[1]);
	}
	if (this->wave.mana < structInv.windTower.towerCost) {
		inventoryBox[1].setTexture(&towerNoTextures[2]);
	}
	else {
		inventoryBox[1].setTexture(&this->towerTextures[2]);
	}
	if (this->wave.mana < structInv.iceTower.towerCost) {
		inventoryBox[8].setTexture(&towerNoTextures[3]);
	}
	else {
		inventoryBox[8].setTexture(&this->towerTextures[3]);
	}
	if (this->wave.mana < structInv.earthTower.towerCost) {
		inventoryBox[2].setTexture(&towerNoTextures[4]);
	}
	else {
		inventoryBox[2].setTexture(&this->towerTextures[4]);
	}
	if (this->wave.mana < structInv.energyTower.towerCost) {
		inventoryBox[9].setTexture(&towerNoTextures[5]);
	}
	else {
		inventoryBox[9].setTexture(&this->towerTextures[5]);
	}
	if (this->wave.mana < structInv.lightTower.towerCost) {
		inventoryBox[3].setTexture(&towerNoTextures[6]);
	}
	else {
		inventoryBox[3].setTexture(&this->towerTextures[6]);
	}
	if (this->wave.mana < structInv.darkTower.towerCost) {
		inventoryBox[10].setTexture(&towerNoTextures[7]);
	}
	else {
		inventoryBox[10].setTexture(&this->towerTextures[7]);
	}
	if (this->wave.mana < structInv.elementalAmplifier.towerCost) {
		inventoryBox[4].setTexture(&towerNoTextures[8]);
	}
	else {
		inventoryBox[4].setTexture(&this->towerTextures[8]);
	}
	if (this->wave.mana < structInv.elementalOverclocker.towerCost) {
		inventoryBox[5].setTexture(&towerNoTextures[9]);
	}
	else {
		inventoryBox[5].setTexture(&this->towerTextures[9]);
	}
	if (this->wave.mana < structInv.manaAmplifier.towerCost) {
		inventoryBox[6].setTexture(&towerNoTextures[10]);
	}
	else {
		inventoryBox[6].setTexture(&this->towerTextures[10]);
	}
	if (this->wave.mana < structInv.observatory.towerCost) {
		inventoryBox[11].setTexture(&towerNoTextures[11]);
	}
	else {
		inventoryBox[11].setTexture(&this->towerTextures[11]);
	}
	if (this->wave.mana < structInv.regenTower.towerCost) {
		inventoryBox[12].setTexture(&towerNoTextures[12]);
	}
	else {
		inventoryBox[12].setTexture(&this->towerTextures[12]);
	}
	if (this->wave.mana < structInv.voidTower.towerCost) {
		inventoryBox[13].setTexture(&towerNoTextures[13]);
	}
	else {
		inventoryBox[13].setTexture(&this->towerTextures[13]);
	}
}

void GUI::keyHandler(sf::Keyboard::Key key)
{
	// Testing purposes, will be removed
	if (key == sf::Keyboard::Key::Q) {
		this->wave.mana += 1000;
	}
	if (key == sf::Keyboard::Key::E) {
		this->health += 100;
	}
	if (key == sf::Keyboard::Key::C) {
		this->towerMenuOpen = false;
	}
	else if (key == sf::Keyboard::Key::V) {
		this->towerMenuOpen = true;
	}
}

void GUI::mouseHandler(sf::Vector2i &windowPos, sf::Vector2u &gridPos)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		if (structInv.isFollowing() == false) {

			this->uiButtonsMouseHandler(windowPos);
			if (towerMenuOpen == true) {
				this->towerMenuMouseHandler(windowPos);
			}
			this->towerUIMouseHandler(windowPos);
			structInv.towerClicked(sf::Vector2i(gridPos.x * gridSizeF, gridPos.y * gridSizeF));
		}
		else {
			if (this->mouseHeld == false && this->wave.mana >= this->structInv.getTowerCost()) {
				if (this->structInv.towerPlacable(sf::Vector2i(gridPos.x * gridSizeF, gridPos.y * gridSizeF)) == true) {
					this->wave.mana -= this->structInv.towerPlace(sf::Vector2i(gridPos.x * gridSizeF, gridPos.y * gridSizeF));
				}
				this->mouseHeld = true;
			}
		}
		this->mouseHeld = true;
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

void GUI::renderGUI(sf::RenderTarget & target)
{
	if (this->towerMenuOpen == false) {
		this->towerToggleTexture.loadFromFile(this->towerOpenString);
	}
	else {
		this->towerToggleTexture.loadFromFile(this->towerCloseString);
	}

	int max = 0;
	for (int i = 0; i < invMaxX; i++) {
		for (int j = 0; j < invMaxY; j++) {
			this->inventoryBox[max].setPosition((this->guiBox[3].getPosition().x + 25) + (float)(i * inventoryBox[max].getSize().x), (this->guiBox[3].getPosition().y + 225) + (float)(j * inventoryBox[max].getSize().y));
			max++;
		}
	}

	for (int i = 0; i < uiButtons.size(); i++) {
		target.draw(uiButtons[i]);
	}
	for (int i = 0; i < guiBox.size(); i++) {
		if (i != 3 && i != 4 && i != 5 && i != 6) {
			target.draw(guiBox[i]);
		}
	}
	if (towerMenuOpen == true) {
		this->renderTowerMenu(target);
	}
	else {
		towerMenuToggle.setPosition(sf::Vector2f((this->guiBox[3].getPosition().x + this->guiBox[3].getSize().x - towerMenuToggle.getSize().x), this->guiBox[3].getPosition().y + (this->guiBox[3].getSize().y / 2)));
		towerMenuToggle.setTexture(&towerToggleTexture);
		target.draw(towerMenuToggle);
	}
	//target.draw(miniMapBox);
	target.draw(timerText);
	target.draw(dayText);
}

void GUI::renderTowerMenu(sf::RenderTarget & target)
{
	towerMenuToggle.setPosition(sf::Vector2f((this->guiBox[3].getPosition().x - towerMenuToggle.getSize().x), this->guiBox[3].getPosition().y + (this->guiBox[3].getSize().y / 2)));
	towerMenuToggle.setTexture(&towerToggleTexture);

	target.draw(this->guiBox[3]);
	target.draw(this->guiBox[4]);
	target.draw(this->guiBox[5]);
	target.draw(this->guiBox[6]);
	for (int i = 0; i < inventoryBox.size(); i++) {
		target.draw(inventoryBox[i]);
	}
	target.draw(healthText);
	target.draw(manaText);
	target.draw(waveText);
	target.draw(towerMenuToggle);
}

void GUI::render(sf::RenderTarget & target, sf::View & view)
{
	this->renderResources(target, view);
	this->renderGUI(target);
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
