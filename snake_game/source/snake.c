/*
 * snake.c
 *
 *  Created on: Apr 20, 2021
 *      Author: dcalvo
 */
#include "../headers/snake.h"

snake *new_snake(int x, int y, char d)
{
    snake *s = malloc(sizeof(snake));

    s->head = new_node(x, y);
    s->tail = s->head;
    s->snakeLength = 1;
    s->direction = d;

    return s;
}

/*
 * Check if input is in the same direction as the snake's direction.
 * This function prevents the snake from going faster if directional button
 * is held.
 */
bool same_direction(snake *s, int input)
{
    if (s->direction == input)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*
 * Returns true if snake head is on the same coordinates as the apple
 */
bool snake_on_apple(snake *s, apple *a)
{
    int snakeX = s->head->x;
    int snakeY = s->head->y;

    int appleX = a->x;
    int appleY = a->y;

    if (snakeX == appleX && snakeY == appleY)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*
 * Update the snake's direction and increment the snake's individual body coordinates
 * according to the direction. This function also checks for invalid inputs (ie. User input is DOWN
 * while snake is going UP) so they can be ignored.
 *
 * @param d: The new direction for the snake
 */
void change_snake_direction(snake *s, int d)
{
    int x, y;
    int *snakeDir = &(s->direction);

    x = s->head->x;
    y = s->head->y;


    switch(d)
    {
        case KEY_UP:
            if (*snakeDir == KEY_DOWN)
            {
                return;
            }
            else
            {
                update_snake(s->head, x - 1, y);
                *snakeDir = KEY_UP;
                break;
            }

        case KEY_DOWN:
            if (*snakeDir == KEY_UP)
            {
                return;
            }
            else
            {
                update_snake(s->head, x + 1, y);
                *snakeDir = KEY_DOWN;
                break;
            }

        case KEY_LEFT:
            if (*snakeDir == KEY_RIGHT)
            {
                return;
            }
            else
            {
                update_snake(s->head, x, y - 1);
                *snakeDir = KEY_LEFT;
                break;
            }

        case KEY_RIGHT:
            if (*snakeDir == KEY_LEFT)
            {
                return;
            }
            else
            {
                update_snake(s->head, x , y + 1);
                *snakeDir = KEY_RIGHT;
                break;
            }
    }
}

/*
 * Free all of the pieces of given snake
 */
void destroy_snake(snake **s)
{
    destroy_linked_list(&((*s)->head));
    (*s)->tail = NULL;

    free(*s);
    *s = NULL;
}

/*
 * Give snake a new body piece on top of its tail.
 * This will be corrected once the snake moves forward
 */
void grow_snake(snake *s)
{
    add_last(&(s->tail), s->tail->x, s->tail->y);
    s->snakeLength += 1;
    s->tail = s->tail->next;
}

/*
 * Update the snake's entire body by moving the head forward to coordinate [x][y]
 * followed by updating the rest of the body.
 */
void update_snake(node *s, int x, int y)
{
    if (s == NULL)
    {
        return;
    }

    update_snake(s->next, s->x, s->y);

    s->x = x;
    s->y = y;
}

/*
 * Increment the snake's position by 1 in it's current direction
 */
void snake_forward(snake *s)
{
    {
        int direction = s->direction;

        change_snake_direction(s, direction);
    }
}
