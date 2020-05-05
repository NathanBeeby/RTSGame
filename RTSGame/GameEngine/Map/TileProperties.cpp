#include "TileProperties.h"

void TileProperties::initVariables()
{
	this->tileNumber = 0;
	this->tileMax.x = 100;
	this->tileMax.y = 100;
}

TileProperties::TileProperties()
{
	this->initVariables();
}

TileProperties::~TileProperties()
{
}

void TileProperties::update()
{
}

const int & TileProperties::tileNum(int maxTexture) const
{
	return this->tileNumber;
}
