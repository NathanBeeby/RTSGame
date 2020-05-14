#include "MainGame.h"


void MainGame::initVariables()
{
	this->isRunning = true;
	/*this->viewSpeed = 100.f;*/
	this->startLocation.x = 3000;
	this->startLocation.y = 2500;
}

void MainGame::initView()
{
	view.reset(sf::FloatRect(0, 0, WIDTH, HEIGHT)); // setting the view to the screen
	view.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f)); // from the left point(start point to width scale), top(start to screen height scale), screen width scale, screen height scale
	view.setCenter(startLocation.x, startLocation.y);
	view.zoom(gameState.getZoomAmt()); // zooming out 
	//std::cout << "Gamestate zoom: " << gameState.getZoomAmt() << std::endl;
}

MainGame::MainGame() : m_window("Nathans Game", sf::Vector2u(WIDTH, HEIGHT))
{
	this->initVariables();
	this->initView();
}


MainGame::~MainGame()
{
}

MainWindow * MainGame::GetWindow()
{
	return nullptr;
}

const bool MainGame::running() const
{
	return this->isRunning;
}


void MainGame::keyInput(sf::Keyboard::Key key, sf::View &view)
{
	std::cout << "Key Pressed " << std::endl;
	gameState.keyInput(key, view);
	if (key == sf::Keyboard::Escape) {
		m_window.close();
	}
	if (this->gameState.gState == this->gameState.gameOn) {
		/*if (key == sf::Keyboard::W || key == sf::Keyboard::Up)
		{
				view.move(0.f, -viewSpeed);
		}
		else if (key == sf::Keyboard::S || key == sf::Keyboard::Down)
		{
				view.move(0.f, viewSpeed);
		}
		else if (key == sf::Keyboard::A || key == sf::Keyboard::Left)
		{
			view.move(-viewSpeed, 0.f);
		}
		else if (key == sf::Keyboard::D || key == sf::Keyboard::Right)
		{
			view.move(viewSpeed, 0.f);
		}*/
		if (key == sf::Keyboard::F5)
		{
			m_window.ToggleFullscreen();
		}
	}
}

void MainGame::mouseInput()
{
	gameState.mouseInput(m_window.m_window);
}


void MainGame::updatePollEvents(sf::Time deltaTime)
{

	// use window events for keyboard input
	while (m_window.m_window.pollEvent(this->ev))
	{
		switch (this->ev.type) {
		case sf::Event::KeyPressed: // handling the Key pressed events (mostly in other classes)
			std::cout << "Key Press" << std::endl;
			this->keyInput(this->ev.key.code, this->view);
			break;
		case sf::Event::KeyReleased:

			break;
		case sf::Event::MouseButtonPressed: // case for mouse used
			//gameState.mousePressed();
			break;
		case sf::Event::MouseButtonReleased:
			//gameState.mouseReleased();
			break;
		case sf::Event::MouseWheelScrolled:
			gameState.mouseScrolled(this->ev);
			break;
		case sf::Event::Closed:
			exit(1); // exiting the program if the close button is pressed
			break;
		}
	}
}

void MainGame::updateView()
{
	//std::cout << "Gamestate zoom is now: " << gameState.getZoomAmt() << std::endl;
	this->view.zoom(gameState.getZoomAmt());

	this->view.move(gameState.viewMovement.x, gameState.viewMovement.y);

	//if (view.getCenter().x < m_window.GetWindowSize().x / 2 && view.getCenter().y < m_window.GetWindowSize().y / 2) {
	//		view.setCenter(m_window.GetWindowSize().x / 2, m_window.GetWindowSize().y / 2 + 240);
	//	}
}

void MainGame::update(sf::Time deltaTime)
{
	this->updatePollEvents(deltaTime);
	this->gameState.update(deltaTime);
	this->updateView();
	this->mouseInput();
}

void MainGame::render()
{
	m_window.BeginDraw();
	m_window.m_window.setView(view);
	gameState.render(m_window.m_window, view);
	m_window.m_window.setView(m_window.m_window.getDefaultView());
	m_window.EndDraw();
}

void MainGame::run()
{
	sf::Time deltaTime = clock.restart();
	this->update(deltaTime);
	this->render();
}
