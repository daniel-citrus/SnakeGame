/*
 * user_input.c
 *
 *  Created on: Apr 22, 2021
 *      Author: dcalvo
 */

#include "user_input.h"

int main()
{
    int ch;

    do
    {
        ch = getch();

        switch(ch)
        {
            case ESC:
            	printf("Escape.\n");
                break;
            case KEY_UP:
				printf("Up.\n");
				break;
            case KEY_DOWN:
				printf("Down.\n");
				break;
            case KEY_LEFT:
				printf("Left.\n");
				break;
            case KEY_RIGHT:
				printf("Right.\n");
				break;
            case KEY_SPACE:
				printf("Space.\n");
				break;
        }
    }
    while(ch != KEY_SPACE);

    printf("...\nTerminated.");
}
