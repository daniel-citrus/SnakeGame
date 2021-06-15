/*
 * apple.c
 *
 *  Created on: Jun 7, 2021
 *      Author: Daniel
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

    int xCap = A_WIDTH - 2;
    int yCap = A_HEIGHT - 2;


    a->x = rand() % xCap;
    a->y = rand() % yCap;

    // Generate new coordinates if apple collides with anything
    while (collides(a)) {
        a->x = rand() % xCap;
        a->y = rand() % yCap;
    }

    return a;
}

/*
 * Check if current coordinates of the apple is colliding with anything in the arena.
 */

bool collides(apple *a)
{
    if (Arena[a->x][a->y] != ' ')
    {
        return false;
    }
    else
    {
        return true;
    }
}

/*
 * Destroy apple
 */
void destroy_apple(apple *a)
{
    free(a);
}
