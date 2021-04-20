/*
 * snake.c
 *
 *  Created on: Apr 20, 2021
 *      Author: dcalvo
 */

#include "snake.h";

snake *newSnake(int x, int y)
{
	snake *s = malloc(sizeof(snake));
	s->head = newNode(x, y);
	s->tail = s->head;  				// A new snake only has one body "piece"
	s->speed = 1;						// 1 for now
	s->snakeLength = 1; 				// Always start at length 1
	return s;
}

//void changeDirections() // Find a way to retrieve real time user input
//void displaySnake() // Probably do not need this, I might let the "arena" do all of the displaying.

void growSnake(snake *s)
{
	addLast()
}

void snakeSpeed(snake *s)
{
	s->speed += 1;
}

//void updateSnakeBody() // Updates the snake's entire body after each game tick.
