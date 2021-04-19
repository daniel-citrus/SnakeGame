/*
 * snake.h
 *
 *  Created on: Apr 19, 2021
 *      Author: dcalvo
 */

#ifndef SNAKE_H_
#define SNAKE_H_
#include <linked_list.h>
#include <stdio.h>

typedef struct snake snake;

struct snake
{
	node *head = NULL;
	node *tail = NULL;
	int speed = 0; // Need to configure according to how fast the game window updates.
	int snakeLength = 0; // Not sure if I need this
};

// void changeDirections(); // Find a way to retrieve real time user input
void displaySnake();
void growSnake(int x); // Ideally, the snake should grow by one, but for future features, I will make it possible to grow the snake even more.
void snakeSpeed(int x);
void updateSnakeBody(); // Most likely used by changeDirections once user updates snake direction

#endif /* SNAKE_H_ */
