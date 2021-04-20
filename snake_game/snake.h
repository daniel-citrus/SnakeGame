/*
 * snake.h
 *
 *  Created on: Apr 19, 2021
 *      Author: dcalvo
 */

#ifndef SNAKE_H_
#define SNAKE_H_
#include "linked_list.h"
#include <stdio.h>

typedef struct snake snake;

struct snake
{
	node *head;
	node *tail;
	int speed; // Need to configure according to how fast the game window updates.
	int snakeLength; // Not sure if I need this
};

snake *newSnake(int x, int y); // Generate new snake at coord

// void changeDirections(); // Find a way to retrieve real time user input
void displaySnake(); // Probably do not need this, I might let the "arena" do all of the displaying.
void growSnake(snake *s, int x, int y); // Grow snake by 1
void snakeSpeed(snake *s);
void updateSnakeBody(); // Updates the snake's entire body after each game tick.

#endif /* SNAKE_H_ */
