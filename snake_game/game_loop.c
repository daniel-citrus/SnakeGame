/*
 * game_loop.c
 *
 *  Created on: Apr 30, 2021
 *      Author: dcalvo
 */

#include "headers/general.h"
#include "headers/game_loop.h"

/*
*    Title: Constant Game Speed with Maximum FPS
*    Author: Koen Witters
*    Date: 4/30/2021
*    Code version: N/A
*    Availability: https://dewitters.com/dewitters-gameloop/
*/
int main(void)
{
	const int TICKS_PER_SECOND = 50;
	const int SKIP_TICKS = 1000 / TICKS_PER_SECOND;
	const int MAX_FRAMESKIP = 10;

	DWORD next_game_tick = GetTickCount();
	int loops;

	bool game_is_running = true;

	while(game_is_running)
	{

		loops = 0;

		while(GetTickCount() > next_game_tick && loops < MAX_FRAMESKIP)
		{

			//update_game();

			next_game_tick += SKIP_TICKS;
			loops++;
		}

		//display_game();
		printf("0000000000000000000000000000000000000000\n");
	}

}
