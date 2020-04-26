#include "OptionsMenu.h"


// Initialization
void OptionsMenu::initVariables()
{
	this->Music = 0.0f;
	this->Sound = 0.0f;
	this->instructionsPressed = false;
	this->backPressed = false;

}

void OptionsMenu::initSprites()
{
	this->background.setPosition(0, 0);
	this->background.setSize(sf::Vector2f(this->width, this->height));
	this->background.setTexture(&this->backgroundTexture);

	emptyMaster.setSize(sf::Vector2f(800, 60));
	emptyMaster.setFillColor(sf::Color(255, 0, 0));
	emptyMaster.setOutlineThickness(2);
	emptyMaster.setOutlineColor(sf::Color(0, 0, 0));

	emptyMusic.setSize(sf::Vector2f(800, 60));
	emptyMusic.setFillColor(sf::Color(255, 0, 0));
	emptyMusic.setOutlineThickness(2);
	emptyMusic.setOutlineColor(sf::Color(0, 0, 0));

	emptySound.setSize(sf::Vector2f(800, 60));
	emptySound.setFillColor(sf::Color(255, 0, 0));
	emptySound.setOutlineThickness(2);
	emptySound.setOutlineColor(sf::Color(0, 0, 0));

	MasterBar.setFillColor(sf::Color(0, 0, 255));
	MasterBar.setOutlineThickness(2);
	MasterBar.setOutlineColor(sf::Color(0, 0, 0));

	MusicBar.setFillColor(sf::Color(0, 0, 255));
	MusicBar.setOutlineThickness(2);
	MusicBar.setOutlineColor(sf::Color(0, 0, 0));

	SoundBar.setFillColor(sf::Color(0, 0, 255));
	SoundBar.setOutlineThickness(2);
	SoundBar.setOutlineColor(sf::Color(0, 0, 0));

	emptyMaster.setPosition(sf::Vector2f(750, 65));
	emptySound.setPosition(sf::Vector2f(750, 175));
	emptyMusic.setPosition(sf::Vector2f(750, 285));
}

void OptionsMenu::initTextures()
{
	if (!this->backgroundTexture.loadFromFile("../Assets/Image_Assets/Menus/GameBackground.png")) {
		std::cout << "Error: loading Game Background.png" << std::endl;
	}
}

void OptionsMenu::initText()
{
	MenuText[0].setFont(font);
	MenuText[0].setCharacterSize(60);
	MenuText[0].setFillColor(sf::Color::Blue);
	MenuText[0].setString("Master Volume");
	MenuText[0].setPosition(sf::Vector2f(120, 55)); // center item for width, have the amount of string items + 1, so that they're equally spaced out

	MenuText[1].setFont(font);
	MenuText[1].setCharacterSize(60);
	MenuText[1].setFillColor(sf::Color::White);
	MenuText[1].setString("SFX Volume");
	MenuText[1].setPosition(sf::Vector2f(120, 165)); // center item for width, have the amount of string items + 1, so that they're equally spaced out

	MenuText[2].setFont(font);
	MenuText[2].setCharacterSize(60);
	MenuText[2].setFillColor(sf::Color::White);
	MenuText[2].setString("Music Volume");
	MenuText[2].setPosition(sf::Vector2f(120, 275)); // center item for width, have the amount of string items + 1, so that they're equally spaced out

	MenuText[3].setFont(font);
	MenuText[3].setCharacterSize(60);
	MenuText[3].setFillColor(sf::Color::White);
	MenuText[3].setString("Instructions");
	MenuText[3].setPosition(sf::Vector2f(40, this->height - 150)); // center item for width, have the amount of string items + 1, so that they're equally spaced out

	MenuText[4].setFont(font);
	MenuText[4].setCharacterSize(60);
	MenuText[4].setFillColor(sf::Color::White);
	MenuText[4].setString("Back");
	MenuText[4].setPosition(sf::Vector2f(this->width - 200, this->height - 150)); // center item for width, have the amount of string items + 1, so that they're equally spaced out

}

// Constructor / Destructor
OptionsMenu::OptionsMenu()
{
	this->initVariables();
	this->initTextures();
	this->initSprites();
	this->initText();
}


OptionsMenu::~OptionsMenu()
{
}

void OptionsMenu::instructionsButtonPressed()
{
	this->instructionsPressed = true;
}

void OptionsMenu::backButtonPressed()
{
	this->backPressed = true;
}

void OptionsMenu::Up()
{
	if (this->selectedItemIndex - 1 >= 0) { // If the item index is above 0, so you cant just keep pressing up and break stuff
		this->MenuText[selectedItemIndex].setFillColor(sf::Color::White); //set the blue color to white
		this->selectedItemIndex--; //decrememnt the index
		this->MenuText[selectedItemIndex].setFillColor(sf::Color::Blue); //set the white colour to blue
	}
}

void OptionsMenu::Down()
{
	if (this->selectedItemIndex + 1 < item_Number) { // If the item index is above 0, so you cant just keep pressing up and break stuff
		this->MenuText[selectedItemIndex].setFillColor(sf::Color::White); //set the blue color to white
		this->selectedItemIndex++; // increment the index
		this->MenuText[selectedItemIndex].setFillColor(sf::Color::Blue); //set the white colour to blue
	}
}

// Public Functions
void OptionsMenu::keyHandler(sf::Keyboard::Key key)
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
		case 0: std::cout << "Master pressed" << std::endl;
			if (Master != 0) {
				Master--;
			}
			break;
		case 1: std::cout << "Sound pressed" << std::endl;
			if (Sound != 0) {
				Sound--;
			}
			break;
		case 2: std::cout << "Music pressed" << std::endl;
			if (Music != 0) {

				Music--;
			}
			break;
		}
	}

	else if (key == sf::Keyboard::Right) {
		std::cout << "Right Pressed" << std::endl;
		switch (GetPressedItem()) {
		case 0: std::cout << "Master pressed" << std::endl;
			if (Master <= 99) {
				Master++;


			}
			break;
		case 1: std::cout << "Sound pressed" << std::endl;
			if (Sound <= 99) {
				Sound++;


			}
			break;
		case 2: std::cout << "Music pressed" << std::endl;
			if (Music <= 99) {
				Music++;

			}
			break;
		}
	}
	if (key == sf::Keyboard::Return) {
		std::cout << "Return Pressed" << std::endl;
		switch (GetPressedItem()) {
		case 3: std::cout << "Instructions" << std::endl;
			instructionsButtonPressed();
			break;
		case 4: std::cout << "Back" << std::endl;
			backButtonPressed();
			break;

		}
	}
}

void OptionsMenu::mouseHandler(sf::RenderWindow & window)
{
	sf::Vector2i mousePos = ::sf::Mouse::getPosition(window); // getting the position of the mouse relative to the window
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) { // left mouse button
		if (mousePos.x >= MenuText[0].getPosition().x && mousePos.x <= MenuText[0].getPosition().x + 130) { // if the x position is on the first HUD button
			if (mousePos.y >= MenuText[0].getPosition().y && mousePos.y <= MenuText[0].getPosition().y + 100) { // if the y position is between the HUD button
				std::cout << "Master Volume pressed" << std::endl;
			}
		}
		if (mousePos.x >= MenuText[1].getPosition().x && mousePos.x <= MenuText[1].getPosition().x + 130) { // if the x position is on the first HUD button
			if (mousePos.y >= MenuText[1].getPosition().y && mousePos.y <= MenuText[1].getPosition().y + 100) { // if the y position is between the HUD button
				std::cout << "SFX Volume pressed" << std::endl;
			}
		}
		if (mousePos.x >= MenuText[2].getPosition().x && mousePos.x <= MenuText[2].getPosition().x + 130) { // if the x position is on the first HUD button
			if (mousePos.y >= MenuText[2].getPosition().y && mousePos.y <= MenuText[2].getPosition().y + 100) { // if the y position is between the HUD button
				std::cout << "Music pressed" << std::endl;
			}
		}
		if (mousePos.x >= MenuText[3].getPosition().x && mousePos.x <= MenuText[3].getPosition().x + 300) { // if the x position is on the first HUD button
			if (mousePos.y >= MenuText[3].getPosition().y && mousePos.y <= MenuText[3].getPosition().y + 100) { // if the y position is between the HUD button
				std::cout << "Instructions pressed" << std::endl;
				instructionsButtonPressed();
			}
		}
		if (mousePos.x >= MenuText[4].getPosition().x && mousePos.x <= MenuText[4].getPosition().x + 100) { // if the x position is on the first HUD button
			if (mousePos.y >= MenuText[4].getPosition().y && mousePos.y <= MenuText[4].getPosition().y + 100) { // if the y position is between the HUD button
				std::cout << "Instructions pressed" << std::endl;
				backButtonPressed();
			}
		}
		
	}
}

void OptionsMenu::update()
{
	SoundBar.setPosition(emptySound.getPosition().x, emptySound.getPosition().y);
	MusicBar.setPosition(emptyMusic.getPosition().x, emptyMusic.getPosition().y);
	MasterBar.setPosition(emptyMaster.getPosition().x, emptyMaster.getPosition().y);

	MasterBar.setSize(sf::Vector2f((Master * 8), 60));
	MusicBar.setSize(sf::Vector2f((Music * 8), 60));
	SoundBar.setSize(sf::Vector2f((Sound * 8), 60));
}

void OptionsMenu::render(sf::RenderTarget & target)
{
	target.draw(background);

	target.draw(emptyMaster);
	target.draw(emptyMusic);
	target.draw(emptySound);
	target.draw(MasterBar);
	target.draw(MusicBar);
	target.draw(SoundBar);

	for (int i = 0; i < item_Number; i++) {
		target.draw(MenuText[i]);
	}
}
