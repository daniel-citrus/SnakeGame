/*
 * apple.h
 *
 *  Created on: Jun 15, 2021
 *      Author: dcalvo
 * Description: Header for all apple related functions and information.
 *              In traditional game rules, there is usually only 1 apple
 *              present at a time.
 */

#ifndef HEADERS_APPLE_H_
#define HEADERS_APPLE_H_

#include <stdbool.h>
#include <time.h>

typedef struct apple apple;

struct apple {
    int x;
    int y;
};

apple *generate_apple();

bool collides(int x, int y);
bool same_coord(apple *a, int x, int y);

void destroy_apple(apple *a);

#endif /* HEADERS_APPLE_H_ */
