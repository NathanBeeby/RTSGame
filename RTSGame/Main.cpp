
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "GameEngine/MainGame.h"

	/* 
	TODO NEXT:
	- Fix the selection of tower bug where 2 towers or more get selected at once.
	- Fix enemy wave bug where enemies get stuck on path.

	- Implement different tower ranges depending on the tower and change the tower select radius based on tower clicked.


	- Create 10 Unique maps, each with a path spanning from beginning to end
	- When wave ends all enemies in the wave are to be destroyed (when vector reaches 0)
	- Make it so that only water towers can be placed on water tiles
	- Make pathway tiles unplacable positions for towers
	- Fix view going outside the bounds of the map
	- Fix menu system overlapping with eachother
	- Clean up entity system / Tower creation system / Enemy Creation System
	- When level is switched, change health and mana back to original value
	- Set up Elemental enemy classes, adding in the textures, the push back for the arrays, the different types of enemies in that element, etc.
	- Get an enemy moving from the starting point to the right


	- Once Enemy path movement & destruction has finished, begin implementing multithreading into the game
	- Implement a bloom shader into the game & set it on and off via key press
	- Implement state where if lives are less or equal to 0, game over
	- Implement state where if wave 30 complete, level success
	- Implement collapsable tower menu
	- Implement Start round button

	----------------------------------- HOW WE COULD MAKE WAVE SYSTEM -----------------------------------
	- Create a play button near the mini map or near pause button
	- When Pressed, begin count of 30 seconds. 
	- Have a integer variable for amount of enemies in wave. Increase this per wave.
	- Divide the amount of enemies by the time period, push back another enemy each timeframe

	By doing this, every so often a new enemy will come out of spawn, with their unique speed and health, the wave start button
	will be pressed, the enemies will come out one by one until 30 seconds has passed, once the 30 seconds has passed, the second wave will
	be ready to go. 
	----------------------------------- HOW WE COULD MAKE WAVE SYSTEM -----------------------------------

	------------------------------------ HOW WE COULD MAKE WAYPOINTS ------------------------------------
	The waypoints can be calculated within the tile class, where each corner tile is considered a waypoint
	The goal waypoint will be the next waypoint in the array of integers
	When you've reached the last corner waypoint, make the next waypoint off the map within the X position
	The enemy will walk off the map to the right, when the enemy is past the last map tile in X position, delete the enemy and remove a life
	------------------------------------ HOW WE COULD MAKE WAYPOINTS ------------------------------------
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