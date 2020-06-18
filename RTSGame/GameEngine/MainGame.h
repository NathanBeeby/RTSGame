#pragma once
#include "MainWindow.h"
#include "States/GameState.h"
#include <sstream>
class MainGame
{
private:
	// Private Variables
	bool isRunning;
	sf::Clock clock;
	sf::View view;
	sf::Event ev;
	int height = static_cast<int>(sf::VideoMode::getDesktopMode().height);
	int width = static_cast<int>(sf::VideoMode::getDesktopMode().width);
	GameState gameState;
	MainWindow m_window;

	static sf::Vector2i startLocation;

	// Initialization
	void initVariables();
	void initView();
	void initCursor();
	void initCursorTextures();
public:
	// Constructor / Destructor
	MainGame();
	~MainGame();

	// Public Variables
	MainWindow* GetWindow();
	sf::Texture cursorAttack, cursor, cursorDefend, cursorGrabbed, cursorHover;
	sf::RectangleShape cursorSprite;

	// Accessors
	const bool running() const;

	// Public Functions
	void mouseAttack();
	void mouseDefend();
	void mouseCursor();
	void mouseGrabbed();
	void mouseHover();
	void keyInput(sf::Keyboard::Key key, sf::View &view);
	void mouseInput();
	void updateView();
	void updateMouseCursor();
	void updatePollEvents(sf::Time deltaTime);
	void update(sf::Time deltaTime);
	void renderMouseCursor();
	void render();
	void run();
};

