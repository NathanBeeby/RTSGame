#include <SFML/Graphics.hpp>
#include "../UI/GUI.h"
#include "../Map/Tile.h"
class Game {
private:
	// Private Variables
	float gridSizeF = 200.f;
	unsigned gridSizeU = static_cast<unsigned>(gridSizeF);
	GUI gui;
	Tile tile;
	std::vector<sf::RectangleShape> sprite;
	std::vector<sf::Texture> spriteTexture;
	sf::RectangleShape tileSelector;

	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;
	sf::Vector2u mousePosGrid;

	// Initialization
	void initVariables();
	void initTextures();
	void initSprites();
public:
	// Constructor / Destructor
	Game();
	virtual ~Game();

	// Public Functions
	void keyHandler(sf::Keyboard::Key key);
	void mouseHandler(sf::RenderWindow &window);
	void updateTileView(sf::View &view);
	void update(sf::Time deltaTime);
	void render(sf::RenderWindow &window, sf::View &view);
};