/*
 * arena.c
 *
 *  Created on: May 5, 2021
 *      Author: dcalvo
 */

#include "headers/arena.h"
#include "headers/user_input.h"

/*
 * Generate the arena borders
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
	}
}

