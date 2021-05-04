/*
 * snake.c
 *
 *  Created on: Apr 20, 2021
 *      Author: dcalvo
 */

#include "headers/snake.h"
/*
int main(void)
{
	snake *s = newSnake(0, 1);
	displaySnake(s);
	growSnake(s, 1, 2);
	displaySnake(s);
	growSnake(s, 2, 3);
	displaySnake(s);
	destroySnake(&s);
	displaySnake(s);
}
*/
snake *newSnake(int x, int y)
{
	snake *s = malloc(sizeof(snake));

	s->head = newNode(x, y);
	s->tail = s->head;
	s->speed = 1;
	s->snakeLength = 1; 				// Start at length 1

	return s;
}



/*
void changeDirections(snake *s) // Find a way to retrieve real time user input
{

}
*/


/*
 * For testing
 */
void displaySnake(snake *s)
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

/*
 * Free all of the pieces of given snake
 */
void destroySnake(snake **s)
{
	destroyLinkedList(&((*s)->head));
	(*s)->tail = NULL;

	free(*s);
	*s = NULL;
}

/*
 * Give snake a new body piece at location (x, y)
 */
void growSnake(snake *s, int x, int y)
{
	addLast(&(s->tail), x, y);
	s->snakeLength += 1;
	s->tail = s->tail->next;
}

/*
 * Increase snake speed by 1
 */
void snakeSpeed(snake *s)
{
	s->speed += 1;
}

/*
 * Update the snake's entire body after each game tick. Dependent on the snake's
 * current head direction.
 */
void updateSnakeBody(snake *s)
{
	// Start from tail
	// last = 2nd to last
	// 2nd to last = 3rd to last
	//
}
