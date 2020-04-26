#include "StartMenu.h"



void StartMenu::initVariables()
{
}

void StartMenu::initSprites()
{
	this->background.setPosition(0, 0);
	this->background.setSize(sf::Vector2f(this->width, this->height));
	this->background.setTexture(&this->backgroundTexture);
}

void StartMenu::initTextures()
{
	if (!this->backgroundTexture.loadFromFile("../Assets/Image_Assets/Menus/Background.png")) {
		std::cout << "Error: loading Background.png" << std::endl;
	}
}

void StartMenu::initText()
{
	this->MenuText[0].setFont(font);
	this->MenuText[0].setCharacterSize(60);
	this->MenuText[0].setFillColor(sf::Color::Blue);
	this->MenuText[0].setString("New Game");
	this->MenuText[0].setPosition(sf::Vector2f(this->width / 2.5, this->height / (item_Number + 2) * 1)); // center item for width, have the amount of string items + 1, so that they're equally spaced out

	this->MenuText[1].setFont(font);
	this->MenuText[1].setCharacterSize(60);
	this->MenuText[1].setFillColor(sf::Color::White);
	this->MenuText[1].setString("Load Game");
	this->MenuText[1].setPosition(sf::Vector2f(this->width / 2.5, this->height / (item_Number + 2) * 2)); // center item for width, have the amount of string items + 1, so that they're equally spaced out

	this->MenuText[2].setFont(font);
	this->MenuText[2].setCharacterSize(60);
	this->MenuText[2].setFillColor(sf::Color::White);
	this->MenuText[2].setString("Options");
	this->MenuText[2].setPosition(sf::Vector2f(this->width / 2.5, this->height / (item_Number + 2) * 3)); // center item for width, have the amount of string items + 1, so that they're equally spaced out

	this->MenuText[3].setFont(font);
	this->MenuText[3].setCharacterSize(60);
	this->MenuText[3].setFillColor(sf::Color::White);
	this->MenuText[3].setString("Quit");
	this->MenuText[3].setPosition(sf::Vector2f(this->width / 2.5, this->height / (item_Number + 2) * 4)); // center item for width, have the amount of string items + 1, so that they're equally spaced out

}

// Constructor / Destructor
StartMenu::StartMenu()
{
	this->initVariables();
	this->initTextures();
	this->initText();
	this->initSprites();
}


StartMenu::~StartMenu()
{

}

void StartMenu::Up()
{
	if (this->selectedItemIndex - 1 >= 0) { // If the item index is above 0, so you cant just keep pressing up and break stuff
		this->MenuText[selectedItemIndex].setFillColor(sf::Color::White); //set the blue color to white
		this->selectedItemIndex--; //decrememnt the index
		this->MenuText[selectedItemIndex].setFillColor(sf::Color::Blue); //set the white colour to blue
	}
}

void StartMenu::Down()
{
	if (this->selectedItemIndex + 1 < item_Number) { // If the item index is above 0, so you cant just keep pressing up and break stuff
		this->MenuText[selectedItemIndex].setFillColor(sf::Color::White); //set the blue color to white
		this->selectedItemIndex++; // increment the index
		this->MenuText[selectedItemIndex].setFillColor(sf::Color::Blue); //set the white colour to blue
	}
}

// Public Functions
void StartMenu::keyHandler(sf::Keyboard::Key key)
{
	if (key == sf::Keyboard::W || key == sf::Keyboard::Up) {
		Up();
		std::cout << "Up pressed" << std::endl;
	}
	if (key == sf::Keyboard::S || key == sf::Keyboard::Down) {
		Down();
		std::cout << "Down pressed" << std::endl;
	}


	if (key == sf::Keyboard::Return) {
		std::cout << "return pressed" << std::endl;
		switch (GetPressedItem()) {
		case 0: std::cout << "play pressed" << std::endl;
			newGamePressed = true;
			break;
		case 1: std::cout << "options pressed" << std::endl;
			loadGamePressed = true;
			break;
		case 2: std::cout << "exit pressed" << std::endl;
			optionsPressed = true;
			break;
		case 3: std::cout << "exit pressed" << std::endl;
			quitPressed = true;
			break;
		}
	}
}

void StartMenu::mouseHandler(sf::RenderWindow & window)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) { // left mouse button
		if (mousePos.x >= MenuText[0].getPosition().x && mousePos.x <= MenuText[0].getPosition().x + 320) { // if the x position is on the first HUD button
			if (mousePos.y >= MenuText[0].getPosition().y && mousePos.y <= MenuText[0].getPosition().y + 130) { // if the y position is between the HUD button
				std::cout << "New Game pressed" << std::endl;
				newGamePressed = true;
			}
		}
		if (mousePos.x >= MenuText[1].getPosition().x && mousePos.x <= MenuText[1].getPosition().x + 320) { // if the x position is on the first HUD button
			if (mousePos.y >= MenuText[1].getPosition().y && mousePos.y <= MenuText[1].getPosition().y + 130) { // if the y position is between the HUD button
				std::cout << "Load Game pressed" << std::endl;
				loadGamePressed = true;
			}
		}
		if (mousePos.x >= MenuText[2].getPosition().x && mousePos.x <= MenuText[2].getPosition().x + 260) { // if the x position is on the first HUD button
			if (mousePos.y >= MenuText[2].getPosition().y && mousePos.y <= MenuText[2].getPosition().y + 130) { // if the y position is between the HUD button
				std::cout << "Options pressed" << std::endl;
				optionsPressed = true;
			}
		}
		if (mousePos.x >= MenuText[3].getPosition().x && mousePos.x <= MenuText[3].getPosition().x + 160) { // if the x position is on the first HUD button
			if (mousePos.y >= MenuText[3].getPosition().y && mousePos.y <= MenuText[3].getPosition().y + 130) { // if the y position is between the HUD button
				std::cout << "Quit Button pressed" << std::endl;
				quitPressed = true;
			}
		}
	}
}

void StartMenu::update()
{
}

void StartMenu::render(sf::RenderTarget & target)
{
	target.draw(background);

	for(int i = 0; i < item_Number; i++){
	target.draw(MenuText[i]);
	}
}
