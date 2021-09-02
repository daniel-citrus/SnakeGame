/*
 * game_loop.h
 *
 *  Created on: Apr 30, 2021
 *      Author: dcalvo
 */

#ifndef GAME_LOOP_H_
#define GAME_LOOP_H_

#include <curses.h>
#include <windows.h>
#include "snake.h"

#define DELAY 60

typedef unsigned long DWORD, *PDWORD, *LPDWORD;

apple *a;

int screen_row, screen_col;             // Stores dimensions of stdscr

void display_game(void);                // Output the frame of the current game state
void initialize_game(void);             // Call initialization functions
void pause_game(void);                  // Pause game and wait for user input
void update_game(int input, snake *s, apple *a);  // Update game state

#endif /* GAME_LOOP_H_ */
