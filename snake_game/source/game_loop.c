/*
 * game_loop.c
 *
 *  Created on: Apr 30, 2021
 *      Author: dcalvo
 */

#include "../headers/game_loop.h"
#include "../headers/arena.h"
#include "../headers/user_input.h"

int main(void)
{
    int input;

    initialize_game();
    create_arena();

    snake *s = new_snake(screen_row / 2, screen_col / 2, KEY_RIGHT);

    while(true)
    {
        input = getch();

        if (input == ESC)
        {
            pause_game();
        }

        update_game(input, s);

        display_game();
    }
}

/*
 *  Update the screen
 */
void display_game(void)
{
    clear();
    display_arena();
    refresh();
}

/*
 *  Call initialization functions, mainly for the curses library
 */
void initialize_game(void)
{
    initscr();
    raw();
    noecho();
    keypad(stdscr, TRUE);
    timeout(DELAY);

    // Get terminal dimensions
    getmaxyx(stdscr, screen_row, screen_col);

}

/*
 * Pause the game
 *
 * This functions will prevent the curses timeout from activating for
 * indefinite pause time. A message will pop-up on the center of the
 * terminal. The game will resume once any key is pressed.
 */
void pause_game(void)
{
    timeout(-1);

    char *message1 = "PAUSED";
    char *message2 = "Press any button to continue";
    mvwprintw(stdscr, screen_row / 2, (screen_col - strlen(message1)) / 2, "%s\n", message1);
    mvwprintw(stdscr, (screen_row / 2) + 1, (screen_col - strlen(message2)) / 2, "%s\n", message2);
    refresh();

    getch();
    timeout(DELAY);

    return;
}

/*
 *  Receive user input then update the snake state and arena state
 */
void update_game(int input, snake *s)
{
    create_arena();

    if (input == ERR)
    {
        snake_forward(s);
    }
    else if (!same_direction(s, input))
    {
        change_snake_direction(s, input);
    }

    update_arena(s);
}


