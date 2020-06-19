
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "GameEngine/Game/MainGame.h"

	/* 
	// ------------------------- BUG FIXES ------------------------- //

		- Tower textures reset when placing new towers
		- Bullet textures reset when placing new towers
		- Since changing tower class, GUI now doesn't display tower upgrades menu - needs fixing
		- Fix enemy class to not have first enemy in wave always be demon
		- Fix enemy class path movement bug
		- Fix menu system overlapping with eachother
		- Change window resolution to smaller than the window (Fix the window to be top left not bottom left)
		
	// ------------------------- BUG FIXES ------------------------- //



	// ------------------------- NEXT GOALS ------------------------- //

		- We have a tripple for loop in structInv which results in lower performance
		- When reading in the map tiles, have a line which has the enemy goal points
		- Add multiple textures to the enemies class, to have multiple elements
		- Add multiple textures to the tower class
		- Make bullets fire from towers only when an enemy is in range
		- Implement each tower having it's own upgrade paths
		- Implement different elemental towers having different upgrades
		- Remove mana once purchasing upgrade (if you have enough mana)
		- Impelement mouse handler for upgrade tower gui (purchase upgrades)
		- Change mouse cursor on grabbing and placing tower
		- Implement level select menu
		- Create Area Of Effect(AOE) animation / attack for the support towers
		- Implement effect for regen tower adding lives to the character after the end of each cooldown (incressing lives once leveled up and or decreasing cooldowns)
		- Implement effect for mana amplifier adding mana per cooldown (incressing mana once leveled up and or decreasing cooldowns)
		- Implement elemental amplifier amplifying attack speed, base damage and range to towers in range of it
		- Remove elemental overclocker tower and onservatory tower from tower list
		- Add 2 new pathway attacks (slow effect & damage on contact) Make them cheaper and remove on certain amount of contacts with enemies (if 15 enemies hit it, destroy it)

	// ------------------------- NEXT GOALS ------------------------- //



	// ------------------------- AFTER GOALS ------------------------- //

		- Nerf the towers to have 3 second time delay and fix all towers having between 0.1-2.9 second attack speed
		- Water tiles need to be ammeneded in the tile class, so that water tiles are unplacable
		- Remove Level string on GUI, ammend GUI to be collapsable
		- Make it so that only water towers can be placed on water tiles
		- When level is switched, change health and mana back to original value
		- Create 10 Unique maps, each with a path spanning from beginning to end
		- Implement different path following dependant on the map
		- Implement audio effects on tower shooting
		- Implement audio effects on enemy dying
		- Implement audio effect on pausing game
		- Implement audio effect on starting round
		- Implement audio effect on winning round
		- Implement audio effect on round loss
		- Implement spatialized 3D audio
		- Implement background music
		- Implement switching of background music in settings menu

	// ------------------------- AFTER GOALS ------------------------- //



	// ------------------------- FUTURE GOALS ------------------------- //

		- Implement multithreading into the game
		- Implement a bloom shader into the game & set it on and off via key press
		- Have all assets created by the asset manager
		- Animate tower firing, bullet animation, tower rotating to follow enemy
		- Animate enemy movement & enemy death
		- Add particle effects or shaders to tower bullets
		- Add shader to tilemap to give added detail
		- Implement BasicAnimation class to add animation effects to enemies / ui items / etc
		- Implement Data-Driven Save/Load game system
		- Add towers to mini map
		- Add enemies to mini-map
		- Implement Level Select Menu
		- Implement Game Success Menu
		- Implement Game Failure Menu
		- Implement in-game currency to purchase new towers

	// ------------------------- FUTURE GOALS ------------------------- //
*/

int main()
{
	srand(time(0));
	MainGame game;

	while (game.running()) {
		game.run();		//Run the game
	}

	return 0;
}