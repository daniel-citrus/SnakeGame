/*
 * apple.c
 *
 *  Created on: Jun 7, 2021
 *      Author: Daniel
 */
#include "../headers/apple.h"
#include "../headers/arena.h"
/*
int main(void)
{
    apple *a = generate_apple();
}*/

/*
 * Spawn an apple in random coordinates (within arena borders - 2)
 */
apple *generate_apple(void)
{
    apple *a = malloc(sizeof(apple));

    srand(time(NULL));

    int xCap = A_WIDTH - 2;


    int x = rand();


    return a;
}
