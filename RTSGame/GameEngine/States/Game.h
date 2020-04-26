#include <SFML/Graphics.hpp>
#include "../UI/GUI.h"
class Game {
private:
	// Private Variables
	GUI gui;
	// Initialization

public:
	// Constructor / Destructor
	Game();
	virtual ~Game();

	// Public Functions
	void keyHandler(sf::Keyboard::Key key);
	void mouseHandler(sf::RenderWindow &window);
	void update(sf::Time deltaTime);
	void render(sf::RenderTarget &target, sf::View &view);
};