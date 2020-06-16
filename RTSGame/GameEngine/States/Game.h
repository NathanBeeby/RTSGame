#include <SFML/Graphics.hpp>
#include "../UI/GUI.h"
#include "../Map/Tile.h"
class Game {
private:
	// Private Variables
	float viewSpeed, deltaTime;
	float gridSizeF = 200.f;
	unsigned gridSizeU = static_cast<unsigned>(gridSizeF);

	GUI gui;
	Tile tile;

	sf::View miniMap;
	sf::RectangleShape tileSelector;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;
	sf::Vector2u mousePosGrid;
	sf::Clock clock;

	std::vector<sf::RectangleShape> sprite;
	std::vector<sf::Texture> spriteTexture;

	// Initialization
	void initVariables();
	void initTextures();
	void initSprites();
public:
	// Constructor / Destructor
	Game();
	virtual ~Game();

	// Accessor
	const bool LevelIsLost() const;
	const bool LevelIsWon() const;

	// Public Functions
	void keyHandler(sf::Keyboard::Key key, sf::View &view);
	void mouseHandler(sf::RenderWindow &window, sf::View &view);
	void updateTileView(sf::View &view);
	void update(sf::Time deltaTime);
	void render(sf::RenderWindow &window, sf::View &view);
};