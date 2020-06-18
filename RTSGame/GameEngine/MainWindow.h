#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


class MainWindow
{
private:
	// Private Variables
	bool m_isFullscreen;
	bool m_isDone;
	sf::Vector2f screenSize;
	sf::Vector2u m_windowSize;
	std::string m_windowTitle;
	int height = static_cast<int>(sf::VideoMode::getDesktopMode().height);
	int width = static_cast<int>(sf::VideoMode::getDesktopMode().width);
	// Initialization
	void Setup(const std::string& l_title, const sf::Vector2u& l_size);
	void Destroy();
	void Create();

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

