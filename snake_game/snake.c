/*
 * snake.c
 *
 *  Created on: Apr 20, 2021
 *      Author: dcalvo
 */
#include <stdlib.h>
#include "snake.h"

int main(void)
{
	snake *s = newSnake(0, 1);
	displaySnake(s);
	growSnake(s, 1, 2);
	displaySnake(s);
	growSnake(s, 2, 3);
	displaySnake(s);
}

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

void displaySnake(snake *s) // For testing
{
	if (s == NULL)
	{
		printf("Snake does not exist.\n");

		return;
	}

	readLinkedList(s->head);
	printf("Head: (%d, %d)\n", s->head->x, s->head->y);
	printf("Tail: (%d, %d)\n", s->tail->x, s->tail->y);
	printf("\n\n");
}

void growSnake(snake *s, int x, int y)
{
	addLast(&(s->tail), x, y);
	s->snakeLength += 1;
	s->tail = s->tail->next;
}

void snakeSpeed(snake *s)
{
	s->speed += 1;
}

//void updateSnakeBody() // Updates the snake's entire body after each game tick.
