#include "GameState.h"


// Initialization
void GameState::initVariables()
{
	this->gState = gameOn; // setting the Gamestate to the start menu initially
	this->zoomAmt = 1.f;
	this->zoomInt = 0;
	this->mouseHeld = false;
	this->viewMovement = sf::Vector2f(0, 0);
}

void GameState::initSprites()
{
}

// Constructor / Destructor
GameState::GameState()
{
	this->initVariables();
	this->initSprites();
}


GameState::~GameState()
{

}

const float & GameState::getZoomAmt() const
{
	//std::cout << "ZoomAmt: " << this->zoomAmt << std::endl;
	return this->zoomAmt;
}

void GameState::zoomOut()
{
	if (zoomInt < 20) {
		this->zoomAmt += 0.05f;
		this->zoomInt++;
		std::cout << "Zooming Out" << std::endl;
	}
}

void GameState::zoomIn()
{
	if (zoomInt > -20) {
		this->zoomAmt -= 0.05f;
		this->zoomInt--;
		std::cout << "Zooming In" << std::endl;
	}
}

void GameState::keyInput(sf::Keyboard::Key key, sf::View &view)
{
	if (this->gState == start) {
		this->startMenu.keyHandler(key);
	}
	else if (this->gState == options) {
		this->optionsMenu.keyHandler(key);
	}
	else if (this->gState == instructions) {
		this->instructionsMenu.keyHandler(key);
	}
	else if (this->gState == credits) {
		this->creditsMenu.keyHandler(key);
	}
	else if (this->gState == initGame) {
		this->initGameMenu.keyHandler(key);
	}
	else if (this->gState == gameOn) {
		this->game.keyHandler(key, view);
	}
	else if (this->gState == gameFailure) {
		this->failMenu.keyHandler(key);
	}
	else if (this->gState == gameSuccess) {
		this->successMenu.keyHandler(key);
	}
}

void GameState::mouseInput(sf::RenderWindow & window)
{
	if (this->gState == start) {
		this->startMenu.mouseHandler(window);
	}
	else if (this->gState == options) {
		this->optionsMenu.mouseHandler(window);
	}
	else if (this->gState == instructions) {
		this->instructionsMenu.mouseHandler(window);
	}
	else if (this->gState == credits) {
		this->creditsMenu.mouseHandler(window);
	}
	else if (this->gState == initGame) {
		this->initGameMenu.mouseHandler(window);
	}
	else if (this->gState == gameOn) {
		//this->game.mouseHandler(window);
	}
	else if (this->gState == gameFailure) {
		this->failMenu.mouseHandler(window);
	}
	else if (this->gState == gameSuccess) {
		this->successMenu.mouseHandler(window);
	}
}

void GameState::mousePressed()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		this->mouseHeld = true;
	}
}

void GameState::mouseReleased()
{
	std::cout << "Mouse Released" << std::endl;
	this->mouseHeld = false;
}

void GameState::mouseScrolled(sf::Event ev)
{
	if (this->gState == gameOn) {
		if (ev.mouseWheel.x < 0) {
			zoomIn();
		}
		else if (ev.mouseWheel.x > 0) {
			zoomOut();
		}
	}
}

void GameState::updateMouseDragged()
{
	mx0 = mx;
	my0 = my;
	mx = sf::Mouse::getPosition().x;
	my = sf::Mouse::getPosition().y;

	if (mx > mx0) {
		viewMovement.x += 10.f;
	}
	else if (mx0 > mx) {
		viewMovement.x -= 10.f;
	}
	if (my > my0) {
		viewMovement.y += 10.f;
	}
	else if (my0 > my) {
		viewMovement.y -= 10.f;
	}
}

// Public Functions
void GameState::updateGameState(sf::Time deltaTime)
{
	if (this->gState == start) {
		this->startMenu.update();
		if (this->startMenu.newGamePressed) {
			this->gState = initGame;
		}
		else if (this->startMenu.loadGamePressed) {

		}
		else if (this->startMenu.optionsPressed) {
			this->gState = options;
		}
		else if (this->startMenu.quitPressed) {
			// Close game here
		}
	}
	else if (this->gState == options) {
		this->optionsMenu.update();
		if (this->optionsMenu.instructionsPressed) {
			this->gState = instructions;
		}
		else if (this->optionsMenu.backPressed) {
			this->gState = start;
		}
	}
	else if (this->gState == instructions) {
		this->instructionsMenu.update();
		if (this->instructionsMenu.backPressed) {
			this->gState = options;
		}
	}
	else if (this->gState == credits) {
		this->creditsMenu.update();
	}
	else if (this->gState == initGame) {
		this->initGameMenu.update();
		if (this->initGameMenu.playPressed) {
			this->gState = gameOn;
		}
		else if (this->initGameMenu.backPressed) {
			this->gState = start;
		}
	}
	else if (this->gState == gameOn) {
		if (this->game.LevelIsLost()) {
		this->gState = gameFailure;
		}
		else if (this->game.LevelIsWon()) {
			this->gState = gameSuccess;
		}
		else {
			this->game.update(deltaTime);
		}
	}
	else if (this->gState == gameFailure) {
		this->failMenu.update();
	}
	else if (this->gState == gameSuccess) {
		this->successMenu.update();
	}
}

void GameState::update(sf::Time deltaTime)
{
	viewMovement.x = 0;
	viewMovement.y = 0;
	//std::cout << "ZoomInt = " << this->zoomInt << std::endl;
	this->updateGameState(deltaTime);
	if (gState == gameOn && mouseHeld) {
		this->updateMouseDragged();
	}
}

void GameState::renderGameState(sf::RenderWindow &window, sf::View &view)
{
	if (this->gState == start) {
		this->startMenu.render(window);
	}
	else if (this->gState == options) {
		this->optionsMenu.render(window);
	}
	else if (this->gState == instructions) {
		this->instructionsMenu.render(window);
	}
	else if (this->gState == credits) {
		this->creditsMenu.render(window);
	}
	else if (this->gState == initGame) {
		this->initGameMenu.render(window);
	}
	else if (this->gState == gameOn) {
		this->game.render(window, view);
		this->zoomAmt = 1.f;
	}
	else if (this->gState == gameFailure) {
		this->failMenu.render(window);
	}
	else if (this->gState == gameSuccess) {
		this->successMenu.render(window);
	}
}

void GameState::render(sf::RenderWindow &window, sf::View &view)
{
	renderGameState(window, view);
}
