#include "GUI.h"


// Initialization
void GUI::initVariables()
{
	this->woodValue = 0;
	this->stoneValue = 0;
	this->coalValue = 0;
	this->goldValue = 0;
	this->invMax = 0;
	this->guiTime = 0;
	this->guiTimeMinute = 0;
	this->day = 0;
	this->minute = 60;
}

void GUI::initTextures()
{
	if (!this->font.loadFromFile("../Assets/Font_Assets/Freshman.ttf")) {
		std::cout << "Error: loading GUI Font" << std::endl;
	}

	if (!this->resourceBarTexture.loadFromFile("../Assets/Image_Assets/GUI/ResourceBar.png")) {
		std::cout << "Error: loading resourceBarTexture" << std::endl;
	}
	if (!this->pauseTexture.loadFromFile("../Assets/Image_Assets/GUI/PauseButton.png")) {
		std::cout << "Error: loading resourceBarTexture" << std::endl;
	}
	if (!this->settingsTexture.loadFromFile("../Assets/Image_Assets/GUI/SettingsButton.png")) {
		std::cout << "Error: loading resourceBarTexture" << std::endl;
	}
	if (!this->chatBoxTexture.loadFromFile("../Assets/Image_Assets/GUI/ChatBox.png")) {
		std::cout << "Error: loading resourceBarTexture" << std::endl;
	}
	if (!this->emptyBoxTexture.loadFromFile("../Assets/Image_Assets/GUI/EmptyBox.png")) {
		std::cout << "Error: loading resourceBarTexture" << std::endl;
	}
	if (!this->inventoryTexture.loadFromFile("../Assets/Image_Assets/GUI/InventoryBox.png")) {
		std::cout << "Error: loading resourceBarTexture" << std::endl;
	}
	if (!this->miniMapTexture.loadFromFile("../Assets/Image_Assets/GUI/MiniMapBox.png")) {
		std::cout << "Error: loading resourceBarTexture" << std::endl;
	}
}

void GUI::initSprites()
{
	screenSize = sf::Vector2f(1920, 1080);
	this->invMaxX = 5;
	this->invMaxY = 3;

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

	this->guiBox.resize(4);
	this->guiBox[0].setSize(sf::Vector2f(screenSize.x / 4, 200.f));
	this->guiBox[0].setTexture(&this->chatBoxTexture);
	this->guiBox[0].setOutlineColor(sf::Color::Yellow);
	this->guiBox[0].setOutlineThickness(2);

	this->guiBox[1].setSize(sf::Vector2f(screenSize.x / 4, 200.f));
	this->guiBox[1].setTexture(&this->emptyBoxTexture);
	this->guiBox[1].setOutlineColor(sf::Color::Yellow);
	this->guiBox[1].setOutlineThickness(2);

	this->guiBox[2].setSize(sf::Vector2f(screenSize.x / 4, 200.f));
	this->guiBox[2].setTexture(&this->inventoryTexture);
	this->guiBox[2].setOutlineColor(sf::Color::Yellow);
	this->guiBox[2].setOutlineThickness(2);

	this->guiBox[3].setSize(sf::Vector2f(screenSize.x / 4, 200.f));
	this->guiBox[3].setTexture(&this->miniMapTexture);
	this->guiBox[3].setOutlineColor(sf::Color::Yellow);
	this->guiBox[3].setOutlineThickness(2);

	this->miniMapBox.setSize(sf::Vector2f(400.f, 180.f));
	this->miniMapBox.setFillColor(sf::Color::Black);
	this->miniMapBox.setOutlineColor(sf::Color::Yellow);
	this->miniMapBox.setOutlineThickness(2);

	this->chatBox.setSize(sf::Vector2f(guiBox[0].getSize().x - 50, guiBox[0].getSize().y - 20));
	this->chatBox.setFillColor(sf::Color::Black);
	this->chatBox.setOutlineColor(sf::Color::Yellow);
	this->chatBox.setOutlineThickness(2);

	this->chatScrollBar.setSize(sf::Vector2f(20.f, guiBox[0].getSize().y - 20));
	this->chatScrollBar.setFillColor(sf::Color::Black);
	this->chatScrollBar.setOutlineColor(sf::Color::Yellow);
	this->chatScrollBar.setOutlineThickness(2);

	this->inventoryBox.resize(invMaxX * invMaxY);

	for (int i = 0; i < invMaxX; i++) {
		for (int j = 0; j < invMaxY; j++) {
			this->inventoryBox[invMax].setSize(sf::Vector2f(60, 60));
			this->inventoryBox[invMax].setFillColor(sf::Color::Black);
			this->inventoryBox[invMax].setOutlineColor(sf::Color::Yellow);
			this->inventoryBox[invMax].setOutlineThickness(2);
			this->inventoryBox[invMax].setPosition((this->guiBox[2].getPosition().x + 90) + (float)(i * inventoryBox[invMax].getSize().x), (this->guiBox[2].getPosition().y + 10) + (float)(j * inventoryBox[invMax].getSize().y));
			this->invMax++;
		}
	}

}

void GUI::initText()
{
	this->woodText.setFont(font);
	this->woodText.setFillColor(sf::Color::Green);
	this->woodText.setCharacterSize(30);

	this->stoneText.setFont(font);
	this->stoneText.setFillColor(sf::Color(125, 125, 125));
	this->stoneText.setCharacterSize(30);

	this->coalText.setFont(font);
	this->coalText.setFillColor(sf::Color(55, 55, 55));
	this->coalText.setCharacterSize(30);

	this->goldText.setFont(font);
	this->goldText.setFillColor(sf::Color::Yellow);
	this->goldText.setCharacterSize(30);

	this->timerText.setFont(font);
	this->timerText.setFillColor(sf::Color(0, 0, 0));

	this->dayText.setFont(font);
	this->dayText.setFillColor(sf::Color(0, 0, 0));
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
	this->woodString = std::to_string(this->woodValue); // converting the int to string, so player knows the stats
	this->stoneString = std::to_string(this->stoneValue);
	this->coalString = std::to_string(this->coalValue);
	this->goldString = std::to_string(this->goldValue);

	this->woodText.setString("Wood: " + woodString);

	this->stoneText.setString("Stone: " + stoneString);

	this->coalText.setString("Coal: " + coalString);

	this->goldText.setString("Gold: " + goldString);
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
	this->updateClock();
	this->updateResources();
}

void GUI::renderResources(sf::RenderTarget & target, sf::View & view)
{
	this->resourceBar.setPosition(0.f, -2.f);
	this->woodText.setPosition(50,10);
	this->stoneText.setPosition(350,10);
	this->coalText.setPosition(650,10);
	this->goldText.setPosition(950, 10);

	//this->resourceBar.setPosition(view.getCenter().x - (view.getSize().x / 2), view.getCenter().y - (view.getSize().y / 2) - 2);
	//this->woodText.setPosition(sf::Vector2f(view.getCenter().x - (view.getSize().x / 2) + 50, view.getCenter().y - (view.getSize().y / 2) + 10));
	//this->stoneText.setPosition(sf::Vector2f(view.getCenter().x - (view.getSize().x / 2) + 350, view.getCenter().y - (view.getSize().y / 2) + 10));
	//this->coalText.setPosition(sf::Vector2f(view.getCenter().x - (view.getSize().x / 2) + 650, view.getCenter().y - (view.getSize().y / 2) + 10));
	//this->goldText.setPosition(sf::Vector2f(view.getCenter().x - (view.getSize().x / 2) + 950, view.getCenter().y - (view.getSize().y / 2) + 10));

	target.setView(sf::View(sf::FloatRect(0, 0, 1920, 1080)));
	target.draw(resourceBar);
	target.draw(woodText);
	target.draw(stoneText);
	target.draw(coalText);
	target.draw(goldText);
}

void GUI::render(sf::RenderTarget & target, sf::View & view)
{
	this->pauseButton.setPosition(1810.f, 10.f);
	this->settingsButton.setPosition(1870.f, 10.f);
	this->guiBox[0].setPosition(0, 1080 - guiBox[0].getSize().y);
	this->guiBox[1].setPosition(0 + guiBox[0].getSize().x, 1080 - guiBox[1].getSize().y);
	this->guiBox[2].setPosition(guiBox[1].getPosition().x + guiBox[1].getSize().x, 1080 - guiBox[2].getSize().y);
	this->guiBox[3].setPosition(guiBox[2].getPosition().x + guiBox[2].getSize().x, 1080 - guiBox[3].getSize().y);
	this->miniMapBox.setPosition(this->guiBox[3].getPosition().x + 45, this->guiBox[3].getPosition().y + 10);
	this->chatBox.setPosition(this->guiBox[0].getPosition().x + 10, this->guiBox[0].getPosition().y + 10);
	this->chatScrollBar.setPosition(this->chatBox.getPosition().x + this->chatBox.getSize().x + 10, this->guiBox[0].getPosition().y + 10);
	this->dayText.setPosition(1450, 10);
	this->timerText.setPosition(1610, 10);
	this->renderResources(target, view);

	int max = 0;
	for (int i = 0; i < invMaxX; i++) {
		for (int j = 0; j < invMaxY; j++) {
			this->inventoryBox[max].setPosition((this->guiBox[2].getPosition().x + 90) + (float)(i * inventoryBox[max].getSize().x), (this->guiBox[2].getPosition().y + 10) + (float)(j * inventoryBox[max].getSize().y));
			max++;
		}
	}

	target.draw(pauseButton);
	target.draw(settingsButton);
	for (int i = 0; i < guiBox.size(); i++) {
		target.draw(guiBox[i]);
	}
	target.draw(miniMapBox);
	for (int i = 0; i < inventoryBox.size(); i++) {
		target.draw(inventoryBox[i]);
	}
	target.draw(timerText);
	target.draw(dayText);
	target.draw(chatBox);
	target.draw(chatScrollBar);
}
