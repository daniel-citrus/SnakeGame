/*
 * apple.c
 *
 *  Created on: Jun 7, 2021
 *      Author: Daniel
 *  Description:
 */
#include "../headers/apple.h"
#include "../headers/arena.h"

/*
 * Spawn an apple in random coordinates (within arena borders - 2).
 * Prevents an apple from spawning on the snake.
 */
apple *generate_apple(void)
{
    apple *a = malloc(sizeof(apple));

    srand(time(NULL));

    int xCap = A_HEIGHT - 2;
    int yCap = A_WIDTH - 2;

    int x = rand() % xCap;
    int y = rand() % yCap;
    /*
     * Generate new coordinates until there are no collisions
     * or duplicate coordinates.
     */
    while (collides(x, y) || same_coord(a, x, y)) {
        x = rand() % xCap;
        y = rand() % yCap;
    }

    a->x = x;
    a->y = y;

    return a;
}

/*
 * Check if the arena is populated in the given coordinates.
 */

bool collides(int x, int y)
{
    if (Arena[x][y] == ' ')
    {
        return false;
    }
    else
    {
        return true;
    }
}

/*
 * Check if the new coordinates match the previous coordinates
 */
bool same_coord(apple *a, int x, int y)
{
    if (a == NULL)
    {
        return false;
    }

    if (a->x == x && a->y == y)
    {
        return true;
    }
    else
    {
        return false;
    }
}


/*
 * Destroy apple
 */
void destroy_apple(apple *a)
{
    free(a);
}
