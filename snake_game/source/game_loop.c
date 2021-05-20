/*
 * game_loop.c
 *
 *  Created on: Apr 30, 2021
 *      Author: dcalvo
 */

#include "../headers/general.h"
#include "../headers/game_loop.h"
#include "../headers/arena.h"
#include "../headers/user_input.h"
#include <curses.h>
/*
int main(void)
{
    initscr();
    raw();
    noecho();
    keypad(stdscr, TRUE);
    timeout(150);

    create_arena();

    snake *s = new_snake(11, 6, KEY_RIGHT);
    grow_snake(s, 11,5);
    grow_snake(s, 11,4);
    grow_snake(s, 11,3);

    int input;

    do
    {
        input = getch();
        clear();

        if (input == ERR)
        {
            snake_forward(s);
        }
        else if (!same_direction(s, input))
        {
            change_snake_direction(s, input);
        }

        update_arena(s);
        display_arena();
        refresh();
        create_arena();
    }while(input != KEY_SPACE);

    destroy_snake(&s);
    endwin();

    return 0;
}
*/

/*
*    Title: Constant Game Speed with Maximum FPS
*    Author: Koen Witters
*    Date: 4/30/2021
*    Code version: N/A
*    Availability: https://dewitters.com/dewitters-gameloop/
*/

int main(void)
{
    const int TICKS_PER_SECOND = 50;
    const int SKIP_TICKS = 1000 / TICKS_PER_SECOND;
    const int MAX_FRAMESKIP = 5;
    DWORD next_game_tick = GetTickCount();
    int loops, input;

    initscr();
    raw();
    noecho();
    keypad(stdscr, TRUE);
    timeout(150);

    create_arena();

    snake *s = new_snake(11, 6, KEY_RIGHT);
    grow_snake(s, 11,5);
    grow_snake(s, 11,4);
    grow_snake(s, 11,3);


    while(true)
    {
        loops = 0;

        while(GetTickCount() > next_game_tick && loops < MAX_FRAMESKIP)
        {
            input = getch();
            clear();

            if (input == ERR)
            {
                snake_forward(s);
            }
            else if (!same_direction(s, input))
            {
                change_snake_direction(s, input);
            }

            update_arena(s);
            next_game_tick += SKIP_TICKS;
            loops++;
        }

        display_arena();
        refresh();
        create_arena();
    }
}
