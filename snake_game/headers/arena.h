/*
 * arena.h
 *
 *  Created on: May 5, 2021
 *      Author: dcalvo
 */

#ifndef arena_H_
#define arena_H_

#include "snake.h"
#include "apple.h"

#define A_HEIGHT 30
#define A_WIDTH 118

char Arena[A_HEIGHT][A_WIDTH];

void create_arena(void);                // Initializes the arena by placing borders and empty spaces, this can also be used to clear the arena
void display_arena(void);               // Outputs the arena
void update_arena(snake *s);  // Update the arena by adding the snake coordinates into the arena arrays

#endif /* arena_H_ */
