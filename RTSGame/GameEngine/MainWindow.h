#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Constants.h"

class MainWindow
{
private:
	// Private Variables
	void Setup(const std::string& l_title,
		const sf::Vector2u& l_size);
	void Destroy();
	void Create();

	sf::Vector2f screenSize;
	bool m_isFullscreen;
	bool m_isDone;
	sf::Vector2u m_windowSize;
	std::string m_windowTitle;

public:
	// Constructor / Destructor
	MainWindow();
	MainWindow(const std::string& l_title, const sf::Vector2u& l_size);
	~MainWindow();

	// Public Variables
	sf::RenderWindow m_window;
	// Accessors


	// Public functions
	void BeginDraw(); // Clear the window.
	void EndDraw(); // Display the changes.
	bool IsFullscreen();
	bool IsDone();
	void close();
	void ToggleFullscreen();
	sf::Vector2u GetWindowSize();
};

