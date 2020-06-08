
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "GameEngine/MainGame.h"

	/* 
	TODO NEXT:

	// ------- NEXT GOALS ------- //
	- Implement Tower Stats Box on GUI
	- Water tiles need to be ammeneded in the tile class, so that water tiles are unplacable
	- Implement Enemy Health
	- Implement enemy health bar that follows the enemy

	// ------- FUTURE GOALS ------- //

	- Remove Level string on GUI, ammend GUI to be collapsable
	- Create 10 Unique maps, each with a path spanning from beginning to end
	- Implement different path following dependant on the map
	- Make it so that only water towers can be placed on water tiles
	- Fix view going outside the bounds of the map
	- Fix menu system overlapping with eachother
	- When level is switched, change health and mana back to original value

	// ------- DISTANT GOALS ------- //
	- Implement tower firing (possibly through bullet class)
	- Implement tower bullet erasing once out of tower range
	- Implement tower bullet following enemy until deletion or collision
	- Implement enemy health reducing if bullet collides with enemy
	- Implement enemy dying / erasing once enemy health is 0
	- Implement multithreading into the game
	- Implement a bloom shader into the game & set it on and off via key press

	// ------- TO DO ONCE IMPLEMENTED ALL NEXT GOALS ------- //
	- Go through existing code, and implement inheritance where possible
	- Clean code up 

*/

int main()
{
	srand(time(0));
	MainGame game;

	while (game.running()) {
		//Run the game
		game.run();
	}

	return 0;
}