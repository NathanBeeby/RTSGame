
#include <iostream>
#include "GameEngine/MainGame.h"

	/* 

	- Create 10 Unique maps, each with a path spanning from beginning to end
	- Create an enemy class, which extends into several types of enemies, each with different health & abilities
	- Create a wave system, which ends when all enemies in the wave are destroyed (when vector reaches 0)
	- Make it so that only water towers can be placed on water tiles
	- Make pathway tiles unplacable positions for towers
	- Fix view going outside the bounds of the map
	- Fix menu system overlapping with eachother
	- Fix deletion of towers (for some reason tower array size is 0 on delete)
	- Clean up entity system / Tower creation system 
	- When level is switched, change health and mana back to original value

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
	MainGame game;

	while (game.running()) {
		//Run the game
		game.run();
	}

	return 0;
}