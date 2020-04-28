
#include <iostream>
#include "GameEngine/MainGame.h"



int main()
{
	/* 
	- Put view movement within the game class, once in game class, make a check to make sure the view is within the bounds
	of the map (e.g. no black space in view, just map.
	
	- Create a structure or class for tile types / tile properties, so that you can call a specific tile by number and
	add it to the map, this will make using perlin noise for map generation easier.

	- Try to implement perlin noise or another algorithm of drawing procedural generated maps

	- Create art assets for a few bases, add them to the tile list within the view.
	- If the structure icon is left clicked, make the icon follow the cursor within grid space
	- If the structure icon is following the cursor and is right clicked, delete the icon following the cursor
	- Make the Icon transparent when following the cursor
	- If the structure is following the cursor and is clicked on a tile, place said structure on that tile and make the
	structures position that position
	- Once structure placement is possible, add resources on initialization, make it so that to place a tile, you have to
	have enough funds, on placement, remove those funds.
	*/


	// Create a base only on a land tile, add boolean value for ifland 
	// base will span 1 tile

	bool running = true;
	//Initializing random seed
	//srand(static_cast<unsigned>(time(0)));

	//Initialize game object
	MainGame game;

	while (running == true) {
		//Run the game
		game.run();
	}

	return 0;
}