#include "MainWindow.h"

void MainWindow::Setup(const std::string & l_title, const sf::Vector2u & l_size)
{
	m_windowTitle = l_title;
	m_windowSize = l_size;
	m_isFullscreen = false;
	m_isDone = false;
	Create();
}

void MainWindow::Destroy()
{
	m_window.close();
}

void MainWindow::Create()
{
	auto style = (m_isFullscreen ? sf::Style::Fullscreen
		: sf::Style::Default);
	m_window.create({ m_windowSize.x, m_windowSize.y, 32 },
		m_windowTitle, style);
	m_window.setFramerateLimit(120);
	m_window.setMouseCursorVisible(false);
}

// Constructor / Destructor
MainWindow::MainWindow()
{
	Setup("Window", sf::Vector2u(WIDTH, HEIGHT));
}

MainWindow::MainWindow(const std::string & l_title, const sf::Vector2u & l_size)
{
	Setup(l_title, l_size);
}

MainWindow::~MainWindow()
{
	Destroy();
}

void MainWindow::BeginDraw()
{
	m_window.clear(sf::Color::Black);
}

void MainWindow::EndDraw()
{
	m_window.display();
}

bool MainWindow::IsFullscreen()
{
	return m_isFullscreen;
}

bool MainWindow::IsDone()
{
	return m_isDone;
}

void MainWindow::close()
{
	m_window.close();
}

void MainWindow::ToggleFullscreen()
{
	m_isFullscreen = !m_isFullscreen;
	Destroy();
	Create();
}

sf::Vector2u MainWindow::GetWindowSize()
{
	return m_windowSize;
}




// Public Functions

//void MainWindow::render()
//{
//	// Clearing the window
//	m_window.clear();
//	// Drawing the game
//	m_window.setView(view);
//
//	//this->gameState.render(m_window, this->view);
//
//
//	m_window.setView(m_window.getDefaultView());
//	m_window.display();
//}

//void MainWindow::run()
//{
//	sf::Time deltaTime = clock.restart();
//	this->update();
//	this->render();
//
//}
