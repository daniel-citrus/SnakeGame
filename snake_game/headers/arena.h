/*
 * arena.h
 *
 *  Created on: May 5, 2021
 *      Author: dcalvo
 */

#ifndef arena_H_
#define arena_H_

#include "snake.h"

#define height 50
#define width 100

char Arena[height][width];

void create_arena();
void display_arena();
void update_arena(snake *s);

#endif /* arena_H_ */
