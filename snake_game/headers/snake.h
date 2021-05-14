/*
 * snake.h
 *
 *  Created on: Apr 19, 2021
 *      Author: dcalvo
 */

#ifndef SNAKE_H_
#define SNAKE_H_

#include "linked_list.h"

typedef struct snake snake;

struct snake
{
	node *head;
	node *tail;
	int speed; 			// Need to configure according to how fast the game window updates.
	int snakeLength; 	// Not sure if I need this (maybe for score)
	int direction; 	// Track the snake head's current direction
};

snake *newSnake(int x, int y, char d); 				// Generate new snake at given coordinate

void changeDirections(void); 					// Receive user input to change snake direction
void displaySnake(void); 						// For testing
void destroySnake(snake **s);				// Free all of the snake pieces
void growSnake(snake *s, int x, int y); 	// Grow snake by 1
void snakeSpeed(snake *s);					// Increase snake speed by s
void updateSnakeBody(node *s, int x, int y); // Updates the snake body

#endif /* SNAKE_H_ */
