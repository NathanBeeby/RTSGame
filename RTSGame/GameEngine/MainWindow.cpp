#include "MainWindow.h"


// Initialization
void MainWindow::initWindow()
{

	this->screenSize = sf::Vector2f(1920, 1080);
	this->videoMode = sf::VideoMode(screenSize.x, screenSize.y);
	this->window = new sf::RenderWindow(this->videoMode, "RTS Game", sf::Style::Fullscreen);
	//this->window = new sf::RenderWindow(this->videoMode, "RTS Game", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(true);
	this->isRunning = true;
	this->viewSpeed = 100.f;
}

void MainWindow::initView()
{
	view.reset(sf::FloatRect(0, 0, screenSize.x, screenSize.y)); // setting the view to the screen
	view.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f)); // from the left point(start point to width scale), top(start to screen height scale), screen width scale, screen height scale
	view.setCenter(screenSize.x / 2.f, screenSize.y / 2.f);
	view.zoom(gameState.getZoomAmt()); // zooming out 
	//std::cout << "Gamestate zoom: " << gameState.getZoomAmt() << std::endl;
}

// Constructor / Destructor
MainWindow::MainWindow()
{
	this->initWindow();
	this->initView();
}

MainWindow::~MainWindow()
{

}

const bool MainWindow::running() const
{
	return isRunning;
}

const sf::Vector2i & MainWindow::getMousePosScreen() const
{
	return sf::Mouse::getPosition();
}

const sf::Vector2i & MainWindow::getMousePosWindow() const
{
	return sf::Vector2i();
}

const sf::Vector2f & MainWindow::getMousePosView() const
{
	return sf::Vector2f();
}

const sf::Vector2u & MainWindow::getMousePosGrid() const
{
	return sf::Vector2u();
}

void MainWindow::keyInput(sf::Keyboard::Key key)
{
	gameState.keyInput(key);
	if (key == sf::Keyboard::Escape) {
		this->window->close();
	}
	if (this->gameState.gState == this->gameState.gameOn) {
		if (key == sf::Keyboard::W || key == sf::Keyboard::Up)
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
		}
	}
}

void MainWindow::mouseInput()
{
	gameState.mouseInput(*this->window);
}


void MainWindow::updateView()
{
	//std::cout << "Gamestate zoom is now: " << gameState.getZoomAmt() << std::endl;
	this->view.zoom(gameState.getZoomAmt());
	this->view.move(gameState.viewMovement.x, gameState.viewMovement.y);
}

void MainWindow::updatePollEvents(sf::Time deltaTime)
{
	// use window events for keyboard input
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type) {
		case sf::Event::KeyPressed: // handling the Key pressed events (mostly in other classes)
			this->keyInput(this->ev.key.code);
			break;
		case sf::Event::KeyReleased:

			break;
		case sf::Event::MouseButtonPressed: // case for mouse used
			gameState.mousePressed();
			break;
		case sf::Event::MouseButtonReleased:
			gameState.mouseReleased();
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

// Public Functions
void MainWindow::update(sf::Time deltaTime)
{
	this->gameState.update(deltaTime);
	this->updatePollEvents(deltaTime);
	this->updateView();
	this->mouseInput();
}

void MainWindow::render()
{
	// Clearing the window
	this->window->clear();
	// Drawing the game
	this->window->setView(view);

	this->gameState.render(*this->window, this->view);


	this->window->setView(this->window->getDefaultView());
	this->window->display();
}

void MainWindow::run()
{
	sf::Time deltaTime = clock.restart();
	this->update(deltaTime);
	this->render();

}
