#pragma once
#include "MainWindow.h"
#include "States/GameState.h"
#include <sstream>
class MainGame
{
private:
	// Private Variables
	GameState gameState;
	sf::Clock clock;
	sf::View view;
	sf::Event ev;
	MainWindow m_window;
	bool isRunning;
	float viewSpeed;
	// Initialization
	void initVariables();
	void initView();
public:
	// Constructor / Destructor
	MainGame();
	~MainGame();

	// Public Variables
	MainWindow* GetWindow();

	// Accessors
	const bool running() const;

	// Public Functions
	void keyInput(sf::Keyboard::Key key);
	void mouseInput();
	void updateView();
	void updatePollEvents(sf::Time deltaTime);
	void update(sf::Time deltaTime);
	void render();
	void run();
};

