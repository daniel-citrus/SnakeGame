/*
 * snake.c
 *
 *  Created on: Apr 20, 2021
 *      Author: dcalvo
 */

#include "../headers/user_input.h"
#include "../headers/snake.h"
#include "../headers/general.h"

snake *newSnake(int x, int y, char d)
{
    snake *s = malloc(sizeof(snake));

    s->head = newNode(x, y);
    s->tail = s->head;
    s->snakeLength = 1;
    s->direction = d;

    return s;
}

void change_snake_direction(snake *s, int d)
{
    int x, y;
    int *snakeDir = &(s->direction);

    x = s->head->x;
    y = s->head->y;

    switch(d)
    {
        case KEY_UP:
            update_snake(s->head, x - 1, y);
            *snakeDir = KEY_UP;
            break;

        case KEY_DOWN:
            update_snake(s->head, x + 1, y);
            *snakeDir = KEY_DOWN;
            break;

        case KEY_LEFT:
            update_snake(s->head, x, y - 1);
            *snakeDir = KEY_LEFT;
            break;

        case KEY_RIGHT:
            update_snake(s->head, x , y + 1);
            *snakeDir = KEY_RIGHT;
            break;
    }
}

/*
 * Free all of the pieces of given snake
 */
void destroy_snake(snake **s)
{
    destroyLinkedList(&((*s)->head));
    (*s)->tail = NULL;

    free(*s);
    *s = NULL;
}

/*
 * Give snake a new body piece at location (x, y)
 */
void grow_snake(snake *s, int x, int y)
{
    addLast(&(s->tail), x, y);
    s->snakeLength += 1;
    s->tail = s->tail->next;
}

/*
 * Update the snake's entire body, starting with the head node to the tail.
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
