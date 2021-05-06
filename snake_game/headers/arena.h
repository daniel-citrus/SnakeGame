/*
 * arena.h
 *
 *  Created on: May 5, 2021
 *      Author: dcalvo
 */

#ifndef arena_H_
#define arena_H_

#include "../headers/snake.h"

#define height 20
#define width 20

char Arena[height][width];

void create_arena();			// Initializes the arena by placing borders and empty spaces, this can also be used to clear the arena
void display_arena();			// Outputs the arena
void update_arena(snake *s);	// Draws the snake into the arena

#endif /* arena_H_ */
