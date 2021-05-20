/*
 * game_loop.c
 *
 *  Created on: Apr 30, 2021
 *      Author: dcalvo
 */

#include "../headers/general.h"
#include "../headers/game_loop.h"
#include "../headers/user_input.h"
#include "../headers/arena.h"

int main(void)
{
    initscr();
    raw();
    timeout(150);
    noecho();
    keypad( stdscr, TRUE);

    create_arena();

    snake *s = newSnake(11, 6, KEY_RIGHT);
    grow_snake(s, 11,5);
    grow_snake(s, 11,4);
    grow_snake(s, 11,3);

    int input;

    do
    {
        input = getch();
        clear();
        if (input != ERR)
        {
            change_snake_direction(s, input);
        }
        else
        {
            snake_forward(s);
        }

        update_arena(s);
        display_arena();
        create_arena();
    }while(input != KEY_SPACE);

    destroy_snake(&s);
    endwin();

    return 0;
}
