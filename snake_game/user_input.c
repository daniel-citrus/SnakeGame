/*
 * user_input.c
 *
 *  Created on: Apr 22, 2021
 *      Author: dcalvo
 */


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define ESC 27
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_SPACE 32

int main()
{
    int ch;

    do
    {
        ch = getch();

        switch(ch)
        {
            case ESC:
                // your logic goes here
            	printf("Escape.\n");
                break;
            case KEY_UP:
				// your logic goes here
				printf("Up.\n");
				break;
            case KEY_DOWN:
				// your logic goes here
				printf("Down.\n");
				break;
            case KEY_LEFT:
				// your logic goes here
				printf("Left.\n");
				break;
            case KEY_RIGHT:
				// your logic goes here
				printf("Right.\n");
				break;
            case KEY_SPACE:
				// your logic goes here
				printf("Space.\n");
				break;
        }
    }
    while(ch != KEY_SPACE);

    printf("...\nTerminated.");
}
