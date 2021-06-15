/*
 * arena.c
 *
 *  Created on: May 5, 2021
 *      Author: dcalvo
 * Description: Defines the game arena. Populates the arena with borders
 *              and draws the snake as theg ame progresses.
 */

#include "../headers/arena.h"

/*
 * Generates the arena borders.
 * This can also serve as an area clear
 */
void create_arena(void)
{
    // Fill borders, coordinates (i, j)
    for (int i = 0; i < A_HEIGHT; i++)
    {
        for (int j = 0; j < A_WIDTH; j++)
        {
            if (i == 0 || i == (A_HEIGHT - 1))
            {
                Arena[i][j] = '-';
            }
            else if (j == 0 || j == (A_WIDTH - 1))
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
void display_arena(void)
{
    if (Arena == NULL)
    {
        return;
    }

    for (int i = 0; i < A_HEIGHT; i++)
    {
        for (int j = 0; j < A_WIDTH; j++)
        {
            printw("%c", Arena[i][j]);
        }
        printw("\n");
    }
}

/*
 * Draw the snake in the arena
 */
void update_arena(snake *s, apple *a)
{
    if (s == NULL)
    {
        return;
    }

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
    if (a != NULL)
    {
        Arena[(int)a->x][(int)a->y] = '@';
    }
}

