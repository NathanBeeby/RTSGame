#include "Tile.h"

void Tile::initVariables()
{
	this->tileMax.x = 35;
	this->tileMax.y = 30;
	this->miniMapOffsetX = 0;
	this->miniMapOffsetY = 0;
	this->mapNo = 0;
	this->mapMax = 10;
	this->mapFile.resize(10);
	this->tileSize = 200;
}

void Tile::initTextures()
{
	this->mapFile[0] = "../Assets/Map_Assets/Map0.txt";
	this->mapFile[1] = "../Assets/Map_Assets/Map1.txt";
	this->mapFile[2] = "../Assets/Map_Assets/Map2.txt";
	this->mapFile[3] = "../Assets/Map_Assets/Map3.txt";
	this->mapFile[4] = "../Assets/Map_Assets/Map4.txt";
	this->mapFile[5] = "../Assets/Map_Assets/Map5.txt";
	this->mapFile[6] = "../Assets/Map_Assets/Map6.txt";
	this->mapFile[7] = "../Assets/Map_Assets/Map7.txt";
	this->mapFile[8] = "../Assets/Map_Assets/Map8.txt";
	this->mapFile[9] = "../Assets/Map_Assets/Map9.txt";
}

void Tile::initWaypoints(int mapNum)
{
	if (mapNum == 0) {
		/*waypoint.AddWayPoint(sf::Vector2i(0, (tileSize * 14) + 20));
		waypoint.AddWayPoint(sf::Vector2i((tileSize * 6) + 20, (tileSize * 14) + 20));
		waypoint.AddWayPoint(sf::Vector2i((tileSize * 6) + 20, (tileSize * 5) + 20));
		waypoint.AddWayPoint(sf::Vector2i((tileSize * 11) + 20, (tileSize * 5) + 20));
		waypoint.AddWayPoint(sf::Vector2i((tileSize * 11) + 20, (tileSize * 22) + 20));
		waypoint.AddWayPoint(sf::Vector2i((tileSize * 22) + 20, (tileSize * 22) + 20));
		waypoint.AddWayPoint(sf::Vector2i((tileSize * 22) + 20, (tileSize * 15) + 20));
		waypoint.AddWayPoint(sf::Vector2i((tileSize * 33) + 20, (tileSize * 15) + 20));*/
	}
	else if (mapNum == 1) {

	}
	else if (mapNum == 2) {

	}
	else if (mapNum == 3) {

	}
	else if (mapNum == 4) {

	}
	else if (mapNum == 5) {

	}
	else if (mapNum == 6) {

	}
	else if (mapNum == 7) {

	}
	else if (mapNum == 8) {

	}
	else if (mapNum == 9) {

	}
}

void Tile::initSprite(int mapNum)
{
	//std::ifstream openfile("../Assets/Map_Assets/Map1.txt");
	try{
	std::ifstream openfile(this->mapFile[mapNum]);
	if (openfile.is_open()) {
		std::string tileLocation;
		sf::Vector2i loadCounter = sf::Vector2i(0, 0);
		openfile >> tileLocation;
		tileText.loadFromFile(tileLocation);
		tile.setTexture(tileText);
		miniMapTile.setTexture(tileText);
		while (!openfile.eof()) {
			std::string str;
			openfile >> str;
			char x = str[0], y = str[2];
			int xa, ya;
			//if (!isdigit(x) || !isdigit(y)) {
			//	map[loadCounter.x][loadCounter.y] = sf::Vector2i(-1, -1);
			//}
			//else {
				xa = x - '0';
				ya = y - '0';
				if (x == 'a') {
					xa = 10;
				}
				else if (x == 'b') {
					xa = 11;
				}
				else if (x == 'c') {
					xa = 12;
				}
				else if (x == 'd') {
					xa = 13;
				}
				else if (x == 'e') {
					xa = 14;
				}
				if (xa <= 14 || ya <= 5) {
				map[loadCounter.x][loadCounter.y] = sf::Vector2i(xa, ya);
				}

			if (openfile.peek() == '\n') {
				loadCounter.x = 0;
				loadCounter.y++;
			}
			else {
				loadCounter.x++;
			}
			if (xa >= 1 && ya < 5 && xa < 8 || xa == 0 && ya == 5) {
				this->waterTiles.push_back(sf::Vector2i(xa, ya));
			}
			if (xa > 8 && ya < 5 && xa < 14) {
				this->unplacableTiles.push_back(sf::Vector2i(xa, ya));
			}
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
	this->initSprite(0);
	this->initWaypoints(0);
}

Tile::~Tile()
{
}

const int Tile::getMapNo() const
{
	return this->mapNo;
}

const int Tile::getMapMax() const
{
	return this->mapMax;
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

void Tile::updateMap(int mapNum)
{
	// Render the new map dependant on the map number


}

void Tile::nextMap()
{
	if (this->mapNo < mapMax) {
		this->mapNo++;
		std::cout << "NEXT: Map Number: " << mapNo << std::endl;
		this->initSprite(mapNo);
		this->initWaypoints(mapNo);
		this->structInv.deleteAllTowers();
	}
}

void Tile::previousMap()
{
	if (this->mapNo > 0) {
		this->mapNo--;
		std::cout << "PREVIOUS: Map Number: " << mapNo << std::endl;
		this->initSprite(mapNo);
		this->initWaypoints(mapNo);
		this->structInv.deleteAllTowers();
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
