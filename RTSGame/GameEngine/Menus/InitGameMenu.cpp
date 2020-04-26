#include "InitGameMenu.h"



void InitGameMenu::initVariables()
{
	this->backPressed = false;
	this->playPressed = false;
}

void InitGameMenu::initSprites()
{
	this->background.setPosition(0, 0);
	this->background.setSize(sf::Vector2f(this->width, this->height));
	this->background.setTexture(&this->backgroundTexture);
}

void InitGameMenu::initTextures()
{
	if (!this->backgroundTexture.loadFromFile("../Assets/Image_Assets/Menus/SkyBackground.png")) {
		std::cout << "Error: loading Game Background.png" << std::endl;
	}
}

void InitGameMenu::initText()
{
	MenuText[0].setFont(font);
	MenuText[0].setCharacterSize(60);
	MenuText[0].setFillColor(sf::Color::Blue);
	MenuText[0].setString("Difficulty");
	MenuText[0].setPosition(sf::Vector2f(120, 55)); // center item for width, have the amount of string items + 1, so that they're equally spaced out

	MenuText[1].setFont(font);
	MenuText[1].setCharacterSize(60);
	MenuText[1].setFillColor(sf::Color::White);
	MenuText[1].setString("Enemies");
	MenuText[1].setPosition(sf::Vector2f(120, 355)); // center item for width, have the amount of string items + 1, so that they're equally spaced out

	MenuText[2].setFont(font);
	MenuText[2].setCharacterSize(60);
	MenuText[2].setFillColor(sf::Color::White);
	MenuText[2].setString("Play");
	MenuText[2].setPosition(sf::Vector2f(120, 655)); // center item for width, have the amount of string items + 1, so that they're equally spaced out

	MenuText[3].setFont(font);
	MenuText[3].setCharacterSize(60);
	MenuText[3].setFillColor(sf::Color::White);
	MenuText[3].setString("Back");
	MenuText[3].setPosition(sf::Vector2f(40, this->height - 150)); // center item for width, have the amount of string items + 1, so that they're equally spaced out
}

InitGameMenu::InitGameMenu()
{
	this->initVariables();
	this->initTextures();
	this->initSprites();
	this->initText();
}


InitGameMenu::~InitGameMenu()
{
}

void InitGameMenu::Up()
{
	if (this->selectedItemIndex - 1 >= 0) { // If the item index is above 0, so you cant just keep pressing up and break stuff
		this->MenuText[selectedItemIndex].setFillColor(sf::Color::White); //set the blue color to white
		this->selectedItemIndex--; //decrememnt the index
		this->MenuText[selectedItemIndex].setFillColor(sf::Color::Blue); //set the white colour to blue
	}
}

void InitGameMenu::Down()
{
	if (this->selectedItemIndex + 1 < item_Number) { // If the item index is above 0, so you cant just keep pressing up and break stuff
		this->MenuText[selectedItemIndex].setFillColor(sf::Color::White); //set the blue color to white
		this->selectedItemIndex++; // increment the index
		this->MenuText[selectedItemIndex].setFillColor(sf::Color::Blue); //set the white colour to blue
	}
}

void InitGameMenu::backButtonPressed()
{
	this->backPressed = true;
}

void InitGameMenu::playButtonPressed()
{
	this->playPressed = true;
}

void InitGameMenu::keyHandler(sf::Keyboard::Key key)
{
	if (key == sf::Keyboard::Up) {
		Up();
		std::cout << "Up Pressed" << std::endl;
	}
	else if (key == sf::Keyboard::Down) {
		Down();
		std::cout << "Down Pressed" << std::endl;
	}

	if (key == sf::Keyboard::Left) {
		std::cout << "Left Pressed" << std::endl;
		switch (GetPressedItem()) {
		case 0: std::cout << "Difficulty pressed" << std::endl;

			break;
		case 1: std::cout << "Enemies pressed" << std::endl;

			break;
		}
	}

	else if (key == sf::Keyboard::Right) {
		std::cout << "Right Pressed" << std::endl;
		switch (GetPressedItem()) {
		case 0: std::cout << "Difficulty pressed" << std::endl;
		
			break;
		case 1: std::cout << "Enemies pressed" << std::endl;
		
			break;
		}
	}
	if (key == sf::Keyboard::Return) {
		std::cout << "Return Pressed" << std::endl;
		switch (GetPressedItem()) {
		case 2: std::cout << "Play Pressed" << std::endl;
			playButtonPressed();
			break;
		case 3: std::cout << "Back Pressed" << std::endl;
			backButtonPressed();
			break;

		}
	}
}

void InitGameMenu::mouseHandler(sf::RenderWindow & window)
{
	sf::Vector2i mousePos = ::sf::Mouse::getPosition(window); // getting the position of the mouse relative to the window
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) { // left mouse button
		if (mousePos.x >= MenuText[0].getPosition().x && mousePos.x <= MenuText[0].getPosition().x + 130) { // if the x position is on the first HUD button
			if (mousePos.y >= MenuText[0].getPosition().y && mousePos.y <= MenuText[0].getPosition().y + 100) { // if the y position is between the HUD button
				std::cout << "Difficulty pressed" << std::endl;
			}
		}
		if (mousePos.x >= MenuText[1].getPosition().x && mousePos.x <= MenuText[1].getPosition().x + 130) { // if the x position is on the first HUD button
			if (mousePos.y >= MenuText[1].getPosition().y && mousePos.y <= MenuText[1].getPosition().y + 100) { // if the y position is between the HUD button
				std::cout << "Enemies pressed" << std::endl;
			}
		}
		if (mousePos.x >= MenuText[2].getPosition().x && mousePos.x <= MenuText[2].getPosition().x + 130) { // if the x position is on the first HUD button
			if (mousePos.y >= MenuText[2].getPosition().y && mousePos.y <= MenuText[2].getPosition().y + 100) { // if the y position is between the HUD button
				std::cout << "Play pressed" << std::endl;
				playButtonPressed();
			}
		}
		if (mousePos.x >= MenuText[3].getPosition().x && mousePos.x <= MenuText[3].getPosition().x + 100) { // if the x position is on the first HUD button
			if (mousePos.y >= MenuText[3].getPosition().y && mousePos.y <= MenuText[3].getPosition().y + 100) { // if the y position is between the HUD button
				std::cout << "Back pressed" << std::endl;
				backButtonPressed();
			}
		}
	}
}

void InitGameMenu::update()
{
}

void InitGameMenu::render(sf::RenderTarget & target)
{
	target.draw(background);
	
	for (int i = 0; i < item_Number; i++) {
		target.draw(MenuText[i]);
	}
}
