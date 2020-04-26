#include "InstructionsMenu.h"



void InstructionsMenu::initVariables()
{
}

void InstructionsMenu::initSprites()
{
	this->background.setPosition(0, 0);
	this->background.setSize(sf::Vector2f(this->width, this->height));
	this->background.setTexture(&this->backgroundTexture);
}

void InstructionsMenu::initTextures()
{
	if (!this->backgroundTexture.loadFromFile("../Assets/Image_Assets/Menus/MenuBackground.png")) {
		std::cout << "Error: loading Game Background.png" << std::endl;
	}
}

void InstructionsMenu::initText()
{
	MenuText[0].setFont(font);
	MenuText[0].setCharacterSize(60);
	MenuText[0].setFillColor(sf::Color::Blue);
	MenuText[0].setString("Instruction 1");
	MenuText[0].setPosition(sf::Vector2f(120, 55)); // center item for width, have the amount of string items + 1, so that they're equally spaced out

	MenuText[1].setFont(font);
	MenuText[1].setCharacterSize(60);
	MenuText[1].setFillColor(sf::Color::White);
	MenuText[1].setString("Instruction 2");
	MenuText[1].setPosition(sf::Vector2f(120, 165)); // center item for width, have the amount of string items + 1, so that they're equally spaced out

	MenuText[2].setFont(font);
	MenuText[2].setCharacterSize(60);
	MenuText[2].setFillColor(sf::Color::White);
	MenuText[2].setString("Instruction 3");
	MenuText[2].setPosition(sf::Vector2f(120, 275)); // center item for width, have the amount of string items + 1, so that they're equally spaced out

	MenuText[3].setFont(font);
	MenuText[3].setCharacterSize(60);
	MenuText[3].setFillColor(sf::Color::White);
	MenuText[3].setString("Instruction 4");
	MenuText[3].setPosition(sf::Vector2f(120, 385)); // center item for width, have the amount of string items + 1, so that they're equally spaced out

	MenuText[4].setFont(font);
	MenuText[4].setCharacterSize(60);
	MenuText[4].setFillColor(sf::Color::White);
	MenuText[4].setString("Back");
	MenuText[4].setPosition(sf::Vector2f(this->width - 150, this->height - 150)); // center item for width, have the amount of string items + 1, so that they're equally spaced out

}


InstructionsMenu::InstructionsMenu()
{
	this->initVariables();
	this->initTextures();
	this->initSprites();
	this->initText();
}


InstructionsMenu::~InstructionsMenu()
{
}

void InstructionsMenu::backButtonPressed()
{
}

void InstructionsMenu::Up()
{
	if (this->selectedItemIndex - 1 >= 0) { // If the item index is above 0, so you cant just keep pressing up and break stuff
		this->MenuText[selectedItemIndex].setFillColor(sf::Color::White); //set the blue color to white
		this->selectedItemIndex--; //decrememnt the index
		this->MenuText[selectedItemIndex].setFillColor(sf::Color::Blue); //set the white colour to blue
	}
}

void InstructionsMenu::Down()
{
	if (this->selectedItemIndex + 1 < item_Number) { // If the item index is above 0, so you cant just keep pressing up and break stuff
		this->MenuText[selectedItemIndex].setFillColor(sf::Color::White); //set the blue color to white
		this->selectedItemIndex++; // increment the index
		this->MenuText[selectedItemIndex].setFillColor(sf::Color::Blue); //set the white colour to blue
	}
}

void InstructionsMenu::keyHandler(sf::Keyboard::Key key)
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
		case 0: std::cout << "ins1 pressed" << std::endl;
			ins1 = true;
			break;
		case 1: std::cout << "ins2 pressed" << std::endl;
			ins2 = true;
			break;
		case 2: std::cout << "ins3 pressed" << std::endl;
			ins3 = true;
			break;
		case 3: std::cout << "ins4 pressed" << std::endl;
			ins4 = true;
			break;
		case 4: std::cout << "back pressed" << std::endl;
			backPressed = true;
			break;
		}
	}
}

void InstructionsMenu::mouseHandler(sf::RenderWindow & window)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) { // left mouse button
		if (mousePos.x >= MenuText[0].getPosition().x && mousePos.x <= MenuText[0].getPosition().x + 320) { // if the x position is on the first HUD button
			if (mousePos.y >= MenuText[0].getPosition().y && mousePos.y <= MenuText[0].getPosition().y + 130) { // if the y position is between the HUD button
				std::cout << "ins1 pressed" << std::endl;
				ins1 = true;
			}
		}
		if (mousePos.x >= MenuText[1].getPosition().x && mousePos.x <= MenuText[1].getPosition().x + 320) { // if the x position is on the first HUD button
			if (mousePos.y >= MenuText[1].getPosition().y && mousePos.y <= MenuText[1].getPosition().y + 130) { // if the y position is between the HUD button
				std::cout << "ins2 pressed" << std::endl;
				ins2 = true;
			}
		}
		if (mousePos.x >= MenuText[2].getPosition().x && mousePos.x <= MenuText[2].getPosition().x + 260) { // if the x position is on the first HUD button
			if (mousePos.y >= MenuText[2].getPosition().y && mousePos.y <= MenuText[2].getPosition().y + 130) { // if the y position is between the HUD button
				std::cout << "ins3 pressed" << std::endl;
				ins3 = true;
			}
		}
		if (mousePos.x >= MenuText[3].getPosition().x && mousePos.x <= MenuText[3].getPosition().x + 160) { // if the x position is on the first HUD button
			if (mousePos.y >= MenuText[3].getPosition().y && mousePos.y <= MenuText[3].getPosition().y + 130) { // if the y position is between the HUD button
				std::cout << "ins4 Button pressed" << std::endl;
				ins4 = true;
			}
		}
		if (mousePos.x >= MenuText[4].getPosition().x && mousePos.x <= MenuText[4].getPosition().x + 260) { // if the x position is on the first HUD button
			if (mousePos.y >= MenuText[4].getPosition().y && mousePos.y <= MenuText[4].getPosition().y + 130) { // if the y position is between the HUD button
				std::cout << "Back Button pressed" << std::endl;
				backButtonPressed();
			}
		}
	}
}

void InstructionsMenu::update()
{
}

void InstructionsMenu::render(sf::RenderTarget & target)
{
	target.draw(background);

	for (int i = 0; i < item_Number; i++) {
		target.draw(MenuText[i]);
	}
}
