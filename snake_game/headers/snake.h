/*
 * snake.h
 *
 *  Created on: Apr 19, 2021
 *      Author: dcalvo
 */

#ifndef SNAKE_H_
#define SNAKE_H_

#include <curses.h>
#include <stdbool.h>
#include "apple.h"
#include "linked_list.h"

typedef struct snake snake;

struct snake
{
    node *head;
    node *tail;
    int snakeLength;       // Not sure if I need this (maybe for score)
    int direction;         // Track the snake head's current direction
};

snake *new_snake(int x, int y, char d);             // Generate new snake at given coordinate

bool same_direction(snake *s, int input);           // Returns true if the input provided is in the same direction as the snake's current direction
bool snake_on_apple(snake *s, apple *a);            // Returns true if snake head is on top of an apple
//bool snake_on_self(snake *s);                       // Returns true if the snake runs into itself

void change_snake_direction(snake* s, int d);       // Receive user input to change snake direction
void destroy_snake(snake **s);                      // Free all of the snake pieces
void grow_snake(snake *s);                          // Grow snake by 1
void update_snake(node *s, int x, int y);           // Updates the snake body
void snake_forward(snake *s);                       // Move snake head forward depending on current direction

#endif /* SNAKE_H_ */
