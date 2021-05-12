/*
 * arena.c
 *
 *  Created on: May 5, 2021
 *      Author: dcalvo
 */

#include "../headers/arena.h"
#include "../headers/user_input.h"
#include <ncurses.h>

int main(void)
{
	initscr();
	refresh();
	create_arena();

	snake *s = newSnake(11, 6,'r');
	growSnake(s, 11,5);
	growSnake(s, 11,4);
	growSnake(s, 11,3);

	int x, y, input;
	int *d = &(s->direction);
	char c;

	do
	{

		x = s->head->x;
		y = s->head->y;

		c = getch();
		input = (int) c;

		if (input == -1)
		{
			input = s->direction;
		}

		switch(input)
		{
			case KEY_UP:
				updateSnakeBody(s->head, x - 1, y);
				*d = KEY_UP;
				break;

			case KEY_DOWN:
				updateSnakeBody(s->head, x + 1, y);
				*d = KEY_DOWN;
				break;

			case KEY_LEFT:
				updateSnakeBody(s->head, x, y - 1);
				*d = KEY_LEFT;
				break;

			case KEY_RIGHT:
				updateSnakeBody(s->head, x , y + 1);
				*d = KEY_RIGHT;
				break;

			case KEY_SPACE:
				break;
		}

		update_arena(s);
		display_arena();
		system("Pause");
		create_arena();
	}while(input != KEY_SPACE);
}

/*
 * Generates the arena borders.
 * This can also serve as an area clear
 */
void create_arena()
{
	// Fill borders, coordinates (i, j)
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (i == 0 || i == (height - 1))
			{
				Arena[i][j] = '-';
			}
			else if (j == 0 || j == (width - 1))
			{
				Arena[i][j] = '|';
			}
			else
			{
				Arena[i][j] = ' ';
			}
		}
	}
}

/*
 * Display the arena array
 */
void display_arena()
{
	if (Arena == NULL)
	{
		return;
	}
	// Fill borders, coordinates (i, j)
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			printf("%c", Arena[i][j]);
		}
		printf("\n");
	}
}

/*
 * Draw the snake in the arena
 */
void update_arena(snake *s)
{
	node *p = s->head;

	int x;
	int y;

	while (p != NULL)
	{
		x = p->x;
		y = p->y;

		Arena[x][y] = '*';

		p = p->next;
	}
}

