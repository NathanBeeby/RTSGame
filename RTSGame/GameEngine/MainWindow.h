#pragma once
#include "States/GameState.h"
class MainWindow
{
private:
	// Private Variables
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Vector2f screenSize;

	sf::Vector2u mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;
	sf::Vector2u mousePosGrid;

	sf::View view;
	bool isRunning;
	float viewSpeed;
	sf::Event ev;

	GameState gameState;
	sf::Clock clock;
	// Initialization
	void initWindow();
	void initView();


public:
	// Constructor / Destructor
	MainWindow();
	virtual ~MainWindow();

	// Accessors
	const bool running() const;
	const sf::Vector2i& getMousePosScreen() const;
	const sf::Vector2i& getMousePosWindow() const;
	const sf::Vector2f& getMousePosView() const;
	const sf::Vector2u& getMousePosGrid() const;

	// Public functions
	void keyInput(sf::Keyboard::Key key);
	void mouseInput();
	void updateView();
	void updatePollEvents(sf::Time deltaTime);
	void update(sf::Time deltaTime);
	void render();
	void run();
};

