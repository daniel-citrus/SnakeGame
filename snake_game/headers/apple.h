/*
 * apple.h
 *
 *  Created on: Jun 7, 2021
 *      Author: Daniel
 */

#ifndef HEADERS_APPLE_H_
#define HEADERS_APPLE_H_

#include <stdlib.h>
#include <time.h>
#include "snake.h"

typedef struct apple apple;

struct apple
{
    int x;
    int y;
};

apple *generate_apple(void);

void destroy_apple(apple *a);           // Free the apple
void eaten(apple *a, snake *s);         // Generate another apple after being eaten?

#endif /* HEADERS_APPLE_H_ */
