
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "GameEngine/MainGame.h"

	/* 
	TODO NEXT:

	// ------- NEXT GOALS ------- //
	++ MAJOR ++
	- Fix enemy class to not have first enemy in wave always be demon
	- Fix enemy class path movement bug
	- Erase bullet and minus health from enemy when hit.
	- When reading in the map tiles, have a line which has the enemy goal points
	- Add multiple textures to the enemies class, to have multiple elements
	++ MAJOR ++



	// ------- AFTER GOALS ------- //
	- Fix first bullet in array always being fire bullet
	- Nerf the towers to have 3 second time delay and fix all towers having between 0.1-2.9 second attack speed
	- Make bullets fire from towers only when an enemy is in range
	- Implement each tower having it's own upgrade paths
	- Implement different elemental towers having different upgrades
	- Impelement mouse handler for upgrade tower gui (purchase upgrades)
	- Remove mana once purchasing upgrade (if you have enough mana)
	- Amend new view constraints as tower menu is now hidable
	- Water tiles need to be ammeneded in the tile class, so that water tiles are unplacable
	- Change mouse cursor on grabbing and placing tower
	- Fix tower class to be like enemy and bullet class

	// ------- FUTURE GOALS ------- //

	- Remove Level string on GUI, ammend GUI to be collapsable
	- Create 10 Unique maps, each with a path spanning from beginning to end
	- Implement different path following dependant on the map
	- Make it so that only water towers can be placed on water tiles
	- Fix menu system overlapping with eachother
	- When level is switched, change health and mana back to original value

	// ------- DISTANT GOALS ------- //
	- Implement tower bullet following enemy until deletion or collision
	- Implement enemy health reducing if bullet collides with enemy
	- Implement multithreading into the game
	- Implement a bloom shader into the game & set it on and off via key press
	- Have all assets created by the asset manager
	- Animate tower firing, bullet animation, tower rotating to follow enemy
	- Animate enemy movement & enemy death
	- Add particle effects or shaders to tower bullets
	- Add shader to tilemap to give added detail


	// ------- TO DO ONCE IMPLEMENTED ALL NEXT GOALS ------- //
	- Implement BasicAnimation class to add animation effects to enemies / ui items / etc
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