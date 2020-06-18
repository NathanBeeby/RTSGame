#pragma once
// Menus
#include "../Menus/StartMenu.h"
#include "../Menus/OptionsMenu.h"
#include "../Menus/InstructionsMenu.h"
#include "../Menus/CreditsMenu.h"
#include "../Menus/InitGameMenu.h"
#include "../Menus/GameFailureMenu.h"
#include "../Menus/GameSuccessMenu.h"
// GameStates
#include "Game.h"
class GameState
{
private:
	// Private Variables
	float zoomAmt;
	int zoomInt;
	bool mouseHeld;
	double mx, my, mx0, my0;
	// Menus
	StartMenu startMenu;
	OptionsMenu optionsMenu;
	InstructionsMenu instructionsMenu;
	CreditsMenu creditsMenu;
	InitGameMenu initGameMenu;
	GameFailureMenu failMenu;
	GameSuccessMenu successMenu;
	// Game 
	Game game;

	// Initialization
	void initVariables();
	void initSprites();
public:
	// Constructor / Destructor
	GameState();
	virtual ~GameState();

	// Public Variables
	sf::Vector2f viewMovement;
	int gState;
	enum gameState { start = 0, options, instructions, credits, initGame, gameOn, gameFailure, gameSuccess };
	// Accessors
	const float& getZoomAmt() const;

	// Public Functions
	void zoomOut();
	void zoomIn();
	void keyInput(sf::Keyboard::Key key, sf::View &view);
	void mouseInput(sf::RenderWindow &window);
	void mousePressed();
	void mouseReleased();
	void mouseScrolled(sf::Event ev);
	void updateMouseDragged();
	void updateGameState(sf::Time deltaTime);
	void update(sf::Time deltaTime);
	void renderGameState(sf::RenderWindow &window, sf::View &view);
	void render(sf::RenderWindow &window, sf::View &view);
};

