
#include <iostream>
#include "GameEngine/MainWindow.h"
const float& HEIGHT = 1080, WIDTH = 1920;
int main()
{
	// Create Tile Lists (Sand, water, dirt, grass etc)
	// Make a vector list of each tile
	// create procedural generated map
	// Create a base only on a land tile, add boolean value for ifland 
	// base will span 1 tile


	//Initializing random seed
	//srand(static_cast<unsigned>(time(0)));

	//Initialize game object
	MainWindow win;

	while (win.running()) {
		//Run the game
		win.run();
	}

	return 0;
}