#pragma once
#include "NPC.h"
#include "../../GameAssets/AssetManager.h"
class Enemy : public NPC
{
private:
	sf::Sprite sprite;
	AssetManager manager;
public:
	Enemy();
	virtual ~Enemy();
};

