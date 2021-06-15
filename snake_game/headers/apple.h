/*
 * apple.h
 *
 *  Created on: Jun 15, 2021
 *      Author: dcalvo
 * Description: Header for all apple related functions and information.
 *              There should only be one apple at a time.
 */

#ifndef HEADERS_APPLE_H_
#define HEADERS_APPLE_H_

#include "arena.h"

typedef struct apple apple;

apple *gala;

struct apple {
    int x;
    int y;
};

#endif /* HEADERS_APPLE_H_ */
