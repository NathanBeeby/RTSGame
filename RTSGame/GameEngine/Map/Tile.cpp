#include "Tile.h"

void Tile::initVariables()
{
	this->tileMax.x = 35;
	this->tileMax.y = 30;
	this->miniMapOffsetX = 0;
	this->miniMapOffsetY = 0;
	this->isWater.resize(tileMax.x * tileMax.y);
}

void Tile::initTextures()
{
	//this->tileTexture.resize(8);
	//if (!this->tileTexture[0].loadFromFile("../Assets/Image_Assets/Tiles/Dirt1.png")) {
	//	std::cout << "Dirt 1 Failed to load" << std::endl;
	//}
	//if (!this->tileTexture[1].loadFromFile("../Assets/Image_Assets/Tiles/Dirt2.png")) {
	//	std::cout << "Dirt 1 Failed to load" << std::endl;
	//}
	//if (!this->tileTexture[2].loadFromFile("../Assets/Image_Assets/Tiles/Grass1.png")) {
	//	std::cout << "Dirt 1 Failed to load" << std::endl;
	//}
	//if (!this->tileTexture[3].loadFromFile("../Assets/Image_Assets/Tiles/Grass2.png")) {
	//	std::cout << "Dirt 1 Failed to load" << std::endl;
	//}
	//if (!this->tileTexture[4].loadFromFile("../Assets/Image_Assets/Tiles/Grass3.png")) {
	//	std::cout << "Dirt 1 Failed to load" << std::endl;
	//}
	//if (!this->tileTexture[5].loadFromFile("../Assets/Image_Assets/Tiles/Sand1.png")) {
	//	std::cout << "Dirt 1 Failed to load" << std::endl;
	//}
	//if (!this->tileTexture[6].loadFromFile("../Assets/Image_Assets/Tiles/Sand2.png")) {
	//	std::cout << "Dirt 1 Failed to load" << std::endl;
	//}
	//if (!this->tileTexture[7].loadFromFile("../Assets/Image_Assets/Tiles/Water.png")) {
	//	std::cout << "Dirt 1 Failed to load" << std::endl;
	//}
}

void Tile::initSprite()
{
	try{
	std::ifstream openfile("../Assets/Map_Assets/Map1.txt");
	if (openfile.is_open()) {
		std::string tileLocation;
		sf::Vector2i loadCounter = sf::Vector2i(0, 0);
		openfile >> tileLocation;
		tileText.loadFromFile(tileLocation);
		tile.setTexture(tileText);
		miniMapTile.setTexture(tileText);
		int isWaterCount = 0;
		while (!openfile.eof()) {
			std::string str;
			openfile >> str;
			char x = str[0], y = str[2];
			if (!isdigit(x) || !isdigit(y)) {
				map[loadCounter.x][loadCounter.y] = sf::Vector2i(-1, -1);
			}
			else {
				map[loadCounter.x][loadCounter.y] = sf::Vector2i(x - '0', y - '0');
			}

			if (openfile.peek() == '\n') {
				loadCounter.x = 0;
				loadCounter.y++;
			}
			else {
				loadCounter.x++;
			}
			if (x >= 1 && y < 5 || x == 0 && y == 5) {
				this->isWater[isWaterCount] = true;
			}
			else {
				this->isWater[isWaterCount] = false;
			}
			isWaterCount++;
		}
		loadCounter.y++;
		this->toX = loadCounter.x;
		this->toY = loadCounter.y;
	}
	}
	catch (std::exception ex) {
		std::cout << ex.what() << std::endl;
		system("pause");
	}

	this->miniMapFromX = 0;
	this->miniMapToX = 0;
	this->miniMapFromY = 0;
	this->miniMapToY = 0;

	this->fromX = 0;
	this->toX = 0;
	this->fromY = 0;
	this->toY = 0;
}

Tile::Tile()
{
	this->initVariables();
	this->initTextures();
	this->initSprite();
}

Tile::~Tile()
{
}

void Tile::updateTileView()
{
	if (fromX < 0) {
		fromX = 0;
	}
	else if (fromX >= tileMax.x) {
		fromX = tileMax.x - 1;
	}
	if (toX < 0) {
		toX = 0;
	}
	else if (toX >= tileMax.x) {
		toX = tileMax.x - 1;
	}


	if (fromY < 0) {
		fromY = 0;
	}
	else if (fromY >= tileMax.y) {
		fromY = tileMax.y - 1;
	}
	if (toY < 0) {
		toY = 0;
	}
	else if (toY >= tileMax.y) {
		toY = tileMax.y - 1;
	}
}

void Tile::updateMiniMapView()
{
	if (miniMapFromX < 0) {
		miniMapFromX = 0;
	}
	else if (miniMapFromX >= tileMax.x) {
		miniMapFromX = tileMax.x - 1;
	}
	if (miniMapToX < 0) {
		miniMapToX = 0;
	}
	else if (miniMapToX >= tileMax.x) {
		miniMapToX = tileMax.x - 1;
	}


	if (miniMapFromY < 0) {
		miniMapFromY = 0;
	}
	else if (miniMapFromY >= tileMax.y) {
		miniMapFromY = tileMax.y - 1;
	}
	if (miniMapToY < 0) {
		miniMapToY = 0;
	}
	else if (miniMapToY >= tileMax.y) {
		miniMapToY = tileMax.y - 1;
	}
}

void Tile::update()
{
	this->updateTileView();
	this->updateMiniMapView();
}
void Tile::renderMiniMap(sf::RenderTarget & target, sf::View &view)
{
	//std::cout << "Rendering miniMapFromX: " << this->miniMapFromX << ", miniMapFromY: " << this->miniMapFromY << std::endl;
	//std::cout << "Rendering miniMapToX: " << this->miniMapToX << ", miniMapToY: " << this->miniMapToY << std::endl;
	
	for (int x = 0; x < 34; x++) {
		for (int y = 0; y <  29; y++) {
			if (map[x][y].x != -1 && map[x][y].y != -1) {
				miniMapTile.setPosition((target.getView().getCenter().x + target.getView().getCenter().x - 205) + x * 6, (target.getView().getCenter().y + target.getView().getCenter().y - 175) + y * 6);
				miniMapTile.setTextureRect(sf::IntRect(map[x][y].x * 200, map[x][y].y * 200, 200, 200));
				miniMapTile.setScale(0.04f, 0.04f);
				target.draw(miniMapTile);
			}
		}
	}
}

void Tile::render(sf::RenderTarget &target)
{
	//std::cout << "Rendering FromX: " << this->fromX << ", FromY: " << this->fromY << std::endl;
	//std::cout << "Rendering ToX: " << this->toX << ", ToY: " << this->toY << std::endl;
	//for (int x = fromX; x < toX; x++) {
	//	for (int y = fromY; y < toY; y++) {
	//		target.draw(tiles[x][y]);
	//	}
	//}

	for (int x = fromX; x < toX; x++) {
		for (int y = fromY; y < toY; y++) {
			if (map[x][y].x != -1 && map[x][y].y != -1) {
				tile.setPosition(x * 200, y * 200);
				tile.setTextureRect(sf::IntRect(map[x][y].x * 200, map[x][y].y * 200, 200, 200));
				target.draw(tile);
			}
		}
	}
}
