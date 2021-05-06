/*
 * arena.c
 *
 *  Created on: May 5, 2021
 *      Author: dcalvo
 */

#include "../headers/arena.h"
#include "../headers/user_input.h"

int main(void)
{
	create_arena();

	char ch;
	snake *s = newSnake(10,5);
	growSnake(s, 11,5);
	growSnake(s, 11,6);
	growSnake(s, 12,6);
	growSnake(s, 13,6);

	update_arena(s);
	system("cls");
	display_arena();

	int x, y;

	do
	{
		x = s->head->x;
		y = s->head->y;

		ch =  getch();

		switch(ch)
		{
			case KEY_UP:
				updateSnakeBody(s->head, x - 1, y);
				break;
			case KEY_DOWN:
				updateSnakeBody(s->head, x + 1, y);
				break;
			case KEY_LEFT:
				updateSnakeBody(s->head, x, y - 1);
				break;
			case KEY_RIGHT:
				updateSnakeBody(s->head, x , y + 1);
				break;
			case KEY_SPACE:
				break;
		}

		create_arena();
		update_arena(s);
		system("cls");
		display_arena();

	}while(ch != KEY_SPACE);
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

